#pragma once
#include "Network.h"


class Thruster{

public:

	// thrust value between 0-10,corresponds to acceleration
	double thrust;

	//  angle (in radians) the thuster makes with the drone body, 0 is upright
	double angle;

	Thruster();

}

Thruster::Thruster(){
	thrust = 0;
	angle = 0;
}



class Drone{

public:
	Drone();
	~Drone();

	/*
	7 Inputs:
	- target distance x
	- target distance y
	- velocity x
	- velocity y
	- cos(angle)
	- sin(angle)
	- angluar velocity
	4 Outputs:
	- thrust left
	- thrust right
	- thruster angle left
	- thruster angle right
	*/
	Network flightComputer;

	Thruster leftThruster = Thruster();

	Thruster rightThruster = Thruster();

	// current position of the drone
	double posX;
	double posY;

	// current velocity of the drone
	double velX;
	double velY;

	// current angle of the drone
	double angle;

	// current angular velocity
	double angularVel;

	// position of the target
	double targetX;
	double targetY;

	/*
	Applies the forces from the thrusters and gravity to the drone,
	the thruster will affect the angular velocity of the drone.
	This will update all the spatial variables of the drone.
	*/
	void applyForces();

	/*
	Propagates the current spatial properties through the flightComputer
	*/
	void computeThrust();

	// checks if the target has been hit, returns true if it has
	bool hitTarget();

};


