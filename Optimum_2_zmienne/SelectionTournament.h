#pragma once
#include"stdafx.h"
#include"Selection.h"

class SelectionTournament : public Selection
{
	void select(Population &population, Population&parentsPopulation);
};