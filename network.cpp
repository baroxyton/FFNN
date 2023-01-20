#include "neuron.h"
#include "layer.h"
#include "network.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Network::Network(std::vector<int> numlayers){
	// Init random number generator
	srand(time(NULL));
		for(int i = 0; i < numlayers.size(); i++){
		if(i == 0){
			Layer* inputLayer = new Layer{numlayers[i]};
			inputLayer->isInput = true;
			input = inputLayer;
			layers.push_back(inputLayer);
			continue;
		}
		if(i == numlayers.size() - 1){
			Layer* outputLayer = new Layer{numlayers[i]};
			output = outputLayer;
			outputLayer->isOutput = true;	
			layers.push_back(outputLayer);
			continue;
		}
		Layer* hiddenLayer = new Layer{numlayers[i]};
		layers.push_back(hiddenLayer);
		continue;
	}
	for(int i = 0; i < numlayers.size(); i++){
		if(i == 0){
			// Hack: passing output layer twice
			// The layer known that it's an input layer
			layers[i]->connect(layers[i+1], layers[i+1]);
			continue;
		}
		if(i==(numlayers.size()-1)){
			layers[i]->connect(layers[i-1], layers[i-1]);
			continue;
		}
		layers[i]->connect(layers[i-1], layers[i+1]);
		continue;
	}
}
int main(){
	Network testNetwork{std::vector<int>{10, 10, 10}};
}