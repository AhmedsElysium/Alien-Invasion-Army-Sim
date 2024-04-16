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
    // Simulate battles for 50 time steps
    for (int timestep = 1; timestep <= 50; ++timestep) {
        cout << "Time Step: " << timestep << endl;

        // Generate units for both Earth and Alien armies
        ranGen->GenerateEA(EA);
        ranGen->GenerateAA(AA);

        // Generate a number X from 1 to 100 and perform operations accordingly
        int X = rand() % 100 + 1;

        if (0 < X && X < 10) {
            // Reinsert earth soldiers
            Queue<earthSoldier*> earthSoldiers = EA->getSoldiers();
            earthSoldier* es = nullptr;
            if(earthSoldiers.dequeue(es))
            earthSoldiers.enqueue(es);
        }
        else if (10 < X && X < 20) {
            // Move earth tank to the killed list
            Stack<earthTank*> earthTanks = EA->getTanks();
            earthTank* et = nullptr;
            if (earthTanks.pop(et)) {

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
            // Pick 5 Alien Soldiers, decrement their health, and store them temporarily
            Queue<alienSoldier*> alienSoldiers = AA->getSoldiers();
            Queue<alienSoldier*> tempSoldiers;
            for (int i = 0; i < 5 && !alienSoldiers.isEmpty(); ++i) {
                alienSoldier* as;
                alienSoldiers.dequeue(as);
                // Decrement health
                int currentHealth = *(as->getHealth());
                int newHealth = currentHealth - 1; // Decrement health by 1 (adjust as needed)
                *(as->getHealth()) = newHealth;
                // Store temporarily
                tempSoldiers.enqueue(as);
            }

            // Put the temporarily stored soldiers back into their original list
            while (!tempSoldiers.isEmpty()) {
                alienSoldier* asTemp = nullptr;
                tempSoldiers.dequeue(asTemp);
                alienSoldiers.enqueue(asTemp);
            }
        }
        else if (40 < X && X < 50) {
            // Reinsert 5 monsters into alien army
            Array<alienMonster*>* alienMonsters = AA->getMonsters();
            alienMonster* am = nullptr;
            for (int i = 0; i < 5; ++i) {
                if(alienMonsters->remove(am))
                alienMonsters->insert(am);
            }
        }
        else if (50 < X && X < 60) {
            // Move 6 drones to the killed list
            dQueue<alienDrone*> alienDrones = AA->getDrones();
            for (int i = 0; i < 3; ++i) {
                alienDrone* adFront = nullptr;
                alienDrone* adRear = nullptr;
                alienDrones.popHead(adFront);
                alienDrones.popRear(adRear);
                ArmyUnit* armyUnitFront = static_cast<ArmyUnit*>(adFront);
                ArmyUnit* armyUnitRear = static_cast<ArmyUnit*>(adRear);
                killedList->enqueue(armyUnitFront);
                killedList->enqueue(armyUnitRear);
            }
        }

        // Print information except the units fighting part
        cout << "Earth Army Status:" << endl;
        // Print status of earth soldiers
        Queue<earthSoldier*> earthSoldiersStatus = EA->getSoldiers();
        while (!earthSoldiersStatus.isEmpty()) {
            earthSoldier* es = nullptr;
            if(earthSoldiersStatus.dequeue(es))
            cout << "Earth Soldier " << es->getID() << ": Health: " << *(es->getHealth()) << ", Power: " << es->getPower() << ", Attack Capacity: " << es->getAtkCapacity() << endl;
        }
        // Print status of earth tanks
        Stack<earthTank*> earthTanksStatus = EA->getTanks();
        while (!earthTanksStatus.isEmpty()) {
            earthTank* et = nullptr;
            if(earthTanksStatus.pop(et))
            cout << "Earth Tank " << et->getID() << ": Health: " << *(et->getHealth()) << ", Power: " << et->getPower() << ", Attack Capacity: " << et->getAtkCapacity() << endl;
        }
        // Print status of earth gunnery
        pQueue<earthGunnery*>* earthGunneryStatus = EA->getGunneryAddress();
        while (!earthGunneryStatus->isEmpty()) {
            earthGunnery* eg = nullptr;
            if (earthGunneryStatus->dequeue(eg))
            cout << "Earth Gunnery " << eg->getID() << ": Health: " << *(eg->getHealth()) << ", Power: " << eg->getPower() << ", Attack Capacity: " << eg->getAtkCapacity() << endl;
        }

        cout << "Alien Army Status:" << endl;
        // Print status of alien soldiers
        Queue<alienSoldier*> alienSoldiersStatus = AA->getSoldiers();
        while (!alienSoldiersStatus.isEmpty()) {
            alienSoldier* as = nullptr;
            if(alienSoldiersStatus.dequeue(as))
            cout << "Alien Soldier " << as->getID() << ": Health: " << *(as->getHealth()) << ", Power: " << as->getPower() << ", Attack Capacity: " << as->getAtkCapacity() << endl;
        }
        // Print status of alien monsters
        //Array<alienMonster*>* alienMonstersStatus = AA->getMonsters();
        //alienMonstersStatus->print();

        ////this doesn't work, change how it does

        // Print status of alien drones
        dQueue<alienDrone*> alienDronesStatus = AA->getDrones();
        while (!alienDronesStatus.isEmpty()) {
            alienDrone* ad=nullptr;
            alienDronesStatus.popRear(ad);
            if (ad) {
            cout << "Alien Drone " << ad->getID() << ": Health: " << *(ad->getHealth()) << ", Power: " << ad->getPower() << ", Attack Capacity: " << ad->getAtkCapacity() << endl;
            }
        }

        cout << endl;
    }
}