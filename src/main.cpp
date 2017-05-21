#include "ThreeLayeredNN.h"

int main(int argc, char* argv[]) {
	ThreeLayeredNN network;
	network.initialize();
	network.forward();

	return 0;
}
