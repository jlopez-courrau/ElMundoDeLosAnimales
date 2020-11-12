#pragma once
#include <iostream>
#include <string>
#include<stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include "Sistema.h"//sistema

using namespace std;


#define ARR 72 
#define ABJ 80 
#define DER 77 
#define IZQ 75
#define ENT 13
#define ESC 27
class Interfaz{
private:
	Sistema* sistema;
public:
	Interfaz(void);
	void gotoxy(int, int);
	int getKey(void);
	void setColor(unsigned short color);
	void Portada(void);
	void MenuPrincipal(void);
	void Correr(void);
	string ingresaSTring(string);	
	void iniciar();
	bool siNo(string);
	void bajarNivel();
	~Interfaz(void);
};

