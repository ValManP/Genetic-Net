#pragma once

#include "GAMutation.h"
#include "GACrossover.h"
#include "GASelection.h"
#include "GAFitness.h"
#include "GACrossbreeding.h"
#include "GAReproductionScheme.h"

template<class PopulationType, class GenomeType, class Data>
class GAGeneticAlgorithm {
protected:
	PopulationType* population;
	PopulationType* childPopulation;
	PopulationType* mutantPopulation;
	PopulationType* reproductionArray;
	GACrossover<GenomeType, Data> *crossoverOperator;
	GAMutation<GenomeType, Data> *mutationOperator;
	GASelection<PopulationType> *selectionOperator;
	GAFitness<PopulationType, Data> *fitnessFunction;
	GACrossbreeding<PopulationType, GenomeType> *crossbreedingOperator;
	GAReproductionScheme<PopulationType> *reproductionOperator;

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
	void setSelectionOperator(GASelection<PopulationType> *new_operator);
	void setFitnessFunction(GAFitness<PopulationType, Data> *new_function);
	void setCrossbreedingOperator(GACrossbreeding<PopulationType, GenomeType> *new_operator);
	void setReproductionOperator(GAReproductionScheme<PopulationType> *new_operator);

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

template<class PopulationType, class GenomeType, class Data>
void GAGeneticAlgorithm<PopulationType, GenomeType, Data>::setSelectionOperator(GASelection<PopulationType> *new_operator) {
	selectionOperator = new_operator;
}

template<class PopulationType, class GenomeType, class Data>
void GAGeneticAlgorithm<PopulationType, GenomeType, Data>::setFitnessFunction(GAFitness<PopulationType, Data> *new_function) {
	fitnessFunction = new_function;
}

template<class PopulationType, class GenomeType, class Data>
void GAGeneticAlgorithm<PopulationType, GenomeType, Data>::setCrossbreedingOperator(GACrossbreeding<PopulationType, GenomeType> *new_operator){
	crossbreedingOperator = new_operator;
}

template<class PopulationType, class GenomeType, class Data>
void GAGeneticAlgorithm<PopulationType, GenomeType, Data>::setReproductionOperator(GAReproductionScheme<PopulationType> *new_operator){
	reproductionOperator = new_operator;
}