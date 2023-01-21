#ifndef LAYER_CPP
#define LAYER_CPP
#include "neuron.h"
#include "layer.h"
#include <vector>
#include <iostream>
class Neuron;
class Layer;
void Layer::generateNeurons(int num)
{
}
Layer::Layer(int num)
{
	for (int i = 0; i < num; i++)
	{
		Neuron *newNeuron = new Neuron{};
		neurons.push_back(newNeuron);
	}
}
void Layer::connect(Layer *inputLayera, Layer *outputLayera)
{
	inputLayer = inputLayera;
	outputLayer = outputLayera;
	for (auto neuron : neurons)
	{
		neuron->isInput = isInput;
		neuron->isOutput = isOutput;
		neuron->generateWeights(inputLayer->neurons.size());
	}
}
void Layer::activate(std::vector<double> inputs = std::vector<double>{})
{
	if (isInput)
	{
		for (int i = 0; i < inputs.size(); i++)
		{
			neurons[i]->activate(std::vector<double>{inputs[i]});
		}
	}
	else
	{
		std::vector<double> inputOutputs;
		for (auto inputNeuron : inputLayer->neurons)
		{
			inputOutputs.push_back(inputNeuron->output);
		}
		for (auto neuron : neurons)
		{
			neuron->activate(inputOutputs);
		}
	}
	if (!isOutput)
	{
		outputLayer->activate();
	}
}
#endif
