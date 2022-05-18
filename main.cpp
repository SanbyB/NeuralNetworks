
#include "include/Network.h"
#include "include/Propagation.h"
#include "include/BackPropagation.h"
#include "include/Drone.h"
#include <iostream>

#include <SFML/Graphics.hpp>


// defines a function that the network will try to replicate
// Eigen::VectorXd testFunction(Eigen::VectorXd inputActivations);


// Visual constants

int screenSize = 800;

int droneWidth = 40;
int droneHeight = 16;

int thrusterWidth = 8;
int thrusterHeight = 20;


int main(){

	sf::RenderWindow window(sf::VideoMode(screenSize, screenSize), "Drone simulation!");
	window.setFramerateLimit(200);

	Drone drone = Drone();

	// Drone graphics

    sf::RectangleShape droneShape(sf::Vector2f(droneWidth, droneHeight));
	sf::RectangleShape leftThrShape(sf::Vector2f(thrusterWidth, thrusterHeight));
	sf::RectangleShape rightThrShape(sf::Vector2f(thrusterWidth, thrusterHeight));

	// init graphics

	sf::Vector2f droneOrigin(screenSize/2, screenSize/2);
	sf::Vector2f lThrOffset(droneWidth/2, -droneHeight/2);
	sf::Vector2f rThrOffset(-droneWidth/2, -droneHeight/2);

    droneShape.setFillColor(sf::Color::White);
	droneShape.setOrigin(sf::Vector2f(droneWidth/2, droneHeight/2));
	droneShape.setPosition(droneOrigin);

	leftThrShape.setFillColor(sf::Color::Green);
	leftThrShape.setOrigin(sf::Vector2f(thrusterWidth/2, thrusterHeight/2));
	leftThrShape.setPosition(sf::Vector2f(droneOrigin - lThrOffset));

	rightThrShape.setFillColor(sf::Color::Red);
	rightThrShape.setOrigin(sf::Vector2f(thrusterWidth/2, thrusterHeight/2));
	rightThrShape.setPosition(sf::Vector2f(droneOrigin - rThrOffset));


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

		if(w){ drone.leftThruster.thrust += 0.000005; }
		if(s){ drone.leftThruster.thrust -= 0.000005; }
		if(a){ drone.leftThruster.angle += 0.01; }
		if(d){ drone.leftThruster.angle -= 0.01; }
		if(i){ drone.rightThruster.thrust += 0.000005; }
		if(k){ drone.rightThruster.thrust -= 0.000005; }
		if(j){ drone.rightThruster.angle += 0.01; }
		if(l){ drone.rightThruster.angle -= 0.01; }

		drone.applyForces(screenSize);

		droneShape.setPosition(droneOrigin - sf::Vector2f(drone.posX, drone.posY));
		droneShape.setRotation(-drone.angle * 180 / M_PI);

		lThrOffset = sf::Vector2f(droneWidth/2 * std::cos(drone.angle) - std::sin(drone.angle) * droneHeight/2, -droneHeight/2 * std::cos(drone.angle) - std::sin(drone.angle) * droneWidth/2);
		rThrOffset = sf::Vector2f(-droneWidth/2 * std::cos(drone.angle) - std::sin(drone.angle)* droneHeight/2, -droneHeight/2 * std::cos(drone.angle) + std::sin(drone.angle)* droneWidth/2);

		leftThrShape.setPosition(droneShape.getPosition() - lThrOffset);
		rightThrShape.setPosition(droneShape.getPosition() - rThrOffset);

		leftThrShape.setRotation((-drone.leftThruster.angle - drone.angle) * 180 / M_PI);
		rightThrShape.setRotation((-drone.rightThruster.angle - drone.angle) * 180 / M_PI);

        window.clear();
        window.draw(droneShape);
		window.draw(leftThrShape);
		window.draw(rightThrShape);
        window.display();
    }

	// srand( (unsigned)time( NULL ) );

	// Network net = Network({5, 10, 10, 2});

	// for(int j = 0; j < 5; j++){
	// Eigen::VectorXd input(5);

	// Eigen::VectorXd output(2);

	// for(int i = 0; i < 5; i++){
	// 	input(i) = rand()%10 + 1;
	// }

	// output = testFunction(input);

	// std::cout << "standard output: \n" << output << "\n";

	// output = Propagation::propagate(input, net);

	// std::cout << "network output: \n" << output << "\n";

	// }

	// std::cout << "===================\n";


	// BackPropagation backPropagate = BackPropagation();

	// int num = 0;

	// while (num < 50000){
	// 	Eigen::VectorXd input(5);

	// 	Eigen::VectorXd output(2);

	// 	for(int i = 0; i < 5; i++){
	// 		input(i) = rand()%10 + 1;
	// 	}

	// 	output = testFunction(input);

	// 	net = backPropagate.backProp(net, input, output);

	// 	num++;
	// }

	// for(int j = 0; j < 5; j++){
	// Eigen::VectorXd input(5);

	// Eigen::VectorXd output(2);

	// for(int i = 0; i < 5; i++){
	// 	input(i) = rand()%10 + 1;
	// }

	// output = testFunction(input);

	// std::cout << "standard output: \n" << output << "\n";

	// output = Propagation::propagate(input, net);

	// std::cout << "network output: \n" << output << "\n";

	// }

	// return 0;
}



// Eigen::VectorXd testFunction(Eigen::VectorXd inputActivations){

// 	double sum = inputActivations.sum() / 50;
// 	double take = abs((sum * 50) - 2 * (inputActivations(0)  + inputActivations(1)))/48;

// 	Eigen::Vector2d output(sum, take);
// 	return output;
// }



