#pragma once
#include"stdafx.h"
#include"SelectionTournament.h"

void SelectionTournament::select(Population&population, Population&parentsPopulation)
{
	int numberGroup = population.getListOfIndividuals().size() / Configuration::instance()->getTournamentSize();
	int numberRandom;

	vector<Individual>copy(population.getListOfIndividuals());
	parentsPopulation.getListOfIndividuals().clear();

	for (int i = 0; i < numberGroup; ++i)
	{
		vector<Individual>temp;
		for (int j = 0; j < Configuration::instance()->getTournamentSize(); ++j)
		{
			numberRandom = rand() % copy.size();
			temp.push_back(copy[numberRandom]);
			copy.erase(copy.begin() + numberRandom);
		}
		parentsPopulation.getListOfIndividuals().push_back(*(max_element(temp.begin(), temp.end(), [](Individual &a, Individual &b) {return (a.getFitnessValue() < b.getFitnessValue()); })));//uwaga
	}
}