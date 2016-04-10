#include "GAReproductionScheme.h"

class GenerationalStrategies : public GAReproductionScheme <NetworkPopulation> {
public:

	GenerationalStrategies(double value) {
		reproductionVariable = value;
	}

	void reproduct(NetworkPopulation *population, NetworkPopulation *reproductionArray);
};

void GenerationalStrategies::reproduct(NetworkPopulation *population, NetworkPopulation *reproductionArray){

	int size = population->getSize();

	population->replaceAll(*reproductionArray);
	if (size > reproductionArray->getSize()) {
		int i = reproductionArray->getSize();
		while (i != size) {
			population->add(reproductionArray->getGenome((i - reproductionArray->getSize()) % reproductionArray->getSize()));
			i++;
		}
	}

}