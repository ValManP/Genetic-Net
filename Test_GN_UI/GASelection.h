#pragma once

template<class GenomeType, class Data>
class GASelection {

public:

	virtual vector<GenomeType> select(GenomeType parentA, GenomeType parentB, Data description) = 0;
};