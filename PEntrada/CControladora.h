#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Resultados.h"
#include "CEmpleado.h"

using namespace std;
using namespace PEntrada;

class CControladora
{
public:
	CControladora(){
		r1 = r2 = r3 = 0;
	}
	~CControladora(){}
	void agregarDatos(int edad, char p1, char p2, char p3){
		empleado = new CEmpleado();
		empleado->setedad(edad);
		empleado->getencuesta()->setp1(p1);
		empleado->getencuesta()->setp2(p2);
		empleado->getencuesta()->setp3(p3);
		empleados.push_back(empleado);
	}
	void calcularReportes() {
		for (auto& i : empleados) {
			if (i->getencuesta()->getp1() == 'D') r1++;
			if (i->getencuesta()->getp2() == 'B') r2++;
			if (i->getencuesta()->getp1() == 'B' && i->getencuesta()->getp3() == 'B') r3++;
		}
		if (r2 > 0) {
			r2 = r2 * 100.0 / empleados.size();
		}
		txt = "Cantidad de empleados que indican que definitivamente no reciben un salario adecuado por su trabajo: " +
			to_string(r1) + "\n\nPorcentaje de empleados que señalan que a menudo las tareas asignadas ayudan a desarrollar su aspecto profesional: " +
			to_string(r2) + "\n\nCantidad de empleados que si reciben un salario adecuado y si están satisfechos con su empleo: " + to_string(r3);
	}
	void ordenarDatos() {
		sort(empleados.begin(), empleados.end(), [](CEmpleado*& a, CEmpleado*& b) { return  a->getedad() < b->getedad(); });
		txt += "\n\nN°\tEdad\tP1\tP2\tP3";
		for (int i = 0; i < empleados.size(); i++) {
			txt += "\n" + to_string(i + 1) + "\t" + to_string(empleados.at(i)->getedad()) + "\t" + empleados.at(i)->getencuesta()->getp1() + "\t" +
				empleados.at(i)->getencuesta()->getp2() + "\t" + empleados.at(i)->getencuesta()->getp3();
		}
	}
	void mostrarReporte() {
		Resultados^ resultado = gcnew Resultados();
		calcularReportes();
		ordenarDatos();
		String^ texto = gcnew String(txt.c_str());
		resultado->setDatos(texto);
		resultado->imprimirReporte();
		resultado->ShowDialog();
	}
private:
	int r1, r3;
	float r2;
	string txt;
	CEmpleado* empleado;
	vector<CEmpleado*> empleados;
};