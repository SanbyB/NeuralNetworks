#pragma once
#include "Network.h"
#include "Target.h"
#include <memory>

class Thruster{

public:

	// thrust value between 0-10,corresponds to acceleration
	double thrust;

	/*  angle (in radians) the thuster makes with the drone body,
	 0 is upright, counterclockwise convention
	*/
	double angle;

	Thruster(){
		thrust = 0;
		angle = 0;
	}

};


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
	// Network flightComputer;

	Thruster leftThruster = Thruster();

	Thruster rightThruster = Thruster();

	// current position of the drone
	double posX = 0;
	double posY = 0;

	// current velocity of the drone
	double velX = 0;
	double velY = 0;

	// current angle of the drone (rad, counterclockwise convention)
	double angle = 0;

	// current angular velocity (rad, counterclockwise convention)
	double angularVel = 0;

	// drones target
	std::shared_ptr<Target> target;

	/*
	Applies the forces from the thrusters and gravity to the drone,
	the thruster will affect the angular velocity of the drone.
	This will update all the spatial variables of the drone.
	*/
	void applyForces(int screenSize);

	/*
	Propagates the current spatial properties through the flightComputer
	*/
	void computeThrust(Network flightComputer);

	// checks if the target has been hit, returns true if it has
	bool hitTarget();

};


