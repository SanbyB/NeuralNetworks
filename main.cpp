
#include "include/Network.h"
#include "include/Propagation.h"
#include "include/BackPropagation.h"
#include "include/Drone.h"
#include "include/Target.h"
#include <memory>
#include <iostream>

#include <SFML/Graphics.hpp>

// Visual constants

int screenSize = 800;

int droneWidth = 40;
int droneHeight = 16;

int thrusterWidth = 8;
int thrusterHeight = 20;

bool humanControl = false;


int main(){

	sf::RenderWindow window(sf::VideoMode(screenSize, screenSize), "Drone simulation!");
	window.setFramerateLimit(200);

	Drone drone = Drone();

	Network flightComputer = Network({7, 25, 25, 4});

	auto target = std::make_shared<Target>();

	target->initTarget(screenSize);

	drone.target = target;

	int score = 0;

	int pause = 0;

	// Drone graphics

    sf::RectangleShape droneShape(sf::Vector2f(droneWidth, droneHeight));
	sf::RectangleShape leftThrShape(sf::Vector2f(thrusterWidth, thrusterHeight));
	sf::RectangleShape rightThrShape(sf::Vector2f(thrusterWidth, thrusterHeight));

	// Target graphics
	sf::CircleShape targetShape(5);

	// init graphics

	sf::Vector2f droneOrigin(screenSize/2, screenSize/2);
	sf::Vector2f lThrOffset(droneWidth/2, -droneHeight/2);
	sf::Vector2f rThrOffset(-droneWidth/2, -droneHeight/2);
	sf::Vector2f tPos(target->posX, target->posY);

    droneShape.setFillColor(sf::Color::White);
	droneShape.setOrigin(sf::Vector2f(droneWidth/2, droneHeight/2));
	droneShape.setPosition(droneOrigin);

	leftThrShape.setFillColor(sf::Color::Green);
	leftThrShape.setOrigin(sf::Vector2f(thrusterWidth/2, thrusterHeight/2));
	leftThrShape.setPosition(sf::Vector2f(droneOrigin - lThrOffset));

	rightThrShape.setFillColor(sf::Color::Red);
	rightThrShape.setOrigin(sf::Vector2f(thrusterWidth/2, thrusterHeight/2));
	rightThrShape.setPosition(sf::Vector2f(droneOrigin - rThrOffset));

	targetShape.setFillColor(sf::Color::Magenta);
	targetShape.setOrigin(sf::Vector2f(2.5, 2.5));
	targetShape.setPosition(droneOrigin - tPos);

	// Player input

	bool w = false;
	bool s = false;
	bool a = false;
	bool d = false;
	bool i = false;
	bool k = false;
	bool j = false;
	bool l = false;

	// Game loop

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			// close window
            if (event.type == sf::Event::Closed)
                window.close();

			if(humanControl){
				// key pressed
				if(event.type == sf::Event::KeyPressed){
					if(event.key.code == sf::Keyboard::W){ w = true; }
					if(event.key.code == sf::Keyboard::S){ s = true; }
					if(event.key.code == sf::Keyboard::A){ a = true; }
					if(event.key.code == sf::Keyboard::D){ d = true; }
					if(event.key.code == sf::Keyboard::I){ i = true; }
					if(event.key.code == sf::Keyboard::K){ k = true; }
					if(event.key.code == sf::Keyboard::J){ j = true; }
					if(event.key.code == sf::Keyboard::L){ l = true; }
				}
				// key released
				if(event.type == sf::Event::KeyReleased){
					if(event.key.code == sf::Keyboard::W){ w = false; }
					if(event.key.code == sf::Keyboard::S){ s = false; }
					if(event.key.code == sf::Keyboard::A){ a = false; }
					if(event.key.code == sf::Keyboard::D){ d = false; }
					if(event.key.code == sf::Keyboard::I){ i = false; }
					if(event.key.code == sf::Keyboard::K){ k = false; }
					if(event.key.code == sf::Keyboard::J){ j = false; }
					if(event.key.code == sf::Keyboard::L){ l = false; }
				}
			}
        }
		if(humanControl){
			if(w){ drone.leftThruster->thrust += 0.00005; }
			if(s){ drone.leftThruster->thrust -= 0.00005; }
			if(a){ drone.leftThruster->angle += 0.1; }
			if(d){ drone.leftThruster->angle -= 0.1; }
			if(i){ drone.rightThruster->thrust += 0.00005; }
			if(k){ drone.rightThruster->thrust -= 0.00005; }
			if(j){ drone.rightThruster->angle += 0.1; }
			if(l){ drone.rightThruster->angle -= 0.1; }
		}
		else{
			/*
			7 Inputs:
			- target distance x
			- target distance y
			- velocity x
			- velocity y
			- cos(angle)
			- sin(angle)
			- angular velocity
			4 Outputs:
			- thrust left
			- thrust right
			- thruster angle left
			- thruster angle right
			*/
			double distX = drone.posX - target->posX;
			double distY = drone.posY - target->posY;
			Eigen::VectorXd inputs(7);
			// TODO normalise inputs and unnormalise outputs
			inputs(0) = distX / screenSize;
			inputs(1) = distY / screenSize;
			inputs(2) = drone.velX;
			inputs(3) = drone.velY;
			inputs(4) = std::cos(drone.angle);
			inputs(5) = std::sin(drone.angle);
			inputs(6) = drone.angularVel;
			Eigen::VectorXd output = Propagation::propagate(inputs, flightComputer);
			drone.leftThruster->thrust = output(0);
			drone.rightThruster->thrust = output(1);
			drone.leftThruster->angle = output(2);
			drone.rightThruster->angle = output(3);

			std::cout << "lThr: " << drone.leftThruster->thrust << " lAng: " << drone.leftThruster->angle
					  << " rThr: " << drone.rightThruster->thrust << " rAng: " << drone.rightThruster->angle << "\n";
		}

		drone.applyForces(screenSize);

		droneShape.setPosition(droneOrigin - sf::Vector2f(drone.posX, drone.posY));
		droneShape.setRotation(-drone.angle * 180 / M_PI);

		lThrOffset = sf::Vector2f(droneWidth/2 * std::cos(drone.angle) - std::sin(drone.angle) * droneHeight/2, -droneHeight/2 * std::cos(drone.angle) - std::sin(drone.angle) * droneWidth/2);
		rThrOffset = sf::Vector2f(-droneWidth/2 * std::cos(drone.angle) - std::sin(drone.angle)* droneHeight/2, -droneHeight/2 * std::cos(drone.angle) + std::sin(drone.angle)* droneWidth/2);

		leftThrShape.setPosition(droneShape.getPosition() - lThrOffset);
		rightThrShape.setPosition(droneShape.getPosition() - rThrOffset);

		leftThrShape.setRotation((-drone.leftThruster->angle - drone.angle) * 180 / M_PI);
		rightThrShape.setRotation((-drone.rightThruster->angle - drone.angle) * 180 / M_PI);

		if(pause == 0 && drone.hitTarget()){
			target->spawnTarget();
			score++;
		}

		tPos = sf::Vector2f(target->posX, target->posY);
		targetShape.setPosition(droneOrigin - tPos);

        window.clear();
        window.draw(droneShape);
		window.draw(leftThrShape);
		window.draw(rightThrShape);
		window.draw(targetShape);
        window.display();
    }

	return 0;

}



