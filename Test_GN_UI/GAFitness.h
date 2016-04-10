#pragma once

template<class PopulationType, class Data>
class GAFitness {

protected:

public:

	virtual void fitness(PopulationType *population, Data description) = 0;
};