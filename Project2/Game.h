#pragma once
#include "ArmyUnits.h"
#include "Input.h"
#include "RandomGenerator.h"

class Game {
private:
	Queue<ArmyUnit*>* killedList;
	earthArmy* EA;
	alienArmy* AA;
	Input* inputData;
	RandomGenerator* ranGen;
	int* TimeStep;
	gameMode* Mode;

public:
	Game();
	~Game();
	void go();
	void printKilledList();
	void testCode();
	Queue<ArmyUnit*>* getKilledList();
	int getTimeStep();
	gameMode getMode();
	earthArmy* getEarthArmy();
	alienArmy* getAlienArmy();


};