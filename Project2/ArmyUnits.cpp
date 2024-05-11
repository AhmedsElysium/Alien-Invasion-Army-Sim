#include "ArmyUnits.h"
#include "Game.h"

//Constructors of ArmyUnit
ArmyUnit::ArmyUnit(int ID, UnitType type, int* TimeStep, int Health, int Power, int atkCapacity) {
	this->ID = new int(ID); 
	this->type = type;
	this->TimeStep = TimeStep;
	this->Tj = new int(*TimeStep);
	this->Ta = new int(0);
	this->Td = new int(0);
	this->Health = new int(Health); 
	this->Power = new int(Power); 
	this->atkCapacity = new int(atkCapacity);

	this->initialHealth = Health;
};
ArmyUnit::ArmyUnit(Data* data, UnitType type) {
	this->ID = new int(data->ID);
	this->type = type;
	this->TimeStep = data->TimeStep;
	this->Tj = new int(*TimeStep);
	this->Ta = new int(0);
	this->Td = new int(0);
	this->Health = new int(data->Health);
	this->Power = new int(data->Power);
	this->atkCapacity = new int(data->atkCapacity);

	this->initialHealth = data->Health;
};

//Destructor of ArmyUnit
ArmyUnit::~ArmyUnit() {
	delete ID;
	delete Tj;
	delete Health;
	delete Power;
	delete atkCapacity;
}

//Getters of ArmyUnit
int* ArmyUnit::getHealth() {
	return Health;
}
int ArmyUnit::getID() {
	return *ID;
}
const int ArmyUnit::getTj(){
	return *Tj;
}
int* ArmyUnit::getTa() {
	return this->Ta;
}
int* ArmyUnit::getTd() {
	return this->Td;
}
const UnitType ArmyUnit::getType() {
	return type;
}
int ArmyUnit::getPower() {
	return *Power;
}
int ArmyUnit::getAtkCapacity() {
	return *atkCapacity;
}
int ArmyUnit::getInitialHealth() {
	return initialHealth;
}

//Army Class and Getters
Army::Army(Game* game) {
	this->gamePtr = game;
}
Game* Army::getGame() {
	return this->gamePtr;
}

//Constructors of Army and Units
earthArmy::earthArmy(Game* game) :Army(game) {
	Soldiers=new Queue<earthSoldier*>;
	Tanks= new Stack<earthTank*>;
	Gunnery = new pQueue<earthGunnery*>;
	Healers = new Stack<earthHealer*>;
}
alienArmy::alienArmy(Game* game) :Army(game) {
	Soldiers = new Queue<alienSoldier*>;
	Monsters = new Array<alienMonster*>(100);
	Drones = new dQueue<alienDrone*>;
}

earthSoldier::earthSoldier(int ID, int* TimeStep, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthSoldier, TimeStep, Health, Power, atkCapacity) {}
earthGunnery::earthGunnery(int ID, int* TimeStep, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthGunnery, TimeStep, Health, Power, atkCapacity) {}
earthTank::earthTank(int ID, int* TimeStep, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthTank, TimeStep, Health, Power, atkCapacity) {}
earthHealer::earthHealer(int ID, int* TimeStep, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthHealer, TimeStep, Health, Power, atkCapacity) {}

earthSoldier::earthSoldier(Data* data) :ArmyUnit(data,EarthSoldier) {}
earthGunnery::earthGunnery(Data* data) :ArmyUnit(data,EarthGunnery) {}
earthTank::earthTank(Data* data) :ArmyUnit(data, EarthTank) {}
earthHealer::earthHealer(Data* data) :ArmyUnit(data, EarthHealer) {}

alienSoldier::alienSoldier(int ID, int* TimeStep, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienSoldier, TimeStep, Health, Power, atkCapacity) {}
alienMonster::alienMonster(int ID, int* TimeStep, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienMonster, TimeStep, Health, Power, atkCapacity) {}
alienDrone::alienDrone(int ID, int* TimeStep, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienDrone, TimeStep, Health, Power, atkCapacity) {}

