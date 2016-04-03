#include "NetworkGenome.h"

NetworkGenome::NetworkGenome(int _size) : GAGenome(_size) {

}

void NetworkGenome::initialize(NetworkDescription description){
	vector<int> positions(description.platformCount, 0);

	int geneNumber, devicePosition;
	int i = 0;

	deviceCount = rand() % (description.platformCount - description.minDeviceCount + 1) + description.minDeviceCount; // —лучайное число в диапазоне minDeviceCount:platformCount

	// «аполн€ем геном случайными значени€ми и позици€ми
	while (i != deviceCount) {
		geneNumber = rand() % size;
		devicePosition = rand() % description.platformCount;
		if (genome[geneNumber].isSet == 0) {

			//while (positions[devicePosition] == 1)
			devicePosition = rand() % description.platformCount;

			if (positions[devicePosition] == 1) {
				for (int i = 0; i < description.platformCount; i++) {
					if (positions[i] == 0) {
						devicePosition = i;
						break;
					}
				}
			}

			genome[geneNumber].position = devicePosition;
			genome[geneNumber].isSet = 1;
			positions[devicePosition] = 1;
			i++;
		}
	}

}

void NetworkGenome::fixNetworkGenome(NetworkDescription description){
	vector<int> positions(description.platformCount, 0);

	int devicePosition, i = 0;

	for (unsigned int i = 0; i < genome.size(); i++) {
		if (genome[i].isSet == 1) {
			devicePosition = genome[i].position;

			/*if (positions[devicePosition] == 1) {
			int pos = 0;
			do {
			devicePosition = pos;
			pos++;
			} while (positions[devicePosition] == 1);
			}*/

			if (positions[devicePosition] == 1) {
				int pos = 0;

				for (int i = 0; i < description.platformCount; i++) {
					if (positions[i] == 0) {
						devicePosition = i;
						break;
					}
				}
			}

			/*while (positions[devicePosition] == 1) {
			devicePosition = rand() % description.platformCount;
			}*/


			genome[i].position = devicePosition;
			positions[devicePosition] = 1;
		}
	}
}

int NetworkGenome::getDeviceCount(){
	return deviceCount;
}

void NetworkGenome::calculateDevice() {
	deviceCount = 0;
	for (NE_to_Platform i : genome) {
		if (i.isSet) deviceCount++;
	}
}

int NetworkGenome::compare(GAGenome compareGenome) {
	if (size != compareGenome.getSize())
		return 0;
	else {
		for (int i = 0; i < size; i++) {
			if (!(genome[i] == compareGenome.getGene(i))) return 0;
		}
		return 1;
	}
}

int NetworkGenome::calculateCost(NetworkDescription description) {
	cost = 0;
	for (int i = 0; i < size; i++)
		if (genome[i].isSet) cost += description.storage[i].price;

	return cost;
}

int NetworkGenome::calculateCapacity(NetworkDescription description, Network n) {

	Network temp = n;

	for (int i = 0; i < size; i++) {
		if (genome[i].isSet)
			temp.updatePlatform(genome[i].position, description.storage[i].capacity);
	}

	capacity = temp.findNetworkCapacity();

	return capacity;
}

string NetworkGenome::toString(NetworkDescription description) {
	string result;
	char tmp[10];
	result = "Network Genome:\n";

	_itoa_s(deviceCount, tmp, 10);
	result += "Number of Devices = " + (string)tmp + "\n";
	_itoa_s(cost, tmp, 10);
	result += "Cost = " + (string)tmp + ", ";
	_itoa_s(capacity, tmp, 10);
	result += "Capacity = " + (string)tmp + "\n";

	for (int i = 0; i < size; i++) {
		if (genome[i].isSet) {
			_itoa_s(description.storage[i].price, tmp, 10);
			result += genome[i].toString(description.storage[i].name) + "(Price=" + (string)tmp + ",";
			_itoa_s(description.storage[i].capacity, tmp, 10);
			result += " capacity=" + (string)tmp + ")\n";
		}
	}

	return result;

}

void NetworkGenome::setFitness(int _fitness){
	fitness = _fitness;
}

int NetworkGenome::getFitness(){
	return fitness;
}

int NetworkGenome::getCapacity(){
	return capacity;
}

int NetworkGenome::getCost(){
	return cost;
}
