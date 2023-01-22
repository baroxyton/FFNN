#include "neuron.h"
#include "layer.h"
#include "network.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Network::Network(std::vector<int> numlayers)
{
	// Init random number generator
	srand(time(NULL));
	//srand(100);
	for (int i = 0; i < numlayers.size(); i++)
	{
		if (i == 0)
		{
			Layer *inputLayer = new Layer{numlayers[i]};
			inputLayer->isInput = true;
			input = inputLayer;
			layers.push_back(inputLayer);
			continue;
		}
		if (i == numlayers.size() - 1)
		{
			Layer *outputLayer = new Layer{numlayers[i]};
			output = outputLayer;
			outputLayer->isOutput = true;
			layers.push_back(outputLayer);
			continue;
		}
		Layer *hiddenLayer = new Layer{numlayers[i]};
		layers.push_back(hiddenLayer);
		continue;
	}
	for (int i = 0; i < numlayers.size(); i++)
	{
		if (i == 0)
		{
			// Hack: passing output layer twice
			// The layer known that it's an input layer
			layers[i]->connect(layers[i + 1], layers[i + 1]);
			continue;
		}
		if (i == (numlayers.size() - 1))
		{
			layers[i]->connect(layers[i - 1], layers[i - 1]);
			continue;
		}
		layers[i]->connect(layers[i - 1], layers[i + 1]);
		continue;
	};
}
void Network::activate(std::vector<double> inputs)
{
	input->activate(inputs);
}
void Network::train(std::vector<std::vector<std::vector<double>>> trainingdata, int amount = 1000, int display = 10)
	{
		for (int j = 0; j < amount; j++)
		{
			for (int i = 0; i < trainingdata.size(); i++)
			{
				activate(trainingdata[i][0]);
				output->propagate(trainingdata[i][1]);
			}
			if (j % display == 0)
			{
				std::cout << j << "/" << amount << std::endl;
			}
		}
	}
int main()
{
	std::vector<std::vector<std::vector<double>>> testData {
        std::vector<std::vector<double>>{std::vector<double>{0, 0}, std::vector<double>{0}},
        std::vector<std::vector<double>>{std::vector<double>{1, 0}, std::vector<double>{0}},
        std::vector<std::vector<double>>{std::vector<double>{0, 1}, std::vector<double>{0}},
        std::vector<std::vector<double>>{std::vector<double>{1, 1}, std::vector<double>{1}}};
	Network testNetwork{std::vector<int>{2, 16, 16, 1}};
	testNetwork.activate(std::vector<double>{1,1});
	for (auto neuron : testNetwork.output->neurons)
	{
		std::cout << neuron->output << std::endl;
	}
	testNetwork.train(testData, 10000, 1000);
	testNetwork.activate(std::vector<double>{1,1});
	for (auto neuron : testNetwork.output->neurons)
	{
		std::cout << neuron->output << std::endl;
	}

}