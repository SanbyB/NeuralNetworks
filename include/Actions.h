#pragma once
#include <SFML/Graphics.hpp>

class Actions{
public:
	Actions();

	static void keyPressed(sf::Event event, bool &w, bool &a, bool &d);

};