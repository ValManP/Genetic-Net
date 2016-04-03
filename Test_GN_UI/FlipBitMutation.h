#pragma once

#include "GAMutation.h"

class FlipBitMutation : public GAMutation <NetworkGenome, NetworkDescription > {

public:

	FlipBitMutation() {

	}

	NetworkGenome mutate(NetworkGenome genome, NetworkDescription description);
};

NetworkGenome FlipBitMutation::mutate(NetworkGenome genome, NetworkDescription description) {

	NetworkGenome result = genome;

	for (int i = 0; i < result.getSize(); i++) {
		if (result.getGene(i).isSet == 1) {
			result.setGene(i, NE_to_Platform(0, 0));
		}
		else {
			result.setGene(i, NE_to_Platform(1, 0));
		}
	}

	result.fixNetworkGenome(description);

	return result;

}