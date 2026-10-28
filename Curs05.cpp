//#include <iostream>
//
//using namespace std;
//
//class Marker {
//private:
//	static int numarObiecte;
//	const int id;
//	string culoare;
//	float greutate;
//	int lungime;
//	char* producator;
//public:
//	class Capac {
//	private:
//		int lungime;
//	public:
//		Capac() {
//			this->lungime = 3;
//		}
//		Capac(int lungime) {
//			this->lungime = lungime;
//		}
//		int getLungimeTotala(Marker m){
//			return this->lungime + m.lungime;
//		}
//	};
//	friend void functieGlobala(Marker m);
//};
//
//void functieGlobala(Marker m) {
//	m.culoare = "Rosu";
//}
//
//int suma(int a, int b) {
//	return a + b;
//}
//float suma(float a, float b) {
//	return a + b;
//}
//char suma(char a, char b) {
//	return a + b;
//}
//
//void main() {
//	cout << suma(6, 7.5);
//	Marker::Capac c;
//}