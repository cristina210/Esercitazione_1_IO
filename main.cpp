#include <iomanip>
#include <iostream>
#include <fstream>
#include <iomanip>

// definisco la funzione che mappa un punto proveniente dall'intervallo [1,5] a un punto nell'intevallo [-1,2]
double mappa(double a) //per mappare uso la retta y = mx+q con m e q determinati in modo che la retta passi per (-1,1) e (2,5)
{   double m = 3.0/4;
    double q = -7.0/4;
    double ris=m*a+q;
    return ris;
}
int main()
{    int N=1000; //valore di N=numero righe i (supposto arbitrario)
    if (N<1 || N>1000) {
        std::cout << "errore con il valore di N";
        return 1;
    }
    std::string NameFile="data.csv";
    std::ifstream fstr(NameFile);
    if (fstr.fail()){
        std::cerr << "file not found";
        return 1;
    }
    std::ofstream fout("result.csv");
    fout << " # Mean" <<std::endl;
    double var;
    double somma=0;
    for (int i = 1; i <= N; i++) {
        fstr >> var;
        double valoreMappato = mappa(var);
        somma = somma + valoreMappato;
        double mean = somma/i ;
        fout << std::scientific << std::setprecision(16) << mean << std::endl;
        }
    fstr.close();
    fout.close();
    return 0;
}
