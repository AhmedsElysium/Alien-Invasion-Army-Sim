#pragma once
#include "ArmyUnits.h"
#include "Input.h"
#include <cstdlib>
using namespace std;



class RandomGenerator
{
	static int Tj;
	Data* data = new Data;
	Input* p;
	int** sortE = new int* [3];
	int** sortA = new int* [3];

public:
	RandomGenerator(Input* fd);

	ArmyUnit* Generate(int* c);

	ArmyUnit* GenerateEA();

	ArmyUnit* GenerateAA();

	void AssignEData();

	void AssignAData();

};
