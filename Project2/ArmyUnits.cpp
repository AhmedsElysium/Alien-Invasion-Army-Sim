#include "ArmyUnits.h"
#include "Game.h"

#pragma region "Army Unit Class: Constructors, Destructors, Getters"
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
const int ArmyUnit::getTimeStep() {
	return *TimeStep;
}
const UnitType ArmyUnit::getType() const {
	return type;
}
int ArmyUnit::getPower() {
	return *Power;
}
int ArmyUnit::getAtkCapacity() {
	return *atkCapacity;
}
int ArmyUnit::getInitialHealth() const {
	return initialHealth;
}
#pragma endregion

#pragma region "Parent Army Class: Constuctor, Getter"
//Army Class and Getters
Army::Army(Game* game) {
	this->gamePtr = game;
}
Game* Army::getGame() {
	return this->gamePtr;
}

#pragma endregion

#pragma region "Army Constructors and Destructors"

//Constructors of Army and Units
earthArmy::earthArmy(Game* game) :Army(game) {
	Soldiers=new Queue<earthSoldier*>;
	Tanks= new Stack<earthTank*>;
	Gunnery = new pQueue<earthGunnery*>;
	Healers = new Stack<earthHealer*>;
	UMLs = new pQueue<earthSoldier*>;
	UMLt = new Queue<earthTank*>;
}
alienArmy::alienArmy(Game* game) :Army(game) {
	Soldiers = new Queue<alienSoldier*>;
	Monsters = new Array<alienMonster*>(100);
	Drones = new dQueue<alienDrone*>;
}

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
	earthSoldier* temp5;
	while (UMLs->dequeue(temp5)) {
		delete temp5;
	};
	earthTank* temp6;
	while (UMLt->dequeue(temp6)) {
		delete temp6;
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
#pragma endregion

#pragma region "Army Units Constructors"
//Earth Units
earthSoldier::earthSoldier(int ID, int* TimeStep, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthSoldier, TimeStep, Health, Power, atkCapacity) {}
earthGunnery::earthGunnery(int ID, int* TimeStep, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthGunnery, TimeStep, Health, Power, atkCapacity) {}
earthTank::earthTank(int ID, int* TimeStep, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthTank, TimeStep, Health, Power, atkCapacity) {}
earthHealer::earthHealer(int ID, int* TimeStep, int Health, int Power, int atkCapacity) :ArmyUnit(ID, EarthHealer, TimeStep, Health, Power, atkCapacity) {}

earthSoldier::earthSoldier(Data* data) :ArmyUnit(data,EarthSoldier) {}
earthGunnery::earthGunnery(Data* data) :ArmyUnit(data,EarthGunnery) {}
earthTank::earthTank(Data* data) :ArmyUnit(data, EarthTank) {}
earthHealer::earthHealer(Data* data) :ArmyUnit(data, EarthHealer) {}

bool earthTank::underSiege = false;

//Alien Units
alienSoldier::alienSoldier(int ID, int* TimeStep, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienSoldier, TimeStep, Health, Power, atkCapacity) {}
alienMonster::alienMonster(int ID, int* TimeStep, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienMonster, TimeStep, Health, Power, atkCapacity) {}
alienDrone::alienDrone(int ID, int* TimeStep, int Health, int Power, int atkCapacity) : ArmyUnit(ID, AlienDrone, TimeStep, Health, Power, atkCapacity) {}

alienSoldier::alienSoldier(Data* data) :ArmyUnit(data,AlienSoldier) {}
alienMonster::alienMonster(Data* data) :ArmyUnit(data, AlienMonster) {}
alienDrone::alienDrone(Data* data) :ArmyUnit(data, AlienDrone) {}
#pragma endregion

#pragma region "Army Unit Adders"
//Adders of Earth Units
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

void earthArmy::addUMLs(earthSoldier* s, int pri)
{
	UMLs->enqueue(s, pri);
}

void earthArmy::addUMLt(earthTank* t)
{
	UMLt->enqueue(t);
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

//Adders of Alien Units
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

#pragma endregion

#pragma region "Army Lists Getters"
//Getters of Earth Units
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


//Getters of Alien Units
Queue<alienSoldier*>* alienArmy::getSoldiers() {
	return Soldiers;
}
Array<alienMonster*>* alienArmy::getMonsters() {
	return Monsters;
}
dQueue<alienDrone*>* alienArmy::getDrones() {
	return Drones;
}
#pragma endregion

#pragma region "Earth Army Attacks"
//Earth Army Parent Attack Function
void earthArmy::attack(Army* army) {
	alienArmy* armyPtr = dynamic_cast <alienArmy*>(army);
	if (!armyPtr) throw ("armyPtr is invalid");	

	//attacks
	SoldiersAttack(armyPtr);
	TanksAttack(armyPtr);
	GunneryAttack(armyPtr);
	//heal
	Heal();
}

//Earth Army Base Attack Functions
void earthArmy::SoldiersAttack(alienArmy* Enemy) {
	earthSoldier* soldier;
	if (this->Soldiers->dequeue(soldier)) {
		soldier->attack(Enemy);
		this->Soldiers->enqueue(soldier);
	}
}
void earthArmy::TanksAttack(alienArmy* Enemy) {
	earthTank* tank;
	if (this->Tanks->pop(tank)) {
		tank->attack(Enemy);
		this->Tanks->push(tank);
	};
	return;
}
void earthArmy::GunneryAttack(alienArmy* Enemy) {

}

void earthArmy::Heal() {
	//check health
	earthSoldier* soldier;
	earthTank* tank;
	Queue<earthSoldier*>* tempQ;
	while (!this->getSoldiers()->isEmpty())
	{
		this->getSoldiers()->dequeue(soldier);
		if (this->CheckUnitHealth(soldier))
		{
			tempQ->enqueue(soldier);
		}
	}
	while (!tempQ->isEmpty())
	{
		tempQ->dequeue(soldier);
		this->getSoldiers()->enqueue(soldier);
	}
	while (!this->getTanks()->isEmpty())
	{
		this->getTanks()->pop(tank);
		if (this->CheckUnitHealth(tank))
		{
			tempQ->enqueue(soldier);
		}
	}
	while (!tempQ->isEmpty())
	{
		tempQ->dequeue(soldier);
		this->getSoldiers()->enqueue(soldier);
	}
	//heal units
	if(Healers && UMLs)
	{
		earthHealer* healunit;
		Healers->pop(healunit);
		for(int i = 0; i < healunit->getAtkCapacity(); i++)
		{
			earthSoldier* soldier;
			UMLs->dequeue(soldier);
			Healers->pop(healunit);
			healunit->attack(this);
			if (!UMLs)
			{
				break;
			}
		}
	}

}

#pragma endregion

#pragma region "Earth Unit Attacks"
//Earth Unit Attacks
void earthSoldier::attack(Army* army) {
	alienArmy* armyPtr=dynamic_cast <alienArmy*>(army);
	cout << this->getID() << " shoots [ ";
	for (int i = 0; i < this->getAtkCapacity(); i++) {
		attackSoldier(armyPtr);
	};
	cout << "] " << endl;

}

#pragma region "Earth Soldier attacks"
void earthSoldier::attackSoldier(alienArmy* army){
	alienSoldier* enemy;
	if (army->getSoldiers()->dequeue(enemy)) {
		if (!*enemy->getTa()) *enemy->getTa() = this->getTimeStep();
		
		double damage = ((*this->getHealth()) * (this->getPower()) / 100.0) / sqrt(*enemy->getHealth());
		(*enemy->getHealth()) -= damage;
		cout << " "<<enemy->getID() << ",";
		if (army->CheckUnitHealth(enemy)) {
			army->getSoldiers()->enqueue(enemy);
		};
	}
}

#pragma endregion


void earthGunnery::attack(Army* army)  {
	alienArmy* armyPtr = dynamic_cast <alienArmy*>(army);
	cout << this->getID() << " shoots [ ";
	for (int i = 0; i < this->getAtkCapacity(); i++) {
		if (rand() % 2) {
			this->attackDrones(armyPtr);

		}
		else {
			this->attackMonster(armyPtr);

		};
	};

	cout << "\b" << "] " << endl;

}

#pragma region "Earth Gunnery attacks"
void earthGunnery::attackMonster(alienArmy* army) {
	alienMonster* enemy;
	if (army->getMonsters()->remove(enemy)) {
		if (!*enemy->getTa()) *enemy->getTa() = this->getTimeStep();
		double damage = ((*this->getHealth()) * (this->getPower()) / 100.0) / sqrt(*enemy->getHealth());
		(*enemy->getHealth()) -= damage;
		cout << " " << enemy->getID() << ",";
		if (army->CheckUnitHealth(enemy)) {
			army->getMonsters()->insert(enemy);
		};
	}

}
void earthGunnery::attackDrones(alienArmy* army) {
	alienDrone* enemy1;
	alienDrone* enemy2;
	if (army->getDrones()->popHead(enemy1)) {
		if (!*enemy1->getTa()) *enemy1->getTa() = this->getTimeStep();

		double damage = ((*this->getHealth()) * (this->getPower()) / 100.0) / sqrt(*enemy1->getHealth());
		(*enemy1->getHealth()) -= damage;
		cout << " " << enemy1->getID() << ",";

		if (army->getDrones()->popRear(enemy2)) {
			if (!*enemy2->getTa()) *enemy2->getTa() = this->getTimeStep();
			
			damage = ((*this->getHealth()) * (this->getPower()) / 100.0) / sqrt(*enemy2->getHealth());
			(*enemy2->getHealth()) -= damage;
			cout << " " << enemy2->getID() << ",";

			if (army->CheckUnitHealth(enemy2)) {
				army->getDrones()->pushRear(enemy2);
			};
		};

		if (army->CheckUnitHealth(enemy1)) {
			army->getDrones()->pushHead(enemy1);
		};
	}
}

#pragma endregion


void earthTank::attack(Army* army)  {
	alienArmy* armyPtr = dynamic_cast <alienArmy*>(army);
	cout << this->getID() << " shoots [ ";
	for (int i = 0; i < this->getAtkCapacity(); i++) {
		if (checkSiege(armyPtr) && rand() % 2) {
			this->attackSoldier(armyPtr);

		}
		else {
			this->attackMonster(armyPtr);

		};
	};
	
	cout <<"\b"<< "] " << endl;
}

#pragma region "Earth Tank attacks"
void earthTank::attackSoldier(alienArmy* army) {
	alienSoldier* enemy;
	if (army->getSoldiers()->dequeue(enemy)) {
		if (!*enemy->getTa()) *enemy->getTa() = this->getTimeStep();
		double damage = ((*this->getHealth()) * (this->getPower()) / 100.0) / sqrt(*enemy->getHealth());
		(*enemy->getHealth()) -= damage;
		cout << " "<<enemy->getID() << ",";
		if (army->CheckUnitHealth(enemy)) {
			army->getSoldiers()->enqueue(enemy);
		};
	}
}

void earthTank::attackMonster(alienArmy* army) {
	alienMonster* enemy;
	if (army->getMonsters()->remove(enemy)) {
		if (!*enemy->getTa()) *enemy->getTa() = this->getTimeStep();

		double damage = ((*this->getHealth()) * (this->getPower()) / 100.0) / sqrt(*enemy->getHealth());
		(*enemy->getHealth()) -= damage;
		cout << " " << enemy->getID() << ",";
		if (army->CheckUnitHealth(enemy)) {
			army->getMonsters()->insert(enemy);
		};
	}
}

bool earthTank::checkSiege(alienArmy* AA) {
	earthArmy* EA = AA->getGame()->getEarthArmy();
	if (this->underSiege&& (EA->getSoldiers()->getCount() >= 0.8 * (AA->getSoldiers()->getCount()))) {
		this->underSiege = false;		
	}
	else if (EA->getSoldiers()->getCount() < 0.3 * (AA->getSoldiers()->getCount())) {
		this->underSiege = true;
	};
	return this->underSiege;

}
#pragma endregion


//Earth Unit Heals
void earthHealer::attack(Army* army) {

}

#pragma region "Earth Healer Functions"
//put any healer functions here


#pragma endregion



#pragma endregion

#pragma region "Alien Army Attacks"
//Alien Army Parent Attack Function
void alienArmy::attack(Army* army) {
	earthArmy* armyPtr = dynamic_cast <earthArmy*>(army);
	if (!armyPtr) throw ("armyPtr is invalid");

	//Attacks
	SoldiersAttack(armyPtr);
	MonstersAttack(armyPtr);
	DronesAttack(armyPtr);


}

//Alien Army Base Attack functions
void alienArmy::SoldiersAttack(earthArmy* Enemy) {

}


void alienArmy::MonstersAttack(earthArmy* Enemy) {

}


void alienArmy::DronesAttack(earthArmy* Enemy) {

}


#pragma endregion

#pragma region "Alien Army Unit Attacks"
//Alien Unit Attacks
void alienSoldier::attack(Army* army) {
	earthArmy* armyPtr = dynamic_cast <earthArmy*>(army);
	if (!armyPtr) return;
}

#pragma region "Alien Soldier Attacks"


#pragma endregion


void alienDrone::attack(Army* army) {
	earthArmy* armyPtr = dynamic_cast <earthArmy*>(army);
	if (!armyPtr) return;
}

#pragma region "Alien Drone Attacks"


#pragma endregion


void alienMonster::attack(Army* army) {
	earthArmy* armyPtr = dynamic_cast <earthArmy*>(army);
	if (!armyPtr) return;
}

#pragma region "Alien Monster Attacks"


#pragma endregion



#pragma endregion

#pragma region "Health Checkers"
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
			if (Unit->getType() == EarthTank)
			{
				this->addUMLt(dynamic_cast<earthTank*> (Unit));
			}
			else
			{
				this->addUMLs(dynamic_cast<earthSoldier*> (Unit), 100 - *Unit->getHealth());
			}
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
#pragma endregion 

#pragma region "Printers"
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
#pragma endregion


