#pragma once
#include"stdafx.h"
#include"SelectionTheBest.h"

void SelectionTheBest::select(Population&population, Population&parentsPopulation)
{
	parentsPopulation.getListOfIndividuals().clear();

	//sortujemy chromosomy
	sort(population.getListOfIndividuals().begin(), population.getListOfIndividuals().end(), [](Individual &a, Individual&b) {return (a.getFitnessValue() > b.getFitnessValue()); });
	//chromosomy na poczatku tablicy sa najlepsze
	for (int i = 0; i < static_cast<double>(Configuration::instance()->getPercentTheBest() / 100.0) * population.getListOfIndividuals().size(); ++i)
	{
		parentsPopulation.getListOfIndividuals().push_back(population.getListOfIndividuals()[i]);//wsadzamy numery chromosow
	}
}