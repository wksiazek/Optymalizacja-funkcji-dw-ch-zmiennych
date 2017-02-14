#pragma once
#include"stdafx.h"
#include"Mutation.h"

class MutationSinglePoint :public Mutation
{
public:
	MutationSinglePoint() :Mutation() {}
	void mutate(Population&population);
	void randomingMutationPoints(set<int>& mutationPoints);
};