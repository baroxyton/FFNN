#ifndef LAYER_H
#define LAYER_H
#include <vector>
#include "neuron.h"
class Layer{
	public:
		Layer* inputLayer;
		Layer* outputLayer;
		bool isInput;
		bool isOutput;
		void connect(Layer* inputLayer, Layer* outputLayer);
		void generateNeurons(int num);
		std::vector<Neuron*> neurons;
		Layer(int num, Layer* inputLayer, Layer* outputLayer);
		Layer(int num);
		void activate(std::vector<double> inputs);
		void propagate(std::vector<double> expectedOutput);
};
#endif
