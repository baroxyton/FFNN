#ifndef LAYER_CPP
#define LAYER_CPP
#include "neuron.h"
#include "layer.h"
#include <vector>
#include <iostream>
const double learning_rate = 0.3;
void Layer::generateNeurons(int num)
{
}
Layer::Layer(int num)
{
	for (int i = 0; i < num; i++)
	{
		Neuron *newNeuron = new Neuron{};
		neurons.push_back(newNeuron);
		isOutput = false;
		isInput = false;
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
void Layer::propagate(std::vector<double> expectedOutput=std::vector<double>{})
{
	if (isOutput)
	{
		for (int i = 0; i < neurons.size(); i++)
		{
			double sum = neurons[i]->output - expectedOutput[i];
			neurons[i]->error = sum * neurons[i]->outputDerrivative;
			neurons[i]->bias -= learning_rate * neurons[i]->error;
		}
	}
	else
	{
		for (int i = 0; i < neurons.size(); i++)
		{
			double sum = 0;
			for(int j = 0; j < outputLayer->neurons.size(); j++){
				double adjustedWeight = outputLayer->neurons[j]->weights[i] - (learning_rate * outputLayer->neurons[j]->error * neurons[i]->output);
				outputLayer->neurons[j]->weights[i] = adjustedWeight;
				sum += outputLayer->neurons[j]->error * neurons[i]->weights[j];
			}
			neurons[i]->error = sum * neurons[i]->outputDerrivative;
			neurons[i]->bias = learning_rate * neurons[i]->error;
		}
	};
	if(!isInput){
		inputLayer->propagate();
	}
};
#endif
