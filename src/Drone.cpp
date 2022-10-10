#include "../include/Drone.h"
#include "../include/Propagation.h"
#include <iostream>

Drone::Drone(){}
Drone::~Drone(){}

void Drone::computeThrust(Network flightComputer){
	Eigen::VectorXd input(7);

	input(0) = posX - target->posX;
	input(1) = posY - target->posY;
	input(2) = velX;
	input(3) = velY;
	input(4) = std::cos(angle);
	input(5) = std::sin(angle);
	input(6) = angularVel;

	Eigen::VectorXd output(4);

	output = Propagation::propagate(input, flightComputer);

	leftThruster->thrust = output(0);
	rightThruster->thrust = output(1);
	leftThruster->angle = output(2);
	rightThruster->angle = output(3);
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
	std::cout << "Velocity: " << velX << ", " << velY << "\n";
	count++;
	// apply force of gravity
	velY -= gravity;

	// restrict thrust
	if(leftThruster->thrust < 0){ leftThruster->thrust = 0; }
	else if(leftThruster->thrust > maxThrust){ leftThruster->thrust = maxThrust; }
	if(rightThruster->thrust < 0){ rightThruster->thrust = 0; }
	else if(rightThruster->thrust > maxThrust){ rightThruster->thrust = maxThrust; }

	// restrict angle (for normalisation)
	if(leftThruster->angle < -M_PI){ leftThruster->angle = M_PI; }
	else if(leftThruster-> angle > M_PI){ leftThruster->angle = -M_PI; }
	if(rightThruster->angle < -M_PI){ rightThruster->angle = M_PI; }
	else if (rightThruster->angle > M_PI){ rightThruster->angle = -M_PI; }


	// apply thruster force in the Y direction
	velY += std::cos(leftThruster->angle + angle) * leftThruster->thrust;
	velY += std::cos(rightThruster->angle + angle) * rightThruster->thrust;
	//  apply thruster force in the X direction
	velX += std::sin(leftThruster->angle + angle) * leftThruster->thrust;
	velX += std::sin(rightThruster->angle  + angle) * rightThruster->thrust;

	// apply thruster force to the angluar velocity
	angularVel += inertia * std::cos(rightThruster->angle) * rightThruster->thrust;
	angularVel -= inertia * std::cos(leftThruster->angle) * leftThruster->thrust;

	terminalVelocity();

	// apply velocity to position
	posX += velX;
	posY += velY;

	// apply angular vel to angle
	angle += angularVel;

	// apply wall forces
	if(posX < -screenSize / 2){ posX = -screenSize / 2; velX = 0; }
	if(posX > screenSize / 2){ posX = screenSize / 2; velX = 0; }
	if(posY < -screenSize / 2){ posY = -screenSize / 2; velY = 0; }
	if(posY > screenSize / 2){ posY = screenSize / 2; velY = 0; }

}

void Drone::terminalVelocity(){
	if(velX * velX + velY * velY > terminalVel){
		double k = velY / velX;
		velX = sign(velX) * std::sqrt(terminalVel / (1 + k));
		velY = sign(velY) * std::sqrt(terminalVel - velX); 
	}
}