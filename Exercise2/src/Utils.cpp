#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"



using namespace std;

bool genera_valori( const string& nome_file_input,
                    size_t& n,
                    float& S,
                    float*& vector_w,
                    float*& vector_r 
                    ){

    string riga1,riga2;
    int i=0;
    size_t j=0;
    ifstream file_data;
    file_data.open(nome_file_input);
    if (file_data.fail()){
        cerr << "Errore nell'apertura del file!" << endl;
        return false;
    }

    while (getline(file_data,riga1,';')&&getline(file_data,riga2)){
        if (i==0){
        stringstream ssS(riga2);
        ssS >> S;
        }
        if (i==1){
        stringstream ssn(riga2);
        ssn >> n;
        vector_r = new  float[n];// allocazione dinamica 
        vector_w = new  float[n];
        }
        if (i>2){
        stringstream ssw(riga1);
        stringstream ssr(riga2);
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

float funzione_rate_of_return(  const size_t& n,
                                const float* const& vector_w,
                                const float* const& vector_r
                            ){
float rate_of_return=0;
size_t i=0;
for (i=0 ; i<n ;i++){
    rate_of_return += vector_w[i]*vector_r[i];
    }
return rate_of_return;
}

float funzione_final_value( const float rate_of_return,
                            const float& S
                        ){
float final_value = (( 1 + rate_of_return ) * S);             
return final_value;
}

bool genera_file_output(     const string nome_file_output,
                             const float& S,
                             const size_t& n,
                             const float* const& vector_w,
                             const float* const& vector_r,
                             const float rate_of_return,
                             const float final_value
                        ){
    ofstream file_output;
    file_output.open(nome_file_output);
    if (file_output.fail())
    {
        return false;
    }
    file_output << "S = "<< fixed << setprecision(2) << S << ", n = "<< n << endl;
    file_output << "vector_w = [ ";
    for (size_t k = 0; k < n; k++)
    {
        file_output << vector_w[k] << " ";
    }
    file_output << "]" << endl;
    file_output << "vector_r = [ ";
    for (size_t k = 0; k < n; k++)
    {
        file_output << vector_r[k] << " ";
    }
    file_output << "]" << endl;
    file_output << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate_of_return << endl;
    file_output << "V: " << fixed << setprecision(2) << final_value << endl;
    file_output.close();
    return true;
}