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
#endif
