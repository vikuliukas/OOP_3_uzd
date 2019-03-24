#include "struktura.h"

void vidurkis(std::list<mokinys> &mok)
{
	for (auto it = mok.begin(); it != mok.end(); it++)
	{
		if (it->ndrez.empty())
		{
			it->vid = 0;
		}
		else
		{
			it->vid = std::accumulate(it->ndrez.begin(), it->ndrez.end(), 0.0) / it->ndrez.size();
		}
		it->galutinis = 0.40 * it->vid + 0.60 * it->egzaminorez;
		it->ndrez.clear();
	}
}

void mediana(std::list<mokinys> &mok)
{
	for (auto it = mok.begin(); it != mok.end(); it++)
	{
		if (it->ndrez.empty())
		{
			it->med = 0;
		}
		else
		{
			it->ndrez.sort();
			auto it1 = it->ndrez.begin();
			auto it2 = it->ndrez.begin();
			if (it->ndrez.size() % 2 == 0)
			{
				it1 = std::next(it->ndrez.begin(), it->ndrez.size() / 2);
				it2 = std::next(it->ndrez.begin(), it->ndrez.size() / 2 - 1);
				it->med = (double)(*it1 + *it2) / 2;
			}
			else
			{
				it1 = std::next(it->ndrez.begin(), it->ndrez.size() / 2);
				it->med = *it1;
			}
		}
		it->galutinis = (double)0.4 * it->med + 0.6 * it->egzaminorez;
		it->ndrez.clear();
	}
}

bool pagal_galutini(const mokinys &a, const mokinys &b)
{
	return a.galutinis > b.galutinis;
}

void spausdinimas(std::list<mokinys> &mok, int ilgvardas, int ilgpavarde)
{
	mok.sort(pagal_galutini);

	auto it = mok.begin();
	int i = 0;

	while (it->galutinis >= 5)
	{
		i++;
		it++;
	}
	std::list<mokinys> saunuoliai;
	std::list<mokinys> vargsiukai;
	saunuoliai.assign(mok.begin(), std::next(mok.begin(), i));
	vargsiukai.assign(std::next(mok.begin(), i), mok.end());
	mok.clear();

	std::ofstream s("šaunuoliai.txt");
	for (auto it = saunuoliai.begin(); it != saunuoliai.end(); it++)
	{
		s << std::left << std::setw(ilgpavarde + 1) << it->pavarde << std::left << std::setw(ilgvardas + 1) << it->vardas;
		s << std::left << std::setw(20) << std::fixed << std::setprecision(2) << it->galutinis << "\r\n";
	}
	s.close();
	saunuoliai.clear();

	std::ofstream v("vargšiukai.txt");
	for (auto it1 = vargsiukai.begin(); it1 != vargsiukai.end(); it1++)
	{
		v << std::left << std::setw(ilgpavarde + 1) << it1->pavarde << std::left << std::setw(ilgvardas + 1) << it1->vardas;
		v << std::left << std::setw(20) << std::fixed << std::setprecision(2) << it1->galutinis << "\r\n";
	}
	v.close();
	vargsiukai.clear();
}