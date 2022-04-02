#pragma once
#include "CEncuesta.h"
class CEmpleado
{
public:
	CEmpleado(){
		encuesta = new CEncuesta();
	}
	~CEmpleado(){}
	void setedad(int nuevo) { edad = nuevo; }
	void setencuesta(CEncuesta* nuevo) { encuesta = nuevo; }
	int getedad() { return edad; }
	CEncuesta* getencuesta() { return encuesta; }
private:
	int edad;
	CEncuesta* encuesta;
};