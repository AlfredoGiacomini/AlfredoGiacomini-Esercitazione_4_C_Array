#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"

using namespace std;

int main()
{
    string inputFileName = "../data.txt";
    float* vector_r = nullptr;
    float* vector_w = nullptr;
    size_t n = 0;
    float S = 0;

    if (!(genera_valori(inputFileName, n, S, vector_w, vector_r)))
    {
        cerr<< "Qualcosa è andato storto con la creazione delle variabili"<< endl;
        return -1;
    }
    else
    {
        cout<< "Creazione corretta delle variabili"<< endl;
    }
    
    float rate_of_return = funzione_rate_of_return(n, vector_w, vector_r);

    float final_value = funzione_final_value(rate_of_return, S);
    
    string outputFileName = "result.txt";
    if (!(genera_file_output(outputFileName, S, n, vector_w, vector_r, rate_of_return, final_value)))
    {
        cerr<< "Qualcosa è andato storto con la creazione del file di output"<< endl;
        return -1;
    }
    else
    {
        cout<< "Creazione corretta del file di output"<< endl;
    }

    delete[] vector_r;
    delete[] vector_w;

    return 0;
}