#ifndef NEURON_H
#define NEURON_H
class Layer;
class Neuron{
	public:
		Layer* input;
		Layer* output;
		Neuron(Layer* inputl, Layer* outputl);
};

#endif
