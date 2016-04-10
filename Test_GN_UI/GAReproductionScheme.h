#pragma once

template<class PopulationType>
class GAReproductionScheme {

protected:
	double reproductionVariable;

public:

	virtual void reproduct(PopulationType *population, PopulationType *reproductionArray) = 0;
};