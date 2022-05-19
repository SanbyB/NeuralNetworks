#include "../include/Target.h"
#include <time.h>
#include <cstdlib>

Target::Target(){}

Target::~Target(){}

void Target::initTarget(int screen){
	screenSize = screen;
	spawnTarget();
}

void Target::spawnTarget(){
	srand( (unsigned)time( NULL ) );
	posX = (rand() % screenSize) - (screenSize / 2);
	posY = (rand() % screenSize) - (screenSize / 2);
}