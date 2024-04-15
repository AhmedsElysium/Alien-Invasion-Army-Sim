#include "ArmyUnits.h"

ArmyUnit::ArmyUnit(int ID, UnitType type, int Tj, int Health, int Power, int atkCapacity) {
	this->ID = new int(ID); 
	this->type = type;
	this->Tj = new int(Tj);
	this->Health = new int(Health); 
	this->Power = new int(Power); 
	this->atkCapacity = new int(atkCapacity);
};

ArmyUnit::ArmyUnit(Data* data, UnitType type) {
	this->ID = new int(data->ID);
	this->type = type;
	this->Tj = new int(data->Tj);
	this->Health = new int(data->Health);
	this->Power = new int(data->Power);
	this->atkCapacity = new int(data->atkCapacity);
};


int* ArmyUnit::getHealth() {
	return Health;
}
const int ArmyUnit::getTj(){
	return *Tj;
}
const UnitType ArmyUnit::getType() {
	return type;
}
int ArmyUnit::getPower() {
	return *Power;
}
int ArmyUnit::getAtkCapacity() {
	return *atkCapacity;
}

earthArmy::earthArmy() {}
alienArmy::alienArmy() {
	Monsters = new Array<alienMonster*>(100);
}



earthSoldier::earthSoldier(Data* data) :ArmyUnit(data,EarthSoldier) {}
earthGunnery::earthGunnery(Data* data) :ArmyUnit(data,EarthGunnery) {}
earthTank::earthTank(Data* data) :ArmyUnit(data, EarthTank) {}


alienSoldier::alienSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienSoldier, Tj, Health, Power, atkCapacity) {};
alienMonster::alienMonster(int ID, int Tj, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienMonster, Tj, Health, Power, atkCapacity) {};
alienDrone::alienDrone(int ID, int Tj, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienDrone, Tj, Health, Power, atkCapacity) {};

alienSoldier::alienSoldier(Data* data) :ArmyUnit(data,AlienSoldier) {}
alienMonster::alienMonster(Data* data) :ArmyUnit(data, AlienMonster) {}
alienDrone::alienDrone(Data* data) :ArmyUnit(data, AlienDrone) {}




void earthArmy::addSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) {
	earthSoldier* temp = new earthSoldier(ID, Tj, Health, Power, atkCapacity);
	Soldiers.enqueue(temp);
}

void earthArmy::addGunnery(int ID, int Tj, int Health, int Power, int atkCapacity) {
	earthGunnery* temp = new earthGunnery(ID, Tj, Health, Power, atkCapacity);
	Gunnery.enqueue(temp, Health + Power);
}
void earthArmy::addTank(int ID, int Tj, int Health, int Power, int atkCapacity) {
	earthTank* temp = new earthTank(ID, Tj, Health, Power, atkCapacity);
	Tanks.push(temp);
}

void earthArmy::addSoldier(earthSoldier* Unit) {

	Soldiers.enqueue(Unit);
}
void earthArmy::addGunnery(earthGunnery* Unit) {

	Gunnery.enqueue(Unit, *Unit->getHealth() + Unit->getPower());
}
void earthArmy::addTank(earthTank* Unit) {

	Tanks.push(Unit);
}


Queue<earthSoldier*> earthArmy::getSoldiers() {
	return Soldiers;
}
Stack<earthTank*> earthArmy::getTanks() {
	return Tanks;
}
pQueue<earthGunnery*> earthArmy::getGunnery() {
	return Gunnery;
}

void alienArmy::addSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) {
	alienSoldier* temp = new alienSoldier(ID, Tj, Health, Power, atkCapacity);
	Soldiers.enqueue(temp);
}
void alienArmy::addMonster(int ID, int Tj, int Health, int Power, int atkCapacity) {
	alienMonster* temp = new alienMonster(ID, Tj, Health, Power, atkCapacity);
	Monsters->insert(temp);
}
void alienArmy::addDrone(int ID, int Tj, int Health, int Power, int atkCapacity) {
	alienDrone* temp = new alienDrone(ID, Tj, Health, Power, atkCapacity);
	Drones.pushRear(temp);
}

void alienArmy::addSoldier(alienSoldier* Unit) {

	Soldiers.enqueue(Unit);
}
void alienArmy::addMonster(alienMonster* Unit) {
	Monsters->insert(Unit);
}
void alienArmy::addDrone(alienDrone* Unit) {

	Drones.pushRear(Unit);
}



Queue<alienSoldier*> alienArmy::getSoldiers() {
	return Soldiers;
}
Array<alienMonster*>* alienArmy::getMonsters() {
	return Monsters;
}
dQueue<alienDrone*> alienArmy::getDrones() {
	return Drones;
}

void earthSoldier::attack(Army* army) {

}

void earthGunnery::attack(Army* army)  {

}

void earthTank::attack(Army* army)  {

}

void alienSoldier::attack(Army* army) {

}

void alienDrone::attack(Army* army) {

}

void alienMonster::attack(Army* army) {

}




