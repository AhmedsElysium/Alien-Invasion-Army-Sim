#include "Game.h"


Game::Game() {
    inputData = input("input.txt");
    killedList=new Queue<ArmyUnit*>;
    EA = new earthArmy(this);
    AA=new alienArmy(this);
    TimeStep=new int(0);
    ranGen = new RandomGenerator(inputData,TimeStep);
}

Game::~Game() {
    ArmyUnit* temp;
    while (killedList->dequeue(temp)) {
        delete temp;
    };

    delete killedList;
    delete EA;
    delete AA;
    delete ranGen;
    delete inputData;
    delete TimeStep;
}

Queue<ArmyUnit*>* Game::getKilledList() {
    return killedList;
}
void Game::printKilledList() {
    cout << "[";
    Queue<ArmyUnit*> tempQueue;
    ArmyUnit* tempUnit=nullptr;
    while (killedList->dequeue(tempUnit)) {
        tempQueue.enqueue(tempUnit);
        cout << tempUnit->getID() << " ";
    }
    cout << "]" << endl;
    while (tempQueue.dequeue(tempUnit)) {
        killedList->enqueue(tempUnit);
    }
}

int Game::getTimeStep() {
    return *this->TimeStep;
}

void Game::go() {
    try {

    }
    catch (string s) {
        cout << s;
    }


}

void Game::testCode() {
    // Generate units for both Earth and Alien armies
    // Simulate battles for 50 time steps
    *this->TimeStep = 1;
    int X;
    for (*TimeStep; *TimeStep <= 50; ++*TimeStep) {
        ranGen->GenerateEA(EA);
        ranGen->GenerateAA(AA);
        cout << "Time Step: " << *TimeStep << endl;
        // Generate a number X from 1 to 100 and perform operations accordingly
  
        X = rand() % 100 + 1;
        cout << X << endl;
        if (0 < X && X < 10) {
            // Reinsert earth soldiers
            cout << "Earth soldiers removed then added: " << endl;
            cout << "Earth soldiers before: "<<endl;
            EA->printSoldiers();
            Queue<earthSoldier*>* earthSoldiers = EA->getSoldiers();
            earthSoldier* es = nullptr;
            if(earthSoldiers->dequeue(es))
                earthSoldiers->enqueue(es);
            cout << "Earth soldiers after: " << endl;
            EA->printSoldiers();
        }
        else if (10 < X && X < 20) {
            // Move earth tank to the killed list
            cout << "Move earth tank to the killed list"<<endl;
            cout << "Killed list before:";
            printKilledList();
            Stack<earthTank*>* earthTanks = EA->getTanks();
            earthTank* et = nullptr;
            if (earthTanks->pop(et)) {

                ArmyUnit* armyUnit = static_cast<ArmyUnit*>(et);
                killedList->enqueue(armyUnit);
            }
            cout << "Killed list after:";
            printKilledList();

        }
        else if (20 < X && X < 30) {
            // Decrement earth gunnery's health and reinsert
            cout << "Decrement earth gunnery's health and reinsert" << endl;
            cout << "Gunnery before: " << endl;
            EA->printGunnery();
            pQueue<earthGunnery*>* egQueue= EA->getGunnery();
            earthGunnery* eg=nullptr;
            egQueue->dequeue(eg);
            if (eg) {
                *(eg->getHealth()) *=(0.5);
                egQueue->enqueue(eg, *eg->getHealth() + eg->getPower());
            };
            cout << "Gunnery after: " << endl;
            EA->printGunnery();
        }
        else if (30 < X && X < 40) {
            // Decrement the health of Alien Soldiers directly
            cout << "Decrement the health of Alien Soldiers directly" << endl;
            cout << " Alien Soldiers before: " << endl;
            AA->printSoldiers();
            Queue<alienSoldier*>* alienSoldiers = AA->getSoldiers();
            for (int i = 0; i < 5 && !alienSoldiers->isEmpty(); ++i) {
                alienSoldier* as=nullptr;
                if (alienSoldiers->dequeue(as)) {
                    // Decrement health
                    *(as->getHealth()) *=(0.5) ;
                    // Reinsert into the same queue
                    alienSoldiers->enqueue(as);
                }
            }
            cout << " Alien Soldiers after: " << endl;
            AA->printSoldiers();
        }
        else if (40 < X && X < 50) {
            // Reinsert 5 monsters into alien army
            cout << "Reinsert 5 monsters into alien army" << endl;
            cout << "Alien monsters before:" << endl;
            AA->printMonsters();
            Array<alienMonster*>* alienMonsters = AA->getMonsters();
            Array<alienMonster*> tempArr(5);
                    alienMonster* selectedMonster = nullptr;
            for (int i = 0; i < 5; i++) {
                if (alienMonsters->getCount() > 0) {
                    if (alienMonsters->remove(selectedMonster)) {
                        tempArr.insert(selectedMonster);
                    }
                }
            };
            cout << "IDs of removed monsters: " << endl;
            for (int i=0; i < 5; i++) {
                if (tempArr.remove(selectedMonster)) {
                alienMonsters->insert(selectedMonster);
                cout << selectedMonster->getID() << " ";
            }
            };
            cout << endl<< "Alien monsters after:" << endl;
            AA->printMonsters();
        }
        else if (50 < X && X < 60) {
            // Move 6 drones to the killed list
            cout << "Move 6 drones to the killed list" << endl;
            cout << "Killed list before: ";
            printKilledList();
            dQueue<alienDrone*>* alienDrones = AA->getDrones();
                alienDrone* adFront = nullptr;
                alienDrone* adRear = nullptr;
            for (int i = 0; i < 3; ++i) {
                if (alienDrones->popHead(adFront)) {
                ArmyUnit* armyUnitFront = static_cast<ArmyUnit*>(adFront);
                killedList->enqueue(armyUnitFront);
            }
                if(alienDrones->popRear(adRear)) {

                    ArmyUnit* armyUnitRear = static_cast<ArmyUnit*>(adRear);
                    killedList->enqueue(armyUnitRear);
            }

        }
            cout << "Killed list after: ";
            printKilledList();
            }


        //cout << "Earth Army Status:" << endl;
        //// Print status of earth soldier
        //EA->printSoldiers();

        //// Print status of earth tanks
        //EA->printTanks();

        //// Print status of earth gunnery
        //EA->printGunnery();

        //cout << "Alien Army Status:" << endl;
        //// Print status of alien soldiers
        //AA->printSoldiers();

        //// Print status of alien drones
        //AA->printDrones();

        //// Print status of alien monsters
        //AA->printMonsters();
    }
}
