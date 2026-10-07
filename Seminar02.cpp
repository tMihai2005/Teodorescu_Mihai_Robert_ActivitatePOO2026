#include <iostream>

using namespace std;

struct cladire{
	char* culoare;
	float inaltime;
	int nrEtaje;
	bool deschis;
};

cladire citireCladire() {
	cladire c;
	char x[100];
	cout << "Culoare: ";	cin >> x;
	c.culoare = new char[strlen(x) + 1];
	strcpy_s(c.culoare, strlen(x) + 1, x);
	cout << "\nInaltime: ";	cin >> c.inaltime;
	cout << "\nNumar etaje: ";	cin >> c.nrEtaje;
	cout << "\nDeschis (0/1): ";	cin >> c.deschis;
	return c;
}

void modificaNrEtaje(int noulNrEtaje, cladire *c){
	(*c).nrEtaje = noulNrEtaje;
}

void referinta(int noulNrEtaje, cladire &c) {
	c.nrEtaje = noulNrEtaje;
}
void afisareCladire(cladire c) {
	cout << "Culoarea cladirii este: " << c.culoare << endl;
	cout << "Inaltimea cladirii este: " << c.inaltime << endl;
	cout << "Nr. etaje: " << c.nrEtaje << endl;
	cout << "Deschis: " << c.deschis << endl;
}

void main() {
	cladire c = citireCladire();
	afisareCladire(c);
	modificaNrEtaje(8, &c);
	afisareCladire(c);
	referinta(10, c);
	//cladire c;
	//int nrCladiri = 5;
	//cladire* cladiri;
	//cladiri = new cladire[nrCladiri];
	//// cladiri=(cladire*)malloc(sizeof(cladire)*nrCladiri)

	/*char* vectorC;
	vectorC = new char[strlen("POO") + 1];
	strcpy_s(vectorC, strlen("POO") + 1, "POO");*/
}