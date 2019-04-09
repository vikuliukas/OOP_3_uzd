#include "struktura.h"

void vidurkis(std::deque<mokinys> &mok)
{
	for (int i = 0; i < mok.size(); i++)
	{
		if (mok[i].ndrez.empty())
		{
			mok[i].vid = 0;
		}
		else
		{
			mok[i].vid = accumulate(mok[i].ndrez.begin(), mok[i].ndrez.end(), 0.0) / mok[i].ndrez.size();
		}
		mok[i].galutinis = round((0.40 * mok[i].vid + 0.60 * mok[i].egzaminorez) * 100) / 100;
		mok[i].ndrez.clear();
	}
}

void mediana(std::deque<mokinys> &mok)
{
	for (int i = 0; i < mok.size(); i++)
	{
		if (mok[i].ndrez.empty())
		{
			mok[i].med = 0;
		}
		else
		{
			std::sort(mok[i].ndrez.begin(), mok[i].ndrez.end());
			if (mok[i].ndrez.size() % 2 == 0)
			{
				mok[i].med = (double)(mok[i].ndrez[mok[i].ndrez.size() / 2] + mok[i].ndrez[mok[i].ndrez.size() / 2 - 1]) / 2;
			}
			else
			{
				mok[i].med = (double)mok[i].ndrez[mok[i].ndrez.size() / 2];
			}
		}
		mok[i].galutinis = round((0.40 * mok[i].med + 0.60 * mok[i].egzaminorez) * 100) / 100;
		mok[i].ndrez.clear();
	}
}

bool pagal_galutini(const mokinys &a, const mokinys &b)
{
	return a.galutinis > b.galutinis;
}

void iterpkKietus(std::deque<mokinys> &mok, std::deque<mokinys> &vargsiukai)
{
	std::deque<mokinys>::size_type i = 0;
	mokinys t;
	int n;
	while (i != mok.size())
	{
		if (mok[i].galutinis < 5)
		{
			vargsiukai.push_back(mok[i]);
		}
		else
		{
			n++;
			mok.push_front(mok[i]);
			i++;
		}
		i++;
	}
	mok.resize(n);
	mok.shrink_to_fit();
}

void raskMinkstus(std::deque<mokinys> &mok, std::deque<mokinys> &vargsiukai)
{
	std::deque<mokinys>::size_type i = 0;
	while (i != mok.size())
	{
		if (mok[i].galutinis < 5)
		{
			vargsiukai.push_back(mok[i]);
			mok.erase(mok.begin() + i);
		}
		else
		i++;
	}
}

void spausdinimas(std::deque<mokinys> &vargsiukai, std::deque<mokinys> &mok, int ilgvardas, int ilgpavarde)
{
	std::ofstream s("šaunuoliai.txt");
	for (int i = 0; i < mok.size(); i++)
	{
		s << std::left << std::setw(ilgpavarde + 1) << mok[i].pavarde << std::left << std::setw(ilgvardas + 1) << mok[i].vardas;
		s << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis << "\r\n";
	}
	s.close();
	std::ofstream v("vargšiukai.txt");
	for (int i = 0; i < vargsiukai.size(); i++)
	{
		v << std::left << std::setw(ilgpavarde + 1) << vargsiukai[i].pavarde << std::left << std::setw(ilgvardas + 1) << vargsiukai[i].vardas;
		v << std::left << std::setw(20) << std::fixed << std::setprecision(2) << vargsiukai[i].galutinis << "\r\n";
	}
	v.close();
}