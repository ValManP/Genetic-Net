#include "GACrossbreeding.h"

class Panmixia : public GACrossbreeding <NetworkPopulation, NetworkGenome> {
public:

	Panmixia(double value) {
		crossbreedingVariable = value;
	}

	void cross(NetworkPopulation *population, NetworkGenome* parentA, NetworkGenome *parentB);
};

void Panmixia::cross(NetworkPopulation *population, NetworkGenome* parentA, NetworkGenome *parentB){

	int parent1 = rand() % population->getSize();
	*parentA = population->getPopulation()[parent1];

	int parent2 = rand() % population->getSize();
	*parentB = population->getPopulation()[parent2];
}