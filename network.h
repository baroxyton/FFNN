#ifndef NETWORK_H
#define NETWORK_H
#include "neuron.h"
#include "layer.h"
#include <vector>

class Network
{
public:
	std::vector<Layer *> layers;
	Layer *input;
	Layer *output;
	Network(std::vector<int> numlayers);
	void activate(std::vector<double> inputs);
};

#endif
