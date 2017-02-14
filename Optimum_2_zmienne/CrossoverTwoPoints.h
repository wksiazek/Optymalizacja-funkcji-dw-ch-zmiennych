#pragma once
#include"stdafx.h"
#include"Crossover.h"

class CrossoverTwoPoints : public Crossover
{
public:
	CrossoverTwoPoints() :Crossover() {}
	void randCrossoverPoints(set<int>&crossoverPoints);
	void prepareNewIndywiduals(Population&parentsPopulation, set<int>& crossoverPoints, Individual &temp, Individual &temp2, int a, int b);
};
