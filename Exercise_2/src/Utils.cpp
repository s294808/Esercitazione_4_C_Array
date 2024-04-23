#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   unsigned int& S,
                   size_t& n,
                   double*& w,
                   double*& r)
{
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    string line;

    getline(file, line);
    istringstream convertS(line.substr(2));
    convertS >> S;

    getline(file, line);
    istringstream convertN(line.substr(2));
    convertN >> n;

    // Skip the line "w;r"
    getline(file, line);

    w = new double[n];
    r = new double[n];

    istringstream convertW;
    istringstream convertR;

    for (unsigned int i = 0; i < n; ++i) {
        getline(file, line);
        size_t pos = line.find(';');
        istringstream convertW(line.substr(0, pos));
        istringstream convertR(line.substr(pos + 1));
        convertW >> w[i];
        convertR >> r[i];
    }

    file.close();

    return true;
}

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}

double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r)
{
    double rateOfReturn = 0;

    for (unsigned int i = 0; i < n; i++)
    {
        rateOfReturn += w[i]*r[i];
    }

    return rateOfReturn;
}

double FinalValue(const unsigned int& S,
                  const double rateOfReturn)
{
    double V;
    V = (1+rateOfReturn)*S;
    return V;
}

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const unsigned int& S,
                  const double& V,
                  const double* const& w,
                  const double* const& r,
                  const double& rateOfReturn)
{
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << "S = " << S << ".00" << " ; "<< "n = " << n << endl;

    file << "w = [ ";
    for (unsigned int i = 0; i < n; i++)
        file<< (i != 0 ? " " : "")<< w[i];
    file<< " ]" << endl;

    file << "r = [ ";
    for (unsigned int i = 0; i < n; i++)
        file<< (i != 0 ? " " : "")<< r[i];
    file<< " ]" << endl;

    file << "Rate of return of the portfolio: " << rateOfReturn << endl;

    file << "V: " << fixed << setprecision(2) << V << endl;

    file.close();

    return true;

}
