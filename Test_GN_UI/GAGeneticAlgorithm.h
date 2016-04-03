#pragma once

#include "GAMutation.h"
#include "GACrossover.h"

template<class PopulationType, class GenomeType, class Data>
class GAGeneticAlgorithm {
protected:
	PopulationType* population;
	PopulationType* childPopulation;
	PopulationType* mutantPopulation;
	GACrossover<GenomeType, Data> *crossoverOperator;
	GAMutation<GenomeType, Data> *mutationOperator;

	int populationSize;
	int coupleCount;
	int mutationCount;
	double mutationProbability;

public:
	GAGeneticAlgorithm() {

	}

	void setCoupleCount(int value);
	void setMutationCount(int value);
	void setMutationProbability(double value);

	void setPopulation(PopulationType* new_population);
	PopulationType getPopulation();
	void setCrossoverOperator(GACrossover<GenomeType, Data> *new_operator);
	void setMutationOperator(GAMutation<GenomeType, Data> *new_operator);

	virtual void gaCreatePopulation(Data data, int _populationSize) = 0;
	virtual void gaCrossbreeding(Data data) = 0;
	virtual void gaMutation(Data data) = 0;
	virtual void gaFitness(Data data) = 0;
	virtual void gaSelection(int g) = 0;
}; 

template<class PopulationType, class GenomeType, class Data>
void GAGeneticAlgorithm<PopulationType, GenomeType, Data>::setCoupleCount(int value){
	coupleCount = value;
}

template<class PopulationType, class GenomeType, class Data>
void GAGeneticAlgorithm<PopulationType, GenomeType, Data>::setMutationCount(int value){
	mutationCount = value;
}

template<class PopulationType, class GenomeType, class Data>
void GAGeneticAlgorithm<PopulationType, GenomeType, Data>::setMutationProbability(double value){
	mutationProbability = value;
}

template<class PopulationType, class GenomeType, class Data>
void GAGeneticAlgorithm<PopulationType, GenomeType, Data>::setPopulation(PopulationType* new_population){
	population = new_population;
}

template<class PopulationType, class GenomeType, class Data>
PopulationType GAGeneticAlgorithm<PopulationType, GenomeType, Data>::getPopulation(){
	return *population;
}

template<class PopulationType, class GenomeType, class Data>
void GAGeneticAlgorithm<PopulationType, GenomeType, Data>::setCrossoverOperator(GACrossover<GenomeType, Data> *new_operator){
	crossoverOperator = new_operator;
}

template<class PopulationType, class GenomeType, class Data>
void GAGeneticAlgorithm<PopulationType, GenomeType, Data>::setMutationOperator(GAMutation<GenomeType, Data> *new_operator) {
	mutationOperator = new_operator;
}