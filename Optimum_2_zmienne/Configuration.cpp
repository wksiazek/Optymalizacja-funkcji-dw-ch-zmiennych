#pragma once
#include"stdafx.h"
#include"Configuration.h"

Configuration *Configuration::configuration = 0;

void Configuration::setParameters(int optimization, int precision, double constant, int numberBitsX, int numberBitsY, int populationSize,
	int numberGeneration, int probabilityMutation, int probabilityCrossover,
	int probabilityInversion, int percentElite, int typeCrossover, int typeMutation, int typeSelection,
	bool uniqueIndyvidual, int percentTheBest, int tournamentSize, int typeScaled, int power,
	double leftBoundaryX, double rightBoundaryX, double leftBoundaryY, double rightBoundaryY, int typeFunction)
{
	this->optimization = optimization;
	this->precision = precision;
	this->constant = constant;
	//this->ilosc_przedzialow = static_cast<int>(p.dlugosc * pow(10, dokladnosc));
	this->numberBitsX = numberBitsX;
	this->numberBitsY = numberBitsY;
	sumbits = numberBitsX + numberBitsY;
	this->populationSize = populationSize;
	this->numberGeneration = numberGeneration;
	this->probabilityMutation = probabilityMutation;
	this->typeCrossover = typeCrossover;
	this->typeMutation = typeMutation;
	this->uniqueIndyvidual = uniqueIndyvidual;
	this->percentElite = percentElite;
	this->numberElite = (static_cast<double>(percentElite) / 100) * this->populationSize;
	this->probabilityCrossover = probabilityCrossover;
	this->typeSelection = typeSelection;
	this->percentTheBest = percentTheBest;
	this->tournamentSize = tournamentSize;
	this->typeScaled = typeScaled;
	this->power = power;
	this->probabilityInversion = probabilityInversion;
	this->leftBoundaryX = leftBoundaryX;
	this->rightBoundaryX = rightBoundaryX;
	lengthIntervalX = rightBoundaryX - leftBoundaryX;
	this->leftBoundaryY = leftBoundaryY;
	this->rightBoundaryY = rightBoundaryY;
	lengthIntervalY = rightBoundaryY - leftBoundaryY;
	this->typeFunction = typeFunction;
}