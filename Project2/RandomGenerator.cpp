#include "RandomGenerator.h"

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	int temp;
	for (int j = low;j <= high;j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

void Sort(int arr[], int high, int low)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		Sort(arr, low, pi - 1);
		Sort(arr, pi + 1, high);
	}
}

RandomGenerator::RandomGenerator(Input* p)
{
	this->p = p;
	sortE[0] = &p->ES;
	sortE[1] = &p->EG;
	sortE[2] = &p->ET;
	sortA[0] = &p->AS;
	sortA[1] = &p->AM;
	sortA[2] = &p->AD;
}

ArmyUnits* RandomGenerator::Generate(int* c)
{
	if (*c == p->ES)
	{
		earthSoldier* S = new earthSoldier;
		AssignData(S);
		return S;
	}
	else if (*c == p->EG)
	{
		earthGunnery* G = new earthGunnery;
		AssignData(G);
		return G;
	}
	else if (*c == p->ET)
	{
		earthTank* T = new earthTank;
		AssignData(T);
		return T;
	}
	else if (*c == p->AS)
	{
		alienSoldier* S = new alienSoldier;
		AssignData(S);
		return S;
	}
	else if (*c == p->AM)
	{
		alienMonster* M = new alienMonster;
		AssignData(M);
		return M;
	}
	else if (*c == p->AD)
	{
		alienDrone* D = new alienDrone;
		AssignData(D);
		return D;
	}
}

ArmyUnits* RandomGenerator::GenerateEA()
{
	Sort(*sortE,2, 1);
	int A, B;
	A = (rand() % 100) + 1;
	if (A <= p->Prob)
	{
		B = (rand() % 100) + 1;
		if (B <= *sortE[0])
		{
			return Generate(sortE[0]);
		}
		else if (B <= *sortE[0] + *sortE[1])
		{
			return Generate(sortE[1]);
		}
		else
		{
			return Generate(sortE[2]);
		}	
	}
} 

ArmyUnits* RandomGenerator::GenerateAA()
{
	Sort(*sortA, 2, 1);
	int A, B;
	A = (rand() % 100) + 1;
	if (A <= p->Prob)
	{
		B = (rand() % 100) + 1;
		if (B <= *sortA[0])
		{
			return Generate(sortA[0]);
		}
		else if (B <= *sortA[0] + *sortA[1])
		{
			return Generate(sortA[1]);
		}
		else
		{
			return Generate(sortA[2]);
		}
	}
}

void RandomGenerator::AssignData(ArmyUnits* unit)
{
	
}