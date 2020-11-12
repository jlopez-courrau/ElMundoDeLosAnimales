#pragma once
#include"Arbol.h"

class Sistema{
private:
	Arbol* arbol;
public:
	Sistema(void);
	void agregar(string);
	void agregar(string, string);
	void agregar(string, string,string);
	Nodo* getRaiz();	
	bool bajarNIvel(string);
	void mostrarEnOrden();
	void mostrarEnPreOrden();
	void mostrarEnPosOrden();

	~Sistema(void);
};

