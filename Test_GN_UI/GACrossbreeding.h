#pragma once

template<class PopulationType, class GenomeType>
class GACrossbreeding {

protected:
	double crossbreedingVariable;

public:

	virtual void cross(PopulationType *population, GenomeType* parentA, GenomeType *parentB) = 0;
};