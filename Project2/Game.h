#pragma once
#include "ArmyUnits.h"
#include "Input.h"
#include "RandomGenerator.h"

class Game {
private:
	const Queue<ArmyUnit*>* killedList;
	const earthArmy* EA;
	const alienArmy* AA;
	const Input* inputData;
	RandomGenerator* ranGen;
public:
	Game();
	void go();
	
	void testCode();


};