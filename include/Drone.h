#pragma once
#include "Network.h"
#include "Target.h"
#include "Utils.h"
#include <memory>

class Thruster{

public:

	Thruster(){
		thrustVal = 0;
		angleVal = 0;
	}

	// getters and setters for the thrust and angle
	void thrust(double t);

	double thrust();

	void angle(double a);

	double angle();

private:

	// thrust value between 0-10,corresponds to acceleration
	double thrustVal;

	/*  angle (in radians) the thuster makes with the drone body,
	 0 is upright, counterclockwise convention
	*/
	double angleVal;

};


class Drone{

public:
	Drone();

	// called each game loop
	void update(bool w, bool a, bool d);

	void init(int screenSize, std::shared_ptr<Target> t);

	// returns x, y position of the drone
	std::vector<double> pos();

	// getters for the thrusters thrust and angle
	double thrust();

	double angle();

	// get count
	int getCount();

	void setCount(int c);

	// returns the score
	int getScore();

	void setScore(int s);

protected:
	// size of the screen the done can operate on
		int screenSize;

	// current position of the drone
	double posX = 0;
	double posY = 0;

	// current velocity of the drone
	double velX = 0;
	double velY = 0;

	// Configs
	double maxThrust = 0.015;

	std::shared_ptr<Thruster> thruster = std::make_shared<Thruster>();

	// drones target
	std::shared_ptr<Target> target;

	// returns the maximum possible velocity
	double maxVel();

private:
	int rechargeTime = 100;
	double minDist = 80;
	double terminalVel = 0.99;

	// Timing variables
	int recharge = 0;
	int count = 0;
	int score = 0;

	// Slow the movement
	void terminalVelocity();

	// sets target
	void setTarget(std::shared_ptr<Target> t);

	// sets screenSize
	void setScreenSize(int s);


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
	void setFlightComputer(Network fc);

	// get the flight computer
	Network getFlightComputer();

	// Propagates the current spatial properties through the flightComputer
	void computeThrust();

private:

	Network flightComputer;

};

