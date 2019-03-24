#include "struktura.h"

void skaitymas(std::list<mokinys> &mok, int &ilgvardas, int &ilgpavarde)
{
	std::ifstream d("kursiokai10.txt");
	std::string t, t1;
	int n;
	if (d.fail())
	{
		throw std::exception();
	}
	mok.push_back(mokinys());
	auto it = mok.begin();
	while (!d.eof())
	{
		std::getline(d, t, '\n');
		std::istringstream iss(t);
		iss >> it->vardas;
		if (it->vardas.size() > ilgvardas)
		{
			ilgvardas = it->vardas.size();
		}
		iss >> it->pavarde;
		if (it->pavarde.size() > ilgpavarde)
		{
			ilgpavarde = it->pavarde.size();
		}
		while (iss >> t1)
		{
			if (!std::all_of(t1.begin(), t1.end(), ::isdigit) || std::stoi(t1) > 10 || std::stoi(t1) < 0)
			{
				throw it;
			}
			n = std::stoi(t1);
			it->ndrez.push_back(n);
		}
		it->egzaminorez = n;
		it->ndrez.pop_back();
		mok.push_back(mokinys());
		it++;
	}
	mok.pop_back();
	d.close();
}

void failu_generavimas(int &failu_sk)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(0, 10);

	int failo_numeris = 0, N, M;
	std::string t, a = "1";
	while (failo_numeris < failu_sk)
	{
		std::cout << "kiek įrašų " << failo_numeris + 1 << " faile?\n";
		std::cin >> t;
		while (!std::all_of(a.begin(), a.end(), ::isdigit) || std::stoi(t) <= 0)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Įveskite skaičių didesni uz 0";
			std::cin >> t;
		}
		N = std::stoi(t);
		//N = 100000;
		M = N;
		a = a + "0";
		std::ofstream r("kursiokai" + a + ".txt");
		auto pradzia = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < N; i++)
		{
			r << "Vardas" << i + 1 << " "
			  << "Pavardė" << i + 1;
			for (int j = 0; j < M; j++)
			{
				r << " " << uni(rng);
			}
			if (i + 1 < N)
			{
				r << "\n";
			}
		}
		r.close();
		auto pabaiga = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> trukme = pabaiga - pradzia;
		std::cout << "sugeneruoti failą su " << N << " mokiniu ir pažymiu užtruko: " << trukme.count() << " sek.\n";
		failo_numeris++;
	}
}