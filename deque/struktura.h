#ifndef STUKTURA_H
#define STUKTURA_H
#include <iostream>
#include <deque>
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
	std::deque<int> ndrez;
	double vid, med, galutinis;
};

void irasimas(std::deque<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
void skaitymas(std::string failo_pav, std::deque<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
int tikrinimas(std::string a);
void vidurkis(std::deque<mokinys> &mok);
void mediana(std::deque<mokinys> &mok);
bool pagal_galutini(const mokinys &a, const mokinys &b);
void spausdinimas(std::deque<mokinys> &vargsiukai, std::deque<mokinys> &saunuoliai, int ilgvardas, int ilgpavarde);
void failu_generavimas(int &failu_sk);
void raskMinkstus(std::deque<mokinys> &mok, std::deque<mokinys> &vargsiukai);
void iterpkKietus(std::deque<mokinys> &mok, std::deque<mokinys> &vargsiukai);

#endif