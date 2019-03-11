#include "struktura.h"

void skaitymas(std::list<mokinys> &mok, int &ilgvardas, int &ilgpavarde)
{
	std::ifstream d("kursiokai.txt");
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

void failu_generavimas()
{
	const int N = 10000;
	std::ofstream r("kursiokai.txt");
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