#pragma once

template<class PopulationType, class Data>
class GAGeneticAlgorithm {
protected:
	PopulationType population;

public:
	GAGeneticAlgorithm(){

	}

	virtual vector<PopulationType> gaSinglePointCrossover(PopulationType parentA, PopulationType parentB);
	virtual PopulationType gaMutation(PopulationType a, Data data);

	virtual void createPopulation(Data data);
	virtual void gaEvolution(int childCount, double mutation, Data data);
	virtual void gaFitness();
	virtual void gaSelection(int excludedCount, int max_price);
}; 