#include "../include/Drone.h"
#include "../include/Propagation.h"
#include <iostream>

Drone::Drone(){}

void init(int s, std::shared_ptr<Target> t){
	screenSize(s);
	target(t);
}

void Drone::update(bool humanControl, bool w, bool a, bool d){
	hitTarget();
	applyForces();
	if(humanControl){
		if(w){ thruster->thrust += 5e-4; }
		else{ thruster->thrust -= 1e-4; }
		if(a){ thruster->angle += 0.01; }
		if(d){ thruster->angle -= 0.01; }
	}
}

bool Drone::hitTarget(){
	if(recharge){
		recharge--;
		return false;
	}
	if(abs(posX - target->posX) < minDist){
		if(abs(posY - target->posY) < minDist){
			recharge = rechargeTime;
			target->spawnTarget();
			score++;
			return true;
		}
	}
	return false;
}

void Drone::applyForces(){
	count++;

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
	velX = velX * terminalVel;
	velY = velY * terminalVel;
}

void Drone::target(std::shared_ptr<Target> t){
	target = t;
}

void Drone::screenSize(int s){
	screenSize = s;
}


AutoDrone::AutoDrone(){}

void AutoDrone::flightComputer(Network fc){
	// TODO need to restrict it to make sure it has the right input and output nodes
	flightComputer = fc;
}

void AutoDrone::computeThrust(){
	Eigen::VectorXd input(4);

	input(0) = posX - target->posX;
	input(1) = posY - target->posY;
	input(2) = velX;
	input(3) = velY;

	Eigen::VectorXd output(2);

	output = Propagation::propagate(input, flightComputer);

	thruster->thrust = output(0);
	thruster->angle = output(1);
}