#ifndef LAYER_CPP
#define LAYER_CPP
#include "neuron.h"
#include "layer.h"
#include <vector>
#include <iostream>
class Neuron;
class Layer;
void Layer::generateNeurons(int num){

}		
Layer::Layer(int num){
	for(int i = 0; i < num; i++){
		Neuron* newNeuron = new Neuron{};
		neurons.push_back(newNeuron);	
	}
}
void Layer::connect(Layer* inputLayera, Layer* outputLayera){
	inputLayer = inputLayera;
	outputLayer = outputLayera;
	for(Neuron* neuron : neurons){
		neuron->isInput = isInput;
		neuron->isOutput = isOutput;
		neuron->generateWeights(inputLayer->neurons.size());
		std::cout << neuron->weights.size() << std::endl;
	}
}
#endif
