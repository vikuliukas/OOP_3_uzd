#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

struct mokinys {
	std::string vardas, pavarde;
	int n = 0, egzaminorez;
	std::vector<int> ndrez;
	double vid, med, galutinis_vid, galutinis_med;
};

std::vector<mokinys> mok;

void skaitymas();
void vidurkis();
void mediana();
void spausdinimas();
void atsitiktinis(int i, int k);

int main() {
	setlocale(LC_ALL, "Lithuanian");
	srand(time(NULL));
	skaitymas();
	vidurkis();
	mediana();
	spausdinimas();
	return 0;
}

void skaitymas() {
	int b,k;
	char ats;
	std::string a;
	std::cout << "iveskite varda: ";
	std::cin >> a;
	int i = 0;
	while (a != "0") {
		mok.push_back(mokinys());
		mok[i].vardas = a;
		std::cout << "iveskite pavarde: ";
		std::cin >> mok[i].pavarde;
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
		std::cout << s << "\n";
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

void spausdinimas() {
	char p;
	std::cout << "jei galutini bala skaiciuoti pagal vidurki rasykite v, jei pagal mediana - m \n";
	std::cin >> p;
	if (p == 'v') {
		std::cout << std::left << std::setw(20) << "Pavardė" << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Galutinis (Vid.)" << std::endl;
		std::cout << std::string(60, '-') << "\n";
		for (int i = 0; i < mok.size(); i++) {
			std::cout << std::left << std::setw(20) << mok[i].pavarde << std::left << std::setw(20) << mok[i].vardas;
			std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis_vid << "\n";
		}
	}
	else if (p == 'm') {
		std::cout << std::left << std::setw(20) << "Pavardė" << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Galutinis (Med.)" << std::endl;
		std::cout << std::string(60, '-') << "\n";
		for (int i = 0; i < mok.size(); i++) {
			std::cout << std::left << std::setw(20) << mok[i].pavarde << std::left << std::setw(20) << mok[i].vardas;
			std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis_med << "\n";
		}
	}
}