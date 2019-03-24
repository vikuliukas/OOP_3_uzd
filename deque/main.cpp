#include "struktura.h"

int main()
{
	auto pradzia = std::chrono::high_resolution_clock::now();
	std::deque<mokinys> mok;
	std::string t;

	int ilgvardas = 10, ilgpavarde = 10, x;
	setlocale(LC_ALL, "Lithuanian");
	std::cout << "Kiek failų norite sugeneruoti? (nuo 0 iki 5)\n";
	std::cin >> t;
	while (!std::all_of(t.begin(), t.end(), ::isdigit) || std::stoi(t) < 0 || std::stoi(t) > 5)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių nuo 0 iki 5 \n";
		std::cin >> t;
	}
	int failu_sk = std::stoi(t);
	//int failu_sk = 1;
	if (failu_sk != 0)
	{
		failu_generavimas(failu_sk);
	}
	std::cout << "Ar norite duomenis ivesti ar nuskaityti nuo failo? \n";
	std::cout << "jei norite įvesti duomenis tada rašykite 0, jei skaityti - 1 \n";
	std::cin >> t;
	while (t != "0" && t != "1")
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių 0 - duomenų įvedimui arba 1 - duomenų nuskaitymui. \n";
		std::cin >> t;
	}
	//t = "1";
	if (t == "0")
	{
		irasimas(mok, ilgvardas, ilgpavarde);
	}
	else
	{
		try
		{
			skaitymas(mok, ilgvardas, ilgpavarde);
		}
		catch (std::exception &e)
		{
			std::cout << "Nepavyko atidaryti failo \n";
			return 0;
		}
		catch (int x)
		{
			std::cout << "failo " << x + 1 << " eiluteje yra klaida\n";
			return 0;
		}
	}

	std::cout << "jei galutini bala skaiciuoti pagal vidurki rasykite 0, jei pagal mediana - 1 \n";
	std::cin >> t;
	while (t != "0" && t != "1")
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių 0 - skaiciavimui pagal vidurki arba 1 - skaiciavimui pagal mediana. \n";
		std::cin >> t;
	}
	//t = "0";
	if (t == "0")
	{
		vidurkis(mok);
	}
	else
	{
		mediana(mok);
	}

	spausdinimas(mok, ilgvardas, ilgpavarde);

	auto pabaiga = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> trukme = pabaiga - pradzia;
	std::cout << "visa programa uztruko " << trukme.count() << " sek.\n";
	return 0;
}