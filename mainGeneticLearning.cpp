#include "include/Drone.h"
#include "include/Target.h"
#include "include/Propagation.h"
#include <memory>
#include <iostream>

#include <SFML/Graphics.hpp>

//Visual constants

int screenSize = 800;

int droneSize = 20;

int thrusterWidth = 8;
int thrusterHeight = 20;

bool humanControl = true;
bool gui = true;


int main(){
	if(gui){

		Drone drone = Drone();

		Network flightComputer = Network({11, 40, 50, 40, 4});

		auto target = std::make_shared<Target>();

		target->initTarget(screenSize);

		drone.target = target;


		sf::RenderWindow window(sf::VideoMode(screenSize, screenSize), "Drone simulation!");
		window.setFramerateLimit(200);

		// Drone graphics

		sf::CircleShape droneShape(droneSize);
		sf::RectangleShape thrShape(sf::Vector2f(thrusterWidth, thrusterHeight));

		// Target graphics
		sf::CircleShape targetShape(5);

		// init graphics

		sf::Vector2f droneOrigin(screenSize/2, screenSize/2);
		sf::Vector2f tPos(target->posX, target->posY);

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
		bool s = false;
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
					std::cout << drone.score <<  "\n";
					window.close();
				}

				if(humanControl){
					// key pressed
					if(event.type == sf::Event::KeyPressed){
						if(event.key.code == sf::Keyboard::W){ w = true; }
						if(event.key.code == sf::Keyboard::S){ s = true; }
						if(event.key.code == sf::Keyboard::A){ a = true; }
						if(event.key.code == sf::Keyboard::D){ d = true; }
					}
					// key released
					if(event.type == sf::Event::KeyReleased){
						if(event.key.code == sf::Keyboard::W){ w = false; }
						if(event.key.code == sf::Keyboard::S){ s = false; }
						if(event.key.code == sf::Keyboard::A){ a = false; }
						if(event.key.code == sf::Keyboard::D){ d = false; }
					}
				}
			}
			if(humanControl){
				if(w){ drone.thruster->thrust += 5e-4; }
				else{ drone.thruster->thrust -= 1e-4; }
				if(a){ drone.thruster->angle += 0.01; }
				if(d){ drone.thruster->angle -= 0.01; }
			}
			else{
				//TODO this is supposed to be part of the compute thrust function in th drone class
				/*
				11 Inputs:
				- target distance x
				- target distance y
				- velocity x
				- velocity y
				- cos(angle)
				- sin(angle)
				- angular velocity
				- left thruster thrust
				- left thruster angle
				- right thruster thrust
				- right thruster angle
				4 Outputs:
				- thrust left
				- thrust right
				- thruster angle left
				- thruster angle right
				*/
				// double distX = drone.posX - target->posX;
				// double distY = drone.posY - target->posY;
				// Eigen::VectorXd inputs(11);
				// // TODO better noramlisation
				// inputs(0) = distX / screenSize;
				// inputs(1) = distY / screenSize;
				// inputs(2) = drone.velX / 5;
				// inputs(3) = drone.velY / 5;
				// inputs(4) = std::cos(drone.angle);
				// inputs(5) = std::sin(drone.angle);
				// inputs(6) = drone.angularVel * 10;
				// inputs(7) = drone.thruster->thrust / 0.005; // TODO change this to a config
				// inputs(8) = drone.thruster->angle / M_PI;
				// inputs(9) = drone.rightThruster->thrust / 0.005;
				// inputs(10) = drone.rightThruster->angle /  M_PI;
				// Eigen::VectorXd output = Propagation::propagate(inputs, flightComputer);
				// double lt = output(0);
				// double la = output(1);
				// double rt = output(2);
				// double ra = output(3);

				// if(lt < 10.0 / 24.0){
				// 	drone.thruster->thrust -= 1e-4;
				// }
				// else if (lt > 14.0 / 24.0){
				// 	drone.thruster->thrust += 1e-4;
				// }

				// if(la < 1.0 / 3.0){
				// 	drone.thruster->angle -= 0.02;
				// }
				// else if (la > 2.0 / 3.0){
				// 	drone.thruster->angle += 0.02;
				// }

			}

			// std::cout << drone.score << "\n";

			drone.applyForces(screenSize);

			droneShape.setPosition(droneOrigin - sf::Vector2f(drone.posX, drone.posY));
			// droneShape.setRotation(-drone.angle * 180 / M_PI);

			thrShape.setPosition(droneShape.getPosition() + sf::Vector2f(thrusterHeight/2, thrusterHeight/2));

			thrShape.setRotation((-drone.thruster->angle) * 180 / M_PI);

			if(drone.hitTarget()){
				target->spawnTarget();
				drone.score++;
			}

			tPos = sf::Vector2f(target->posX, target->posY);
			targetShape.setPosition(droneOrigin - tPos);

			window.clear();
			window.draw(droneShape);
			window.draw(thrShape);
			window.draw(targetShape);
			window.display();
		}

	}
	else{
		// Drone drone = Drone();

		// auto target = std::make_shared<Target>();

		// target->initTarget(screenSize);

		// drone.target = target;

		// std::vector<Network> flightComps;
		// std::vector<int> scores;

		// for(int i = 0; i < 10000; i++){

		// 	Network flightComputer = Network({11, 40, 50, 40, 4});



		// 	while (drone.count < 100000){
		// 		/*
		// 		11 Inputs:
		// 		- target distance x
		// 		- target distance y
		// 		- velocity x
		// 		- velocity y
		// 		- cos(angle)
		// 		- sin(angle)
		// 		- angular velocity
		// 		- left thruster thrust
		// 		- left thruster angle
		// 		- right thruster thrust
		// 		- right thruster angle
		// 		4 Outputs:
		// 		- thrust left
		// 		- thrust right
		// 		- thruster angle left
		// 		- thruster angle right
		// 		*/
		// 		double distX = drone.posX - target->posX;
		// 		double distY = drone.posY - target->posY;
		// 		Eigen::VectorXd inputs(11);
		// 		// TODO better noramlisation
		// 		inputs(0) = distX / screenSize;
		// 		inputs(1) = distY / screenSize;
		// 		inputs(2) = drone.velX / 5;
		// 		inputs(3) = drone.velY / 5;
		// 		inputs(4) = std::cos(drone.angle);
		// 		inputs(5) = std::sin(drone.angle);
		// 		inputs(6) = drone.angularVel * 10;
		// 		inputs(7) = drone.thruster->thrust / 0.005; // TODO change this to a config
		// 		inputs(8) = drone.thruster->angle / M_PI;
		// 		inputs(9) = drone.rightThruster->thrust / 0.005;
		// 		inputs(10) = drone.rightThruster->angle /  M_PI;
		// 		Eigen::VectorXd output = Propagation::propagate(inputs, flightComputer);
		// 		double lt = output(0);
		// 		double la = output(1);
		// 		double rt = output(2);
		// 		double ra = output(3);

		// 		if(lt < 10.0 / 24.0){
		// 			drone.thruster->thrust -= 1e-4;
		// 		}
		// 		else if (lt > 14.0 / 24.0){
		// 			drone.thruster->thrust += 1e-4;
		// 		}

		// 		if(la < 1.0 / 3.0){
		// 			drone.thruster->angle -= 0.02;
		// 		}
		// 		else if (la > 2.0 / 3.0){
		// 			drone.thruster->angle += 0.02;
		// 		}

		// 		if(rt < 10.0 / 24.0){
		// 			drone.rightThruster->thrust -= 1e-4;
		// 		}
		// 		else if (rt > 14.0 / 24.0){
		// 			drone.rightThruster->thrust += 1e-4;
		// 		}

		// 		if(ra < 1.0 / 3.0){
		// 			drone.rightThruster->angle -= 0.02;
		// 		}
		// 		else if (ra > 2.0 / 3.0){
		// 			drone.rightThruster->angle += 0.02;
		// 		}
		// 		drone.applyForces(screenSize);

		// 	}

		// 	if(drone.hitTarget()){
		// 		target->spawnTarget();
		// 		drone.score++;
		// 	}


		// 	if(flightComps.size() < 5){
		// 		flightComps.push_back(flightComputer);
		// 		scores.push_back(drone.score);
		// 	}
		// 	else{
		// 		int min = 2000;
		// 		int mindex;
		// 		for(int i; i < 5; i++){
		// 			int prev = min;
		// 			min = std::min(scores.at(i), min);
		// 			if(min < prev){
		// 				mindex = i;
		// 			}
		// 		}
		// 		if(drone.score > min){
		// 			flightComps.at(mindex) = flightComputer;
		// 			scores.at(mindex) = drone.score;
		// 		}
		// 	}

		// }

		// for(int i : scores){
		// 	std::cout << "score: " << i <<  "\n";
		// }

	}

	return 0;

}

