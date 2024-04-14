 #include "Input.h"


void insert(string& line, string& variable, int(&values)[20], int& index, int& num) {
    for (int i = 0; i < line.size(); i++) {
        if (line[i] != ' ' && line[i] != '-') {
            variable += line[i];
        }
        else {
            num = stoi(variable);
            values[index++] = num;
            variable = "";
        }
        if (i == line.size() - 1) {
            num = stoi(variable);
            values[index++] = num;
        }
    }
    variable = "";
}



Input* input(string file_name) {
    string variable = "";
    int values[20];
    int index = 0;
    int num;
    Input* Data = new Input;

    fstream Input_File;
    Input_File.open(file_name, ios::in);
    if (Input_File.is_open()) {
        string line;
        while (getline(Input_File, line)) {
            insert(line, variable, values, index, num);
        }
        Input_File.close();
    }
    else return nullptr;
    int j = 0;
    Data->N = values[j++];
    Data->ES = values[j++];
    Data->ET = values[j++];
    Data->EG = values[j++];
    Data->AS = values[j++];
    Data->AM = values[j++];
    Data->AD = values[j++];
    Data->Prob = values[j++];
    Data->E_Power_Range_start = values[j++];
    Data->E_Power_Range_end = values[j++];
    Data->E_Health_Range_start = values[j++];
    Data->E_Health_Range_end = values[j++];
    Data->E_Capacity_Range_start = values[j++];
    Data->E_Capacity_Range_end = values[j++];
    Data->A_Power_Range_start = values[j++];
    Data->A_Power_Range_end = values[j++];
    Data->A_Health_Range_start = values[j++];
    Data->A_Health_Range_end = values[j++];
    Data->A_Capacity_Range_start = values[j++];
    Data->A_Capacity_Range_end = values[j++];

    return Data;
}



