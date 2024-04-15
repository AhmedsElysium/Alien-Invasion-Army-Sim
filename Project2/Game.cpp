#include "Game.h"


Game::Game() {
	inputData = input("input.txt");
	killedList=new Queue<ArmyUnit*>;
	EA = new earthArmy;
	AA=new alienArmy;
	ranGen = new RandomGenerator(inputData);
}


void Game::go() {

}

void Game::testCode() {



}