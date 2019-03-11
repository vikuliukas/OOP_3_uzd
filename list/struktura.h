#ifndef STUKTURA_H
#define STUKTURA_H
#include <iostream>
#include <list>
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
	std::list<int> ndrez;
	double vid, med, galutinis;
};

void irasimas(std::list<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
void skaitymas(std::list<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
int tikrinimas(std::string a);
void vidurkis(std::list<mokinys> &mok);
void mediana(std::list<mokinys> &mok);
void atsitiktinis(std::list<mokinys> &mok, std::list<mokinys>::iterator it, int k);
bool pagal_galutini(const mokinys &a, const mokinys &b);
bool pagal_pavarde(const mokinys &a, const mokinys &b);
void spausdinimas(std::list<mokinys> mok, int ilgvardas, int ilgpavarde, std::list<mokinys> &saunuoliai, std::list<mokinys> &vargsiuka);
void failu_generavimas();

#endif