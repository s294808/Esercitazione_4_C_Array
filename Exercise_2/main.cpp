#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "Utils.hpp"

using namespace std;

int main()
{
    string inputFileName = "./data.csv";
    size_t n = 0;
    unsigned int S;
    double* w = nullptr;
    double* r = nullptr;

    if(!ImportVectors(inputFileName, S, n, w, r)){

        cerr<< "Something goes wrong with import"<< endl;
        return -1;

    }else{

        cout<< "Import successful" << endl;
        cout<< "S = " << S << ".00" << " ; "<< "n = " << n << endl;
        cout<< "w = " << ArrayToString(n, w) << endl;
        cout<< "r = " << ArrayToString(n, r) << endl;

     }

    double rateOfReturn = RateOfReturn(n, w, r);
    cout << "Rate of return of the portfolio: " << rateOfReturn << endl;

    double V  = FinalValue(S, rateOfReturn);
    cout << "V: " << fixed << setprecision(2) << V << endl;

    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, n, S, V, w, r, rateOfReturn))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }else{
        cout<< "Export successful"<< endl;

    }

    delete[] w;
    delete[] r;

    return 0;
}

