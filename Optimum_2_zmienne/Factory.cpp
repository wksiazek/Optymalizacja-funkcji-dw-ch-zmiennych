#pragma once
#include"stdafx.h"
#include"Factory.h"

Mutation* Factory::makeMutation()
{
	Mutation *mut = nullptr;
	switch ((Configuration::instance()->getTypeMutation()))
	{
	case 0:
	{
		mut = new MutationSinglePoint;
		break;
	}

	case 1:
	{
		mut = new MutationTwoPoints;
		break;
	}

	case 2:
	{
		mut = new MutationThreePoints;
		break;
	}
	}
	return mut;
}

Crossover* Factory::makeCrossover()
{
	Crossover *crossover = nullptr;
	switch ((Configuration::instance()->getTypeCrossover()))
	{
	case 0:
	{
		crossover = new CrossoverSinglePoint;
		break;
	}

	case 1:
	{
		crossover = new CrossoverTwoPoints;
		break;
	}

	case 2:
	{
		crossover = new CrossoverThreePoints;
		break;
	}

	}
	return crossover;
}

Selection* Factory::makeSelection()
{
	Selection *selection = nullptr;
	switch (Configuration::instance()->getTypeSelection())
	{
	case 0:
	{
		selection = new RouletteWheelSelection;
		break;
	}

	case 1:
	{
		selection = new SelectionTheBest;
		break;
	}

	case 2:
	{
		selection = new SelectionTournament;
		break;
	}

	case 3:
	{
		selection = new SelectionRank;
		break;
	}
	}
	return selection;
}

WriterToFile* Factory::makeWriter()
{
	return (new WriterToFile);
}