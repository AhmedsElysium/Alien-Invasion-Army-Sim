#pragma once
#include "ArmyUnits.h"
#include "Input.h"
#include "RandomGenerator.h"
#include "Output.h"
using namespace std;

class Game {
private:
	Queue<ArmyUnit*>* killedList;
	pQueue<earthSoldier*>* tempsoldierQ;
	Queue<earthTank*>* temptankQ;
	earthArmy* EA;
	alienArmy* AA;
	Input* inputData;
	RandomGenerator* ranGen;
	int* TimeStep;
	gameMode* Mode;
	gameResult* Result;

public:
	Game();
	~Game();
	void go();
	void printKilledList();
	void testCode();

	void TestingZone();

	Queue<ArmyUnit*>* getKilledList();
	int getTimeStep();
	gameMode getMode();
	earthArmy* getEarthArmy();
	alienArmy* getAlienArmy();
	string getresult();
	int getInfProb();
	pQueue<earthSoldier*>* gettempsoldierQ();
	Queue<earthTank*>* gettemptankQ();

};