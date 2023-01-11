#ifndef LAYER_CPP
#define LAYER_CPP
#include "neuron.h"
#include "layer.h"
#include <vector>
class Neuron;
class Layer;
void Layer::generateNeurons(int num){

}
Layer::Layer(int num, Layer* inputLayer, Layer* outputLayer){
	for(int i = 0; i < num; i++){
		Neuron newNeuron{inputLayer, outputLayer};
		neurons.push_back(&newNeuron);	
	}
}		
Layer::Layer(int num){
	
}
Layer::connect(Layer* inputLayera, Layer* outputLayera){
	inputLayer = inputLayera;
	outputLayer = outputLayera;	
}
#endif
