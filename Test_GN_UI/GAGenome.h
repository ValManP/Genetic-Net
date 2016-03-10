#pragma once

template<class Gene, class Data>
class GAGenome {
protected:
	vector<Gene> genome;
	int size;

public:

	GAGenome(int _size = 10) {
		size = _size;
		genome.resize(size);
	}

	void setGene(int position, Gene gene){
		if (position > -1 && position < size)
			genome[position] = gene;
		// TODO Add Log
	}
	Gene getGene(int position){
		return genome[position];
	}
	int getSize() {
		return size;
	}
	void setSize(int _size) {
		size = _size;
		genome.resize(size);
	}

	vector<Gene> getGenome(){
		return genome;
	}
};