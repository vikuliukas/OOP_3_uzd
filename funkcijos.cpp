#include "struktura.h"

void irasimas(std::vector<mokinys> & mok, int & ilgvardas, int & ilgpavarde) {
	int b, k, t;
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
		std::cout << "Jei ne rašykite 0, jei taip - 1 \n";
		std::cin >> t;

		while (std::cin.fail() || t > 1 || t < 0)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Įveskite skaičių 0 - duomenų įvedimui arba 1 - duomenų generavimui. \n";
			std::cin >> t;
		}

		if (t == 0) {
			std::cout << "iveskite egzamino rezultata: ";
			std::cin >> mok[i].egzaminorez;

			while (std::cin.fail() || mok[i].egzaminorez > 10 || mok[i].egzaminorez < 1) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Įveskite skaičių nuo 1 iki 10 \n";
				std::cin >> mok[i].egzaminorez;
			}
			
			std::cout << "iveskite namu darbu rezultatus: ";
			std::cin >> b;

			while (std::cin.fail() || b > 10 || b < 0) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Įveskite skaičių nuo 1 iki 10 arba 0 jei norite sustabdyti duomenų įvedimą \n";
				std::cin >> b;
			}

			while (b != 0) {
				mok[i].ndrez.push_back(b);
				std::cin >> b;

				while (std::cin.fail() || b > 10 || b < 0) {
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Įveskite skaičių nuo 1 iki 10 arba 0 jei norite sustabdyti duomenų įvedimą \n";
					std::cin >> b;
				}

			}
			i++;
			std::cout << "iveskite varda: ";
			std::cin >> a;
		}
		else if (t == 1) {
			mok[i].egzaminorez = rand() % 10 + 1;
			std::cout << "egzamino rezultatas: " << mok[i].egzaminorez << "\n";
			std::cout << "kiek namų darbų rezultatų sugeneruoti? \n";
			std::cin >> k;

			while (std::cin.fail() || k < 0) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Įveskite skaičių ne mažesnį nei 0 \n";
				std::cin >> k;
			}

			std::cout << "namų darbų rezultatai yra: \n";
			atsitiktinis(mok, i, k);
			i++;
			std::cout << "iveskite varda: ";
			std::cin >> a;
		}
	}
}

void skaitymas(std::vector<mokinys> & mok, int & ilgvardas, int & ilgpavarde) {
	std::ifstream d("kursiokai.txt");
	std::string t;
	int i = 0, n;
	if (d.fail()) {
		throw std::exception();
	}
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
	d.close();
}

void atsitiktinis(std::vector<mokinys> & mok, int i, int k) {
	int t;
	for (int j = 0; j < k; j++) {
		t = rand() % 10 + 1;
		mok[i].ndrez.push_back(t);
		std::cout << mok[i].ndrez[j] << "\n";
	}
}

void vidurkis(std::vector<mokinys> & mok) {
	int s;
	for (int i = 0; i < mok.size(); i++) {
		s = 0;
		if (mok[i].ndrez.empty()) {
			mok[i].vid = 0;
		}
		else {
			for (int j = 0; j < mok[i].ndrez.size(); j++) {
				s = s + mok[i].ndrez[j];
			}
			mok[i].vid = (double)s / mok[i].ndrez.size();
		}
		mok[i].galutinis_vid = 0.4*mok[i].vid + 0.6*mok[i].egzaminorez;
	}
}

void mediana(std::vector<mokinys> & mok) {
	for (int i = 0; i < mok.size(); i++) {
		std::sort(mok[i].ndrez.begin(), mok[i].ndrez.end());
		if (mok[i].ndrez.size() % 2 == 0) {
			mok[i].med = (double)(mok[i].ndrez[mok[i].ndrez.size() / 2] + mok[i].ndrez[mok[i].ndrez.size() / 2 - 1]) / 2;
		}
		else {
			mok[i].med = mok[i].ndrez[mok[i].ndrez.size() / 2];
		}
		mok[i].galutinis_med = 0.4*mok[i].med + 0.6*mok[i].egzaminorez;
	}
}

bool pagal_varda(const mokinys &a, const mokinys &b) {

	return a.pavarde < b.pavarde;

}

void spausdinimas(std::vector<mokinys> mok, int ilgvardas, int ilgpavarde) {
	int t;
	sort(mok.begin(), mok.end(), pagal_varda);
	std::cout << "jei galutini bala skaiciuoti pagal vidurki rasykite 0, jei pagal mediana - 1 \n";
	std::cin >> t;
	while (std::cin.fail() || t > 1 || t < 0)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių 0 - skaiciavimui pagal vidurki arba 1 - skaiciavimui pagal mediana. \n";
		std::cin >> t;
	}
	if (t == 0) {
		std::cout << std::left << std::setw(ilgpavarde + 2) << "Pavardė" << std::left << std::setw(ilgvardas + 1) << "Vardas" << std::left << std::setw(20) << "Galutinis (Vid.)" << std::endl;
		std::cout << std::string(ilgpavarde + 2 + ilgvardas + 1 + 20, '-') << "\n";
		for (int i = 0; i < mok.size(); i++) {
			std::cout << std::left << std::setw(ilgpavarde + 1) << mok[i].pavarde << std::left << std::setw(ilgvardas + 1) << mok[i].vardas;
			std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis_vid << "\n";
		}
	}
	else if (t == 1) {
		std::cout << std::left << std::setw(ilgpavarde + 2) << "Pavardė" << std::left << std::setw(ilgvardas + 1) << "Vardas" << std::left << std::setw(20) << "Galutinis (Med.)" << std::endl;
		std::cout << std::string(ilgpavarde + 2 + ilgvardas + 1 + 20, '-') << "\n";
		for (int i = 0; i < mok.size(); i++) {
			std::cout << std::left << std::setw(ilgpavarde + 1) << mok[i].pavarde << std::left << std::setw(ilgvardas + 1) << mok[i].vardas;
			std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis_med << "\n";
		}
	}
}