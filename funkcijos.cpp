#include "struktura.h"

void vidurkis(std::vector<studentas> &stud)
{	
	double vid;
	for (int i = 0; i < stud.size(); i++)
	{
		if (stud[i].ndrez_ar_tuscias())
		{
			vid = 0;
		}
		else
		{
			vid = stud[i].ndrez_suma() / stud[i].ndrez_dydis();
		}
		stud[i].galutinis(round((0.40 * vid + 0.60 * stud[i].getEgzaminorez())*100)/100);
		stud[i].ndrez_istrinti();
	}
}

void mediana(std::vector<studentas> &stud)
{
	double med;
	for (int i = 0; i < stud.size(); i++)
	{
		if (stud[i].ndrez_ar_tuscias())
		{
			med = 0;
		}
		else
		{
			stud[i].ndrez_isrikiuoti();
			if (stud[i].ndrez_dydis() % 2 == 0)
			{
				med = (double)(stud[i].getNdrez(stud[i].ndrez_dydis() / 2) + stud[i].getNdrez(stud[i].ndrez_dydis() / 2 - 1)) / 2;
			}
			else
			{
				med = (double)stud[i].getNdrez(stud[i].ndrez_dydis() / 2);
			}
		}
		stud[i].galutinis(round((0.40 * med + 0.60 * stud[i].getEgzaminorez())*100)/100);
		stud[i].ndrez_istrinti();
	}
}

bool pagal_galutini(const studentas &a, const studentas &b)
{
	return a.getGalutinis() > b.getGalutinis();
}

void spausdinimas(std::vector<studentas> &stud, int ilgvardas, int ilgpavarde)
{
	std::sort(stud.begin(), stud.end(), pagal_galutini);
	int i = 0;
	while ((stud[i].getGalutinis() >= 5) && ( i <= stud.size())) 
	{
		i++;
	}

	std::vector<studentas> saunuoliai;
	std::vector<studentas> vargsiukai;
	saunuoliai.assign(stud.begin(), stud.begin() + i);
	vargsiukai.assign(stud.begin() + i, stud.end());
	stud.clear();
	stud.shrink_to_fit();

	std::ofstream s("šaunuoliai.txt");
	for (int i = 0; i < saunuoliai.size(); i++)
	{
		s << std::left << std::setw(ilgpavarde + 1) << saunuoliai[i].getPavarde() << std::left << std::setw(ilgvardas + 1) << saunuoliai[i].getVardas();
		s << std::left << std::setw(20) << std::fixed << std::setprecision(2) << saunuoliai[i].getGalutinis() << "\r\n";
	}
	s.close();
	std::ofstream v("vargšiukai.txt");
	for (int i = 0; i < vargsiukai.size(); i++)
	{
		v << std::left << std::setw(ilgpavarde + 1) << vargsiukai[i].getPavarde() << std::left << std::setw(ilgvardas + 1) << vargsiukai[i].getVardas();
		v << std::left << std::setw(20) << std::fixed << std::setprecision(2) << vargsiukai[i].getGalutinis() << "\r\n";
	}
	v.close();
} 