#include "struktura.h"

void irasimas(std::list<mokinys> &mok, int &ilgvardas, int &ilgpavarde)
{
	int b;
	std::string a, t, t1;
	std::cout << "iveskite varda: ";
	std::cin >> a;
	mok.push_back(mokinys());
	auto it = mok.begin();
	while (a != "0")
	{
		it->vardas = a;
		if (it->vardas.size() > ilgvardas)
		{
			ilgvardas = it->vardas.size();
		}
		std::cout << "iveskite pavarde: ";
		std::cin >> it->pavarde;
		if (it->pavarde.size() > ilgpavarde)
		{
			ilgpavarde = it->pavarde.size();
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
			it->egzaminorez = tikrinimas(t1);
			std::cout << "iveskite namu darbu rezultatus: ";
			std::cin >> t1;
			b = tikrinimas(t1);
			while (b != 0)
			{
				it->ndrez.push_back(b);
				std::cin >> t1;
				b = tikrinimas(t1);
			}
			mok.push_back(mokinys());
			it++;
			std::cout << "iveskite varda: ";
			std::cin >> a;
		}
		else if (t == "1")
		{
			it->egzaminorez = rand() % 10 + 1;
			std::cout << "egzamino rezultatas: " << it->egzaminorez << "\n";
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
			atsitiktinis(mok, it, b);
			mok.push_back(mokinys());
			it++;
			std::cout << "iveskite varda: ";
			std::cin >> a;
		}
	}
	mok.pop_back();
}

int tikrinimas(std::string a)
{
	while (!std::all_of(a.begin(), a.end(), ::isdigit) && std::stoi(a) < 0 && std::stoi(a) > 10)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių nuo 0 iki 10 \n";
		std::cin >> a;
	}
	return std::stoi(a);
}

void atsitiktinis(std::list<mokinys> &mok, std::list<mokinys>::iterator it, int k)
{
	int t;
	std::list<int>::iterator it1 = it->ndrez.begin();
	for (int j = 0; j < k; j++)
	{
		t = rand() % 10 + 1;
		it->ndrez.push_back(t);
		std::cout << t << "\n";
	}
}