#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool genera_valori(  string& nome_file_input,
                     int& n,
                     float& S,
                     float*& vector_w,
                     float*& vector_r);


float funzione_rate_of_return(   int& n,
                                 float*& vector_w,
                                 float*& vector_r );

float funzione_final_value(  float rate_of_return,
                             float& S);

bool genera_file_output(    string nome_file_output,
                             float& S,
                             int& n,
                             float*& vector_w,
                             float*& vector_r,
                             float rate_of_return,
                             float final_value);



