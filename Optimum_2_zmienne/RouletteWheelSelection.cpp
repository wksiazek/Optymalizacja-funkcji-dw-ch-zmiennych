#pragma once
#include"stdafx.h"
#include"RouletteWheelSelection.h"

void RouletteWheelSelection::select(Population&population, Population&parentsPopulation)
{
	parentsPopulation.getListOfIndividuals().clear();
	parentsPopulation.getListOfIndividuals().reserve(1000);//szykujemy nasz wektor do dzia³ania

	for (auto i = population.getListOfIndividuals().begin(); i != population.getListOfIndividuals().end(); ++i)
	{
		for (int j = 0; j < static_cast<int>(i->getProbability() * 1000); ++j)
		{
			parentsPopulation.getListOfIndividuals().push_back(*i);
		}
	}
}