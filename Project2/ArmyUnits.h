#pragma once
#include "dataStructures.h"
#include "RandomGenerator.h"



class Army{

};

class ArmyUnit{
private:
	int ID;
	
	int Tj;
	int Health;
	int Power;
	int atkCapacity;
	UnitType type;
public:
	
	ArmyUnit(Data*);
	virtual void attack(Army *army) = 0;
	UnitType getType();
};

class earthSoldier: public ArmyUnit {
public:
	earthSoldier(Data*);
	void attack(Army *army) override;
};

class earthGunnery : public ArmyUnit {
public:
	earthGunnery(Data*);
	void attack(Army *army) override;
};

class earthTank: public ArmyUnit {
public:
	earthTank(Data*);
	void attack(Army *army) override;
};


class earthArmy:public Army {
private:
	 Queue<earthSoldier*> Soldiers;
	 Stack<earthTank*> Tanks;
	 pQueue<earthGunnery*> Gunnery;
public:
	void addSoldier(earthSoldier*);
	void addTank(earthTank*);
	void addGunnery(earthGunnery*);
};



class alienSoldier : public ArmyUnit {
public:
	alienSoldier(Data*);
	void attack(Army *army) override;

};

class alienMonster : public ArmyUnit {
public:
	alienMonster(Data*);
	void attack(Army *army) override;
};

class alienDrone : public ArmyUnit {
public:
	alienDrone(Data*);
	void attack(Army *army) override;

};


class alienArmy :public Army {
private:
	Queue<alienSoldier*> Soldiers;
	Array<alienMonster*> Monsters;
	dQueue<alienDrone*> Drones;
public:
	void addSoldier(alienSoldier*);
	void addMonster(alienMonster*);
	void addDrone(alienDrone*);
};

