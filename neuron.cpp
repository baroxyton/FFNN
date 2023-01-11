#ifndef NEURON_CPP 
#define NEURON_CPP
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "neuron.h"
#include "layer.h"
double randomFloat(double scalar){
	return (rand()/RAND_MAX * scalar*2) - scalar;
};
Neuron::Neuron(Layer* inputl, Layer* outputl){
	input = inputl;
	output = outputl;	
	std::vector<double> weights;
	for(int i = 0; i < input->neurons.size(); i++){
		weights.push_back(randomFloat(1));	
	}
	double bias = randomFloat(1);
}

#endif
