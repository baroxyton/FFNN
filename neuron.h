#ifndef NEURON_H
#define NEURON_H
#include <vector>
class Layer;
double randomFloat(double scalar);
class Neuron{
	public:
		Layer* input;
		Layer* output;
		double bias;
		std::vector<double> weights;
		Neuron(Layer* inputl, Layer* outputl);
		Neuron();
		void generateWeights(int num);
		bool isInput;
		bool isOutput;
};

#endif
