#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct mokinys {
	std::string vardas, pavarde;
	int n=0, egzaminorez, *ndrez;
	double vid,med,galutinis_vid,galutinis_med;
	mokinys * kitas;
};

void skaitymas(mokinys *root);
void vidurkis(mokinys *root);
void mediana(mokinys *root);
void rikiavimas(int A[], int n);
void spausdinimas(mokinys *root);
void istrinti(mokinys *root);

int main() {
	setlocale(LC_ALL, "Lithuanian");
	mokinys *root;
	root = new mokinys;
	skaitymas(root);
	vidurkis(root);
	mediana(root);
	spausdinimas(root);
	istrinti(root);
	return 0;
}

void skaitymas(mokinys *root) {
	int b,size = 5;
	std::string a;
	std::cout << "iveskite varda: ";
	std::cin >> a;
	if (a != "0") {
		root->vardas = a;
		std::cout << "iveskite pavarde: ";
		std::cin >> root->pavarde;
		std::cout << "iveskite egzamino rezultata: ";
		std::cin >> root->egzaminorez;
		root->ndrez = new int[size];
		std::cout << "iveskite namu darbu rezultatus: ";
		std::cin >> b;
		while (b != 0) {
			if (root->n < size) {
				root->ndrez[root->n] = b;
				root->n++;
			}
			else {
				int *naujas = new int[size+5];
				std::copy(root->ndrez, root->ndrez + size, naujas);
				delete[] root->ndrez;
				root->ndrez = naujas;
				size = size + 5;
				root->ndrez[root->n] = b;
				root->n++;
			}
			std::cout << size << std::endl;
			std::cin >> b;
		}
		root->kitas = NULL;
	}
	std::cout << "iveskite varda: ";
	std::cin >> a;
	mokinys *t = root;
	while (a != "0") {
		size = 5;
		t->kitas = new mokinys;
		t = t->kitas;
		t->vardas = a;
		std::cout << "iveskite pavarde: ";
		std::cin >> t->pavarde;
		std::cout << "iveskite egzamino rezultata: ";
		std::cin >> t->egzaminorez;
		t->ndrez = new int[size];
		std::cout << "iveskite namu darbu rezultatus: ";
		std::cin >> b;
		while (b != 0) {
			if (t->n < size) {
				t->ndrez[t->n] = b;
				t->n++;
			}
			else {
				int *naujas = new int[size + 5];
				std::copy(t->ndrez, t->ndrez + size, naujas);
				delete[] t->ndrez;
				t->ndrez = naujas;
				size = size + 5;
				t->ndrez[t->n] = b;
				t->n++;
			}
			std::cin >> b;
		}
		t->kitas = NULL;
		std::cout << "iveskite varda: ";
		std::cin >> a;
	}
}

void vidurkis(mokinys *root) {
	mokinys *t = root;
	int i, s;
	while (t) {
		s = 0;
		i = 0;
		for (int i = 0; i < t->n; i++) {
			s = s + t->ndrez[i];
		}
		t->vid =(double) s / t->n;
		t->galutinis_vid = 0.4*t->vid + 0.6*t->egzaminorez;
		t = t->kitas;
	}
}

void mediana(mokinys *root) {
	mokinys *t = root;
	while (t) {
		rikiavimas(t->ndrez,t->n);
		if (t->n % 2 == 0) {
			t->med =(double) (t->ndrez[t->n / 2] + t->ndrez[t->n / 2 - 1])/2;
		}
		else {
			t->med = t->ndrez[t->n / 2];
		}
		t->galutinis_med = 0.4*t->med + 0.6*t->egzaminorez;
		t = t->kitas;
	}
}

void rikiavimas(int A[], int n) {
	int t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i] < A[j]) {
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}
}

void spausdinimas(mokinys *root) {
	mokinys *t = root;
	char p;
	std::cout << "jei galutini bala skaiciuoti pagal vidurki rasykite v, jei pagal mediana - m"<<std::endl;
	std::cin >> p;
	if (p == 'v') {
		std::cout << std::left << std::setw(21) << "Pavardė" << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Galutinis (Vid.)" << std::endl;
		while (t) {
			std::cout << std::left << std::setw(20) << t->pavarde << std::left << std::setw(20) << t->vardas;
			std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << t->galutinis_vid << std::endl;
			t = t->kitas;
		}
	}
	else if (p == 'm') {
		std::cout << std::left << std::setw(21) << "Pavardė" << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Galutinis (Med.)" << std::endl;
		while (t) {
			std::cout << std::left << std::setw(20) << t->pavarde << std::left << std::setw(20) << t->vardas;
			std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << t->galutinis_med << std::endl;
			t = t->kitas;
		}
	}
}

void istrinti(mokinys *root) {
	mokinys *t = root;
	while (t) {
		root = t->kitas;
		delete[]t->ndrez;
		delete t;
		t = root;
	}
	delete root;
}