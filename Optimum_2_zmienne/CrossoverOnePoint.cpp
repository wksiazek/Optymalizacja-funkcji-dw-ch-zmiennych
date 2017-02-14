#pragma once
#include"stdafx.h"
#include"CrossoverOnePoint.h"

void CrossoverSinglePoint::randCrossoverPoints(set<int>&crossoverPoints)
{
	crossoverPoints.clear();
	crossoverPoints.insert(rand() % Configuration::instance()->getSumBits());
}

void CrossoverSinglePoint::prepareNewIndywiduals(Population&parentsPopulation, set<int>&crossoverPoints, Individual &temp, Individual &temp2, int a, int b)
{
	//1 potomek
	temp.getGenes().insert(temp.getGenes().begin(), parentsPopulation.getListOfIndividuals()[a].getGenes().begin(), parentsPopulation.getListOfIndividuals()[a].getGenes().begin() + *(crossoverPoints.begin()));
	temp.getGenes().insert(temp.getGenes().end(), parentsPopulation.getListOfIndividuals()[b].getGenes().begin() + *(crossoverPoints.begin()), parentsPopulation.getListOfIndividuals()[b].getGenes().end());

	//drugi potomek
	temp2.getGenes().insert(temp2.getGenes().begin(), parentsPopulation.getListOfIndividuals()[b].getGenes().begin(), parentsPopulation.getListOfIndividuals()[b].getGenes().begin() + *(crossoverPoints.begin()));
	temp2.getGenes().insert(temp2.getGenes().end(), parentsPopulation.getListOfIndividuals()[a].getGenes().begin() + *(crossoverPoints.begin()), parentsPopulation.getListOfIndividuals()[a].getGenes().end());
}