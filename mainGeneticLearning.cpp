#include "include/Drone.h"
#include "include/Target.h"
#include "include/Propagation.h"
#include "include/Actions.h"
#include <memory>
#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

//Visual constants

int screenSize = 800;

int droneSize = 20;

int thrusterWidth = 8;
int thrusterHeight = 20;

bool humanControl = false;
bool gui = true;


int main(){
	srand(0);
	if(gui){
		// TODO want to change this
		AutoDrone drone = AutoDrone();

		auto target = std::make_shared<Target>();

		target->initTarget(screenSize);

		drone.init(screenSize, target);

		Network flightComputer = readNet("../output.txt");

		// flightComputer.setNetwork({6, 10, 5, 3});

		drone.setFlightComputer(flightComputer);


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
			while (window.pollEvent(event)){
				// close window
				if (event.type == sf::Event::Closed){
					window.close();
					Network fc = drone.getFlightComputer();
					// Networks have a print() function, would recommend changing to that
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

		std::map<int, Network> scores;

		for(int i = 0; i < 20; i++){
			for(int n = 0; n < i; n++){
				std::cout << "-";
			}
			std::cout << "\n";
			std::cout << "\x1b[1A";
			// std::this_thread::sleep_for(std::chrono::milliseconds(100));

			Network flightComputer;

			flightComputer.setNetwork({1, 4, 5, 1});

			drone.setFlightComputer(flightComputer);


			// let drone fly for given time
			while (drone.getCount() < 100000){
				drone.computeThrust();
			}

			// push back flight computer and score
			scores[drone.getScore()] = drone.getFlightComputer();
			
			// reset drone
			drone.setCount(0);
			drone.setScore(0);


		}
		std::cout << "\n";

		std::cout << "scores size " << scores.size() << "\n";

		for(auto i = scores.begin(); i != scores.end(); i++){
			std::cout << "###########################\n";
			std::cout << "score: " << i->first <<  "\n\n";
			i->second.print();
		}

	}

	return 0;

}

