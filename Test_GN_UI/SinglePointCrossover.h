#pragma once

#include <vector>
#include "GACrossover.h"

class SinglePointCrossover : public GACrossover <NetworkGenome, NetworkDescription > {

private:

	std::vector<NetworkGenome> gaSinglePointCrossover(NetworkGenome parentA, NetworkGenome parentB);

public:
	SinglePointCrossover();

	std::vector<NetworkGenome> crossover(NetworkGenome parentA, NetworkGenome parentB, NetworkDescription description);
	
};

vector<NetworkGenome> SinglePointCrossover::gaSinglePointCrossover(NetworkGenome parentA, NetworkGenome parentB) {
	int r = rand() % (parentA.getSize() - 1) + 1;

	vector<NetworkGenome> result(2);
	result[0].setSize(parentA.getSize());
	result[1].setSize(parentA.getSize());

	for (int i = 0; i < parentA.getSize(); i++) {
		if (i < r) {
			result[0].setGene(i, parentA.getGene(i));
			result[1].setGene(i, parentB.getGene(i));
		}
		else {
			result[0].setGene(i, parentB.getGene(i));
			result[1].setGene(i, parentA.getGene(i));
		}
	}

	result[0].calculateDevice();
	result[1].calculateDevice();

	return result;
}
SinglePointCrossover::SinglePointCrossover() {

}

vector<NetworkGenome> SinglePointCrossover::crossover(NetworkGenome parentA, NetworkGenome parentB, NetworkDescription description) {

	vector<NetworkGenome> result;

	int minCount = description.minDeviceCount, maxCount = description.platformCount;

	// Выполняем кроссовер до тех пор, пока не получиться хотя бы один потомок
	do {
		result = gaSinglePointCrossover(parentA, parentB);

		if (result[1].getDeviceCount() < minCount || result[1].getDeviceCount() > maxCount) {
			result.pop_back();
		}

		if (result[0].getDeviceCount() < minCount || result[0].getDeviceCount() > maxCount) {
			if (result.size() > 1) {
				result[0] = result[1];
			}

			result.pop_back();
		}

	} while (result.size() == 0);

	result[0].fixNetworkGenome(description);
	if (result.size() == 2) {
		result[1].fixNetworkGenome(description);
	}

	return result;

}