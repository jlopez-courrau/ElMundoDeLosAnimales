#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Nodo{

private:
	string dato;
	Nodo* si;
	Nodo* no;

public:
	Nodo(void);
	Nodo(string);
	~Nodo(void);	
	void setDato(string);
	string getDato(void);
	void setSi(Nodo*);
	Nodo* getSi(void);
	void setNo(Nodo*);
	Nodo* getNo(void);
	string toString();

};

