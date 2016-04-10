#include "GASelection.h"

class B_TournamentSelection : public GASelection <NetworkPopulation> {
public:

	B_TournamentSelection(int b) {
		selectionVariable = b;
	}

	void select(NetworkPopulation *population, NetworkPopulation *finalArray, int g);
};

void B_TournamentSelection::select(NetworkPopulation *reproductionArray, NetworkPopulation *finalArray, int g){

	for (int i = 0; i < g; i++) {

		NetworkGenome best, current;

		best = reproductionArray->getGenome(rand() % reproductionArray->getSize());

		for (int j = 1; j < selectionVariable; j++) {
			int num = rand() % reproductionArray->getSize();

			current = reproductionArray->getGenome(num);
			if (current.getFitness() > best.getFitness()) {
				best = current;
			}
		}

		finalArray->add(best);

	}


}