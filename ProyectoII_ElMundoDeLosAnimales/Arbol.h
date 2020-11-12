#pragma once
#include "Nodo.h"
#include <fstream>

class Arbol{
private:
	Nodo* raiz;	

public://faltan montones de metodos
	Arbol(void);
	void crearRaiz(string,string);	
	void insertar(Nodo*,string,string);
	void insertar(string,string,string);
	void insertar(string);//ojo
	void insertar(string,string);
	Nodo* primero(void);
	bool vacio(void);
	Nodo* obtenerNodo(bool, Nodo*);
	Nodo* buscarElemento(string,Nodo*);
	Nodo* buscarPapa(string,Nodo*);
	void eliminaHijos(Nodo*);
	void impInOrden(Nodo* r);
	void impPosOrden(Nodo* r);
	void impPreOrden(Nodo* r);
	void save(string);
	void save(string,string,string);
	void save(string,string);
	void saveNivel(string);
	void read();
	bool existe(string);
	bool bajarNivel(string);
	~Arbol(void);

};

