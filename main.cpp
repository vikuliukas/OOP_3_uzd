#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <ctype.h>
#include <sstream>

struct mokinys {
	std::string vardas, pavarde;
	int egzaminorez;
	std::vector<int> ndrez;
	double vid, med, galutinis_vid, galutinis_med;
};

std::vector<mokinys> mok;

void irasimas(int & ilgvardas, int & ilgpavarde);
void skaitymas(int & ilgvardas, int & ilgpavarde);
void vidurkis();
void mediana();
bool pagal_varda(const mokinys &a, const mokinys &b);
void spausdinimas(int ilgvardas, int ilgpavarde);
void atsitiktinis(int i, int k);

int main() {
	int t, ilgvardas = 0, ilgpavarde = 0;
	setlocale(LC_ALL, "Lithuanian");
	srand(time(NULL));
	std::cout << "Ar norite duomenis ivesti ar nuskaityti nuo failo? \n";
	std::cout << "jei norite įvesti duomenis tada rašykite 0, jei skaityti - 1 \n";
	std::cin >> t;
	if (t == 0) {
		irasimas(ilgvardas, ilgpavarde);
	}
	if (t == 1) {
		skaitymas(ilgvardas, ilgpavarde);
	}
	vidurkis();
	mediana();
	spausdinimas(ilgvardas, ilgpavarde);
	return 0;
}

void irasimas(int & ilgvardas, int & ilgpavarde) {
	int b, k;
	char ats;
	std::string a;
	std::cout << "iveskite varda: ";
	std::cin >> a;
	int i = 0;
	while (a != "0") {
		mok.push_back(mokinys());
		mok[i].vardas = a;
		if (mok[i].vardas.size() > ilgvardas) {
			ilgvardas = mok[i].vardas.size();
		}
		std::cout << "iveskite pavarde: ";
		std::cin >> mok[i].pavarde;
		if (mok[i].pavarde.size() > ilgpavarde) {
			ilgpavarde = mok[i].pavarde.size();
		}
		std::cout << "Ar norite, kad mokinio egzamino ir namų darbų rezultatai būtu generuojami atsitiktinai? \n";
		std::cout << "Jei taip rašykite t, jei ne - n \n";
		std::cin >> ats;
		if (ats == 'n') {
			std::cout << "iveskite egzamino rezultata: ";
			std::cin >> mok[i].egzaminorez;
			std::cout << "iveskite namu darbu rezultatus: ";
			std::cin >> b;
			while (b != 0) {
				mok[i].ndrez.push_back(b);
				std::cin >> b;
			}
			i++;
			std::cout << "iveskite varda: ";
			std::cin >> a;
		}
		else if (ats == 't') {
			mok[i].egzaminorez = rand() % 10 + 1;
			std::cout << "egzamino rezultatas: " << mok[i].egzaminorez << "\n";
			std::cout << "kiek namų darbų rezultatų sugeneruoti? \n";
			std::cin >> k;
			std::cout << "namų darbų rezultatai yra: \n";
			atsitiktinis(i, k);
			i++;
			std::cout << "iveskite varda: ";
			std::cin >> a;
		}
	}
}

void skaitymas(int & ilgvardas, int & ilgpavarde) {
	std::ifstream d("kursiokai.txt");
	std::string t;
	int i = 0, n;
	if (d) {
		while (!d.eof()) {
			std::getline(d, t, '\n');
			mok.push_back(mokinys());
			std::istringstream iss(t);
			iss >> mok[i].vardas;
			if (mok[i].vardas.size() > ilgvardas) {
				ilgvardas = mok[i].vardas.size();
			}
			iss >> mok[i].pavarde;
			if (mok[i].pavarde.size() > ilgpavarde) {
				ilgpavarde = mok[i].pavarde.size();
			}
			while (iss >> n) {
				mok[i].ndrez.push_back(n);
			}
			mok[i].egzaminorez = n;
			mok[i].ndrez.pop_back();
			i++;
		}
	}
	d.close();
}

void atsitiktinis(int i, int k) {
	int t;
	for (int j = 0; j < k; j++) {
		t = rand() % 10 + 1;
		mok[i].ndrez.push_back(t);
		std::cout << mok[i].ndrez[j] << "\n";
	}
}

void vidurkis() {
	int s;
	for (int i = 0; i<mok.size(); i++) {
		s = 0;
		for (int j = 0; j < mok[i].ndrez.size(); j++) {
			s = s + mok[i].ndrez[j];
		}
		mok[i].vid = (double)s / mok[i].ndrez.size();
		mok[i].galutinis_vid = 0.4*mok[i].vid + 0.6*mok[i].egzaminorez;
	}
}

void mediana() {
	for (int i = 0; i < mok.size(); i++) {
		std::sort(mok[i].ndrez.begin(), mok[i].ndrez.end());
		if (mok[i].ndrez.size() % 2 == 0) {
			mok[i].med = (double)(mok[i].ndrez[mok[i].ndrez.size()/2] + mok[i].ndrez[mok[i].ndrez.size()/2-1]) / 2;
		}
		else {
			mok[i].med = mok[i].ndrez[mok[i].ndrez.size() / 2];
		}
		mok[i].galutinis_med = 0.4*mok[i].med + 0.6*mok[i].egzaminorez;
	}
}

bool pagal_varda(const mokinys &a, const mokinys &b){

	return a.pavarde < b.pavarde;

}

void spausdinimas(int ilgvardas, int ilgpavarde) {
	char p;
	sort(mok.begin(), mok.end(), pagal_varda);
	std::cout << "jei galutini bala skaiciuoti pagal vidurki rasykite v, jei pagal mediana - m \n";
	std::cin >> p;
	if (p == 'v') {
		std::cout << std::left << std::setw(ilgpavarde+2) << "Pavardė" << std::left << std::setw(ilgvardas+1) << "Vardas" << std::left << std::setw(20) << "Galutinis (Vid.)" << std::endl;
		std::cout << std::string(ilgpavarde + 2 + ilgvardas + 1 + 20, '-') << "\n";
		for (int i = 0; i < mok.size(); i++) {
			std::cout << std::left << std::setw(ilgpavarde+1) << mok[i].pavarde << std::left << std::setw(ilgvardas+1) << mok[i].vardas;
			std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis_vid << "\n";
		}
	}
	else if (p == 'm') {
		std::cout << std::left << std::setw(ilgpavarde+2) << "Pavardė" << std::left << std::setw(ilgvardas+1) << "Vardas" << std::left << std::setw(20) << "Galutinis (Med.)" << std::endl;
		std::cout << std::string(ilgpavarde + 2 + ilgvardas + 1 + 20, '-') << "\n";
		for (int i = 0; i < mok.size(); i++) {
			std::cout << std::left << std::setw(ilgpavarde+1) << mok[i].pavarde << std::left << std::setw(ilgvardas+1) << mok[i].vardas;
			std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis_med << "\n";
		}
	}
}