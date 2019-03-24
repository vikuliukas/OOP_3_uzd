#include "struktura.h"

void irasimas(std::vector<mokinys> &mok, int &ilgvardas, int &ilgpavarde)
{
	int b;
	std::string a, t, t1;
	std::cout << "iveskite varda: ";
	std::cin >> a;
	int i = 0;
	while (a != "0")
	{
		mok.push_back(mokinys());
		mok[i].vardas = a;
		if (mok[i].vardas.size() > ilgvardas)
		{
			ilgvardas = mok[i].vardas.size();
		}
		std::cout << "iveskite pavarde: ";
		std::cin >> mok[i].pavarde;
		if (mok[i].pavarde.size() > ilgpavarde)
		{
			ilgpavarde = mok[i].pavarde.size();
		}
		std::cout << "Ar norite, kad mokinio egzamino ir namų darbų rezultatai būtu generuojami atsitiktinai? \n";
		std::cout << "Jei ne rašykite 0, jei taip - 1 \n";
		std::cin >> t;

		while (t != "0" && t != "1")
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Įveskite skaičių 0 - duomenų įvedimui arba 1 - duomenų generavimui. \n";
			std::cin >> t;
		}

		if (t == "0")
		{
			std::cout << "iveskite egzamino rezultata: ";
			std::cin >> t1;
			mok[i].egzaminorez = tikrinimas(t1);
			std::cout << "iveskite namu darbu rezultatus: ";
			std::cin >> t1;
			b = tikrinimas(t1);
			while (b != 0)
			{
				mok[i].ndrez.push_back(b);
				std::cin >> t1;
				b = tikrinimas(t1);
			}
			i++;
			std::cout << "iveskite varda: ";
			std::cin >> a;
		}
		else if (t == "1")
		{
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> uni(0, 10);
			mok[i].egzaminorez = uni(rng);
			std::cout << "egzamino rezultatas: " << mok[i].egzaminorez << "\n";
			std::cout << "kiek namų darbų rezultatų sugeneruoti? \n";
			std::cin >> t1;
			while (!std::all_of(t1.begin(), t1.end(), ::isdigit))
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Įveskite skaičių ne mazesni nei 0 \n";
				std::cin >> t1;
			}
			b = std::stoi(t1);
			std::cout << "namų darbų rezultatai yra: \n";
			int random_skaicius;
			for (int j = 0; j < b; j++)
			{
				random_skaicius = uni(rng);
				mok[i].ndrez.push_back(random_skaicius);
				std::cout << mok[i].ndrez[j] << "\n";
			}			
			i++;
			std::cout << "iveskite varda: ";
			std::cin >> a;
		}
	}
}

int tikrinimas(std::string a)
{
	while (!std::all_of(a.begin(), a.end(), ::isdigit) || std::stoi(a) < 0 || std::stoi(a) > 10)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių nuo 0 iki 10 \n";
		std::cin >> a;
	}
	return std::stoi(a);
}