alienSoldier::alienSoldier(Data* data) :ArmyUnit(data,AlienSoldier) {}
alienMonster::alienMonster(Data* data) :ArmyUnit(data, AlienMonster) {}
alienDrone::alienDrone(Data* data) :ArmyUnit(data, AlienDrone) {}

//Destructors of Army and Units
earthArmy::~earthArmy() {
	earthSoldier* temp;
	while (Soldiers->dequeue(temp)) {
		delete temp;
	};

	earthTank* temp2;
	while (Tanks->pop(temp2)) {
		delete temp2;
	};

	earthGunnery* temp3;
	while (Gunnery->dequeue(temp3)) {
		delete temp3;
	};
	earthHealer* temp4;
	while (Healers->pop(temp4)) {
		delete temp4;
	};

	delete Soldiers;
	delete Tanks;
	delete Gunnery;
	delete Healers;
}
alienArmy::~alienArmy() {
	alienSoldier* temp;
	while (Soldiers->dequeue(temp)) {
		delete temp;
	};

	alienMonster* temp2;
	while (Monsters->remove(temp2)) {
		delete temp2;
	};

	alienDrone* temp3;
	while (Drones->popHead(temp3)) {
		delete temp3;
	};

	delete Soldiers;
	delete Monsters;
	delete Drones;
}



//Adders
void earthArmy::addSoldier(int ID, int* TimeStep, int Health, int Power, int atkCapacity) {
	earthSoldier* temp = new earthSoldier(ID, TimeStep, Health, Power, atkCapacity);
	Soldiers->enqueue(temp);
}
void earthArmy::addGunnery(int ID, int* TimeStep, int Health, int Power, int atkCapacity) {
	earthGunnery* temp = new earthGunnery(ID, TimeStep, Health, Power, atkCapacity);
	Gunnery->enqueue(temp, Health + Power);
}
void earthArmy::addTank(int ID, int* TimeStep, int Health, int Power, int atkCapacity) {
	earthTank* temp = new earthTank(ID, TimeStep, Health, Power, atkCapacity);
	Tanks->push(temp);
}
void earthArmy::addHealer(int ID, int* TimeStep, int Health, int Power, int atkCapacity) {
	earthHealer* temp = new earthHealer(ID, TimeStep, Health, Power, atkCapacity);
	Healers->push(temp);
}

void earthArmy::addSoldier(earthSoldier* Unit) {

	Soldiers->enqueue(Unit);
}
void earthArmy::addGunnery(earthGunnery* Unit) {

	Gunnery->enqueue(Unit, *Unit->getHealth() + Unit->getPower());
}
void earthArmy::addTank(earthTank* Unit) {

	Tanks->push(Unit);
}
void earthArmy::addHealer(earthHealer* Unit) {

	Healers->push(Unit);
}

//Getters
Queue<earthSoldier*>* earthArmy::getSoldiers() {
	return Soldiers;
}
Stack<earthTank*>* earthArmy::getTanks() {
	return Tanks;
}
pQueue<earthGunnery*>* earthArmy::getGunnery() {
	return Gunnery;
}
Stack<earthHealer*>* earthArmy::getHealers() {
	return Healers;
}

//Adders
void alienArmy::addSoldier(int ID, int* TimeStep, int Health, int Power, int atkCapacity) {
	alienSoldier* temp = new alienSoldier(ID, TimeStep, Health, Power, atkCapacity);
	Soldiers->enqueue(temp);
}
void alienArmy::addMonster(int ID, int* TimeStep, int Health, int Power, int atkCapacity) {
	alienMonster* temp = new alienMonster(ID, TimeStep, Health, Power, atkCapacity);
	Monsters->insert(temp);
}
void alienArmy::addDrone(int ID, int* TimeStep, int Health, int Power, int atkCapacity) {
	alienDrone* temp = new alienDrone(ID, TimeStep, Health, Power, atkCapacity);
	Drones->pushRear(temp);
}

void alienArmy::addSoldier(alienSoldier* Unit) {

	Soldiers->enqueue(Unit);
}
void alienArmy::addMonster(alienMonster* Unit) {
	Monsters->insert(Unit);
}
void alienArmy::addDrone(alienDrone* Unit) {

	Drones->pushRear(Unit);
}


