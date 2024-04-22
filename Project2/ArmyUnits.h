#pragma once
#include "dataStructures.h"
#include "dataTypes.h"

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
	ArmyUnit(Data* data, UnitType type);
	virtual void attack(Army *army)=0;
	int* getHealth();
	int getID();
	const int getTj();
	const UnitType getType();
	int getPower();
	int getAtkCapacity();
};


class earthSoldier: public ArmyUnit {
public:
	earthSoldier(int ID, int Tj, int Health, int Power, int atkCapacity);
	earthSoldier(Data* data);
	void attack(Army *army) override;
};

class earthGunnery : public ArmyUnit {
public:
	earthGunnery(int ID, int Tj, int Health, int Power, int atkCapacity);
	earthGunnery(Data* data);
	void attack(Army *army) override;
};

class earthTank: public ArmyUnit {
public:
	earthTank(int ID, int Tj, int Health, int Power, int atkCapacity);
	earthTank(Data* data);
	void attack(Army *army) override;
};


class earthArmy:public Army {
private:
	 Queue<earthSoldier*>* Soldiers;
	 Stack<earthTank*>* Tanks;
	 pQueue<earthGunnery*>* Gunnery;
public:
	earthArmy();
	void addSoldier(int ID, int Tj, int Health, int Power, int atkCapacity);
	void addTank(int ID, int Tj, int Health, int Power, int atkCapacity);
	void addGunnery(int ID, int Tj, int Health, int Power, int atkCapacity);

	void addSoldier(earthSoldier* Unit);
	void addTank(earthTank* Unit);
	void addGunnery(earthGunnery* Unit);


	Queue<earthSoldier*>* getSoldiers();
	Stack<earthTank*>* getTanks();
	pQueue<earthGunnery*>* getGunnery();


	void printSoldiers();
	void printTanks();
	void printGunnery();
};

class alienSoldier : public ArmyUnit {
public:
	alienSoldier(int ID, int Tj, int Health, int Power, int atkCapacity);
	alienSoldier(Data* data);
	void attack(Army *army) override;

};

class alienMonster : public ArmyUnit {
public:
	alienMonster(int ID, int Tj, int Health, int Power, int atkCapacity);
	alienMonster(Data* data);
	void attack(Army *army) override;
};

class alienDrone : public ArmyUnit {
public:
	alienDrone(int ID, int Tj, int Health, int Power, int atkCapacity);
	alienDrone(Data* data);
	void attack(Army *army) override;

};

class alienArmy :public Army {
private:
	Queue<alienSoldier*>* Soldiers;
	Array<alienMonster*>* Monsters;
	dQueue<alienDrone*>* Drones;
public:
	alienArmy();
	void addSoldier(int ID, int Tj, int Health, int Power, int atkCapacity);
	void addMonster(int ID, int Tj, int Health, int Power, int atkCapacity);
	void addDrone(int ID, int Tj, int Health, int Power, int atkCapacity);

	void addSoldier(alienSoldier* Unit);
	void addMonster(alienMonster* Unit);
	void addDrone(alienDrone* Unit);

	Queue<alienSoldier*>* getSoldiers();
	Array<alienMonster*>* getMonsters();
	dQueue<alienDrone*>* getDrones();


	void printSoldiers();
	void printMonsters();
	void printDrones();
};