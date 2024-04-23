#pragma once
#include "iostream"

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   unsigned int& S,
                   size_t& n,
                   double*& w,
                   double*& r);

double RateOfReturn(const size_t& n,
                        const double* const& w,
                        const double* const& r);

double FinalValue(const unsigned int& S,
                        const double rateOfReturn);

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const unsigned int& S,
                  const double& V,
                  const double* const& w,
                  const double* const& r,
                  const double& rateOfReturn);

string ArrayToString(const size_t& n,
                     const double* const& v);
