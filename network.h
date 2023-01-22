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
	void train(std::vector<std::vector<std::vector<double>>> trainingdata, int amount, int display);
};

#endif
