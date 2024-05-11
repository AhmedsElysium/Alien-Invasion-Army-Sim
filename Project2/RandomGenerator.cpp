#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(Input* p,int* TimeStep)
{
    this->p = p;
    this->TimeStep = TimeStep;
    srand((unsigned)time(NULL));
}

ArmyUnit* RandomGenerator::Generate(UnitType unit)
{
    if (unit == EarthSoldier)
    {
        AssignEData(unit);
        earthSoldier* S = new earthSoldier(data);
        return S;
    }
    else if (unit == EarthGunnery)
    {
        AssignEData(unit);
        earthGunnery* G = new earthGunnery(data);
        return G;
    }
    else if (unit == EarthTank)
    {
        AssignEData(unit);
        earthTank* T = new earthTank(data);
        return T;
    }
    else if (unit == AlienSoldier)
    {
        AssignAData(unit);
        alienSoldier* S = new alienSoldier(data);
        return S;
    }
    else if (unit == AlienMonster)
    {
        AssignAData(unit);
        alienMonster* M = new alienMonster(data);
        return M;
    }
    else if (unit == AlienDrone)
    {
        AssignAData(unit);
        alienDrone* D = new alienDrone(data);
        return D;
    }
    else return nullptr;
}

ArmyUnit* RandomGenerator::GenerateEU()
{
    int B;
    B =  (rand() % 100) + 1;
    if (B <= p->ES)
    {
         return Generate(EarthSoldier);
    }
    else if (B > p->ES  && B <= p->ES + p->EG)
    {
        return Generate(EarthGunnery);
    }
    else 
    {
        return Generate(EarthTank);
    }
}

ArmyUnit* RandomGenerator::GenerateAU()
{
    int B;
    B = (rand() % 100) + 1;
    if (B <= p->AS)
    {
        return Generate(AlienSoldier);
    }
    else if (B > p->AS  && B <= p->AS + p->AM)
    {
        return Generate(AlienMonster);
    }
    else
    {
        return Generate(AlienDrone);
    }
}

void RandomGenerator::AssignEData(UnitType unit)
{
    static int Eid_index = 1;
    if (Eid_index < 1000)
    {
        data->ID = Eid_index;
        Eid_index++;
    }
    else
        return ;
    data->Health = (rand() % p->A_Health_Range_end) + p->A_Health_Range_start;
    ;
    data->atkCapacity = (rand() % p->A_Capacity_Range_end) + p->A_Capacity_Range_start;
    data->Power = (rand() % p->A_Power_Range_end) + p->A_Power_Range_start;
    data->type = unit;
    data->TimeStep = this->TimeStep;
 
}

void RandomGenerator::AssignAData(UnitType unit)
{
    static int Aid_index = 2000;
    if (Aid_index < 3000)
        data->ID = Aid_index++;
    else
        return ;
    data->Health = (rand() % p->E_Health_Range_end) + p->E_Health_Range_start;
    data->atkCapacity = (rand() % p->E_Capacity_Range_end) + p->E_Capacity_Range_start;
    data->Power = (rand() % p->E_Power_Range_end) + p->E_Power_Range_start;
    //data->type = unit;
    data->TimeStep = TimeStep;
}

void RandomGenerator::GenerateEA(earthArmy* army)
{
    int A;
    A = (rand() % 100) + 1;
    ArmyUnit* unit;
     if (A <= p->Prob)
    {
        for (int i = 0; i < p->N; i++)
        {
             unit = GenerateEU();
            if (unit) {
                if (unit->getType() == EarthSoldier)
                    army->addSoldier(dynamic_cast<earthSoldier*>(unit));
                else if (unit->getType() == EarthGunnery)
                    army->addGunnery(dynamic_cast<earthGunnery*>(unit));
                else
                    army->addTank(dynamic_cast<earthTank*>(unit));
            }
        }
    }
}

void RandomGenerator::GenerateAA(alienArmy* army)
{
    int A;
    A = (rand() % 100) + 1;
    ArmyUnit* unit;
    if (A <= p->Prob)
    {
        for (int i = 0; i < p->N; i++)
        {
            unit = GenerateAU();
            if (unit) {

                if (unit->getType() == AlienSoldier) {
                    army->addSoldier(dynamic_cast<alienSoldier*>(unit));
                }
                else if (unit->getType() == AlienMonster) {
                    army->addMonster(dynamic_cast<alienMonster*>(unit));
                }
                else
                    army->addDrone(dynamic_cast<alienDrone*>(unit));
            }
        }
    }
}

RandomGenerator::~RandomGenerator()
{
    delete data;
}
