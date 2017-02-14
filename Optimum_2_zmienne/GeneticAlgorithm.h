#pragma once
#include"stdafx.h"
#include"Factory.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	~GeneticAlgorithm();

	//realizacja operatora inwersji -(przecinamy w dwoch miejsach i to co w srodku odwracamy)
	void inversion();

	//wlasciwy algorytm genetyczny
	void geneticLoop();

	//strategia elitarna
	void elitism(Population&population);

	//gettery
	Population& getPopulation() { return population; }
	Population& getParentsPopulation() { return parentsPopulation; }
	WriterToFile* getWriter() { return writer; }

private:
	Population population;
	Population parentsPopulation;
	Factory factory;
	Crossover *crossover = nullptr;
	Selection *selection = nullptr;
	Mutation *mutation = nullptr;
	WriterToFile *writer = nullptr;
};
