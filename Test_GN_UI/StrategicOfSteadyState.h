#include "GAReproductionScheme.h"

class StrategicOfSteadyState : public GAReproductionScheme <NetworkPopulation> {
public:

	StrategicOfSteadyState(double value) {
		reproductionVariable = value;
	}

	void reproduct(NetworkPopulation *population, NetworkPopulation *reproductionArray);
};

void StrategicOfSteadyState::reproduct(NetworkPopulation *population, NetworkPopulation *reproductionArray){

	int size = population->getSize();
	int v = size * reproductionVariable;

	NetworkPopulation *tmpPopulation = new NetworkPopulation(size);

	tmpPopulation->replaceAll(*population);

	tmpPopulation->setFitness(population->getFitness());

	population->removeAll();

	for (int i = 0; i < v; i++) {

		population->add(tmpPopulation->getGenome(tmpPopulation->worst()));
		tmpPopulation->remove(tmpPopulation->worst());

		population->add(reproductionArray->getGenome(reproductionArray->best()));
		reproductionArray->remove(reproductionArray->best());
	}

	delete tmpPopulation;

}