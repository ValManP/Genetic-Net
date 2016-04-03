#pragma once

template<class GenomeType, class Data>
class GAMutation {

public:

	virtual GenomeType mutate(GenomeType genome, Data description) = 0;
};