//Getters
Queue<alienSoldier*>* alienArmy::getSoldiers() {
	return Soldiers;
}
Array<alienMonster*>* alienArmy::getMonsters() {
	return Monsters;
}
dQueue<alienDrone*>* alienArmy::getDrones() {
	return Drones;
}


//Earth Attacks
void earthSoldier::attack(Army* army) {
	alienArmy* armyPtr=dynamic_cast <alienArmy*>(army);
	if (!armyPtr) throw ("armyPtr is invalid");
	



}

void earthGunnery::attack(Army* army)  {
	alienArmy* armyPtr = dynamic_cast <alienArmy*>(army);
	if (!armyPtr) return;
}

void earthTank::attack(Army* army)  {
	alienArmy* armyPtr = dynamic_cast <alienArmy*>(army);
	if (!armyPtr) return;
}

void earthHealer::attack(Army* army) {

}


//Alien Attacks
void alienSoldier::attack(Army* army) {
	earthArmy* armyPtr = dynamic_cast <earthArmy*>(army);
	if (!armyPtr) return;
}

void alienDrone::attack(Army* army) {
	earthArmy* armyPtr = dynamic_cast <earthArmy*>(army);
	if (!armyPtr) return;
}

void alienMonster::attack(Army* army) {
	earthArmy* armyPtr = dynamic_cast <earthArmy*>(army);
	if (!armyPtr) return;
}


//Health Checkers
bool earthArmy::CheckUnitHealth(ArmyUnit* Unit) {
	if (*Unit->getHealth() >= 0.20 * Unit->getInitialHealth()) {
		return true;
	}
	else if (*Unit->getHealth() > 0) {
		//If Gunnery send back
		if (Unit->getType() == EarthGunnery) {
			return true;
		}
		//Else if soldier or tank send to unit maintenance
		else {
			//send to unit maintenance here
			return false;
		}
	}
	else {
		*Unit->getTd() = this->getGame()->getTimeStep();
		this->getGame()->getKilledList()->enqueue(Unit);
		return false;
	}
}

bool alienArmy::CheckUnitHealth(ArmyUnit* Unit) {
	if (*Unit->getHealth() >0) {
		return true;
	}
	else {
		*Unit->getTd() = this->getGame()->getTimeStep();
		this->getGame()->getKilledList()->enqueue(Unit);
		return false;
	}
}


//Printers

