#include "struktura.h"

int main()
{
	std::vector<mokinys> mok;
	std::string t;

	int ilgvardas = 10, ilgpavarde = 10, x;
	setlocale(LC_ALL, "Lithuanian");
	std::cout<<"Kiek failų norite sugeneruoti? (nuo 0 iki 5)\n";
	std::cin>>t;
	while (!std::all_of(t.begin(), t.end(), ::isdigit) || std::stoi(t) < 0 || std::stoi(t) > 5)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių nuo 0 iki 5 \n";
		std::cin >> t;
	}
	int failu_sk = std::stoi(t);
	//int failu_sk = 0;
	if(failu_sk != 0){
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
		std::string failo_pav;
		std::cout<<"Įveskite failo pavadinimą iš kurio norite nuskaityti duomenis. (pvz. kursiokai1)\n";
		std::cin>>failo_pav;
		//failo_pav = "kursiokai100000";
		failo_pav += ".txt";
		try
		{
			skaitymas(failo_pav, mok, ilgvardas, ilgpavarde);
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
	if(t == "0"){
		vidurkis(mok);
	}
	else{
		mediana(mok);
	}

	std::vector<mokinys> vargsiukai;

	std::cout << "jei norite naudoti funkciją ''raskMinkstus'' įveskite 0, jei norite naudoti fukciją ''iterpkKietus'' - 1. \n";
	std::cin >> t;
	while (t != "0" && t != "1")
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių 0 - funkcijai ''raskMinstus'' arba 1 - funkcijai ''iterpkKietus''. \n";
		std::cin >> t;
	}
	//t = "0";
	if(t == "0"){
		auto pradzia = std::chrono::high_resolution_clock::now();
		raskMinkstus(mok,vargsiukai);
		auto pabaiga = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> trukme = pabaiga - pradzia;
		std::cout << "''raskMinkstus'' uztruko " << trukme.count() << " sek.\n";
	}
	else{
		auto pradzia = std::chrono::high_resolution_clock::now();
		iterpkKietus(mok,vargsiukai);
		auto pabaiga = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> trukme = pabaiga - pradzia;
		std::cout << "''iterpkKietus'' uztruko " << trukme.count() << " sek.\n";
	}

	spausdinimas(vargsiukai, mok, ilgvardas, ilgpavarde);
	vargsiukai.clear();
	mok.clear();

	return 0;
}