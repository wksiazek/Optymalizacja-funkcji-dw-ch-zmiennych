#pragma once
#include"stdafx.h"
#include"MutationThreePoints.h"

void MutationThreePoints::mutate(Population&population)
{
	int numberRandom;
	
	for (auto i = population.getListOfIndividuals().begin(); i != population.getListOfIndividuals().end(); ++i)
	{
		numberRandom = rand() % 100;
		if (getTableMutation()[numberRandom] == 1)
		{
			randomingMutationPoints(getMutationPoints());
			auto tempek = *(++getMutationPoints().begin());//dostep do drugiego elementu zbioru

			i->getGenes()[*getMutationPoints().begin()] = abs(i->getGenes()[*getMutationPoints().begin()] - 1);
			i->getGenes()[tempek] = abs(i->getGenes()[tempek] - 1);
			i->getGenes()[*(getMutationPoints().rbegin())] = abs(i->getGenes()[*(getMutationPoints().rbegin())] - 1);
		}
	}
}

void MutationThreePoints::randomingMutationPoints(set<int>& mutationPoints)
{
	getMutationPoints().clear();
	while (getMutationPoints().size() != 3)
	{
		getMutationPoints().insert(rand() % Configuration::instance()->getSumBits());
	}
}