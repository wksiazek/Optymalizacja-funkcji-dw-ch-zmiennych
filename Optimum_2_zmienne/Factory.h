#pragma once
#include"stdafx.h"
#include"MutationSinglePoint.h"
#include"MutationTwoPoints.h"
#include"MutationThreePoints.h"
#include"CrossoverOnePoint.h"
#include"CrossoverTwoPoints.h"
#include"CrossoverThreePoint.h"
#include"SelectionTheBest.h"
#include"SelectionRank.h"
#include"SelectionTournament.h"
#include"RouletteWheelSelection.h"
#include"WriterToFile.h"
class Factory
{
public:
	Factory() {}
	Mutation* makeMutation();
	Crossover* makeCrossover();
	Selection *makeSelection();
	WriterToFile* makeWriter();
};
