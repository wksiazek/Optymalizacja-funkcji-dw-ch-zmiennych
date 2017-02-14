#pragma once
#include"stdafx.h"

class Individual
{
private:
	vector<int>genes;
	int representation10X;
	int representation10Y;
	double scaledRepresentation10X;
	double scaledRepresentation10Y;
	double fitnessValue;
	double scaledFitnessValue;
	double probability;
	unsigned int rank;
public:
	//konstruktory
	Individual();

	//funkcja ktorej optimum szukamy
	double fitnessFunction(double x,double y);

	//metody do pracy na pojedyncznym chromosomie
	void displayGenes();
	bool nonUnique(vector<Individual> &tab);
	void calculateRepresentation10();
	void scaleRepresentation10();
	void calculateFitness();
	void scaledFitness(vector<Individual> &tab);

	//gettery
	vector<int>& getGenes() { return genes; }
	int getRepresentation10X() { return representation10X; }
	int getRepresentation10Y() { return representation10Y; }
	double getScaledRepresentation10X() { return scaledRepresentation10X; }
	double getScaledRepresentation10Y() { return scaledRepresentation10Y; }
	double getFitnessValue() { return fitnessValue; }
	double getProbability() { return probability; }
	double getRank() { return rank; }
	double getScaledFitnessValue() { return scaledFitnessValue; }

	//setter
	void setProbability(double probability) { this->probability = probability; }
	void setRank(int rank) { this->rank = rank; }
};

enum SCALE
{
	LINEAR,
	EXPONENTIATION, //potegowe
	SKALOWANIE_OBCINAJACE_TYPU_SIGMA
};
