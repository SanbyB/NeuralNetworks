/**
 * This is the main file which is used to train
 * a neural network on the MNIST data of hand written
 * digits. The technique used is back propagation,and
 * is currently set up without optimisation but it can achieve
 * over 90% accuracy when idenifying a digit.
 */


#include "include/Network.h"
#include "include/Propagation.h"
#include "include/BackPropagation.h"
#include "include/Utils.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
// #include <string>
// #include <vector>
// #include <sstream>

std::vector<double> draw(){
	std::vector<double> output(784);

	std::vector<sf::RectangleShape> pixels(784);

	int screenSize = 28 * 28;

		// create the window
	sf::RenderWindow window(sf::VideoMode(screenSize, screenSize), "Draw");

	// run the program as long as the window is open
	while (window.isOpen()){
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)){
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed){
				window.close();
			}
			sf::Mouse::Button left = sf::Mouse::Button::Left;
			if(sf::Mouse::isButtonPressed(left)){
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				sf::RectangleShape pixel(sf::Vector2f(28, 28));

				int i = pos.x /  28 + 28 * (pos.y / 28);

				pixel.setFillColor(sf::Color(0, 0, 0));
				pixel.setOrigin(sf::Vector2f(0, 0));
				pixel.setPosition(sf::Vector2f(28 * (i % 28), 28 * (i / 28)));

				pixels.at(i) = pixel;
				output.at(i) = 1;
			}
		}

		// clear the window with color
		window.clear(sf::Color(255,255,255));

		// draw everything here...
		for(int i = 0; i < 784; i++){
			window.draw(pixels.at(i));
		}

		// end the current frame
		window.display();
	}
	return output;
}


int main () {

	std::vector<std::vector<double>> td= {};
	readData(td, "../neural-networks-and-deep-learning-master/data/trainData.csv");


	std::vector<double> trainAns = {};
	readAns(trainAns, "../neural-networks-and-deep-learning-master/data/trainAnswers.csv");


	std::vector<std::vector<double>> tsd= {};
	readData(tsd, "../neural-networks-and-deep-learning-master/data/testData.csv");


	std::vector<double> testAns = {};
	readAns(testAns, "../neural-networks-and-deep-learning-master/data/testAnswers.csv");


	std::vector<std::vector<double>> vd= {};
	readData(vd, "../neural-networks-and-deep-learning-master/data/valData.csv");


	std::vector<double> valAns = {};
	readAns(valAns, "../neural-networks-and-deep-learning-master/data/valAnswers.csv");

	std::vector<int> n = {784, 100, 10};

	Network net;

	net.setNetwork(n);

	std::cout << "Neural Network of size: ";

	for(int i = 0; i < n.size(); i++){
		std::cout << n.at(i) << ", ";
	}

	std::cout << "\n";

	BackPropagation bp  = BackPropagation();

	std::cout << "Training data used to tune the network\n";

	for(int i = 0; i < 50000; i++){
		net = bp.backProp(net, toEigen(td[i]), output(trainAns[i]));
	}

	std::cout << "Validation data used to check the network\n";

	int count = 0;

	for(int i = 0; i < 10000; i++){
	Eigen::MatrixXd ans = Propagation::propagate(toEigen(vd[i]), net);
	if(valAns[i] == output(ans)){
		count++;
	}
	}

	std::cout << count << " out of 10,000 images identified correctly\n";

	std::vector<double> drawnInt = draw();

	int myAns = output(Propagation::propagate(toEigen(drawnInt), net));

	std::cout << "You drew a " << myAns << "\n";

	return 0;
}

