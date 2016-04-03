#pragma once

#include "Network.h"
#include "NetworkGenome.h"
#include "GAPopulation.h"

using namespace std;

struct Net {
	int averageCapacity;
	int price;

	bool operator==(Net a) {
		if (averageCapacity == a.averageCapacity && price == a.price) return true;
		return false;
	}
};

class NetworkPopulation : public GAPopulation<NetworkGenome, int> {
private:
	Network net;
	vector<NetworkElement> storage;

	vector<Net> data;

public:

	NetworkPopulation(int _size = 10, string fileName = "NA") : GAPopulation(_size){
		if (fileName != "NA")
			fillStorage(fileName);
	}

	int best() {
		NetworkGenome tmp;
		int max = 0;

		for (int i = 1; i < size; i++) {
			if (fitness[i] > fitness[max]) max = i;
		}

		return max;
	}

	int worst() {
		NetworkGenome tmp;
		int min = 0;

		for (int i = 1; i < size; i++) {
			tmp = population[i];
			if (fitness[i] < fitness[min]) min = i;
		}

		return min;
	}

	void add(NetworkGenome genome){
		population.push_back(genome); // CHECK !!!
		size = population.size();
	}

	void remove(int position){
		population.erase(population.begin() + position);
		size = population.size();
	}

	void addAll(NetworkPopulation p){
		for (int i = 0; i < p.getSize(); i++) {
			this->add(p.getGenome(i));
		}
	}

	void setFitness(vector<int> new_fitness);
	vector<int> getFitness();
	void setNet(Network new_net);
	Network getNet();
	void setStorage(vector<NetworkElement> _storage);
	vector<NetworkElement> getStorage();
	void setData(vector<Net> _data);
	vector<Net> getData();
	
	#pragma region TechnicalOperation

	int fillStorage(string file) {
		ifstream fin(file);

		//Проверка успешности открытия файла для чтения
		if (fin.fail()) {
			cout << " Ошибка открытия файла";
			exit(1);
		}

		string name;
		int price, cap;
		int count = 0;

		fin >> count;

		storage.resize(count);

		for (int i = 0; i < count; i++)
		{
			fin >> name;
			fin >> cap;
			fin >> price;

			storage[i].name = name;
			storage[i].capacity = cap;
			storage[i].price = price;
		}

		//Закрытие файла
		fin.close();

		return 0;
	}
	/* --------------------------------------------------*/
	#pragma endregion


};

void NetworkPopulation::setFitness(vector<int> new_fitness){
	fitness = new_fitness;
}

vector<int> NetworkPopulation::getFitness(){
	return fitness;
}

void NetworkPopulation::setNet(Network new_net){
	net = new_net;
}

Network NetworkPopulation::getNet(){
	return net;
}

void NetworkPopulation::setStorage(vector<NetworkElement> _storage){
	storage = _storage;
}

vector<NetworkElement> NetworkPopulation::getStorage(){
	return storage;
}

void NetworkPopulation::setData(vector<Net> _data){
	data = _data;
}

vector<Net> NetworkPopulation::getData(){
	return data;
}