#ifndef NEURON_CPP
#define NEURON_CPP
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "neuron.h"
#include "layer.h"
#include <iostream>
double randomFloat(double scalar)
{
	return ((double)rand() / (double)RAND_MAX * scalar * 2) - scalar;
};
double ReLU(double input)
{
	if (input < 0)
	{
		return 0;
	}
	return input;
}
double ReLUDerrivative(double input)
{
	if (input <= 0)
	{
		return 0;
	}
	return 1;
}
Neuron::Neuron()
{
	bias = randomFloat(1);
}
void Neuron::generateWeights(int num)
{
	for (int i = 0; i < num; i++)
	{
		weights.push_back(randomFloat(1));
	}
}
void Neuron::activate(std::vector<double> inputs)
{
	output = bias;
	if (isInput)
	{
		output = inputs[0];
		return;
	}
	for (int i = 0; i < inputs.size(); i++)
	{
		output += inputs[i] * weights[i];
	}
	output = ReLU(output);
	return;
}
#endif
