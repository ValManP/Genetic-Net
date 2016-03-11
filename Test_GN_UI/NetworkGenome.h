#pragma once

#include "GAGenome.h"

struct NetworkElement {
	string name;
	int capacity;
	int price;
};

struct NE_to_Platform{
	int isSet;
	int position;

	bool operator== (NE_to_Platform ne) {
		if (isSet == ne.isSet && position == ne.position) return true;
		return false;
	}

	string toString (string NE_name) {
		char pos[10];
		_itoa_s(position, pos, 10);
		if (isSet)
			return ("Network Element " + NE_name + " is set on " + (string)pos + " platform");
		else
			return ("Network Element" + NE_name + " is not set");
	}
};

struct NetworkDescription {
	int platformCount;
	int minDeviceCount;
	vector<NetworkElement> storage;

	NetworkDescription(int _minDeviceCount, int _platformCount, vector<NetworkElement> _storage) {
		platformCount = _platformCount;
		minDeviceCount = _minDeviceCount;
		storage = _storage;
	}
};

class NetworkGenome : public GAGenome<NE_to_Platform, NetworkDescription> {
private:
	int deviceCount;

	int cost;
	int capacity;

	int fitness;
public:

	NetworkGenome(int _size = 10) : GAGenome(_size) {

	}

	void initialize(NetworkDescription description){
		vector<int> positions(description.platformCount, 0);

		int geneNumber, devicePosition;
		int i = 0;

		deviceCount = rand() % (description.platformCount - description.minDeviceCount + 1) + description.minDeviceCount; // —лучайное число в диапазоне minDeviceCount:platformCount

		// «аполн€ем геном случайными значени€ми и позици€ми
		while (i != deviceCount) {
			geneNumber = rand() % size;
			devicePosition = rand() % description.platformCount;
			if (genome[geneNumber].isSet == 0) {
				while (positions[devicePosition] == 1)
					devicePosition = rand() % description.platformCount;
				genome[geneNumber].position = devicePosition;
				genome[geneNumber].isSet = 1;
				positions[devicePosition] = 1;
				i++;
			}
		}

	}

	void fixNetworkGenome(NetworkDescription description){
		vector<int> positions(description.platformCount, 0);

		int devicePosition, i = 0;

		for (unsigned int i = 0; i < genome.size(); i++) {
			if (genome[i].isSet == 1) {
				devicePosition = genome[i].position;
				while (positions[devicePosition] == 1)
					devicePosition = rand() % description.platformCount;
				genome[i].position = devicePosition;
				positions[devicePosition] = 1;
			}
		}
	}

	int getDeviceCount(){
		return deviceCount;
	}
	void setFitness(int _fitness);
	int getFitness();
	int getCapacity();
	int getCost();

	void calculateDevice() {
		deviceCount = 0;
		for (NE_to_Platform i : genome) {
			if (i.isSet) deviceCount++;
		}
	}

	int compare(GAGenome compareGenome) {
		if (size != compareGenome.getSize())
			return 0;
		else {
			for (int i = 0; i < size; i++) {
				if (!(genome[i] == compareGenome.getGene(i))) return 0;
			}
			return 1;
		}
	}

	int calculateCost(NetworkDescription description) {
		cost = 0;
		for (int i = 0; i < size; i++)
			if (genome[i].isSet) cost += description.storage[i].price;

		return cost;
	}

	int calculateCapacity(NetworkDescription description, Network n) {

		Network temp = n;

		for (int i = 0; i < size; i++) {
			if (genome[i].isSet)
				temp.updatePlatform(genome[i].position, description.storage[i].capacity);
		}

		capacity = temp.findNetworkCapacity();

		return capacity;
	}

	string toString(NetworkDescription description) {
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
};

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
