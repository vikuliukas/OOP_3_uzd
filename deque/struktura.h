#ifndef STUKTURA_H
#define STUKTURA_H
#include <iostream>
#include <deque>
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
#include <iterator>

struct mokinys
{
	std::string vardas, pavarde;
	int n = 0, egzaminorez;
	std::deque<int> ndrez;
	double vid, med, galutinis;
};

void irasimas(std::deque<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
void skaitymas(std::deque<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
int tikrinimas(std::string a);
void vidurkis(std::deque<mokinys> &mok);
void mediana(std::deque<mokinys> &mok);
void atsitiktinis(std::deque<mokinys> &mok, int i, int k);
bool pagal_galutini(const mokinys &a, const mokinys &b);
bool pagal_pavarde(const mokinys &a, const mokinys &b);
void spausdinimas(std::deque<mokinys> &mok, int ilgvardas, int ilgpavarde);
void failu_generavimas();

#endif