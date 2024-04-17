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

    // Generate units for both Earth and Alien armies
    ranGen->GenerateEA(EA);
    ranGen->GenerateAA(AA);

    // Simulate battles for 50 time steps
    for (int timestep = 1; timestep <= 50; ++timestep) {
        cout << "Time Step: " << timestep << endl;


        // Generate a number X from 1 to 100 and perform operations accordingly
        int X = rand() % 60 + 1;
        cout << X << endl;
        if (0 < X && X < 10) {
            // Reinsert earth soldiers
            Queue<earthSoldier*>* earthSoldiers = EA->getSoldiers();
            earthSoldier* es = nullptr;
            if(earthSoldiers->dequeue(es))
                earthSoldiers->enqueue(es);
        }
        else if (10 < X && X < 20) {
            // Move earth tank to the killed list
            Stack<earthTank*>* earthTanks = EA->getTanks();
            earthTank* et = nullptr;
            if (earthTanks->pop(et)) {

                ArmyUnit* armyUnit = static_cast<ArmyUnit*>(et);
                killedList->enqueue(armyUnit);
            }

        }
        else if (20 < X && X < 30) {
            // Decrement earth gunnery's health and reinsert
            pQueue<earthGunnery*>* egQueue= EA->getGunnery();
            earthGunnery* eg=nullptr;
            egQueue->dequeue(eg);
            if (eg) {
                *(eg->getHealth()) = *eg->getHealth() - 1;
                egQueue->enqueue(eg, *eg->getHealth() + eg->getPower());
            };
        }
        else if (30 < X && X < 40) {
            // Decrement the health of Alien Soldiers directly
            Queue<alienSoldier*>* alienSoldiers = AA->getSoldiers();
            for (int i = 0; i < 5 && !alienSoldiers->isEmpty(); ++i) {
                alienSoldier* as;
                if (alienSoldiers->dequeue(as)) {
                    // Decrement health
                    int currentHealth = *(as->getHealth());
                    int newHealth = currentHealth - 1; // Decrement health by 1 (adjust as needed)
                    *(as->getHealth()) = newHealth;
                    // Reinsert into the same queue
                    alienSoldiers->enqueue(as);
                }
            }
        }
        else if (40 < X && X < 50) {
            // Reinsert 5 monsters into alien army
            Array<alienMonster*>* alienMonsters = AA->getMonsters();
            for (int i = 0; i < 5; ++i) {
                int numMonsters = alienMonsters->getCount();
                if (numMonsters > 0) {
                    int randomIndex = rand() % numMonsters;
                    alienMonster* selectedMonster = nullptr;
                    alienMonsters->peekIndex(selectedMonster, randomIndex);
                    if(alienMonsters->remove(selectedMonster)){
                    AA->addMonster(selectedMonster);
                    }
                }
            }
        }
        else if (50 < X && X < 60) {
            // Move 6 drones to the killed list
            dQueue<alienDrone*>* alienDrones = AA->getDrones();
            for (int i = 0; i < 3; ++i) {
                alienDrone* adFront = nullptr;
                alienDrone* adRear = nullptr;
                alienDrones->popHead(adFront);
                alienDrones->popRear(adRear);
                ArmyUnit* armyUnitFront = static_cast<ArmyUnit*>(adFront);
                ArmyUnit* armyUnitRear = static_cast<ArmyUnit*>(adRear);
                killedList->enqueue(armyUnitFront);
                killedList->enqueue(armyUnitRear);
            }
        }

        Queue<earthSoldier*>* earthSoldiersStatus = EA->getSoldiers();
        Queue<earthSoldier*> tempEarthSoldiers; // Temporary queue to store elements

        while (!earthSoldiersStatus->isEmpty()) {
            earthSoldier* es = nullptr;
            if (earthSoldiersStatus->dequeue(es)) {
                cout << "Earth Soldier " << es->getID() << ": Health: " << *(es->getHealth()) << ", Power: " << es->getPower() << ", Attack Capacity: " << es->getAtkCapacity() << endl;
                tempEarthSoldiers.enqueue(es); // Store the element temporarily
            }
        }

        // Re-enqueue the elements back to the original queue
        while (!tempEarthSoldiers.isEmpty()) {
            earthSoldier* esTemp = nullptr;
            tempEarthSoldiers.dequeue(esTemp);
            earthSoldiersStatus->enqueue(esTemp);
        }
        cout << endl;

// Print status of earth tanks
        Stack<earthTank*>* earthTanksStatus = EA->getTanks();
        Stack<earthTank*> tempEarthTanks; // Temporary stack to store elements
        while (!earthTanksStatus->isEmpty()) {
            earthTank* et = nullptr;
            if(earthTanksStatus->pop(et)) {
                cout << "Earth Tank " << et->getID() << ": Health: " << *(et->getHealth()) << ", Power: " << et->getPower() << ", Attack Capacity: " << et->getAtkCapacity() << endl;
                tempEarthTanks.push(et); // Store the element temporarily
            }
        }

// Re-push the elements back to the original stack
        while (!tempEarthTanks.isEmpty()) {
            earthTank* etTemp = nullptr;
            tempEarthTanks.pop(etTemp);
            earthTanksStatus->push(etTemp);
        }

// Print status of earth gunnery
        pQueue<earthGunnery*>* earthGunneryStatus = EA->getGunnery();
        pQueue<earthGunnery*> tempEarthGunnery; // Temporary priority queue to store elements
        while (!earthGunneryStatus->isEmpty()) {
            earthGunnery* eg = nullptr;
            if (earthGunneryStatus->dequeue(eg)) {
                cout << "Earth Gunnery " << eg->getID() << ": Health: " << *(eg->getHealth()) << ", Power: " << eg->getPower() << ", Attack Capacity: " << eg->getAtkCapacity() << endl;
                tempEarthGunnery.enqueue(eg, *eg->getHealth() + eg->getPower()); // Store the element temporarily
            }
        }

// Re-enqueue the elements back to the original priority queue
        while (!tempEarthGunnery.isEmpty()) {
            earthGunnery* egTemp = nullptr;
            int priority;
            tempEarthGunnery.dequeue(egTemp);
            earthGunneryStatus->enqueue(egTemp, priority);
        }

// Print status of alien soldiers
        Queue<alienSoldier*>* alienSoldiersStatus = AA->getSoldiers();
        Queue<alienSoldier*> tempAlienSoldiers; // Temporary queue to store elements
        while (!alienSoldiersStatus->isEmpty()) {
            alienSoldier* as = nullptr;
            if(alienSoldiersStatus->dequeue(as)) {
                cout << "Alien Soldier " << as->getID() << ": Health: " << *(as->getHealth()) << ", Power: " << as->getPower() << ", Attack Capacity: " << as->getAtkCapacity() << endl;
                tempAlienSoldiers.enqueue(as); // Store the element temporarily
            }
        }

// Re-enqueue the elements back to the original queue
        while (!tempAlienSoldiers.isEmpty()) {
            alienSoldier* asTemp = nullptr;
            tempAlienSoldiers.dequeue(asTemp);
            alienSoldiersStatus->enqueue(asTemp);
        }

// Print status of alien drones
        dQueue<alienDrone*>* alienDronesStatus = AA->getDrones();
        dQueue<alienDrone*> tempAlienDrones; // Temporary double-ended queue to store elements
        while (!alienDronesStatus->isEmpty()) {
            alienDrone* ad=nullptr;
            alienDronesStatus->popRear(ad);
            if (ad) {
                cout << "Alien Drone " << ad->getID() << ": Health: " << *(ad->getHealth()) << ", Power: " << ad->getPower() << ", Attack Capacity: " << ad->getAtkCapacity() << endl;
                tempAlienDrones.pushRear(ad); // Store the element temporarily
            }
        }

// Re-push the elements back to the original double-ended queue
        while (!tempAlienDrones.isEmpty()) {
            alienDrone* adTemp = nullptr;
            tempAlienDrones.popRear(adTemp);
            alienDronesStatus->pushRear(adTemp);
        }

        cout << endl;

        Array<alienMonster*>* alienMonstersStatus = AA->getMonsters();
        cout << "Enemy Monsters Status:" << endl;
        for (int i = 0; i < alienMonstersStatus->getCount(); ++i) {
            alienMonster* am = nullptr;
            if (alienMonstersStatus->peekIndex(am, i)) {
                cout << "Enemy Monster " << am->getID() << ": Health: " << *(am->getHealth()) << ", Power: " << am->getPower() << ", Attack Capacity: " << am->getAtkCapacity() << endl;
            }
        }
        cout << endl;

    }


    cout << "Killed List:" << endl;
    Queue<ArmyUnit*>* tempKilledList = new Queue<ArmyUnit*>(); // Create a temporary queue to store items

    // Print and re-enqueue items from the killed list
    while (!killedList->isEmpty()) {
        ArmyUnit* unit = nullptr;
        if (killedList->dequeue(unit)) {
            cout << "ID: " << unit->getID() << ", Type: " << unit->getType() << endl;
            tempKilledList->enqueue(unit); // Store the unit temporarily
        }
    }

    // Re-enqueue the units back to the original killed list
    while (!tempKilledList->isEmpty()) {
        ArmyUnit* unitTemp = nullptr;
        tempKilledList->dequeue(unitTemp);
        killedList->enqueue(unitTemp); // Re-enqueue the unit back to the killed list
    }

}
