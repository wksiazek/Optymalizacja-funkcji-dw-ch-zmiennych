#pragma once
#include"stdafx.h"
#include"MutationSinglePoint.h"

void MutationSinglePoint::mutate(Population&population)
{
	int numberRandom;
	

	for (auto i = population.getListOfIndividuals().begin(); i != population.getListOfIndividuals().end(); ++i)
	{
		numberRandom = rand() % 100;
		if (getTableMutation()[numberRandom] == 1)
		{
			randomingMutationPoints(getMutationPoints());
			i->getGenes()[*getMutationPoints().begin()] = abs(i->getGenes()[*getMutationPoints().begin()] - 1);
		}
	}
	
}

void MutationSinglePoint::randomingMutationPoints(set<int>& mutationPoints)
{
	getMutationPoints().clear();
	getMutationPoints().insert(rand() % Configuration::instance()->getSumBits());
}