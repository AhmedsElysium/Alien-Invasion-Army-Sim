#pragma once
enum UnitType {
	EarthSoldier,
	EarthGunnery,
	EarthTank,

	AlienSoldier,
	AlienDrone,
	AlienMonster
};

struct Data {
	int ID, Tj, Health, Power, atkCapacity;
	UnitType type;
};