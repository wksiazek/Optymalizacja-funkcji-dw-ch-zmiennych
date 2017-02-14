#pragma once
#include"stdafx.h"
#include"Crossover.h"

class CrossoverThreePoints : public Crossover
{
public:
	CrossoverThreePoints() :Crossover() {}
	void randCrossoverPoints(set<int>&crossoverPoints);
	void prepareNewIndywiduals(Population&parentsPopulation, set<int>&crossoverPoints, Individual &temp, Individual &temp2, int a, int b);
};