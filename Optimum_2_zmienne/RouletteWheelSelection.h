#pragma once
#include"stdafx.h"
#include"Selection.h"
class RouletteWheelSelection : public Selection
{
	void select(Population&population, Population&parentsPopulation);
};
