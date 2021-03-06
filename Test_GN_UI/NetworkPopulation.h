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

class NetworkPopulation : public GAPopulation<NetworkGenome, double> {
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
			if (population[i].getFitness() > population[max].getFitness()) max = i;
		}

		return max;
	}

	int worst() {
		NetworkGenome tmp;
		int min = 0;
		
		for (int i = 1; i < size; i++) {
			tmp = population[i];
			if (population[i].getFitness() < population[min].getFitness()) min = i;
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

	void removeAll(){
		population.clear();
		size = 0;
	}

	void addAll(NetworkPopulation p){
		for (int i = 0; i < p.getSize(); i++) {
			this->add(p.getGenome(i));
		}
	}

	void replaceAll(NetworkPopulation p){
		population.clear();
		size = 0;
		fitness.clear();

		for (int i = 0; i < p.getSize(); i++) {
			this->add(p.getGenome(i));
		}
	}

	void setNet(Network new_net);
	Network getNet();
	void setStorage(vector<NetworkElement> _storage);
	vector<NetworkElement> getStorage();
	void setData(vector<Net> _data);
	vector<Net> getData();
	
	#pragma region TechnicalOperation

	int fillStorage(string file) {
		ifstream fin(file);

		//�������� ���������� �������� ����� ��� ������
		if (fin.fail()) {
			cout << " ������ �������� �����";
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

		//�������� �����
		fin.close();

		return 0;
	}
	/* --------------------------------------------------*/
	#pragma endregion


};

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