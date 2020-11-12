#include "Sistema.h"


Sistema::Sistema(void){
	arbol= new Arbol();
	arbol->read();
	/*
	arbol->insertar("ave","aguila");	
	arbol->insertar("Reptil","Lagarto");
	arbol->insertar("Mamifero","Perro");
	arbol->insertar("Perro","maulla","Gato");
	arbol->insertar("maulla","acuatico","Ballena");
	arbol->insertar("Pez","Betta");
	arbol->insertar("invertebrado","Araña");
	arbol->insertar("Anfibio","Rana");
	arbol->insertar("Culebra");
	*/
}

void Sistema::agregar(string dato){
	arbol->insertar(dato);
}
void Sistema::agregar(string dato, string dato2){
	arbol->insertar(dato,dato2);	
}
void Sistema::agregar(string dato, string dato2,string dato3){
	arbol->insertar(dato,dato2,dato3);
}
Nodo* Sistema::getRaiz(){
	return arbol->primero();
}
bool Sistema::bajarNIvel(string dato){
	return arbol->bajarNivel(dato);
}
void Sistema::mostrarEnOrden(){
	arbol->impInOrden(arbol->primero() );
}
void Sistema::mostrarEnPreOrden(){
	arbol->impPreOrden(arbol->primero() );
}
void Sistema::mostrarEnPosOrden(){
	arbol->impPosOrden(arbol->primero() );
}
Sistema::~Sistema(void){	
	delete arbol;
}
