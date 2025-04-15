#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool genera_valori(  const string& nome_file_input,
                     size_t& n,
                     float& S,
                     float*& vector_w,
                     float*& vector_r);


float funzione_rate_of_return(   const size_t& n,
                                 const float* const& vector_w,
                                 const float* const& vector_r
                                  );

float funzione_final_value(  const float rate_of_return,
                             const float& S);

bool genera_file_output(     const string nome_file_output,
                             const float& S,
                             const size_t& n,
                             const float* const& vector_w,
                             const float* const& vector_r,
                             const float rate_of_return,
                             const float final_value);