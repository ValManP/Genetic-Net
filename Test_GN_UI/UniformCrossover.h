#pragma once

#include "GACrossover.h"

class UniformCrossover : public GACrossover <NetworkGenome, NetworkDescription > {

private:

public:
	UniformCrossover() {

	}

	vector<NetworkGenome> crossover(NetworkGenome parentA, NetworkGenome parentB, NetworkDescription description);

};

vector<NetworkGenome> UniformCrossover::crossover(NetworkGenome parentA, NetworkGenome parentB, NetworkDescription description) {

	vector<NetworkGenome> result(1);

	result[0].setSize(parentA.getSize());

	int minCount = description.minDeviceCount, maxCount = description.platformCount;

	double fit_A = parentA.getFitness();
	double fit_B = parentB.getFitness();

	double p = 0.5;

	if (fit_A != 0 && fit_B != 0) {
		p = fit_A / (fit_A + fit_B);
	}
	double chance;

	for (int i = 0; i < parentA.getSize(); i++) {
		chance = (double)rand() / INT_MAX;

		if (chance < p) {
			result[0].setGene(i, parentA.getGene(i));
		}
		else {
			result[0].setGene(i, parentB.getGene(i));
		}
	}

	result[0].fixNetworkGenome(description);

	return result;
}