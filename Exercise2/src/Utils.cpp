#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"



using namespace std;

bool genera_valori( string& nome_file_input,
                    int& n,
                    float& S,
                    float*& vector_w,
                    float*& vector_r 
                    ){

    string riga;
    int i=0;
    int j=0;
    ifstream file_data;
    file_data.open(nome_file_input);
    if (file_data.fail()){
        cerr << "Errore nell'apertura del file" << endl;
        return false;
    }
    while (getline(file_data,riga)){
        if (i==0){
        riga.erase(0, 2);
        stringstream ssS;
        ssS << riga;
        ssS >> S;
        }
        if (i==1){
        riga.erase(0, 2);
        stringstream ssn;
        ssn << riga;
        ssn >> n;
        vector_r = new  float[n];// allocazione dinamica 
        vector_w = new  float[n];
        }
        if (i>2){
        stringstream ss(riga);
        string w_str, r_str;
        getline(ss, w_str, ';');
        getline(ss, r_str);
        stringstream ssw(w_str), ssr(r_str);
        ssw >> vector_w[j];
        ssr >> vector_r[j];
        j++;
        }
        i++;
        }
    if (n!=j){
        file_data.close();
        return false;
    }
    else{
        file_data.close();
        return true;
    }
}

float funzione_rate_of_return(  int& n,
                                float*& vector_w,
                                float*& vector_r 
                    ){
float rate_of_return=0;
int i=0;
for (i=0 ; i<n ;i++){
    rate_of_return += vector_w[i]*vector_r[i];
    }
return rate_of_return;
}

float funzione_final_value( float rate_of_return,
                            float& S
                        ){
float final_value = (( 1 + rate_of_return ) * S);             
return final_value;
}

bool genera_file_output(    string nome_file_output,
                             float& S,
                             int& n,
                             float*& vector_w,
                             float*& vector_r,
                             float rate_of_return,
                             float final_value
                        ){
    ofstream file_output;
    file_output.open(nome_file_output);
    if (file_output.fail())
    {
        return false;
    }
    file_output << "S = "<< fixed << setprecision(2) << S << ", n = "<< n << endl;
    file_output << "vector_w = [ ";
    for (int k = 0; k < n; k++)
    {
        file_output << vector_w[k] << " ";
    }
    file_output << "]" << endl;
    file_output << "vector_r = [ ";
    for (int k = 0; k < n; k++)
    {
        file_output << vector_r[k] << " ";
    }
    file_output << "]" << endl;
    file_output << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate_of_return << endl;
    file_output << "V: " << fixed << setprecision(2) << final_value << endl;
    file_output.close();
    return true;
}



