#pragma once
#include"stdafx.h"
#include"Mutation.h"

class MutationThreePoints : public Mutation
{
public:
	MutationThreePoints() :Mutation() {}
	void mutate(Population&population);
	void randomingMutationPoints(set<int>& mutationPoints);
};