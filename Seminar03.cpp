#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class prajitura {
public:
	char* denumire;
	float pret;
	int cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;
	/*const int id;*/
	prajitura() {
		this->denumire = new char[strlen("Tiramisu") + 1];
		strcpy(denumire, "Tiramisu");
		this->pret = 15;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";
	}

	prajitura(const char*denumire, float pret) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";
	}

	void afisare() {
		cout << "Denumire: " << this->denumire << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Cantitate: " << this->cantitate << endl;
		cout << "De post: " << (this->dePost ? "Da" : "Nu") << endl;
		cout << "Numar ingrediente: " << this->nrIngrediente << endl;
		cout << "Ingredientele sunt: ";
		for (int i = 0; i < this->nrIngrediente; i++) {
			cout << this->ingrediente[i] << "; ";
		}
		cout << endl;
	}

	float costMediuGram() {
		if (this->cantitate == 0)
			return 0;
		else
			return this->pret / this->cantitate;
	}

	void modificaDenumire(const char* denumire) {
		delete this->denumire;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}
};

float calculeazaCantitateTotala(prajitura* prajituri, int nr_prajituri) {
	float greutate = 0;
	for (int p = 0; p < nr_prajituri; p++)
		greutate += prajituri[p].cantitate;
	return greutate;
}

void main() {
	prajitura p;
	prajitura p2("Amandina", 40);
	p.afisare();
	p2.afisare();
	cout << p.costMediuGram();
	prajitura* prajituri;
	prajituri = new prajitura[3];
	prajituri[2].afisare();
	prajituri[1].pret = 50;
	prajituri[2].cantitate = 70;

	prajituri[0].modificaDenumire("Tort");
	prajituri[1].modificaDenumire("Ecler");

	for (int i = 0; i < 3; i++) {
		cout << prajituri[i].denumire << ' ' << prajituri[i].costMediuGram() << endl;
	}
	float greutate_totala = calculeazaCantitateTotala(prajituri, 3);
	cout << "Total: " << greutate_totala << endl;
}