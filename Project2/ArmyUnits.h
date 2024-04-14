#pragma once
#include "dataStructures.h"

enum UnitType {
	EarthSoldier,
	EarthGunnery,
	EarthTank,

	AlienSoldier,
	AlienDrone,
	AlienMonster
};

class Army{};


class ArmyUnit{
private:
	int ID;
	UnitType type;
	int Tj;
	int Health;
	int Power;
	int atkCapacity;
public:

	ArmyUnit(int ID, UnitType type, int Tj, int Health, int Power, int atkCapacity);
	virtual void attack(Army army) = 0;



};

class earthSoldier: public ArmyUnit {

};

class earthGunnery : public ArmyUnit {

};

class earthTank: public ArmyUnit {
	
};


class earthArmy:public Army {
private:
	 Queue<earthSoldier*> Soldiers;
	 Stack<earthTank*> Tanks;
	 pQueue<earthGunnery*> Gunnery;


};



class alienSoldier : public ArmyUnit {};

class alienMonster : public ArmyUnit {};

class alienDrone : public ArmyUnit {};


class alienArmy :public Army {
private:
	Queue<alienSoldier*> Soldiers;
	alienMonster** Monsters;
	dQueue<alienDrone> Drones;

};

