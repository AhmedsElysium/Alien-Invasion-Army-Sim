#pragma once
#include "ArmyUnits.h"
#include "Input.h"
#include <cstdlib>
#include "dataTypes.h"
using namespace std;




class RandomGenerator
{
private:
	static int Tj;
	Data* data = new Data;
	const Input* p;

public:
	RandomGenerator(Input* fd);

	ArmyUnit* Generate(UnitType unit);

	ArmyUnit* GenerateEU();

	ArmyUnit* GenerateAU();

	void GenerateEA(earthArmy* );

	void GenerateAA(alienArmy* );

	void AssignEData(UnitType );

	void AssignAData(UnitType);

	~RandomGenerator();
};
