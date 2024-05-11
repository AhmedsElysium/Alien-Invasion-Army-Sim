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
public:
	Game();
	~Game();
	void go();
	void printKilledList();
	void testCode();

	Queue<ArmyUnit*>* getKilledList();
	int getTimeStep();

};