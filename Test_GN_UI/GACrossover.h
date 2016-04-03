#pragma once

template<class GenomeType, class Data>
class GACrossover {

public:

	virtual vector<GenomeType> crossover(GenomeType parentA, GenomeType parentB, Data description) = 0;
};