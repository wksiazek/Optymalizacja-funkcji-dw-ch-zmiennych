#pragma once
#include"stdafx.h"
#include"Population.h"

class Selection
{
public:
	virtual void select(Population& population, Population &parentsPopulation) = 0;
};

enum SELECTION
{
	ROULETTE_WHEEL_SELECTION,
	SELECTION_THE_BEST, //% najlepszych z populacji
	SELECTION_TOURNAMENT,
	SELECTION_RANK
};
