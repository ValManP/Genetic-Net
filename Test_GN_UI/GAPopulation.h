#pragma once

using namespace std;

template<class Genotype, class FitnessValue>
class GAPopulation {
protected:
	vector<Genotype> population;
	int size;
	vector<FitnessValue> fitness;
public:

	GAPopulation(int _size = 10) {
		size = _size;
		//population.resize(size);
		//fitness.resize(size);
	}

	int getSize() {
		return size;
	}
	void setSize(int _size) {
		size = _size;
		population.resize(s);
	}

	void setPopulation(vector<Genotype> new_population){
		population = new_population;
	}

	vector<Genotype> getPopulation(){
		return population;
	}

	Genotype getGenome(int i){
		return population[i];
	}

	void setFitness(vector<FitnessValue> new_fitness){
		fitness = new_fitness;
		for (int i = 0; i < fitness.size(); i++) {
			population[i].setFitness(fitness[i]);
		}
	}

	vector<FitnessValue> getFitness(){
		return fitness;
	}
};
