#include "struktura.h"

int tikrinimas(std::string a)
{
	while (!std::all_of(a.begin(), a.end(), ::isdigit) && std::stoi(a) < 0 && std::stoi(a) > 10)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių nuo 0 iki 10 \n";
		std::cin >> a;
	}
	return std::stoi(a);
}

void atsitiktinis(std::vector<mokinys> &mok, int i, int k)
{
	int t;
	for (int j = 0; j < k; j++)
	{
		t = rand() % 10 + 1;
		mok[i].ndrez.push_back(t);
		std::cout << mok[i].ndrez[j] << "\n";
	}
}

void vidurkis(std::vector<mokinys> &mok, int i)
{
	if (mok[i].ndrez.empty())
	{
		mok[i].vid = 0;
	}
	else
	{
		mok[i].vid = accumulate(mok[i].ndrez.begin(), mok[i].ndrez.end(), 0.0) / mok[i].ndrez.size();
	}
	mok[i].galutinis = 0.4 * mok[i].vid + 0.6 * mok[i].egzaminorez;
}

void mediana(std::vector<mokinys> &mok, int i)
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
			mok[i].med = mok[i].ndrez[mok[i].ndrez.size() / 2];
		}
	}
	mok[i].galutinis = 0.4 * mok[i].med + 0.6 * mok[i].egzaminorez;
}

bool pagal_varda(const mokinys &a, const mokinys &b)
{
	return a.pavarde < b.pavarde;
}

void spausdinimas(std::vector<mokinys> mok, int ilgvardas, int ilgpavarde)
{
	std::string t;
	std::ofstream v("vargšiukai.txt");
	std::ofstream s("šaunuoliai.txt");
	sort(mok.begin(), mok.end(), pagal_varda);
	std::cout << "jei galutini bala skaiciuoti pagal vidurki rasykite 0, jei pagal mediana - 1 \n";
	std::cin >> t;
	while (t != "0" && t != "1")
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių 0 - skaiciavimui pagal vidurki arba 1 - skaiciavimui pagal mediana. \n";
		std::cin >> t;
	}
	if (t == "0")
	{
		for (int i = 0; i < mok.size(); i++)
		{
			vidurkis(mok, i);
			if (mok[i].galutinis < 5)
			{
				v << std::left << std::setw(ilgpavarde + 1) << mok[i].pavarde << std::left << std::setw(ilgvardas + 1) << mok[i].vardas;
				v << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis << "\r\n";
			}
			else
			{
				s << std::left << std::setw(ilgpavarde + 1) << mok[i].pavarde << std::left << std::setw(ilgvardas + 1) << mok[i].vardas;
				s << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis << "\r\n";
			}
		}
		v.close();
		s.close();
	}
	else
	{
		for (int i = 0; i < mok.size(); i++)
		{
			mediana(mok, i);
			if (mok[i].galutinis < 5)
			{
				v << std::left << std::setw(ilgpavarde + 1) << mok[i].pavarde << std::left << std::setw(ilgvardas + 1) << mok[i].vardas;
				v << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis << "\r\n";
			}
			else
			{
				s << std::left << std::setw(ilgpavarde + 1) << mok[i].pavarde << std::left << std::setw(ilgvardas + 1) << mok[i].vardas;
				s << std::left << std::setw(20) << std::fixed << std::setprecision(2) << mok[i].galutinis << "\r\n";
			}
		}
		v.close();
		s.close();
	}
}