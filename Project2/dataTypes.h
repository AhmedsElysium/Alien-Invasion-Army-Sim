#pragma once
enum UnitType {
	EarthSoldier,
	EarthGunnery,
	EarthTank,
	EarthHealer,

	AlienSoldier,
	AlienDrone,
	AlienMonster,
	EathHealer
};

struct Data {
	int ID, Health, Power, atkCapacity;
	const int* TimeStep;
	UnitType type;
};

enum gameMode
{
	Interactive_Mode=1,
	Silent_Mode
};