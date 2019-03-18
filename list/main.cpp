#include "struktura.h"

int main()
{
	auto pradzia = std::chrono::high_resolution_clock::now();
	std::list<mokinys> mok;
	std::list<mokinys> saunuoliai;
	std::list<mokinys> vargsiukai;
	std::string t;

	int ilgvardas = 10, ilgpavarde = 10, x;
	setlocale(LC_ALL, "Lithuanian");
	srand(time(NULL));
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
			failu_generavimas();
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

	spausdinimas(mok, ilgvardas, ilgpavarde, saunuoliai, vargsiukai);

	auto pabaiga = std::chrono::high_resolution_clock::now();

	saunuoliai.clear();
	vargsiukai.clear();
	
	std::chrono::duration<double> trukme = pabaiga - pradzia;
	std::cout << "užtruko " << trukme.count() << " sek.\n";
	return 0;
}