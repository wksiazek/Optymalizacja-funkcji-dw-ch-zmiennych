#pragma once
#include "stdafx.h"
#include "Mutation.h"

Mutation::Mutation()
{
	//wypelnienie tablicy mutacji zerami i jedynkami
	fillTableMutation();
}

void Mutation::fillTableMutation()
{
	for (int i = 0; i < Configuration::instance()->getProbabilityMutation(); i++)
	{
		tableMutation.push_back(1);
	}

	for (int i = Configuration::instance()->getProbabilityMutation(); i <100; i++)
	{
		tableMutation.push_back(0);
	}
}