#pragma once
#include "ArmyUnits.h"
#include <cstdlib>

using namespace std;

struct Input {
	int N, ES, ET, EG, AS, AM, AD, Prob, E_Power_Range_start, E_Health_Range_start, E_Capacity_Range_start, A_Power_Range_start, A_Health_Range_start, A_Capacity_Range_start,
		E_Power_Range_end, E_Health_Range_end, E_Capacity_Range_end, A_Power_Range_end, A_Health_Range_end, A_Capacity_Range_end;
};

class RandomGenerator
{
	Input* p;
	int** sortE = new int*[3];
	int** sortA = new int* [3];
public:
	RandomGenerator(Input* fd);

	ArmyUnits* Generate(int* c);

	ArmyUnits* GenerateEA();

	ArmyUnits* GenerateAA();

	void AssignData(ArmyUnits* unit);

};

