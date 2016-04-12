#include "GAReproductionScheme.h"

class ElitistGenerationalStrategies : public GAReproductionScheme <NetworkPopulation> {
public:

	ElitistGenerationalStrategies(double value) {
		reproductionVariable = value;
	}

	void reproduct(NetworkPopulation *population, NetworkPopulation *reproductionArray);
};

void ElitistGenerationalStrategies::reproduct(NetworkPopulation *population, NetworkPopulation *reproductionArray){

	int size = population->getSize();

	NetworkGenome bestGenome = population->getGenome(population->best());

	population->replaceAll(*reproductionArray);
	population->add(bestGenome);

}