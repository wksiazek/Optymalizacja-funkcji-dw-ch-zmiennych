#pragma once
#include"stdafx.h"
#include"Crossover.h"

class CrossoverSinglePoint : public Crossover
{
public:
	CrossoverSinglePoint() :Crossover() {}
	void randCrossoverPoints(set<int>&crossoverPoints);
	void prepareNewIndywiduals(Population&parentsPopulation, set<int>&crossoverPoints, Individual &temp, Individual &temp2, int a, int b);
};
