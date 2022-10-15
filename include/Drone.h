#pragma once
#include "Network.h"
#include "Target.h"
#include "Utils.h"
#include <memory>

class Thruster{

public:

	Thruster(){
		thrust = 0;
		angle = 0;
	}

private:

	// thrust value between 0-10,corresponds to acceleration
	double thrust;

	/*  angle (in radians) the thuster makes with the drone body,
	 0 is upright, counterclockwise convention
	*/
	double angle;

};


class Drone{

public:
	Drone();

	// called each game loop
	void update(bool humanControl, bool w, bool a, bool d);

	void init(int screenSize, std::shared_ptr<Target> t);

private:
	// Configs
	double maxThrust = 0.015;
	int rechargeTime = 100;
	double minDist = 80;
	double terminalVel = 0.99;

	// Timing variables
	int recharge = 0;
	int count = 0;
	int score = 0;

	// Slow the movement
	void terminalVelocity();

	// current position of the drone
	double posX = 0;
	double posY = 0;

	// current velocity of the drone
	double velX = 0;
	double velY = 0;

	std::shared_ptr<Thruster> thruster = std::make_shared<Thruster>();

	// drones target
	std::shared_ptr<Target> target;

	// sets target
	void target(std::shared_ptr<Target> t);

	// size of the screen the done can operate on
	int screenSize;

	// sets screenSize
	void screenSize(int s);


	/*
	Applies the forces from the thrusters and gravity to the drone,
	the thruster will affect the angular velocity of the drone.
	This will update all the spatial variables of the drone.
	*/
	void applyForces();


	// checks if the target has been hit, returns true if it has
	bool hitTarget();

};


class AutoDrone: public Drone{
public:
	AutoDrone();

	// set the flight computer
	void flightComputer(Network fc);

	// Propagates the current spatial properties through the flightComputer
	void computeThrust();

private:

	Network flightComputer;

};

