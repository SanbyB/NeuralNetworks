#include "include/Utils.h"

int main(){

	Network net;

	// net.setNetwork({3, 5, 4, 2});

	// net.print();

	// writeNet(net, "../output.txt");


	auto n = readNet("../output.txt");

	n.print();

	return 0;
}