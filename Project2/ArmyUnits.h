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

class Army{

};


class ArmyUnit{
private:
	int *ID;
	UnitType type;
	int *Tj;
	int *Health;
	int *Power;
	int *atkCapacity;
public:

	ArmyUnit(int ID, UnitType type, int Tj, int Health, int Power, int atkCapacity);
	virtual void attack(Army *army)=0;
	int* getHealth();
	const int getTj();
	int getPower();
	int getAtkCapacity();


};


class earthSoldier: public ArmyUnit {
public:
	earthSoldier(int ID, int Tj, int Health, int Power, int atkCapacity);
	void attack(Army *army) override;
};

class earthGunnery : public ArmyUnit {
public:
	earthGunnery(int ID, int Tj, int Health, int Power, int atkCapacity);
	void attack(Army *army) override;
};

class earthTank: public ArmyUnit {
public:
	earthTank(int ID, int Tj, int Health, int Power, int atkCapacity);
	void attack(Army *army) override;
};


class earthArmy:public Army {
private:
	 Queue<earthSoldier*> Soldiers;
	 Stack<earthTank*> Tanks;
	 pQueue<earthGunnery*> Gunnery;
public:
	earthArmy();
	void addSoldier(int ID, int Tj, int Health, int Power, int atkCapacity);
	void addTank(int ID, int Tj, int Health, int Power, int atkCapacity);
	void addGunnery(int ID, int Tj, int Health, int Power, int atkCapacity);

	Queue<earthSoldier*> getSoldiers();
	Stack<earthTank*> getTanks();
	pQueue<earthGunnery*> getGunnery();
};



class alienSoldier : public ArmyUnit {
public:
	alienSoldier(int ID, int Tj, int Health, int Power, int atkCapacity);
	void attack(Army *army) override;

};

class alienMonster : public ArmyUnit {
public:
	alienMonster(int ID, int Tj, int Health, int Power, int atkCapacity);
	void attack(Army *army) override;
};

class alienDrone : public ArmyUnit {
public:
	alienDrone(int ID, int Tj, int Health, int Power, int atkCapacity);
	void attack(Army *army) override;

};


class alienArmy :public Army {
private:
	Queue<alienSoldier*> Soldiers;
	Array<alienMonster*>* Monsters;
	dQueue<alienDrone*> Drones;
public:
	alienArmy();
	void addSoldier(int ID, int Tj, int Health, int Power, int atkCapacity);
	void addMonster(int ID, int Tj, int Health, int Power, int atkCapacity);
	void addDrone(int ID, int Tj, int Health, int Power, int atkCapacity);

	Queue<alienSoldier*> getSoldiers();
	Array<alienMonster*>* getMonsters();
	dQueue<alienDrone*> getDrones();
};

