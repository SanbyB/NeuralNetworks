#include "../include/Drone.h"
#include "../include/Propagation.h"


void Drone::computeThrust(){
	Eigen::VectorXd input(7);

	input(0) = posX - targetX;
	input(1) = posY - targetY;
	input(2) = velX;
	input(3) = velY;
	input(4) = std::cos(angle);
	input(5) = std::sin(angle);
	input(6) = angularVel;

	Eigen::VectorXd output(4);

	output = Propagation::propagate(input, flightComputer);

	leftThruster.thrust = output(0);
	rightThruster.thrust = output(1);
	leftThruster.angle = output(2);
	rightThruster.angle = output(3);
}

bool Drone::hitTarget(){
	// TODO define minDIst
	double minDist = 2;
	if(abs(posX - targetX) < minDist){
		if(abs(posY - targetY) < minDist){
			return true;
		}
	}
	return false;
}

void Drone::applyForces(){
	// apply force of gravity
	velY -= 10;

	// apply thruster force in the Y direction
	velY += std::cos(leftThruster.angle + angle) * leftThruster.thrust;
	velY += std::cos(rightThruster.angle + angle) * rightThruster.thrust;
	//  apply thruster force in the X direction
	velX += std::sin(leftThruster.angle + angle) * leftThruster.thrust;
	velX += std::sin(rightThruster.angle  + angle) * rightThruster.thrust;

	// apply thruster force to the angluar velocity
	angularVel += std::cos(rightThruster.angle) * rightThruster.thrust;
	angularVel -= std::cos(leftThruster.angle) * leftThruster.thrust;

	// apply velocity to position
	posX += velX;
	posY += velY;

	// apply angular vel to angle
	angle += angularVel;
}