#pragma once

#include "NetworkPopulation.h"
#include "GAGeneticAlgorithm.h"

class NetworkGeneticAlgorithm {
private:

	NetworkPopulation population;

public:

	NetworkGeneticAlgorithm() {

	}

	void setPopulation(NetworkPopulation new_population){
		population = new_population;
	}

	NetworkPopulation getPopulation(){
		return population;
	}

	vector<NetworkGenome> gaSinglePointCrossover(NetworkGenome parentA, NetworkGenome parentB){
		int r = rand() % (parentA.getSize()-1) + 1;

		vector<NetworkGenome> result(2);
		result[0].setSize(parentA.getSize());
		result[1].setSize(parentA.getSize());

		for (int i = 0; i < parentA.getSize(); i++) {
			if (i < r) {
				result[0].setGene(i, parentA.getGene(i));
				result[1].setGene(i, parentB.getGene(i));
			}
			else {
				result[0].setGene(i, parentB.getGene(i));
				result[1].setGene(i, parentA.getGene(i));
			}
		}
		
		result[0].calculateDevice();
		result[1].calculateDevice();

		return result;
	}

	vector<NetworkGenome> gaSinglePointCrossoverSave(NetworkGenome parentA, NetworkGenome parentB, NetworkDescription description){

		vector<NetworkGenome> result = gaSinglePointCrossover(parentA, parentB);

		int minCount = description.minDeviceCount, maxCount = description.platformCount;

		while (result[0].getDeviceCount() < minCount || result[1].getDeviceCount() < minCount || result[0].getDeviceCount() > maxCount || result[1].getDeviceCount() > maxCount)
			result = gaSinglePointCrossover(parentA, parentB);

		result[0].fixNetworkGenome(description);
		result[1].fixNetworkGenome(description);

		return result;

	}

	NetworkGenome gaMutation(NetworkGenome a, NetworkDescription description){

		NetworkGenome result(a.getSize());
		result = a;

		int m1 = rand() % a.getSize();
		int m2 = rand() % a.getSize();

		result.setGene(m2, a.getGene(m1));
		result.setGene(m1, a.getGene(m2));

		return result;
	}

#pragma region GAOperation

	void createPopulation(NetworkDescription description, int populationSize){
		for (int i = 0; i < populationSize; i++) {
			NetworkGenome genome(population.getStorage().size());
			genome.initialize(description);
			population.add(genome);
		}
	}

	void gaEvolution(int childCount, double mutation, NetworkDescription description){
		int i = childCount;

		double mut;
		int parent1 = 0, parent2 = 0, mut_count;
		NetworkGenome p1, p2;

		int parentCount = population.getSize();

		NetworkGeneticAlgorithm tempGA = (*this);

		vector<NetworkGenome> childs(0);

		//NetworkPopulation tempPopulation = tempGA.getPopulation();

		while (i > 0) {
			// TODO CHANGE
			/*parent1 = tempPopulation.best();
			p1 = tempPopulation.getPopulation()[parent1];
			tempPopulation.remove(parent1);
			tempGA.setPopulation(tempPopulation);
			tempGA.gaFitness(description);

			parent2 = tempPopulation.best();
			p2 = tempPopulation.getPopulation()[parent1];
			tempPopulation.remove(parent2);
			tempGA.setPopulation(tempPopulation);
			tempGA.gaFitness(description);*/

			parent1 = population.best();
			p1 = population.getPopulation()[parent1];

			parent2 = rand() % population.getSize();
			p2 = population.getPopulation()[parent2];

			mut = (double)rand() / INT_MAX;
			mut_count = rand() % p1.getSize();

			vector<NetworkGenome> res = gaSinglePointCrossoverSave(p1, p2, description);
			for (int j = 0; j < mut_count; j++) {
				if (mutation < mut)
					res[0] = gaMutation(res[0], description);
				else
					res[1] = gaMutation(res[1], description);
			}

			childs.push_back(res[0]);
			childs.push_back(res[1]);

			i = i - 2;
		}

		for (NetworkGenome iter : childs) {
			population.add(iter);
		}

	}

	void gaFitness(NetworkDescription description){
		int size = population.getSize();

		vector<Net> data(size);

		NetworkGenome genome;
		vector<NetworkGenome> tempPopulation = population.getPopulation();

		for (int i = 0; i < size; i++) {
			//genome = tempPopulation[i];
			data[i].price = tempPopulation[i].calculateCost(description);
			data[i].averageCapacity = tempPopulation[i].calculateCapacity(description, population.getNet());
		}

		population.setData(data);
		population.setPopulation(tempPopulation);

		vector<int> fitness(size, 0);

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				if (data[i].price < data[j].price && data[i].averageCapacity > data[j].averageCapacity && i != j) fitness[i]++;
		}

		population.setFitness(fitness);

	}

	void gaSelection(int excludedCount, int max_price){
		int num = 0;
		for (int i = 0; i < excludedCount; i++) {
			num = population.worst();
			population.remove(num);
		}

		/*vector<vector<int>>::iterator u = data.begin();
		int pos = 0;
		while (u != data.end()) {
		if ((*u)[0] > max_price) {
		population.erase(population.begin() + pos);
		fitness.erase(fitness.begin() + pos);
		u = data.erase(u);
		}
		else
		pos++;
		}*/
	}
	
#pragma endregion

	string gaShowBest(NetworkDescription description) {

		gaFitness(description);

		return population.getPopulation().at(population.best()).toString(description);

	}

	Network gaGetBestNet(NetworkDescription description) {

		Network result = population.getNet();

		NetworkGenome genome = population.getPopulation().at(population.best());

		for (int i = 0; i < genome.getSize(); i++) {
			if (genome.getGene(i).isSet)
				result.updatePlatform(genome.getGene(i).position, description.storage[i].capacity);
		}

		return result;

	}

	NetworkGenome gaGetBest() {

		return population.getPopulation().at(population.best());

	}

	string gaShowPopulation(){
		string result = "";
		char tmp[10];
		int count = 0;

		vector<Net> data = population.getData();
		vector<bool> flags(data.size(), false);
		result += "Pair    Count\n";
		for (int i = 0; i < flags.size(); i++) {
			if (flags[i] == false) {
				_itoa_s(data[i].price, tmp, 10);
				result += "(" + (string)tmp + ", ";
				_itoa_s(data[i].averageCapacity, tmp, 10);
				result += (string)tmp + ")  ";
				count = 1;
				for (int j = i + 1; j < flags.size(); j++) {
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
	/*
	string gaShowPopulationFitness(){
	string result;
	char tmp[10];

	for (int i = 0; i < fitness.size(); i++) {
	_itoa_s(fitness[i], tmp, 10);
	result += tmp;
	result += " ";
	}

	return result;
	}*/
};