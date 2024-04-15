#include "RandomGenerator.h"

int RandomGenerator::Tj = 0;

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
	arr[i + 1] = arr[high];
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
	Tj++;
	this->p = p;
	sortE[0] = &p->ES;
	sortE[1] = &p->EG;
	sortE[2] = &p->ET;
	sortA[0] = &p->AS;
	sortA[1] = &p->AM;
	sortA[2] = &p->AD;
}

ArmyUnit* RandomGenerator::Generate(int* c)
{
	if (*c == p->ES)
	{
		AssignEData();
		data->Tj = Tj;
		earthSoldier* S = new earthSoldier(data);
		return S;
	}
	else if (*c == p->EG)
	{
		data->Tj = Tj;
		AssignEData();
		earthGunnery* G = new earthGunnery(data);
		return G;
	}
	else if (*c == p->ET)
	{
		data->Tj = Tj;
		AssignEData();
		earthTank* T = new earthTank(data);
		return T;
	}
	else if (*c == p->AS)
	{
		data->Tj = Tj;
		AssignAData();
		alienSoldier* S = new alienSoldier(data);
		return S;
	}
	else if (*c == p->AM)
	{
		data->Tj = Tj;
		AssignAData();
		alienMonster* M = new alienMonster(data);
		return M;
	}
	else if (*c == p->AD)
	{
		data->Tj = Tj;
		AssignAData();
		alienDrone* D = new alienDrone(data);
		return D;
	}
}

ArmyUnit* RandomGenerator::GenerateEA()
{
	Sort(*sortE, 2, 1);
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

ArmyUnit* RandomGenerator::GenerateAA()
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

void RandomGenerator::AssignEData()
{
	static int Eid_index = 1;
	if (Eid_index < 1000)
		data->ID = Eid_index++;
	else
		return;
	data->Health = (rand() % p->A_Health_Range_end) + p->A_Health_Range_start;
	data->atkCapacity = (rand() % p->A_Capacity_Range_end) + p->A_Capacity_Range_start;
	data->Power = (rand() % p->A_Power_Range_end) + p->A_Power_Range_start;
	
}

void RandomGenerator::AssignAData()
{
	static int Aid_index = 2000;
	if (Aid_index < 3000)
		data->ID = Aid_index++;
	else
		return;
	data->Health = (rand() % p->E_Health_Range_end) + p->E_Health_Range_start;
	data->atkCapacity = (rand() % p->E_Capacity_Range_end) + p->E_Capacity_Range_start;
	data->Power = (rand() % p->E_Power_Range_end) + p->E_Power_Range_start;

}