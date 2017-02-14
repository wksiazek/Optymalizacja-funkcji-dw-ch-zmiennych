#pragma once
#include"stdafx.h"
#include"Population.h"

//utworzenie populacji poczatkowej
void Population::createPopulation()
{
	for (int i = 0; i < Configuration::instance()->getPopulationSize(); ++i)
	{
		Individual chrom;
		//wypelnienie chromosomu dowolnymi wartosciami
		for (int j = 0; j < Configuration::instance()->getNumberBitsX(); ++j)
		{
			chrom.getGenes().push_back(rand() % 2);
		}

		for (int j = 0; j < Configuration::instance()->getNumberBitsY(); ++j)
		{
			chrom.getGenes().push_back(rand() % 2);
		}

		if (chrom.nonUnique(listOfIndividuals))
		{
			--i;
		}
		else
		{
			listOfIndividuals.push_back(chrom);
		}
	}
}

//funkcje wykonujace obliczenia dla grupy chromosow
void Population::calculateRepresentation10()
{
	for (vector<Individual>::iterator it = listOfIndividuals.begin(); it != listOfIndividuals.end(); ++it) //zmiana na iterator
	{
		it->calculateRepresentation10();
	}
}

void Population::scaleRepresentation10()
{
	for (vector<Individual>::iterator it = listOfIndividuals.begin(); it != listOfIndividuals.end(); ++it) //zmiana na iterator
	{
		it->scaleRepresentation10();
	}
}

void Population::calculateFitness()
{
	for (vector<Individual>::iterator it = listOfIndividuals.begin(); it != listOfIndividuals.end(); ++it) //zmiana na iterator
	{
		it->calculateFitness();
	}
}

void Population::scaleFitness()
{
	for (vector<Individual>::iterator it = listOfIndividuals.begin(); it != listOfIndividuals.end(); ++it) //zmiana na iterator
	{
		it->scaledFitness(listOfIndividuals);
	}
}

void Population::calculateProbability()
{
	double suma = 0.0;

	for (auto i = listOfIndividuals.begin(); i != listOfIndividuals.end(); ++i)
	{
		suma += i->getScaledFitnessValue();
	}

	for (auto i = listOfIndividuals.begin(); i != listOfIndividuals.end(); ++i)
	{
		i->setProbability(i->getScaledFitnessValue() / suma);
	}
}

void Population::calculateForPopulation()
{
	calculateRepresentation10();
	scaleRepresentation10();
	calculateFitness();
	scaleFitness();
	calculateProbability();
}

//funkcje do wyswietlania
void Population::displayBinary()
{
	cout << endl << "Populacja binarnie:" << endl;

	for (vector<Individual>::iterator it = listOfIndividuals.begin(); it != listOfIndividuals.end(); ++it) //zmiana na iterator
	{
		it->displayGenes();
		cout << endl;
	}
	cout << endl;
}

void Population::displayRepresentation10()
{
	cout << "Populacja po zamianie z binarnych na 10: " << endl;
	for (vector<Individual>::iterator it = listOfIndividuals.begin(); it != listOfIndividuals.end(); ++it) //zmiana na iterator
	{
		cout << "x: " << it->getRepresentation10X() << "y: " << it->getRepresentation10Y();
		cout << endl;
	}
	cout << endl;
}

void Population::displayScale10()
{
	cout << "Populacja po przeskalowaniu: " << endl;
	for (vector<Individual>::iterator it = listOfIndividuals.begin(); it != listOfIndividuals.end(); ++it) //zmiana na iterator
	{
		cout << "x: " << it->getScaledRepresentation10X() << "y: " << it->getScaledRepresentation10Y();
		cout << endl;
	}
	cout << endl;
}

void Population::displayFitness()
{
	cout << "Obliczone wartosci funkcji celu: " << endl;
	for (vector<Individual>::iterator it = listOfIndividuals.begin(); it != listOfIndividuals.end(); ++it) //zmiana na iterator
	{
		cout << it->getFitnessValue();
		cout << endl;
	}
	cout << endl;
}

void Population::displayProbability()
{
	cout << "Obliczone prawdopodobienstwa dla kola ruletki: " << endl;
	for (vector<Individual>::iterator it = listOfIndividuals.begin(); it != listOfIndividuals.end(); ++it) //zmiana na iterator
	{
		cout << it->getProbability();
		cout << endl;
	}
	cout << endl;
}