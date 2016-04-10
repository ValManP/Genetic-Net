#pragma once

#include "NetworkPopulation.h"
#include "GAGeneticAlgorithm.h"
#include "SinglePointCrossover.h"
#include "UniformCrossover.h"
#include "FlipBitMutation.h"
#include "B_TournamentSelection.h"
#include "RandomWeightFitness.h"
#include "Panmixia.h"
#include "Inbreeding.h"
#include "Autobreeding.h"
#include "PositiveAssociativeMating.h"
#include "GenerationalStrategies.h"

class NetworkGeneticAlgorithm : public GAGeneticAlgorithm<NetworkPopulation, NetworkGenome, NetworkDescription> {
private:

public:

	NetworkGeneticAlgorithm() {
		childPopulation = new NetworkPopulation(0, "NA");
		mutantPopulation = new NetworkPopulation(0, "NA");
		reproductionArray = new NetworkPopulation(0, "NA");
	}

#pragma region GAOperation

	void gaCreatePopulation(NetworkDescription description, int _populationSize){
		populationSize = _populationSize;

		for (int i = 0; i < populationSize; i++) {
			NetworkGenome genome(population->getStorage().size());
			genome.initialize(description);
			population->add(genome);
		}
	}

	void gaCrossbreeding(NetworkDescription description){

		NetworkGenome p1, p2;

		int i = coupleCount;

		while (i > 0) {

			crossbreedingOperator->cross(population, &p1, &p2);

			// Crossover
			vector<NetworkGenome> res = crossoverOperator->crossover(p1, p2, description);

			for (int j = 0; j < res.size(); j++) {
				childPopulation->add(res[j]);
				i--;
			}
		}

		reproductionArray->addAll(*childPopulation);

	}

	void gaMutation(NetworkDescription description){
		for (int i = 0; i < mutationCount; i++) {

			double mut = (double)rand() / INT_MAX;
			int genNum = rand() / populationSize;

			if (mut < mutationProbability) {
				mutantPopulation->add(mutationOperator->mutate(population->getGenome(i), description));
			}
		}

		reproductionArray->addAll(*mutantPopulation);
	}

	void gaFitness(NetworkDescription description){

		int size = population->getSize();

		vector<Net> data(size);

		NetworkGenome genome;
		vector<NetworkGenome> tempPopulation = population->getPopulation();

		for (int i = 0; i < size; i++) {
			data[i].price = tempPopulation[i].calculateCost(description);
			data[i].averageCapacity = tempPopulation[i].calculateCapacity(description, population->getNet());
		}

		population->setData(data);
		population->setPopulation(tempPopulation);

		fitnessFunction->fitness(population, description);

	}

	void gaSelection(int g) {

		NetworkPopulation *nextPopulation = new NetworkPopulation(0, "NA");

		selectionOperator->select(reproductionArray, nextPopulation, g);
		reproductionOperator->reproduct(population, nextPopulation);

		reproductionArray->removeAll();

		population->replaceAll(*nextPopulation);

	}
	
#pragma endregion

	string gaShowBest(NetworkDescription description) {

		gaFitness(description);

		return population->getPopulation().at(population->best()).toString(description);

	}

	Network gaGetBestNet(NetworkDescription description) {

		Network result = population->getNet();

		NetworkGenome genome = population->getPopulation().at(population->best());

		for (int i = 0; i < genome.getSize(); i++) {
			if (genome.getGene(i).isSet)
				result.updatePlatform(genome.getGene(i).position, description.storage[i].capacity);
		}

		return result;

	}

	NetworkGenome gaGetBest() {

		return population->getPopulation().at(population->best());

	}

	string gaShowPopulation(){
		string result = "";
		char tmp[10];
		int count = 0;

		vector<Net> data = population->getData();
		vector<bool> flags(data.size(), false);
		result += "Pair    Count\n";
		for (unsigned int i = 0; i < flags.size(); i++) {
			if (flags[i] == false) {
				_itoa_s(data[i].price, tmp, 10);
				result += "(" + (string)tmp + ", ";
				_itoa_s(data[i].averageCapacity, tmp, 10);
				result += (string)tmp + ")  ";
				count = 1;
				for (unsigned int j = i + 1; j < flags.size(); j++) {
					if (data[i] == data[j]) {
						count++;
						flags[j] = true;
					}
				}
				_itoa_s(count, tmp, 10);
				result += (string)tmp + "\n";
			}
		}

		return result;
	}
};