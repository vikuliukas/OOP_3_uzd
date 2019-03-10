#include "struktura.h"

void skaitymas(std::vector<mokinys> &mok, int &ilgvardas, int &ilgpavarde)
{
	std::ifstream d("kursiokai10000.txt");
	std::string t, t1;
	int i = 0, n;
	if (d.fail())
	{
		throw std::exception();
	}
	while (!d.eof())
	{
		std::getline(d, t, '\n');
		mok.push_back(mokinys());
		std::istringstream iss(t);
		iss >> mok[i].vardas;
		if (mok[i].vardas.size() > ilgvardas)
		{
			ilgvardas = mok[i].vardas.size();
		}
		iss >> mok[i].pavarde;
		if (mok[i].pavarde.size() > ilgpavarde)
		{
			ilgpavarde = mok[i].pavarde.size();
		}
		while (iss >> t1)
		{
			if (!std::all_of(t1.begin(), t1.end(), ::isdigit) || std::stoi(t1) > 10 || std::stoi(t1) < 0)
			{
				throw i;
			}
			n = std::stoi(t1);
			mok[i].ndrez.push_back(n);
		}
		mok[i].egzaminorez = n;
		mok[i].ndrez.pop_back();
		i++;
	}
	d.close();
}

void failu_generavimas()
{
	const int N = 100000;
	std::ofstream r("kursiokai10000.txt");
	for (int i = 0; i < N; i++)
	{
		r << "Vardas" << i + 1 << " "
		  << "Pavardė" << i + 1;
		for (int j = 0; j < 10000; j++)
		{
			r << " " << rand() % 10 + 1;
		}
		if (i + 1 < N)
		{
			r << "\n";
		}
	}
	r.close();
}