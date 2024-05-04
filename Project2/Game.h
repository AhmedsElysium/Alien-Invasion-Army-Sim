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
public:
	Game();
	~Game();
	void go();
	void printKilledList();
	void testCode();


};