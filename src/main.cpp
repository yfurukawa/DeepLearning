#include <string>

#include "ThreeLayeredNN.h"
#include "MnistMain.h"

int main(int argc, char* argv[]) {
	MnistMain* mnist;
	mnist = new MnistMain(argc, argv);

	return mnist->run();

	delete mnist;
	/*
	ThreeLayeredNN network;
	network.initialize();
	network.forward();

	return 0;
	*/
}
