#pragma once
enum UnitType {
	EarthSoldier,
	EarthGunnery,
	EarthTank,
	EarthHealer,

	AlienSoldier,
	AlienDrone,
	AlienMonster
};

struct Data {
	int ID, Health, Power, atkCapacity;
	const int* TimeStep;
	UnitType type;
};