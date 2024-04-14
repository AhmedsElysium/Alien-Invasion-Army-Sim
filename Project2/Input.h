#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Input {
    int N, ES, ET, EG, AS, AM, AD, Prob, E_Power_Range_start, E_Health_Range_start, E_Capacity_Range_start, A_Power_Range_start, A_Health_Range_start, A_Capacity_Range_start,
        E_Power_Range_end, E_Health_Range_end, E_Capacity_Range_end, A_Power_Range_end, A_Health_Range_end, A_Capacity_Range_end;
};

void insert(string& line, string& variable, int(&values)[20], int& index, int& num);
Input* input(string file_name);
