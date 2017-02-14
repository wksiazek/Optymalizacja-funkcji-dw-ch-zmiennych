#pragma once
#include"stdafx.h"
#include"Population.h"

class Crossover
{
public:
	Crossover();
	void fillTableCrossover();
	void cross(Population& parentsPopulation, Population& newPopulation);
	virtual void randCrossoverPoints(set<int>& crossoverPoints) = 0; //w zaleznosci od metody odpowiednio 1,2,3 miejsca
	virtual void prepareNewIndywiduals(Population&parentsPopulation, set<int>&crossoverPoints, Individual &temp, Individual &temp2, int a, int b) = 0; //w zaleznosci od ilosci miejsc w ktorych krzyzujemy rozne algorytmy
	void randTwoIndyvidualForCrossovering(Population&parentsPopulation, int &firstIndyvidual, int &secondIndyvidual);
	set<int>& getCrossoverPoints() { return crossoverPoints; }
private:
	vector<int>tableCrossover;
	set<int> crossoverPoints;
};

enum CROSSOVER
{
	CROSSOVER_SINGLE_POINT,
	CROSSOVER_TWO_POINT,
	CROSSOVER_THREE_POINT
};