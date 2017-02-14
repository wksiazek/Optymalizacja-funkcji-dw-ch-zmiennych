#pragma once
#include"stdafx.h"
#include"Population.h"

class Mutation
{
public:
	Mutation();
	virtual void mutate(Population &population) = 0;
	void fillTableMutation();
	virtual void randomingMutationPoints(set<int>& mutationPoints)=0;
	vector<int>& getTableMutation() { return tableMutation; }
	set<int> & getMutationPoints() { return mutationPoints; }
private:
	vector<int> tableMutation;
	set<int> mutationPoints;
};

enum MUTATION
{
	MUTATION_SINGLE_POINT,
	MUTATION_TWO_POINT,
	MUTATION_THREE_POINT
};