#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class CArchivo
{
public:
	CArchivo(){}
	~CArchivo(){}
	void escribirArchivo(string nuevo) {
		ofstream fichero("datos.txt");
		fichero << nuevo;
		fichero.close();
	}
private:
};