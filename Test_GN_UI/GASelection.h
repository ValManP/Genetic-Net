#pragma once

template<class PopulationType>
class GASelection {

protected:
	int selectionVariable;

public:

	virtual void select(PopulationType *reproductionArray, PopulationType *finalArray, int g) = 0;
};