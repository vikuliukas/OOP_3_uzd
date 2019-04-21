#ifndef STUKTURA_H
#define STUKTURA_H
#include <iostream>
#include <vector>
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
	std::vector<int> ndrez;
	double vid, med, galutinis;
};

void irasimas(std::vector<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
void skaitymas(std::string failo_pav, std::vector<mokinys> &mok, int &ilgvardas, int &ilgpavarde);
int tikrinimas(std::string a);
void vidurkis(std::vector<mokinys> &mok);
void mediana(std::vector<mokinys> &mok);
bool pagal_galutini(const mokinys &a, const mokinys &b);
void spausdinimas(std::vector<mokinys> &vargsiukai, std::vector<mokinys> &saunuoliai, int ilgvardas, int ilgpavarde);
void failu_generavimas(int &failu_sk);
void raskMinkstus(std::vector<mokinys> &mok, std::vector<mokinys> &vargsiukai);
void iterpkKietus(std::vector<mokinys> &mok, std::vector<mokinys> &vargsiukai);

#endif