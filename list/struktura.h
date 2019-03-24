#ifndef STUKTURA_H
#define STUKTURA_H
#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <chrono>
#include <random>
#include <fstream>
#include <ctype.h>
#include <sstream>
#include <exception>
#include <numeric>
#include <iterator>

struct mokinys
{
	std::string vardas, pavarde;
	int n = 0, egzaminorez;
	std::list<int> ndrez;
	double vid, med, galutinis;
};

void irasimas(std::list<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
void skaitymas(std::list<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
int tikrinimas(std::string a);
void vidurkis(std::list<mokinys> &mok);
void mediana(std::list<mokinys> &mok);
bool pagal_galutini(const mokinys &a, const mokinys &b);
void spausdinimas(std::list<mokinys> &mok, int ilgvardas, int ilgpavarde);
void failu_generavimas(int &failu_sk);

#endif