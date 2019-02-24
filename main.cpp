#include "struktura.h"

int main(){

	std::vector<mokinys> mok;

	int t, ilgvardas = 10, ilgpavarde = 10;
	setlocale(LC_ALL, "Lithuanian");
	srand(time(NULL));
	std::cout << "Ar norite duomenis ivesti ar nuskaityti nuo failo? \n";
	std::cout << "jei norite įvesti duomenis tada rašykite 0, jei skaityti - 1 \n";
	std::cin >> t;
	while (std::cin.fail() || t > 1 || t < 0)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Įveskite skaičių 0 - duomenų įvedimui arba 1 - duomenų nuskaitymui. \n";
		std::cin >> t;
	}
	if (t == 0) {
		irasimas(mok, ilgvardas, ilgpavarde);
	}
	if (t == 1) {
		try {
			skaitymas(mok, ilgvardas, ilgpavarde);
		}
		catch (std::exception& e) {
			std::cout << "Nepavyko atidaryti failo \n";
			return 0;
		}
	}
	vidurkis(mok);
	mediana(mok);
	spausdinimas(mok, ilgvardas, ilgpavarde);
	return 0;
}
