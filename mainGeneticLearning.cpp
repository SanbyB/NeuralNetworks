#include "include/Drone.h"
#include "include/Target.h"
#include "include/Propagation.h"
#include "include/Actions.h"
#include <memory>
#include <iostream>

#include <SFML/Graphics.hpp>

//Visual constants

int screenSize = 800;

int droneSize = 20;

int thrusterWidth = 8;
int thrusterHeight = 20;

bool humanControl = false;
bool gui = false;


int main(){
	srand(0);
	if(gui){
		// TODO want to change this
		AutoDrone drone = AutoDrone();

		auto target = std::make_shared<Target>();

		target->initTarget(screenSize);

		drone.init(screenSize, target);


		sf::RenderWindow window(sf::VideoMode(screenSize, screenSize), "Drone simulation!");
		window.setFramerateLimit(200);

		// Drone graphics
		sf::CircleShape droneShape(droneSize);
		sf::RectangleShape thrShape(sf::Vector2f(thrusterWidth, thrusterHeight));

		// Target graphics
		sf::CircleShape targetShape(5);

		// init graphics
		sf::Vector2f droneOrigin(screenSize/2, screenSize/2);
		sf::Vector2f tPos(target->getPosX(), target->getPosY());

		droneShape.setFillColor(sf::Color::White);
		droneShape.setOrigin(sf::Vector2f(droneSize/2, droneSize/2));
		droneShape.setPosition(droneOrigin);

		thrShape.setFillColor(sf::Color::Green);
		thrShape.setOrigin(sf::Vector2f(thrusterWidth/2, thrusterHeight/2));
		thrShape.setPosition(sf::Vector2f(droneOrigin));

		targetShape.setFillColor(sf::Color::Magenta);
		targetShape.setOrigin(sf::Vector2f(2.5, 2.5));
		targetShape.setPosition(droneOrigin - tPos);

		// Player input
		bool w = false;
		bool a = false;
		bool d = false;

		// Game loop

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				// close window
				if (event.type == sf::Event::Closed){
					window.close();
					Network fc = drone.getFlightComputer();
					std::cout << "weights\n";
					for(int i = 0; i < fc.numLayers - 1; i++){
						std::cout << fc.weights.at(i) << "\n";
					}
					std::cout << "biases\n";
					for(int i = 0; i < fc.numLayers - 1; i++){
						std::cout << fc.biases.at(i) << "\n";
					}
				}
				if(humanControl){
					Actions::keyPressed(event, w, a, d);
				}
			}
			if(humanControl){
				drone.update(w, a, d);
			}else{
				drone.computeThrust();
			}

			droneShape.setPosition(droneOrigin - sf::Vector2f(drone.pos()[0], drone.pos()[1]));

			thrShape.setPosition(droneShape.getPosition() + sf::Vector2f(thrusterHeight/2, thrusterHeight/2));

			thrShape.setRotation((-drone.angle()) * 180 / M_PI);



			tPos = sf::Vector2f(target->getPosX(), target->getPosY());
			targetShape.setPosition(droneOrigin - tPos);

			window.clear();
			window.draw(droneShape);
			window.draw(thrShape);
			window.draw(targetShape);
			window.display();
		}

	}
	else{

		AutoDrone drone = AutoDrone();

		auto target = std::make_shared<Target>();

		target->initTarget(screenSize);

		drone.init(screenSize, target);

		std::vector<Network> flightComps;
		std::vector<int> scores;

		for(int i = 0; i < 20; i++){

			Network flightComputer;

			flightComputer.setNetwork({6, 10, 5, 3});

			drone.setFlightComputer(flightComputer);

			while (drone.getCount() < 100000){
				drone.computeThrust();
			}

			drone.setCount(0);

			// TODO tidy this up pls
			if(flightComps.size() < 5){
				flightComps.push_back(drone.getFlightComputer());
				scores.push_back(drone.getScore());
			}
			else{
				int min = 2000;
				int mindex;
				for(int i; i < 5; i++){
					int prev = min;
					min = std::min(scores.at(i), min);
					if(min < prev){
						mindex = i;
					}
				}
				if(drone.getScore() > min){
					flightComps.at(mindex) = drone.getFlightComputer();
					scores.at(mindex) = drone.getScore();
				}
			}

		}

		for(int i = 0; i < 5; i++){
			std::cout << "###########################\n";
			std::cout << "score: " << scores.at(i) <<  "\n\n";
			flightComps.at(i).print();
		}

	}

	return 0;

}

