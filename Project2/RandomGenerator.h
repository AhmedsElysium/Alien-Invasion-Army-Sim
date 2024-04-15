#pragma once
#include "ArmyUnits.h"
#include "Input.h"
#include <cstdlib>
using namespace std;



enum UnitType {
	EarthSoldier,
	EarthGunnery,
	EarthTank,

	AlienSoldier,
	AlienDrone,
	AlienMonster
};

class RandomGenerator
{
	static int Tj;
	Data* data = new Data;
	Input* p;
public:
	RandomGenerator(Input* fd);

	ArmyUnit* Generate(UnitType unit);

	ArmyUnit* GenerateEU();

	ArmyUnit* GenerateAU();

	earthArmy* GenerateEA();

	alienArmy* GenerateAA();

	void AssignEData(UnitType);

	void AssignAData(UnitType);

	~RandomGenerator();
};
