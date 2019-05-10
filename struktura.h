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

class zmogus
{
	protected:
	std::string vardas_, pavarde_;
	zmogus( std::string vardas = "", std::string pavarde = "") : vardas_{vardas}, pavarde_{pavarde} {}

	public:
	void vardas ( std::string vardas) { vardas_ = vardas; }
	void pavarde (std::string pavarde) { pavarde_ = pavarde; }
	std::string getVardas () const { return vardas_; }
	std::string getPavarde () const { return pavarde_; }

};

class studentas : public zmogus
{
	private:
	std::vector<double> ndrez_;
	double egzaminorez_, galutinis_;

	public:
	void ndrez ( double n ) { ndrez_.push_back(n); };
	void ndrez_panaikinti_paskutini () { ndrez_.pop_back();};
	void ndrez_isrikiuoti () { std::sort( ndrez_.begin(), ndrez_.end()); };
	void ndrez_istrinti () { ndrez_.clear(); ndrez_.shrink_to_fit(); };
	void egzaminorez ( double n ) { egzaminorez_ = n; }
	void galutinis (double n) { galutinis_ = n; };

	double getNdrez (int j) { return ndrez_[j]; };
	bool ndrez_ar_tuscias() const { return ndrez_.empty(); };
	int ndrez_dydis () const {return ndrez_.size(); };
	double ndrez_suma () { return accumulate(ndrez_.begin(), ndrez_.end(), 0.0); };
	double getEgzaminorez () const { return egzaminorez_; };
	double getGalutinis () const { return galutinis_; };

	friend std::ofstream & operator << (std::ofstream & os, studentas & a);

	studentas(std::string vardas = "", std::string pavarde = "", std::vector<double> ndrez = {}, double egzaminorez = 0) 
	: zmogus{vardas, pavarde}, ndrez_{ndrez}, egzaminorez_{egzaminorez} {}
	~studentas() {};
};

bool operator > (const studentas &a, const studentas &b);
bool operator >= (const studentas &a, const studentas &b);
bool operator < (const studentas &a, const studentas &b);
bool operator <= (const studentas &a, const studentas &b);
bool operator == (const studentas &a, const studentas &b);
bool operator != (const studentas &a, const studentas &b);

void irasimas(std::vector<studentas> &stud, std::size_t &ilgvardas, std::size_t &ilgpavarde);
void skaitymas(std::string failo_pav, std::vector<studentas> &stud, std::size_t &ilgvardas, std::size_t &ilgpavarde);
int tikrinimas(std::string a);
void vidurkis(std::vector<studentas> &stud);
void mediana(std::vector<studentas> &stud);
void spausdinimas(std::vector<studentas> &stud, std::size_t ilgvardas, std::size_t ilgpavarde);
void failu_generavimas(int &failu_sk);

#endif