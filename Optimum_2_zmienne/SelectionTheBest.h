#pragma once
#include"stdafx.h"
#include"Selection.h"

class SelectionTheBest : public Selection
{
	void select(Population &population, Population&parentsPopulation);
};