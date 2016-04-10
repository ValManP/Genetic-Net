#include "GAFitness.h"

class RandomWeightFitness : public GAFitness <NetworkPopulation, NetworkDescription> {
public:

	RandomWeightFitness() {
	}

	void fitness(NetworkPopulation *population, NetworkDescription description);
};

void RandomWeightFitness::fitness(NetworkPopulation *population, NetworkDescription description){

	int size = population->getSize();
	
	vector<double> fitness(size, 0);

	vector<Net> data = population->getData();

	double w1 = (double) rand() / INT_MAX;
	double w2 = 1 - w1;

	for (int i = 0; i < size; i++) {
		fitness[i] = w1 *  data[i].averageCapacity - w2 * data[i].price;
	}

	population->setFitness(fitness);
}