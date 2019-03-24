#include "struktura.h"

void vidurkis(std::vector<mokinys> &mok)
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
		mok[i].galutinis = 0.40 * mok[i].vid + 0.60 * mok[i].egzaminorez;
	}
}

void mediana(std::vector<mokinys> &mok)
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
				mok[i].med = (double) mok[i].ndrez[mok[i].ndrez.size() / 2];
			}
		}
		mok[i].galutinis =(double) 0.4 * mok[i].med + 0.6 * mok[i].egzaminorez;
	}
}

bool pagal_galutini(const mokinys &a, const mokinys &b)
{
	return a.galutinis > b.galutinis;
}

void spausdinimas(std::vector<mokinys> mok, int ilgvardas, int ilgpavarde)
{
	std::sort(mok.begin(), mok.end(), pagal_galutini);
	int i;
	while (mok[i].galutinis >= 5)
	{
		i++;
	}

	std::vector<mokinys> saunuoliai;
	std::vector<mokinys> vargsiukai;
	saunuoliai.assign(mok.begin(), mok.begin() + i);
	vargsiukai.assign(mok.begin() + i, mok.end());

	std::ofstream s("šaunuoliai.txt");
	for(int i=0; i<saunuoliai.size(); i++){
		s << std::left << std::setw(ilgpavarde + 1) << saunuoliai[i].pavarde << std::left << std::setw(ilgvardas + 1) << saunuoliai[i].vardas;
		s << std::left << std::setw(20) << std::fixed << std::setprecision(2) << saunuoliai[i].galutinis << "\r\n";
	}
	s.close();
	std::ofstream v("vargšiukai.txt");
	for(int i=0; i<vargsiukai.size(); i++){
		v << std::left << std::setw(ilgpavarde + 1) << vargsiukai[i].pavarde << std::left << std::setw(ilgvardas + 1) << vargsiukai[i].vardas;
		v << std::left << std::setw(20) << std::fixed << std::setprecision(2) << vargsiukai[i].galutinis << "\r\n";
	}
	v.close();
}