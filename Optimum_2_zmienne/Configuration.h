#pragma once
#include"stdafx.h"

class Configuration
{
private:
	Configuration() {};
	static Configuration *configuration;
	int precision;//10^-dokladosc 
	int optimization; //MAKSIMUM lub MINIMUM
	double constant; //dodawania przy skalowaniu wyniku
	int numberNumericalInterval; //dziedzina zmiennosci, ilosc przedzialow
	int numberBitsX;
	int numberBitsY;
	int populationSize;
	int numberGeneration;
	int probabilityMutation;
	int probabilityCrossover;
	int probabilityInversion;
	int typeCrossover;
	int typeMutation;
	int percentElite;
	int typeSelection;
	int percentTheBest;//do selekcji najlepszych
	double numberElite; //rodzicow do nowej populacji
	bool uniqueIndyvidual;
	int tournamentSize;
	int typeScaled;
	int power; //potega
	//przedzial x
	double leftBoundaryX;
	double rightBoundaryX;
	double lengthIntervalX;
	//przedzial y
	double leftBoundaryY;
	double rightBoundaryY;
	double lengthIntervalY;
	int typeFunction;
	int sumbits;

public:
	static Configuration* instance()
	{
		if (!configuration)
		{
			configuration = new Configuration;
		}
		return configuration;
	}
	void setParameters(int optimization, int precision, double constant, int numberBitsX, int numberBitsY, int populationSize, int numberGeneration, int probabilityMutation,
		int probabilityCrossover, int probabilityInversion, int percentElite, int typeCrossover, int typeMutation, int typeSelection, bool uniqueIndyvidual,
		int percentTheBest, int tournamentSize, int typeScaled, int power, double leftBoundaryX, double rightBoundaryX, double leftBoundaryY, double rightBoundaryY, int typeFunction);

	//gettery
	int getPrecision() { return precision; }
	int getOptimization() { return optimization; }
	double getConstant() { return constant; }
	int getNumberNumericalInterval() { return numberNumericalInterval; }
	int getNumberBitsX() { return numberBitsX; }
	int getNumberBitsY() { return numberBitsY; }
	int getPopulationSize() { return populationSize; }
	int getNumberGeneration() { return numberGeneration; }
	int getProbabilityMutation() { return probabilityMutation; }
	int getProbabilityCrossover() { return probabilityCrossover; }
	int getProbabilityInversion() { return probabilityInversion; }
	int getTypeCrossover() { return typeCrossover; }
	int getTypeMutation() { return typeMutation; }
	int getPercentElite() { return percentElite; }
	int getTypeSelection() { return typeSelection; }
	int getPercentTheBest() { return percentTheBest; }
	double getNumberElite() { return numberElite; }
	bool getUniqueIndyvidual() { return uniqueIndyvidual; }
	int getTournamentSize() { return tournamentSize; }
	int getTypeScaled() { return typeScaled; }
	int getPower() { return power; }
	int getSumBits() { return sumbits; }
	//lewy przedzial
	double getLeftBoundaryX() { return leftBoundaryX; }
	double getRightBoundaryX() { return rightBoundaryX; }
	double getLengthIntervalX() { return lengthIntervalX; }
	//prawy przedzial
	double getLeftBoundaryY() { return leftBoundaryY; }
	double getRightBoundaryY() { return rightBoundaryY; }
	double getLengthIntervalY() { return lengthIntervalY; }
	int getTypeFunction() { return typeFunction; }
};

enum OPTIMIZATION
{
	MAXIMUM,
	MINIMUM
};