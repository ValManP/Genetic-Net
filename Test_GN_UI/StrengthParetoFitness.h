#include "GAFitness.h"

class StrengthParetoFitness : public GAFitness <NetworkPopulation, NetworkDescription> {
public:

	StrengthParetoFitness() {
	}

	void fitness(NetworkPopulation *population, NetworkDescription description);
};

void StrengthParetoFitness::fitness(NetworkPopulation *population, NetworkDescription description){

	int size = population->getSize();

	vector<double> fitness(size, 0);

	vector<Net> data = population->getData();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j != i) {
				if (data[i].averageCapacity > data[j].averageCapacity && data[i].price <= data[j].price) {
					fitness[i]++;
				}
			}
		}
	}

	population->setFitness(fitness);
}