void earthArmy::printSoldiers() {
	// Print status of earth soldiers

	Queue<earthSoldier*> tempEarthSoldiers; // Temporary queue to store elements

	while (!Soldiers->isEmpty()) {
		earthSoldier* es = nullptr;
		if (Soldiers->dequeue(es)) {
			cout << "Earth Soldier " << es->getID() << ": Health: " << *(es->getHealth()) << ", Power: " << es->getPower() << ", Attack Capacity: " << es->getAtkCapacity() << endl;
			tempEarthSoldiers.enqueue(es); // Store the element temporarily
		}
	}

	// Re-enqueue the elements back to the original queue
	while (!tempEarthSoldiers.isEmpty()) {
		earthSoldier* esTemp = nullptr;
		tempEarthSoldiers.dequeue(esTemp);
		Soldiers->enqueue(esTemp);
	}
	cout << endl;
}
void earthArmy::printTanks() {

	// Print status of earth tanks
	Stack<earthTank*> tempEarthTanks; // Temporary stack to store elements
	earthTank* et = nullptr;
	while (!Tanks->isEmpty()) {
		if (Tanks->pop(et)) {
			cout << "Earth Tank " << et->getID() << ": Health: " << *(et->getHealth()) << ", Power: " << et->getPower() << ", Attack Capacity: " << et->getAtkCapacity() << endl;
			tempEarthTanks.push(et); // Store the element temporarily
		}
	}
	cout << endl;


	// Re-push the elements back to the original stack
	while (!tempEarthTanks.isEmpty()) {
		earthTank* etTemp = nullptr;
		tempEarthTanks.pop(etTemp);
		Tanks->push(etTemp);
	}
}
void earthArmy::printGunnery() {
	// Print status of earth gunnery
	pQueue<earthGunnery*> tempEarthGunnery; // Temporary priority queue to store elements
	while (!Gunnery->isEmpty()) {
		earthGunnery* eg = nullptr;
		if (Gunnery->dequeue(eg)) {
			cout << "Earth Gunnery " << eg->getID() << ": Health: " << *(eg->getHealth()) << ", Power: " << eg->getPower() << ", Attack Capacity: " << eg->getAtkCapacity() << endl;
			tempEarthGunnery.enqueue(eg, *eg->getHealth() + eg->getPower()); // Store the element temporarily
		}
	}
	cout << endl;

	// Re-enqueue the elements back to the original priority queue
	while (!tempEarthGunnery.isEmpty()) {
		earthGunnery* egTemp = nullptr;
		tempEarthGunnery.dequeue(egTemp);
		Gunnery->enqueue(egTemp, egTemp->getPower() + *egTemp->getHealth());
	}

}
void earthArmy::printHealers()	 {

	// Print status of earth tanks
	Stack<earthHealer*> tempEarthHealList; // Temporary stack to store elements
	earthHealer* ehu = nullptr;
	while (!Healers->isEmpty()) {
		if (Healers->pop(ehu)) {
			cout << "Earth Healer " << ehu->getID() << ": Health: " << *(ehu->getHealth()) << ", Heal Power: " << ehu->getPower() << ", Heal Capacity: " << ehu->getAtkCapacity() << endl;
			tempEarthHealList.push(ehu); // Store the element temporarily
		}
	}
	cout << endl;


	// Re-push the elements back to the original stack
	while (!tempEarthHealList.isEmpty()) {
		earthHealer* ehTemp = nullptr;
		tempEarthHealList.pop(ehTemp);
		Healers->push(ehTemp);
	}
}

void alienArmy::printSoldiers() {
	// Print status of alien soldiers
	Queue<alienSoldier*> tempAlienSoldiers; // Temporary queue to store elements
	while (!Soldiers->isEmpty()) {
		alienSoldier* as = nullptr;
		if (Soldiers->dequeue(as)) {
			cout << "Alien Soldier " << as->getID() << ": Health: " << *(as->getHealth()) << ", Power: " << as->getPower() << ", Attack Capacity: " << as->getAtkCapacity() << endl;
			tempAlienSoldiers.enqueue(as); // Store the element temporarily
		}
	}
	cout << endl;

	// Re-enqueue the elements back to the original queue
	while (!tempAlienSoldiers.isEmpty()) {
		alienSoldier* asTemp = nullptr;
		tempAlienSoldiers.dequeue(asTemp);
		Soldiers->enqueue(asTemp);
	}
}
void alienArmy::printMonsters() {
	// Print status of alien monsters
	alienMonster* am = nullptr;
	for (int i = 0; i < Monsters->getCount(); i++) {
		if (Monsters->peekIndex(am, i)) {
			cout << "Enemy Monster " << am->getID() << ": Health: " << *(am->getHealth()) << ", Power: " << am->getPower() << ", Attack Capacity: " << am->getAtkCapacity() << endl;
		}
	}
	cout << endl;
}
void alienArmy::printDrones() {
	// Print status of alien drones
	dQueue<alienDrone*> tempAlienDrones; // Temporary double-ended queue to store elements
	while (!Drones->isEmpty()) {
		alienDrone* ad = nullptr;
		Drones->popRear(ad);
		if (ad) {
			cout << "Alien Drone " << ad->getID() << ": Health: " << *(ad->getHealth()) << ", Power: " << ad->getPower() << ", Attack Capacity: " << ad->getAtkCapacity() << endl;
			tempAlienDrones.pushRear(ad); // Store the element temporarily
		}
	}
	cout << endl;

	// Re-push the elements back to the original double-ended queue
	while (!tempAlienDrones.isEmpty()) {
		alienDrone* adTemp = nullptr;
		tempAlienDrones.popRear(adTemp);
		Drones->pushRear(adTemp);
	}

	cout << endl;

}