#pragma once
#include "dataStructures.h"
#include "dataTypes.h"

class Army;
class ArmyUnit;
class Game;
class alienArmy;
class earthArmy;

class ArmyUnit{
private:
	const int *TimeStep;
	int *Tj,*Ta,*Td;
	
	int *ID;
	UnitType type;
	int *Health;
	int *Power;
	int *atkCapacity;

	int  initialHealth;
public:

	ArmyUnit(int ID, UnitType type, int* TimeStep, int Health, int Power, int atkCapacity);
	ArmyUnit(Data* data, UnitType type);
	virtual void attack(Army *army)=0;
	int* getHealth();
	int getID();
	const int getTimeStep();
	const int getTj();
	int* getTa();
	int* getTd();
	const UnitType getType() const;
	int getPower();
	int getAtkCapacity();
	int getInitialHealth() const;
	~ArmyUnit();
};

//Earth Units
class earthSoldier: public ArmyUnit {
private:
	int Uj = -1;
	void attackSoldier(alienArmy* army);
	bool *Infected, *Immune;
public:
	earthSoldier(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	earthSoldier(Data* data);
	int* getUj();
	void incrementUj();
	void attack(Army *army) override;
	bool *isInfected();
	bool *isImmune();

};

class earthHealer: public ArmyUnit {
	double* count = 0;
public:
	earthHealer(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	earthHealer(Data* data);
	double counter();
	void attack(Army* army) override;
};

class earthGunnery : public ArmyUnit {
private:
	void attackMonster(alienArmy* army);
	void attackDrones(alienArmy* army);
public:
	earthGunnery(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	earthGunnery(Data* data);
	void attack(Army *army) override;
};

class earthTank: public ArmyUnit {
private:
	int Uj = -1;
	static bool underSiege;
	void attackSoldier(alienArmy* army);
	void attackMonster(alienArmy* army);
public:
	earthTank(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	earthTank(Data* data);
	void attack(Army *army) override;
	bool checkSiege(alienArmy* AA);
	int* getUj();
	void incrementUj();


};

//Alien Units
class alienSoldier : public ArmyUnit {
	void attackSoldier(earthArmy*);
public:
	alienSoldier(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	alienSoldier(Data* data);
	void attack(Army *army) override;

};

class alienMonster : public ArmyUnit {
	void attackSoldier(earthArmy*);
	void attackTank(earthArmy*);

public:
	alienMonster(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	alienMonster(Data* data);
	void attack(Army *army) override;
};

class alienDrone : public ArmyUnit {
	void attackTanks(earthArmy*);
	void attackGunnerys(earthArmy*);
public:
	alienDrone(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	alienDrone(Data* data);
	void attack(Army *army) override;

};


//Armys 
class Army {
private:
	Game* gamePtr;
public:
	Army(Game* game);
	virtual bool CheckUnitHealth(ArmyUnit* Unit) = 0;
	Game* getGame();
	virtual void attack(Army* army) = 0;
};

class earthArmy :public Army {
private:
	Queue<earthSoldier*>* Soldiers;
	Stack<earthTank*>* Tanks;
	pQueue<earthGunnery*>* Gunnery;
	Stack<earthHealer*>* Healers;
	pQueue<earthSoldier*>* UMLs;
	Queue<earthTank*>* UMLt;

	int* Infected;
public:
	earthArmy(Game* game);
	~earthArmy();

	#pragma region "Adders"
	void addSoldier(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	void addTank(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	void addGunnery(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	void addHealer(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	void addUMLs(earthSoldier*, int);
	void addUMLt(earthTank*);
	void addSoldier(earthSoldier* Unit);
	void addTank(earthTank* Unit);
	void addGunnery(earthGunnery* Unit);
	void addHealer(earthHealer* Unit);
	#pragma endregion
	
	#pragma region "Getters"
	Queue<earthSoldier*>* getSoldiers();
	Stack<earthTank*>* getTanks();
	pQueue<earthGunnery*>* getGunnery();
	Stack<earthHealer*>* getHealers();
	pQueue<earthSoldier*>* getUMLs();
	Queue<earthTank*>* getUMLt();

	int* countInfected();
	void infect();
	#pragma endregion

	#pragma region "Attacks"

	void attack(Army* army) override;

	void SoldiersAttack(alienArmy* Enemy);
	void TanksAttack(alienArmy* Enemy);
	void GunneryAttack(alienArmy* Enemy);


	bool CheckUnitHealth(ArmyUnit* Unit) override;
	#pragma endregion 

	#pragma region "Printers"

	void print();
	#pragma region "Print everything functions"
	void printSoldiers();
	void printTanks();
	void printGunnery();
	void printHealers();
	void printUMLs();
	void printUMLt();
	#pragma endregion 

	void printIDs();
	#pragma region "Print IDs"
	void printSoldiersIDs();
	void printTanksIDs();
	void printGunneryIDs();
	void printHealersIDs();
	void printUMLsIDs();
	void printUMLtIDs();
	#pragma endregion 

	#pragma endregion 

};

class alienArmy :public Army {
private:
	Queue<alienSoldier*>* Soldiers;
	Array<alienMonster*>* Monsters;
	dQueue<alienDrone*>* Drones;
public:
	alienArmy(Game* game);
	~alienArmy();

	#pragma region "Adders"

	void addSoldier(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	void addMonster(int ID, int* TimeStep, int Health, int Power, int atkCapacity);
	void addDrone(int ID, int* TimeStep, int Health, int Power, int atkCapacity);

	void addSoldier(alienSoldier* Unit);
	void addMonster(alienMonster* Unit);
	void addDrone(alienDrone* Unit);
	#pragma endregion 

	#pragma region "Getters"
	Queue<alienSoldier*>* getSoldiers();
	Array<alienMonster*>* getMonsters();
	dQueue<alienDrone*>* getDrones();
	#pragma endregion 

	#pragma region "Attacks"

	void attack(Army* army) override;

	void SoldiersAttack(earthArmy* Enemy);
	void MonstersAttack(earthArmy* Enemy);
	void DronesAttack(earthArmy* Enemy);

	bool CheckUnitHealth(ArmyUnit* Unit) override;

	#pragma endregion 

	#pragma region "Printers"
	//Print everything
	void print();
	#pragma region "Print everything functions"
	void printSoldiers();
	void printMonsters();
	void printDrones();
	#pragma endregion
	
	//Print IDs
	void printIDs();
	#pragma region "Print IDs"
	void printSoldiersIDs();
	void printMonstersIDs();
	void printDronesIDs();
	#pragma endregion

	#pragma endregion 

};