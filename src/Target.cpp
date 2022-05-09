#include "../include/Target.h"

Target::spawnTarget(){
	srand( (unsigned)time( NULL ) );
	// TODO define screen_size
	int screen_size = 200;
	posX = (rand() % screen_size) - (screen_size / 2);
	posY = (rand() % screen_size) - (screen_size / 2)
}