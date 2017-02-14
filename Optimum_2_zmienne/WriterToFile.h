#pragma once
#include"stdafx.h"
#include"Population.h"

class WriterToFile
{
private:
	fstream theBest;
	fstream theWorst;
public:
	WriterToFile();
	~WriterToFile();

	fstream & getTheBest() { return theBest; }
	fstream & getTheWorst() { return theWorst; }

	//funkcje realizujace zapis do pliku najlepszego i najgorszego osobnika
	Individual theBestIndyvidual(Population &population);
	Individual theWorstIndyvidual(Population &population);
};