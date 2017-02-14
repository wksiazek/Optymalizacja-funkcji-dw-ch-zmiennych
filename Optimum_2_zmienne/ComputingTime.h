#pragma once
#include"stdafx.h"

class ComputingTime
{
private:
	time_t startTime, stopTime;
	double difference;
	string info;
public:
	ComputingTime();
	void start();
	void stop();
	void calculateDifference();
	void displayDifference();
	string getInfo();
};
#pragma once
