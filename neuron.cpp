#ifndef NEURON_CPP
#define NEURON_CPP
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "neuron.h"
#include <iostream>
#include <math.h>
const int learning_rate = 0.3;

double randomFloat(double scalar)
{
	return ((double)rand() / (double)RAND_MAX * scalar);
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

/* double ReLU(double input){
	return 1 / (1 + std::exp(-input));
}
double ReLUDerrivative(double input){
return ReLU(input) * (1 - ReLU(input));
} */
/* double ReLU(double input){
	return input;
}
double ReLUDerrivative(double input){
	return 1;
} */
Neuron::Neuron()
{
	bias = randomFloat(0.1);
}
void Neuron::generateWeights(int num)
{
	for (int i = 0; i < num; i++)
	{
		weights.push_back(randomFloat(0.1));
	}
}
void Neuron::activate(std::vector<double> inputs)
{
	double result = bias;
	if (isInput)
	{
		output = inputs[0];
		outputDerrivative = 1;
		return;
	}
	for (int i = 0; i < inputs.size(); i++)
	{
		result += inputs[i] * weights[i];
	}
	output = ReLU(result);
	outputDerrivative = ReLUDerrivative(result);
	
	return;
}
#endif
