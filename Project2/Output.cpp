#include "Output.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


string spacing(const string& str, int width = 10) {
    return str + string(width - str.length(), ' ');
}

void writing(Game* game) {
    
    fstream file;
    
    file.open("output.txt", ios::out);
    if (file.is_open()) {
        
        file << spacing("Td", 10)
            << spacing("ID", 10)
            << spacing("Tj", 10)
            << spacing("Df", 10)
            << spacing("Dd", 10)
            << spacing("Db", 10) << endl;

        string Td, ID, Tj, Df, Dd, Db;
        ArmyUnit* temp;

        double destructedES = 0;
        double destructedET = 0;
        double destructedEG = 0;

        int EScount = game->getEarthArmy()->getSoldiers()->getCount();
        int ETcount = game->getEarthArmy()->getTanks()->getCount();
        int EGcount = game->getEarthArmy()->getGunnery()->getCount();

        double Dff = 0;
        double Ddd = 0;
        double Dbb = 0;

        int counterDf = 0;
        int counterDd = 0;
        int counterDb = 0;

        double destructedAS = 0;
        double destructedAM = 0;
        double destructedAD = 0;

        int AScount = game->getAlienArmy()->getSoldiers()->getCount();
        int AMcount = game->getAlienArmy()->getMonsters()->getCount();
        int ADcount = game->getAlienArmy()->getDrones()->getCount();

        double DffA = 0;
        double DddA = 0;
        double DbbA = 0;

        int counterDfA = 0;
        int counterDdA = 0;
        int counterDbA = 0;

        while (game->getKilledList()->dequeue(temp)) {
            if (temp->getType() == EarthTank) { 
                destructedET++;
                Dff += (*temp->getTa() - temp->getTj());
                counterDf++;

                Ddd += (*temp->getTd() - *temp->getTa());
                counterDb++;

                Dbb += (*temp->getTd() - temp->getTj());
                counterDd++;
            }
            else if (temp->getType() == EarthGunnery) { 
                destructedEG++;
                Dff += (*temp->getTa() - temp->getTj());
                counterDf++;

                Ddd += (*temp->getTd() - *temp->getTa());
                counterDb++;

                Dbb += (*temp->getTd() - temp->getTj());
                counterDd++;
            }
            else if (temp->getType() == EarthSoldier) { 
                destructedES++;
                Dff += (*temp->getTa() - temp->getTj());
                counterDf++;

                Ddd += (*temp->getTd() - *temp->getTa());
                counterDb++;

                Dbb += (*temp->getTd() - temp->getTj());
                counterDd++;
            }


            else if (temp->getType() == AlienSoldier) { 
                destructedAS++;
                DffA += (*temp->getTa() - temp->getTj());
                counterDfA++;

                DddA += (*temp->getTd() - *temp->getTa());
                counterDbA++;

                DbbA += (*temp->getTd() - temp->getTj());
                counterDdA++;
            }
            else if (temp->getType() == AlienMonster) { 
                destructedAM++;
                DffA += (*temp->getTa() - temp->getTj());
                counterDfA++;

                DddA += (*temp->getTd() - *temp->getTa());
                counterDbA++;

                DbbA += (*temp->getTd() - temp->getTj());
                counterDdA++;
            }
            else if (temp->getType() == AlienDrone) { 
                destructedAD++;
                DffA += (*temp->getTa() - temp->getTj());
                counterDfA++;

                DddA += (*temp->getTd() - *temp->getTa());
                counterDbA++;

                DbbA += (*temp->getTd() - temp->getTj());
                counterDdA++;
            }

            

            Td = to_string(*temp->getTd());
            ID = to_string(temp->getID());
            Tj = to_string(temp->getTj());
            Df = to_string(*temp->getTa() - temp->getTj());
            Dd = to_string(*temp->getTd() - *temp->getTa());
            Db = to_string(*temp->getTd() - temp->getTj());
            file << spacing(Td, 10) << spacing(ID, 10) << spacing(Tj, 10) << spacing(Df, 10) << spacing(Dd, 10) << spacing(Db, 10) << endl;
        }
        file << "====================================================\n" << endl;
        file<< "Battle Result: " << game->getresult()<<"\n" << endl;
        file << "====================================================\n" << endl;
        file << "For Earth Army:\n" << endl;
        file << "   -   Earth Soldiers total number: " << EScount + destructedES << endl;
        file << "   -   Earth Tanks total number: " << ETcount + destructedET << endl;
        file << "   -   Earth Gunnery total number: " << EGcount + destructedEG << endl;
        file << "   -   Earth units healing % : " << (game->getEarthArmy()->getHealers()->getCount() / (destructedEG + destructedES + destructedET + EGcount + EScount + ETcount)) * 100 << "%" << endl;
        file << "   -   Earth Soldiers destruction % : " << (destructedES / (EScount+ destructedES)) * 100 << "%" << endl;
        file << "   -   Earth Tanks destruction % : " << (destructedET / (ETcount+ destructedET)) * 100 << "%" << endl;
        file << "   -   Earth Gunnery destruction % : " << (destructedEG / (EGcount+ destructedEG)) * 100 << "%" << endl;
        file << "   -   Earth total destruction % : " << ((destructedEG + destructedES + destructedET) / (destructedEG + destructedES + destructedET + EGcount + EScount + ETcount)) * 100 << "%" << endl;
        file << "   -   Average of Df : " << Dff / counterDf << endl;
        file << "   -   Average of Db : " << Dbb / counterDb << endl;
        file << "   -   Average of Dd : " << Ddd / counterDd << endl;
        file << "   -   Df/Db % : " << (Dff / Dbb) * 100 << "%" << endl;
        file << "   -   Dd/Db % : " << (Ddd / Dbb) * 100 << "%\n" << endl;
        file << "====================================================\n" << endl;
        file << "For Alien Army:\n" << endl;
        file << "   -   Alien Soldiers total number: " << AScount + destructedAS << endl;
        file << "   -   Alien Monsters total number: " << AMcount + destructedAM << endl;
        file << "   -   Alien Drones total number: " << ADcount + destructedAD << endl;
        file << "   -   Alien Soldiers destruction % : " << (destructedAS / (AScount+ destructedAS)) * 100 << "%" << endl;
        file << "   -   Alien Monsters destruction % : " << (destructedAM / (AMcount+ destructedAM)) * 100 << "%" << endl;
        file << "   -   Alien Drones destruction % : " << (destructedAD / (ADcount+ destructedAD)) * 100 << "%" << endl;
        file << "   -   Alien total destruction % : " << ((destructedAD + destructedAM + destructedAS) / (destructedAD + destructedAM + destructedAS + AScount + AMcount + ADcount)) * 100 << "%" << endl;
        file << "   -   Average of Df : " << DffA / counterDfA << endl;
        file << "   -   Average of Db : " << DbbA / counterDbA << endl;
        file << "   -   Average of Dd : " << DddA / counterDdA << endl;
        file << "   -   Df/Db % : " << (DffA / DbbA) * 100 << "%" << endl;
        file << "   -   Dd/Db % : " << (DddA / DbbA) * 100 << "%\n" << endl;
        file << "====================================================" << endl;






        file.close();
    }
    else {
        cerr << "Error opening file!" << endl;
    }
}