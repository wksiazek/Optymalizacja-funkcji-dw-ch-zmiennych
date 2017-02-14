#pragma once
#include"stdafx.h"
#include"SelectionRank.h"

void SelectionRank::select(Population&population, Population &parentsPopulation)
{
	parentsPopulation.getListOfIndividuals().clear();

	//posortowanie populacji
	sort(population.getListOfIndividuals().begin(), population.getListOfIndividuals().end(), [](Individual &a, Individual &b) {return (a.getFitnessValue() > b.getFitnessValue()); });

	int temp = population.getListOfIndividuals().size();
	//obliczenie rang- najlepszy osobnik ma range=ilosc populacji, kolejny ilosc populacji-1
	for (auto a = population.getListOfIndividuals().begin(); a != population.getListOfIndividuals().end(); ++a)
	{
		a->setRank(temp);
		--temp;
	}

	for (auto i = population.getListOfIndividuals().begin(); i != population.getListOfIndividuals().end(); ++i)
	{
		for (int j = 0; j < i->getRank(); ++j)
		{
			parentsPopulation.getListOfIndividuals().push_back(*i);
		}
	}

}