#pragma once

#include "GAGenome.h"
#include "Network.h"

using namespace std;

struct NetworkElement {
	string name;
	int capacity;
	int price;
};

struct NE_to_Platform{
	int isSet;
	int position;

	NE_to_Platform() {
		isSet = 0;
		position = 0;
	}

	NE_to_Platform (int _isSet, int _position) {
		isSet = _isSet;
		position = _position;
	}

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

	double fitness;
public:

	NetworkGenome(int _size = 10);

	void initialize(NetworkDescription description);

	void fixNetworkGenome(NetworkDescription description);

	int getDeviceCount();
	void setFitness(double _fitness);
	double getFitness();
	int getCapacity();
	int getCost();

	void calculateDevice();

	int compare(GAGenome compareGenome);

	int calculateCost(NetworkDescription description);

	int calculateCapacity(NetworkDescription description, Network n);

	string toString(NetworkDescription description);
};
