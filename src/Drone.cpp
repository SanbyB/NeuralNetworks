#include "../include/Drone.h"
#include "../include/Propagation.h"
#include <iostream>

void Thruster::angle(double a){
	angleVal = a;
}

double Thruster::angle(){
	return angleVal;
}

void Thruster::thrust(double t){
	thrustVal = t;
}

double Thruster::thrust(){
	return thrustVal;
}

Drone::Drone(){}

void Drone::init(int s, std::shared_ptr<Target> t){
	setScreenSize(s);
	setTarget(t);
}

void Drone::update(bool w, bool a, bool d){
	hitTarget();
	applyForces();
	if(w){ thruster->thrust(thruster->thrust() + 5e-4); }
	else{ thruster->thrust(thruster->thrust() - 1e-4); }
	if(a){ thruster->angle(thruster->angle() + 0.01); }
	if(d){ thruster->angle(thruster->angle() - 0.01); }
}

std::vector<double> Drone::pos(){
	std::vector<double> pos {posX, posY};
	return pos;
}

double Drone::thrust(){
	return thruster->thrust();
}

double Drone::angle(){
	return thruster->angle();
}

int Drone::getCount(){
	return count;
}

double Drone::maxVel(){
	return (maxThrust * terminalVel) / (1 - terminalVel);
}

int Drone::getScore(){
	return score;
}

bool Drone::hitTarget(){
	if(recharge){
		recharge--;
		return false;
	}
	if(abs(posX - target->getPosX()) < minDist){
		if(abs(posY - target->getPosY()) < minDist){
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
	if(thruster->thrust() < 0){ thruster->thrust(0); }
	else if(thruster->thrust() > maxThrust){ thruster->thrust(maxThrust); }

	// restrict angle (for normalisation)
	if(thruster->angle() < -M_PI){ thruster->angle(M_PI); }
	else if(thruster->angle() > M_PI){ thruster->angle(-M_PI); }

	//  apply thruster force in the X direction
	velX += std::sin(thruster->angle()) * thruster->thrust();
	// apply thruster force in the Y direction
	velY += std::cos(thruster->angle()) * thruster->thrust();

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

void Drone::setTarget(std::shared_ptr<Target> t){
	target = t;
}

void Drone::setScreenSize(int s){
	screenSize = s;
}

AutoDrone::AutoDrone(){}


void AutoDrone::setFlightComputer(Network fc){
	// TODO need to restrict constructor of NeuralNetwork to make sure it has the right input and output nodes
	flightComputer = fc;
}

Network AutoDrone::getFlightComputer(){
	return  flightComputer;
}

void AutoDrone::computeThrust(){
	Eigen::VectorXd input(6);

	input(0) = posX - target->getPosX() / screenSize;
	input(1) = posY - target->getPosY() / screenSize;
	input(2) = velX / maxVel();
	input(3) = velY / maxVel();
	input(4) = thruster->thrust() / maxThrust;
	input(5) = (thruster->angle() + M_PI) / (2 * M_PI);

	Eigen::VectorXd output(3);

	output = Propagation::propagate(input, flightComputer);

	for(int i = 0; i < output.size(); i++){
		// clamp the output [0, 1]
		if(output(i) <= 0){
			output(i) = 0;
		}else if(output(i) >= 1){
			output(i) = 1;
		}

		// manually set the thresholds
		if(i == 0){
			if(output(i) > 0.3){
				output(i) = 1;
			}else{output(i) = 0;}
		}
		if(i == 1){
			if(output(i) > 0.45){
				output(i) = 1;
			}else{output(i) = 0;}
		}
		if(i == 2){
			if(output(i) > 0.45){
				output(i) = 1;
			}else{output(i) = 0;}
		}
	}

	bool w = output(0);
	bool a = output(1);
	bool d = output(2);

	update(w, a, d);
}