#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Prajitura {
private:
	char* denumire;
	float pret;
	int cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;
	const int id;
	static int contor;
public:
	friend class Student;
	Prajitura():id(contor++) {
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

	Prajitura(const char*denumire, float pret):id(contor++) {
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

	Prajitura(const Prajitura& p):id(contor++) {
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);

		this->pret = p.pret;
		this->cantitate = p.cantitate;
		this->dePost = p.dePost;
		this->nrIngrediente = p.nrIngrediente;

		this->ingrediente = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->ingrediente[i] = p.ingrediente[i];
		}
	}
	~Prajitura(); //declarare destructor

	Prajitura& operator=(const Prajitura& P1) {
		if (this != &P1) {
			this->cantitate = P1.cantitate;
			if (this->denumire != NULL)
				delete[]this->denumire;
			this->denumire = new char[strlen(P1.denumire) + 1];
			strcpy(this->denumire, P1.denumire);
			this->dePost = P1.dePost;
			this->pret = P1.pret;
			this->nrIngrediente = P1.nrIngrediente;
			if (this->ingrediente != NULL)
				delete[]this->ingrediente;
			this->ingrediente = new string[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->ingrediente[i] = P1.ingrediente[i];
			}
		}
		return *this;
	}

	//geteri si seteri
	int getCantitate() {
		return this->cantitate;
	}
	int getPret() {
		return this->pret;
	}
	int getNrIngrediente() {
		return this->nrIngrediente;
	}
	static int getContor() {
		return contor;
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

int Prajitura::contor = 100;

Prajitura::~Prajitura() {//implementare destructor
	delete[] this->denumire;
	delete[] this->ingrediente;
}

float calculeazaCantitateTotala(Prajitura* prajituri, int nr_prajituri) {
	float greutate = 0;
	for (int p = 0; p < nr_prajituri; p++)
		greutate += prajituri[p].getCantitate();
	return greutate;
}

float calculeazaPretPerIngredient(Prajitura p) {
	if (p.getNrIngrediente() != 0)
		return p.getPret() / p.getNrIngrediente();
}

class Student {
private:
	string nume;
	Prajitura prajitura;
public:
	Student() {
		this->nume = "Andrei";
	}
	Student(string nume, Prajitura p) {
		this->nume = nume;
		this->prajitura = p;
	}
	string getNume() {
		return this->nume;
	}
	Prajitura getPrajitura() {
		return this->prajitura;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	void setPrajitura(Prajitura p) {
		this->prajitura = p;
	}
	float calculeazaNrTotalCalorii(float caloriiPerGram) {
		float nrTotal = caloriiPerGram * this->prajitura.getCantitate();
		return nrTotal;
	}
	void afiseazaMasa() {
		cout << this->nume << " mananca prajitura " << this->prajitura.denumire << endl;
	}
};



void main() {
	/*Prajitura p;
	Prajitura p2("Amandina", 40);
	p.afisare();
	p2.afisare();
	cout << p.costMediuGram();
	Prajitura* prajituri;
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
	cout << "Total: " << greutate_totala << endl;*/
	Prajitura p;
	p.afisare();
	Prajitura* pp;
	//(*pp).afisare();
	//pp->afisare();
	Prajitura::getContor();
	Prajitura P1("amandina", 20);
	Student s1("Cristian", P1);
	s1.afiseazaMasa();
	cout << s1.calculeazaNrTotalCalorii(0.5);
	//p = P1;
	//P1 = P1;
	cout << calculeazaPretPerIngredient(p);
}