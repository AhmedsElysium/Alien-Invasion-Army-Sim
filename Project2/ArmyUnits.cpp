#include "ArmyUnits.h"

ArmyUnit::ArmyUnit(Data* data) :ID(data->ID), type(data->type), Tj(data->Tj), Health(data->Health), Power(data->Power), atkCapacity(data->atkCapacity) {};
UnitType ArmyUnit::getType() { return type; }


earthSoldier::earthSoldier(Data* data) :ArmyUnit(data) {};
earthGunnery::earthGunnery(Data* data) :ArmyUnit(data) {};
earthTank::earthTank(Data* data):ArmyUnit(data) {}

alienSoldier::alienSoldier(Data* data) : ArmyUnit(data) {};
alienMonster::alienMonster(Data* data) : ArmyUnit(data) {};
alienDrone::alienDrone(Data* data) : ArmyUnit(data) {};



void earthArmy::addSoldier(earthSoldier* unit) {
	Soldiers.enqueue(unit);
}
void earthArmy::addGunnery(earthGunnery* unit) {
	Gunnery.enqueue(unit, unit->getPower()+unit->getHealth());
}
void earthArmy::addTank(earthTank* unit) {
	Tanks.push(unit);
}

void alienArmy::addSoldier(alienSoldier* unit) {
	Soldiers.enqueue(unit);
}
void alienArmy::addMonster(alienMonster* unit) {
	Monsters.insert(unit);
}
void alienArmy::addDrone(alienDrone* unit) {
	Drones.pushRear(unit);
}