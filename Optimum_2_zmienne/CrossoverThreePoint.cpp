#pragma once
#include"stdafx.h"
#include"CrossoverThreePoint.h"

void CrossoverThreePoints::randCrossoverPoints(set<int>&crossoverPoints)
{
	crossoverPoints.clear();
	while (crossoverPoints.size() != 3)
	{
		crossoverPoints.insert(rand() % Configuration::instance()->getSumBits());
	}
}

void CrossoverThreePoints::prepareNewIndywiduals(Population&parentsPopulation, set<int>&crossoverPoints, Individual &temp, Individual &temp2, int a, int b)
{
	auto tempek = *(++crossoverPoints.begin());//dostep do drugiego elementu zbioru

	//1 potomek
	temp.getGenes().insert(temp.getGenes().begin(), parentsPopulation.getListOfIndividuals()[a].getGenes().begin(), parentsPopulation.getListOfIndividuals()[a].getGenes().begin() + *(crossoverPoints.begin()));
	temp.getGenes().insert(temp.getGenes().end(), parentsPopulation.getListOfIndividuals()[b].getGenes().begin() + *(crossoverPoints.begin()), parentsPopulation.getListOfIndividuals()[b].getGenes().begin() + tempek);
	temp.getGenes().insert(temp.getGenes().end(), parentsPopulation.getListOfIndividuals()[a].getGenes().begin() + tempek, parentsPopulation.getListOfIndividuals()[a].getGenes().begin() + *(crossoverPoints.rbegin()));
	temp.getGenes().insert(temp.getGenes().end(), parentsPopulation.getListOfIndividuals()[b].getGenes().begin() + *(crossoverPoints.rbegin()), parentsPopulation.getListOfIndividuals()[b].getGenes().end());

	//2 potomek
	temp2.getGenes().insert(temp2.getGenes().begin(), parentsPopulation.getListOfIndividuals()[b].getGenes().begin(), parentsPopulation.getListOfIndividuals()[b].getGenes().begin() + *(crossoverPoints.begin()));
	temp2.getGenes().insert(temp2.getGenes().end(), parentsPopulation.getListOfIndividuals()[a].getGenes().begin() + *(crossoverPoints.begin()), parentsPopulation.getListOfIndividuals()[a].getGenes().begin() + tempek);
	temp2.getGenes().insert(temp2.getGenes().end(), parentsPopulation.getListOfIndividuals()[b].getGenes().begin() + tempek, parentsPopulation.getListOfIndividuals()[b].getGenes().begin() + *(crossoverPoints.rbegin()));
	temp2.getGenes().insert(temp2.getGenes().end(), parentsPopulation.getListOfIndividuals()[a].getGenes().begin() + *(crossoverPoints.rbegin()), parentsPopulation.getListOfIndividuals()[a].getGenes().end());
}