#pragma once
#include"stdafx.h"
#include"Individual.h"

//konstruktor
Individual::Individual()
{

}

//funkcje operujace na pojedynczym chromosomie
void Individual::calculateRepresentation10()
{
	representation10X = 0;
	representation10Y = 0;
	
	for (int j = Configuration::instance()->getNumberBitsX(); j >0; --j)
	{
		representation10X += static_cast<int>(pow(2.0, static_cast<double>(Configuration::instance()->getNumberBitsX() - j))*genes[j - 1]);//uwaga na wzór nie jestem pewny
	}

	int potega = Configuration::instance()->getNumberBitsY();
	for (int i = Configuration::instance()->getNumberBitsY(), j = Configuration::instance()->getNumberBitsY() +
		Configuration::instance()->getNumberBitsX(); j > Configuration::instance()->getNumberBitsX(); --j, --i)
	{
		representation10Y += static_cast<int>(pow(2.0, static_cast<double>(potega - i))*genes[j - 1]);//uwaga na wzór nie jestem pewny
	}
}

void Individual::scaleRepresentation10()
{
	scaledRepresentation10X = static_cast<double>(Configuration::instance()->getLeftBoundaryX()) + (Configuration::instance()->getLengthIntervalX()*static_cast<double>(representation10X)) / (pow(2.0, static_cast<double>(Configuration::instance()->getNumberBitsX())) - 1.0);
	
	scaledRepresentation10Y = static_cast<double>(Configuration::instance()->getLeftBoundaryY()) 
		+ (Configuration::instance()->getLengthIntervalY()*static_cast<double>(representation10Y)) / (pow(2.0, static_cast<double>(Configuration::instance()->getNumberBitsY())) - 1.0);
}

void Individual::calculateFitness()
{
	fitnessValue = fitnessFunction(scaledRepresentation10X, scaledRepresentation10Y);
}

void Individual::scaledFitness(vector<Individual> &tab)
{
	//skalowanie funkcji celu
	if (Configuration::instance()->getTypeScaled() == LINEAR)
	{
		scaledFitnessValue = fitnessValue + Configuration::instance()->getConstant();
	}
	else if (Configuration::instance()->getTypeScaled() == EXPONENTIATION)
	{
		scaledFitnessValue = pow(fitnessValue, Configuration::instance()->getPower());
	}
	else if (Configuration::instance()->getTypeScaled() == SKALOWANIE_OBCINAJACE_TYPU_SIGMA)
	{
		double averageFitness = 0.0;
		double standardDeviation;
		double sum = 0.0;
		int c = 3; //liczba z zakresu (1,5)
				   //licze srednia
		for (size_t i = 0; i < tab.size(); ++i)
		{
			averageFitness += tab[i].fitnessValue;
		}
		averageFitness /= tab.size();
		//licze odchylenie standardowe
		for (size_t i = 0; i < tab.size(); ++i)
		{
			sum += pow(tab[i].fitnessValue - averageFitness, 2);
		}

		standardDeviation = sqrt(sum / tab.size());
		scaledFitnessValue = fitnessValue + (averageFitness + c*standardDeviation);
	}
}

bool Individual::nonUnique(vector<Individual> &tab)
{
	for (auto i = tab.begin(); i != tab.end(); ++i)
	{
		if (equal(genes.begin(), genes.end(), i->genes.begin()))
		{
			//cout << "geny nieunikalne, losujemy raz jeszcze: " << a<< endl;
			return true;
		}
	}
	return false;
}

void Individual::displayGenes()
{
	for (vector<int>::iterator it = genes.begin(); it != genes.end(); ++it)
	{
		cout << *it;
	}
}

//funkcja ktorej optimum liczymy
double Individual::fitnessFunction(double x,double y)
{
	if (Configuration::instance()->getTypeFunction() == 0)
	{
		if (Configuration::instance()->getOptimization() == MAXIMUM)
			return 21.5 + x*sin(4.0*M_PI*x) + y*sin(20.0*M_PI*y);
		else
			return -(21.5 + x*sin(4.0*M_PI*x) + y*sin(20.0*M_PI*y));
	}
	else if (Configuration::instance()->getTypeFunction() == 1)
	{
		if (Configuration::instance()->getOptimization() == MAXIMUM)
			return pow(x + 2.0*y - 7.0, 2.0) + pow(2.0*x + y - 5.0, 2.0);
		else
			return -(pow(x + 2.0*y - 7.0, 2.0) + pow(2.0*x + y - 5.0, 2.0));
	}
	return 0;
}