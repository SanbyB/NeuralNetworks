#pragma once

class Target{
public:
	Target();
	~Target();

	void initTarget(int screen);

	void spawnTarget();

	double getPosX();
	double getPosY();

private:
	double posX;
	double posY;

	int screenSize;
};