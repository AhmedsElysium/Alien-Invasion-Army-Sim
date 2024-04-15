#pragma once
#include "ArmyUnits.h"
#include "Input.h"
#include <cstdlib>
using namespace std;





class RandomGenerator
{
	static int Tj;
	Data* data = new Data;
	const Input* p;
public:
	RandomGenerator(const Input* fd);

	ArmyUnit* Generate(UnitType unit);

	ArmyUnit* GenerateEU();

	ArmyUnit* GenerateAU();

	earthArmy* GenerateEA();

	alienArmy* GenerateAA();

	void AssignEData(UnitType);

	void AssignAData(UnitType);

	~RandomGenerator();
};
