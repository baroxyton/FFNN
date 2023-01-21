#ifndef NEURON_H
#define NEURON_H
#include <vector>
class Layer;
double randomFloat(double scalar);
double ReLU(double input);
double ReLuDerrivative(double input);
class Neuron
{
public:
	double bias;
	std::vector<double> weights;
	Neuron(Layer *inputl, Layer *outputl);
	Neuron();
	void generateWeights(int num);
	bool isInput;
	bool isOutput;
	void activate(std::vector<double> inputs);
	double output;
};

#endif
