#ifndef STUKTURA_H
#define STUKTURA_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include <ctype.h>
#include <sstream>
#include <exception>
#include <numeric>

struct mokinys
{
	std::string vardas, pavarde;
	int n = 0, egzaminorez;
	std::vector<int> ndrez;
	double vid, med, galutinis;
};

void irasimas(std::vector<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
void skaitymas(std::vector<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
int tikrinimas(std::string a);
void vidurkis(std::vector<mokinys> &mok, int i);
void mediana(std::vector<mokinys> &mok, int i);
void atsitiktinis(std::vector<mokinys> &mok, int i, int k);
bool pagal_varda(const mokinys &a, const mokinys &b);
void spausdinimas(std::vector<mokinys> mok, int ilgvardas, int ilgpavarde);
void failu_generavimas();

#endif