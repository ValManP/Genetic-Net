#include "math.h"
#include "GACrossbreeding.h"

class PositiveAssociativeMating : public GACrossbreeding <NetworkPopulation, NetworkGenome> {
public:

	PositiveAssociativeMating(double value) {
		crossbreedingVariable = value;
	}

	void cross(NetworkPopulation *population, NetworkGenome* parentA, NetworkGenome *parentB);
};

void PositiveAssociativeMating::cross(NetworkPopulation *population, NetworkGenome* parentA, NetworkGenome *parentB){

	int parent1 = rand() % population->getSize();
	int parent2;
	*parentA = population->getPopulation()[parent1];

	double d = 0;

	bool flag = true;

	while (flag) {
		parent2 = rand() % population->getSize();
		*parentB = population->getPopulation()[parent2];

		if (abs(parentA->getFitness() - parentB->getFitness()) < crossbreedingVariable) {
			flag = false;
		}
	}

}