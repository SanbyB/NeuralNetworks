#include "include/Utils.h"

int main(){

	Network net;

	net.setNetwork({5, 4, 7, 2});

	outputNet(net, "../output.txt");

	inputNet("../output.txt");

	return 0;
}