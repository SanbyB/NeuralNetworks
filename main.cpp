
#include "include/Network.h"
#include "include/Propagation.h"
#include "include/BackPropagation.h"
#include <iostream>

#include <SFML/Graphics.hpp>



// defines a function that the network will try to replicate
Eigen::VectorXd testFunction(Eigen::VectorXd inputActivations);


int main(){

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::RectangleShape shape(sf::Vector2f(20, 30));
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

	srand( (unsigned)time( NULL ) );

	Network net = Network({5, 10, 10, 2});

	for(int j = 0; j < 5; j++){
	Eigen::VectorXd input(5);

	Eigen::VectorXd output(2);

	for(int i = 0; i < 5; i++){
		input(i) = rand()%10 + 1;
	}

	output = testFunction(input);

	std::cout << "standard output: \n" << output << "\n";

	output = Propagation::propagate(input, net);

	std::cout << "network output: \n" << output << "\n";

	}

	std::cout << "===================\n";


	BackPropagation backPropagate = BackPropagation();

	int num = 0;

	while (num < 50000){
		Eigen::VectorXd input(5);

		Eigen::VectorXd output(2);

		for(int i = 0; i < 5; i++){
			input(i) = rand()%10 + 1;
		}

		output = testFunction(input);

		net = backPropagate.backProp(net, input, output);

		num++;
	}

	for(int j = 0; j < 5; j++){
	Eigen::VectorXd input(5);

	Eigen::VectorXd output(2);

	for(int i = 0; i < 5; i++){
		input(i) = rand()%10 + 1;
	}

	output = testFunction(input);

	std::cout << "standard output: \n" << output << "\n";

	output = Propagation::propagate(input, net);

	std::cout << "network output: \n" << output << "\n";

	}

	return 0;
}



Eigen::VectorXd testFunction(Eigen::VectorXd inputActivations){

	double sum = inputActivations.sum() / 50;
	double take = abs((sum * 50) - 2 * (inputActivations(0)  + inputActivations(1)))/48;

	Eigen::Vector2d output(sum, take);
	return output;
}



