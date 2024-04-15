#pragma once
#include "ArmyUnits.h"
#include "Input.h"

class Game {
private:
	const Queue<ArmyUnit*>* killedList;
	const earthArmy* EA;
	const alienArmy* AA;
	const Input* inputData;
public:
	Game();
	void go();
	
	void testCode();


};