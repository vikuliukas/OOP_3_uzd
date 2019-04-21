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

class studentas
{
	private:
	std::string vardas_, pavarde_;
	std::vector<double> ndrez_;
	double egzaminorez_;
	double galutinis_;

	public:
	void vardas ( std::string v ) { vardas_ = v; };
	void pavarde ( std::string p ) { pavarde_ = p; };
	void ndrez ( double n ) { ndrez_.push_back(n); };
	void ndrez_panaikinti_paskutini () { ndrez_.pop_back();};
	void ndrez_isrikiuoti () { std::sort( ndrez_.begin(), ndrez_.end()); };
	void ndrez_istrinti () { ndrez_.clear(); ndrez_.shrink_to_fit(); };
	void egzaminorez ( double n ) { egzaminorez_ = n; }
	void galutinis (double n) { galutinis_ = n; };

	std::string getVardas () const { return vardas_; };
	std::string getPavarde () const { return pavarde_; };
	double getNdrez (int j) { return ndrez_[j]; };
	bool ndrez_ar_tuscias() const { return ndrez_.empty(); };
	int ndrez_dydis () const {return ndrez_.size(); };
	double ndrez_suma () { return accumulate(ndrez_.begin(), ndrez_.end(), 0.0); };
	double getEgzaminorez () const { return egzaminorez_; };
	double getGalutinis () const { return galutinis_; };

	studentas() { vardas_ = ""; pavarde_ = ""; ndrez_ = {}; egzaminorez_ = 0; galutinis_ = 0;};
	~studentas() {};

};

void irasimas(std::vector<studentas> &stud, int &ilgvardas, int &ilgpavarde);
void skaitymas(std::string failo_pav, std::vector<studentas> &stud, int &ilgvardas, int &ilgpavarde);
int tikrinimas(std::string a);
void vidurkis(std::vector<studentas> &stud);
void mediana(std::vector<studentas> &stud);
bool pagal_galutini(const studentas &a, const studentas &b);
void spausdinimas(std::vector<studentas> &stud, int ilgvardas, int ilgpavarde);
void failu_generavimas(int &failu_sk);

#endif