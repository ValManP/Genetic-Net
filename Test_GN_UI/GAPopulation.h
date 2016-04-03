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
};
