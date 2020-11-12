#include "Nodo.h"


Nodo::Nodo(void){
	this->si=NULL;
	this->no=NULL;
	dato="";
}
Nodo::Nodo(string pDato){
	this->si=NULL;
	this->no=NULL;
	dato= pDato;
}
void Nodo::setDato(string pDato){
	this->dato=pDato;
}
string Nodo::getDato(void){
	return this->dato;
}
void Nodo::setSi(Nodo* p){
	this->si=p;
}
Nodo* Nodo::getSi(void){
	return this->si;
}
void Nodo::setNo(Nodo* p){
	this->no=p;
}
Nodo* Nodo::getNo(void){
	return this->no;
}
string Nodo::toString(){
	stringstream ss;
	ss<<dato<<endl;
	return ss.str();
}
Nodo::~Nodo(void){

}
