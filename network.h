#ifndef NETWORK_H
#define NETWORK_H
#include "neuron.h"
#include "layer.h"
#include <vector>
class Network{
	public:
		std::vector<Layer*> layers;
		Network(std::vector<int> numlayers);
		
}
#endif
