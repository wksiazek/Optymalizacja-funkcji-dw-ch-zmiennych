#include"stdafx.h"
#include"ComputingTime.h"

ComputingTime::ComputingTime()
{
	difference = 0;
}

void ComputingTime::start()
{
	time(&startTime);
}

void ComputingTime::stop()
{
	time(&stopTime);
}

void ComputingTime::calculateDifference()
{
	difference = difftime(stopTime, startTime);
}

void ComputingTime::displayDifference()
{
	info = "Computing time: ";
	cout << info << difference << " [s]" << endl;
}

string ComputingTime::getInfo()
{
	return info;
}
