#pragma once
#include"stdafx.h"
#include"Crossover.h"

Crossover::Crossover()
{
	fillTableCrossover();
}

void Crossover::fillTableCrossover()
{
	for (int i = 0; i < Configuration::instance()->getProbabilityCrossover(); i++)
	{
		tableCrossover.push_back(1);
	}

	for (int i = Configuration::instance()->getProbabilityCrossover(); i <100; i++)
	{
		tableCrossover.push_back(0);
	}
}

void Crossover::randTwoIndyvidualForCrossovering(Population &parentsPopulation, int &firstIndyvidual, int &secondIndyvidual)
{
	int randNumber;
	while (1)
	{
		//losujemy chromosom
		firstIndyvidual = rand() % parentsPopulation.getListOfIndividuals().size();
		//sprawdzamy czy ten chromosom bedzie w populacji rodzicow czy losujemy inny
		randNumber = rand() % 100;
		if (tableCrossover[randNumber] == 1)
		{
			break;
		}
	}

	while (1)
	{
		secondIndyvidual = rand() % parentsPopulation.getListOfIndividuals().size();
		randNumber = rand() % 100;
		if (tableCrossover[randNumber] == 1)
		{
			break;
		}
	}
}

void Crossover::cross(Population&parentsPopulation, Population&newPopulation)
{
	int firstIndyvidual, secondIndyvidual;

	if (Configuration::instance()->getProbabilityCrossover() != 0)
	{
		for (int i = 0; i < (Configuration::instance()->getPopulationSize() - Configuration::instance()->getNumberElite()) / 2; ++i)
		{
			Individual temp, temp2;
			//losujemy numery dwoch chromosomow do krzyzowania
			randTwoIndyvidualForCrossovering(parentsPopulation, firstIndyvidual, secondIndyvidual);
			//losujemy miejsca krzyzowania-funkcja wirtualna
			randCrossoverPoints(crossoverPoints);
			//krzyzujemy-funkcja wirtualna
			prepareNewIndywiduals(parentsPopulation, crossoverPoints, temp, temp2, firstIndyvidual, secondIndyvidual);

			//sprawdzenie unikalnosci potomkow !!!!!!!!!!!!nieoptymalne
			if (Configuration::instance()->getUniqueIndyvidual())
			{
				if (temp.nonUnique(newPopulation.getListOfIndividuals()) || temp2.nonUnique(newPopulation.getListOfIndividuals()))
				{
					i--;
					continue;
				}
			}
			newPopulation.getListOfIndividuals().push_back(temp);
			newPopulation.getListOfIndividuals().push_back(temp2);
		}
	}
}