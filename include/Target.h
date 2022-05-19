#pragma once

class Target{
public:
	Target();
	~Target();

	double posX;
	double posY;

	int screenSize;

	void initTarget(int screen);

	void spawnTarget();
};