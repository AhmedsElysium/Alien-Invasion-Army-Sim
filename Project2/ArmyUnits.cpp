#include "ArmyUnits.h"

ArmyUnit::ArmyUnit(int ID, UnitType type, int Tj, int Health, int Power, int atkCapacity) :ID(ID), type(type), Tj(Tj), Health(Health), Power(Power), atkCapacity(atkCapacity) {};

earthSoldier::earthSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthSoldier, Tj, Health, Power, atkCapacity) {};
earthGunnery::earthGunnery(int ID, int Tj, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthGunnery, Tj, Health, Power, atkCapacity) {};
earthTank::earthTank(int ID, int Tj, int Health, int Power, int atkCapacity):ArmyUnit(ID, EarthTank, Tj, Health, Power, atkCapacity) {}

alienSoldier::alienSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienSoldier, Tj, Health, Power, atkCapacity) {};
alienMonster::alienMonster(int ID, int Tj, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienMonster, Tj, Health, Power, atkCapacity) {};
alienDrone::alienDrone(int ID, int Tj, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienDrone, Tj, Health, Power, atkCapacity) {};



void earthArmy::addSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) {
	Soldiers.enqueue(new earthSoldier(ID, Tj, Health, Power, atkCapacity));
}
void earthArmy::addGunnery(int ID, int Tj, int Health, int Power, int atkCapacity) {
	Gunnery.enqueue(new earthGunnery(ID, Tj, Health, Power, atkCapacity), Health + Power);
}
void earthArmy::addTank(int ID, int Tj, int Health, int Power, int atkCapacity) {
	Tanks.push(new earthTank(ID, Tj, Health, Power, atkCapacity));
}

void alienArmy::addSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) {
	Soldiers.enqueue(new alienSoldier(ID, Tj, Health, Power, atkCapacity));
}
void alienArmy::addMonster(int ID, int Tj, int Health, int Power, int atkCapacity) {
	Monsters.insert(new alienMonster(ID, Tj, Health, Power, atkCapacity));
}
void alienArmy::addDrone(int ID, int Tj, int Health, int Power, int atkCapacity) {
	Drones.pushRear(new alienDrone(ID, Tj, Health, Power, atkCapacity));
}