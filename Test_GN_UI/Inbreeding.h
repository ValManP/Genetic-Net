#include "GACrossbreeding.h"

class Inbreeding : public GACrossbreeding <NetworkPopulation, NetworkGenome> {
public:

	Inbreeding(double value) {
		crossbreedingVariable = value;
	}

	void cross(NetworkPopulation *population, NetworkGenome* parentA, NetworkGenome *parentB);
};

void Inbreeding::cross(NetworkPopulation *population, NetworkGenome* parentA, NetworkGenome *parentB){

	int size = parentA->getSize();

	int parent1 = rand() % population->getSize();
	int parent2;
	*parentA = population->getPopulation()[parent1];

	double d = 0;

	bool flag = true;

	while (flag) {
		parent2 = rand() % population->getSize();
		*parentB = population->getPopulation()[parent2];
		for (int i = 0; i < size; i++) {
			if (parentA->getGene(i).isSet == parentB->getGene(i).isSet) {
				d += 0.5;
			}
			if (parentA->getGene(i).position == parentB->getGene(i).position) {
				d += 0.5;
			}
		}
		if (d > crossbreedingVariable) {
			flag = false;
		}
	}
	
}