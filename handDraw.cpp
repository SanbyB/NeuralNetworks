#include <SFML/Graphics.hpp>
#include "include/Utils.h"

int screenSize = 28 * 28;

void run(int &index, std::vector<std::vector<double>> td){
	std::vector<double> image = td.at(index);

	std::vector<sf::RectangleShape> pixels(784);

	for(int i = 0; i < 784; i++){
		sf::RectangleShape pixel(sf::Vector2f(28, 28));
		double pv = image.at(i);
		pv = 255 * (1 - pv);
		pixel.setFillColor(sf::Color(pv, pv, pv));
		pixel.setOrigin(sf::Vector2f(0, 0));
		pixel.setPosition(sf::Vector2f(28 * (i % 28), 28 * (i / 28)));
		pixels.at(i) = pixel;
	}

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
				std::cin >> index;
				if(index >= 0){
					run(index, td);
				}
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
}


int main(){

	std::vector<std::vector<double>> td= {};
	readData(td, "../neural-networks-and-deep-learning-master/data/trainData.csv");

	int index = 0;

	run(index, td);

    return 0;
}
