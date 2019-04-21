﻿#include "struktura.h"

void skaitymas(std::string failo_pav, std::vector<mokinys> &mok, int &ilgvardas, int &ilgpavarde)
{
	std::ifstream d(failo_pav);
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

void failu_generavimas(int &failu_sk)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(0, 10);

	int failo_numeris = 0, N, M;
	std::string t;
	while (failo_numeris < failu_sk)
	{
		std::cout << "kiek studentų " << failo_numeris + 1 << " faile?\n";
		std::cin >> t;
		while (!std::all_of(t.begin(), t.end(), ::isdigit) || std::stoi(t) <= 0)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Įveskite skaičių didesni uz 0";
			std::cin >> t;
		}
		N = std::stoi(t);
		//N = 100000;
		std::cout << "kiek pažymių turi vienas studentas? \n";
		std::cin >> t;
		while (!std::all_of(t.begin(), t.end(), ::isdigit) || std::stoi(t) <= 0)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Įveskite skaičių didesni uz 0";
			std::cin >> t;
		}
		M = std::stoi(t);
		std::ofstream r("kursiokai" + std::to_string(failo_numeris+1) + ".txt");
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
		std::cout << "failas kursiokai" << failo_numeris+1 << ".txt sugeneruotas per " << trukme.count() << "sek.\n";
		failo_numeris++;
	}
}