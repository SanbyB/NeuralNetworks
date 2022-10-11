#include "../include/Drone.h"
#include "../include/Propagation.h"
#include <iostream>

Drone::Drone(){}
Drone::~Drone(){}

void Drone::computeThrust(Network flightComputer){
	Eigen::VectorXd input(4);

	input(0) = posX - target->posX;
	input(1) = posY - target->posY;
	input(2) = velX;
	input(3) = velY;
	// input(4) = std::cos(angle);
	// input(5) = std::sin(angle);
	// input(6) = angularVel;

	Eigen::VectorXd output(2);

	output = Propagation::propagate(input, flightComputer);

	thruster->thrust = output(0);
	thruster->angle = output(1);
}

bool Drone::hitTarget(){
	if(recharge){
		recharge--;
		return false;
	}
	if(abs(posX - target->posX) < minDist){
		if(abs(posY - target->posY) < minDist){
			recharge = rechargeTime;
			return true;
		}
	}
	return false;
}

void Drone::applyForces(int screenSize){
	// std::cout << "Velocity: " << velX << ", " << velY << "\n";
	count++;
	// apply force of gravity
	// velY -= gravity;

	// restrict thrust
	if(thruster->thrust < 0){ thruster->thrust = 0; }
	else if(thruster->thrust > maxThrust){ thruster->thrust = maxThrust; }

	// restrict angle (for normalisation)
	if(thruster->angle < -M_PI){ thruster->angle = M_PI; }
	else if(thruster-> angle > M_PI){ thruster->angle = -M_PI; }


	// apply thruster force in the Y direction
	velY += std::cos(thruster->angle) * thruster->thrust;
	//  apply thruster force in the X direction
	velX += std::sin(thruster->angle) * thruster->thrust;

	// apply thruster force to the angluar velocity
	// angularVel += inertia * std::cos(rightThruster->angle) * rightThruster->thrust;
	// angularVel -= inertia * std::cos(thruster->angle) * thruster->thrust;

	terminalVelocity();

	// apply velocity to position
	posX += velX;
	posY += velY;

	// apply wall forces
	if(posX < -screenSize / 2){ posX = -screenSize / 2; velX = 0; }
	if(posX > screenSize / 2){ posX = screenSize / 2; velX = 0; }
	if(posY < -screenSize / 2){ posY = -screenSize / 2; velY = 0; }
	if(posY > screenSize / 2){ posY = screenSize / 2; velY = 0; }

}

void Drone::terminalVelocity(){
	velX = velX * 0.99;
	velY = velY * 0.99;
}