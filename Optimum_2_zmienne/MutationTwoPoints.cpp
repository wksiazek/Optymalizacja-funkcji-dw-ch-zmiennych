#pragma once
#include"stdafx.h"
#include"MutationTwoPoints.h"

void MutationTwoPoints::mutate(Population&population)
{
	int numberRandom;
	
	for (auto i = population.getListOfIndividuals().begin(); i != population.getListOfIndividuals().end(); ++i)
	{
		numberRandom = rand() % 100;
		if (getTableMutation()[numberRandom] == 1)
		{
			randomingMutationPoints(getMutationPoints());
			i->getGenes()[*getMutationPoints().begin()] = abs(i->getGenes()[*getMutationPoints().begin()] - 1);
			i->getGenes()[*++getMutationPoints().begin()] = abs(i->getGenes()[*++getMutationPoints().begin()] - 1);
		}
	}
}

void MutationTwoPoints::randomingMutationPoints(set<int>& mutationPoints)
{
	getMutationPoints().clear();
	while (getMutationPoints().size() != 2)
	{
		getMutationPoints().insert(rand() % Configuration::instance()->getSumBits());
	}
}