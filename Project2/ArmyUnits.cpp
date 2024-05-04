#include "ArmyUnits.h"


//Constructors of ArmyUnit
ArmyUnit::ArmyUnit(int ID, UnitType type, int Tj, int Health, int Power, int atkCapacity) {
	this->ID = new int(ID); 
	this->type = type;
	this->Tj = new int(Tj);
	this->Health = new int(Health); 
	this->Power = new int(Power); 
	this->atkCapacity = new int(atkCapacity);
};
ArmyUnit::ArmyUnit(Data* data, UnitType type) {
	this->ID = new int(data->ID);
	this->type = type;
	this->Tj = new int(data->Tj);
	this->Health = new int(data->Health);
	this->Power = new int(data->Power);
	this->atkCapacity = new int(data->atkCapacity);
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
const UnitType ArmyUnit::getType() {
	return type;
}
int ArmyUnit::getPower() {
	return *Power;
}
int ArmyUnit::getAtkCapacity() {
	return *atkCapacity;
}

//Constructors of Army and Units

earthArmy::earthArmy() {
	Soldiers=new Queue<earthSoldier*>;
	Tanks= new Stack<earthTank*>;
	Gunnery = new pQueue<earthGunnery*>;
}
alienArmy::alienArmy() {
	Soldiers = new Queue<alienSoldier*>;
	Monsters = new Array<alienMonster*>(100);
	Drones = new dQueue<alienDrone*>;
}

earthSoldier::earthSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthSoldier, Tj, Health, Power, atkCapacity) {};
earthGunnery::earthGunnery(int ID, int Tj, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthGunnery, Tj, Health, Power, atkCapacity) {};
earthTank::earthTank(int ID, int Tj, int Health, int Power, int atkCapacity):ArmyUnit(ID, EarthTank, Tj, Health, Power, atkCapacity) {}

earthSoldier::earthSoldier(Data* data) :ArmyUnit(data,EarthSoldier) {}
earthGunnery::earthGunnery(Data* data) :ArmyUnit(data,EarthGunnery) {}
earthTank::earthTank(Data* data) :ArmyUnit(data, EarthTank) {}

alienSoldier::alienSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienSoldier, Tj, Health, Power, atkCapacity) {};
alienMonster::alienMonster(int ID, int Tj, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienMonster, Tj, Health, Power, atkCapacity) {};
alienDrone::alienDrone(int ID, int Tj, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienDrone, Tj, Health, Power, atkCapacity) {};

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

	delete Soldiers;
	delete Tanks;
	delete Gunnery;
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
void earthArmy::addSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) {
	earthSoldier* temp = new earthSoldier(ID, Tj, Health, Power, atkCapacity);
	Soldiers->enqueue(temp);
}
void earthArmy::addGunnery(int ID, int Tj, int Health, int Power, int atkCapacity) {
	earthGunnery* temp = new earthGunnery(ID, Tj, Health, Power, atkCapacity);
	Gunnery->enqueue(temp, Health + Power);
}
void earthArmy::addTank(int ID, int Tj, int Health, int Power, int atkCapacity) {
	earthTank* temp = new earthTank(ID, Tj, Health, Power, atkCapacity);
	Tanks->push(temp);
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

//Adders
void alienArmy::addSoldier(int ID, int Tj, int Health, int Power, int atkCapacity) {
	alienSoldier* temp = new alienSoldier(ID, Tj, Health, Power, atkCapacity);
	Soldiers->enqueue(temp);
}
void alienArmy::addMonster(int ID, int Tj, int Health, int Power, int atkCapacity) {
	alienMonster* temp = new alienMonster(ID, Tj, Health, Power, atkCapacity);
	Monsters->insert(temp);
}
void alienArmy::addDrone(int ID, int Tj, int Health, int Power, int atkCapacity) {
	alienDrone* temp = new alienDrone(ID, Tj, Health, Power, atkCapacity);
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


//Attack
void earthSoldier::attack(Army* army) {

}

void earthGunnery::attack(Army* army)  {

}

void earthTank::attack(Army* army)  {

}

void alienSoldier::attack(Army* army) {

}

void alienDrone::attack(Army* army) {

}

void alienMonster::attack(Army* army) {

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