// Genetyczny-final.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include"GeneticAlgorithm.h"
#include"ComputingTime.h"

int main()
{
	//uConfigurationnie stalych
	ComputingTime computingTime;
	computingTime.start();
	Configuration::instance()->setParameters(MAXIMUM, 6, 1.0, 18, 15, 100, 100, 15, 70, 10, 20, CROSSOVER_THREE_POINT,
		MUTATION_THREE_POINT, SELECTION_TOURNAMENT, false, 50, 3, 1, 2, -3.0, 3.0, -3.0, 3.0, 1);

	//wybor optimum,dokladnosc, stala, ilosc bitow, poczatkowa populacja, ilosc iteracji,prawdopodobienstwo mutacji,
	//prawdopodobienstwo_krzyzowania,prawdopodobienstwo inwersji,% elitarnych,rodzaj krzyzowania,rodzaj mutacji, 
	//rodzaj selekcji,unikalnosc potomkow, ilosc najlepszych- tylko do selekcji najlepszych,
	//wielkosc turnieju,typ skalowania, potega skalowania potegowego,lewy przedzial, prawy przedzial,lewy przedzial, prawy przedzial,typ funkcji
	GeneticAlgorithm alg;
	alg.geneticLoop();

	computingTime.stop();
	computingTime.calculateDifference();
	computingTime.displayDifference();
	system("pause");
	return 0;
}

