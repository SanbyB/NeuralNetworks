
#include "../include/Actions.h"


Actions::Actions(){}

void Actions::keyPressed(sf::Event event, bool &w, bool &a, bool &d){
	if(event.type == sf::Event::KeyPressed){
		switch (event.key.code){
		case sf::Keyboard::W : w = true; break;
		case sf::Keyboard::A : a = true; break;
		case sf::Keyboard::D : d = true; break;
		}
	}
	// key released
	if(event.type == sf::Event::KeyReleased){
		switch (event.key.code){
		case sf::Keyboard::W : w = false; break;
		case sf::Keyboard::A : a = false; break;
		case sf::Keyboard::D : d = false; break;
		}
	}
}

