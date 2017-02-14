#pragma once
#include"stdafx.h"
#include"Selection.h"

class SelectionRank : public Selection
{
	void select(Population&population, Population&parentsPopulation);
};