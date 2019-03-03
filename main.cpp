#include "struktura.h"

int main()
{
	auto pradzia = std::chrono::high_resolution_clock::now();
	std::vector<mokinys> mok;
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
	
	if (t == "0")
	{
		irasimas(mok, ilgvardas, ilgpavarde);
	}
	if (t == "1")
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
	spausdinimas(mok, ilgvardas, ilgpavarde);
	auto pabaiga = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> trukme = pabaiga - pradzia;
	std::cout << "užtruko " << trukme.count() << " sek.\n";
	return 0;
}