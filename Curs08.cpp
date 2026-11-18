//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class Ghiozdan {
//	char* marca;
//	int capacitate;
//	float greutate;
//	int nrBuzunare;
//public:
//	Ghiozdan() {
//		marca = new char[strlen("Necunoscuta") + 1];
//		strcpy(marca, "Necunoscuta");
//		this->capacitate = 20;
//	}
//	~Ghiozdan() {
//		delete[] marca;
//	}
//
//	const char* getNarca() const {
//		return marca;
//	}
//	int getCapacitate() const {
//		return capacitate;
//	}
//};
//
//class GhiozdanExtensibil :public Ghiozdan {
//private:
//	bool esteExtensibil;
//	int capacitateSuplimentara;
//public:
//	GhiozdanExtensibil() :Ghiozdan() {
//		this->esteExtensibil = true;
//		this->capacitateSuplimentara = 1;
//	}
//	GhiozdanExtensibil(const char* marca, int nrBuzunare, float greutate, int capacitate, bool esteExtensibil, int capSuplimentara) : Ghiozdan(marca, capacitate, greutate,nrBuzunare){
//		this->esteExtensibil = esteExtensibil;
//		this->capacitateSuplimentara = capSuplimentara;
//	}
//	GhiozdanExtensibil(bool esteExtensibil, int capSuplimentara):Ghiozdan("Marca", 20, 10, 3) {
//		this->esteExtensibil = esteExtensibil;
//		this->capacitateSuplimentara = capSuplimentara;
//	}
//
//	~GhiozdanExtensibil() {
//	}
//
//	GhiozdanExtensibil& operator=(const GhiozdanExtensibil& g) {
//		(Ghiozdan)*this = (Ghiozdan)g;
//		this->capacitateSuplimentara = g.capacitateSuplimentara;
//		this->esteExtensibil = g.esteExtensibil;
//		return *this;
//	}
//
//	GhiozdanExtensibil& operator=(const Ghiozdan& g) {
//		(Ghiozdan)*this = (Ghiozdan)g;
//		this->capacitateSuplimentara = 10;
//		this->esteExtensibil = true;
//		return *this;
//	}
//};
//
//void main() {
//	Ghiozdan g;
//	//cout << g;
//	GhiozdanExtensibil ge;
//	cout << getCapacitate();
//
//	GhiozdanExtensibil ge1;
//	ge = ge1;
//
//	g = ge;
//	ge = g;
//}