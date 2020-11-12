#include "Arbol.h"


Arbol::Arbol(void){
	this->raiz=NULL;
}
void Arbol::crearRaiz(string dato1,string dato2){
	if(raiz==NULL){
		Nodo* nuevo= new Nodo(dato1);
		Nodo* nuevo2= new Nodo(dato2);
		nuevo->setSi(nuevo2);
		raiz= nuevo;
	}
}
void Arbol::insertar(Nodo* papa,string dato1,string dato2){		
	if(papa!=NULL){	
		Nodo* nuevo= new Nodo(dato1);
		Nodo* nuevo2= new Nodo(dato2);
		nuevo->setSi(nuevo2);
		nuevo->setNo(papa);
		Nodo* papaito=buscarPapa(papa->getDato(),raiz );
		if(papaito!=NULL){
			if(papaito->getSi()->getDato()==papa->getDato() ){
				papaito->setSi(nuevo);
			}else{
				if(papaito->getNo()->getDato()==papa->getDato() ){
				papaito->setNo(nuevo);
				}	
			}
		}else{
			cout<<"ERROR"<<endl;
		}
	}			
}
void Arbol::insertar(string papa,string dato1,string dato2){
	this->save(papa,dato1,dato2);
	Nodo* p= buscarElemento(papa,raiz);	
	Nodo* nuevo= new Nodo(dato1);
	Nodo* nuevo2= new Nodo(dato2);
	nuevo->setSi(nuevo2);
	nuevo->setNo(p);
	Nodo* papaito=buscarPapa(papa,raiz );
		if(papaito!=NULL){
			if(papaito->getSi()->getDato()==papa){
				papaito->setSi(nuevo);
			}else{
				if(papaito->getNo()->getDato()==papa ){
				papaito->setNo(nuevo);
				}	
			}
		}else{
			cout<<"ERROR"<<endl;
		}
	//insertar(p,dato1,dato2);
}
void Arbol::insertar(string dato){
	this->save(dato);
	Nodo* nuevo= new Nodo(dato);
	if(!vacio() ){
		Nodo* busca=raiz;
		while(busca->getNo()!=NULL){
			busca=busca->getNo();
		}
		busca->setNo(nuevo);
	}else{
		raiz=nuevo;
	}
}
void Arbol::insertar(string dato,string dato2){	
	this->save(dato,dato2);
	Nodo* nuevo= new Nodo(dato);
	Nodo* nuevo2= new Nodo(dato2);
	nuevo->setSi(nuevo2);
	if(!vacio() ){
		Nodo* busca=raiz;
		while(busca->getNo()!=NULL){
			busca=busca->getNo();
		}
		busca->setNo(nuevo);
	}else{
		raiz=nuevo;
	}
}
Nodo* Arbol::primero(void){
	return raiz;
}
bool Arbol::vacio(void){
	if(raiz==NULL){
		return true;
	}
	return false;
}
Nodo* Arbol::buscarElemento(string dato,Nodo* root){//revisar	
	if(root!=NULL){
		if(root->getDato()==dato){
			return root;
		}
		Nodo* aux=buscarElemento(dato,root->getSi() );
		if(aux!=NULL){
			if(aux->getDato()==dato){
				return aux;
			}
		}
		aux=buscarElemento(dato,root->getNo() );
		if(aux!=NULL){
			if(aux->getDato()==dato){
				return aux;
			}
		}
	}
	return NULL;
}//--o--
Nodo* Arbol::buscarPapa(string dato,Nodo* root){//papa
	if(root!=NULL && (root->getSi()!=NULL || root->getNo()!=NULL) ){
		if(root->getSi()!=NULL ){
			if(root->getSi()->getDato()==dato){
				return root;
			}
		}

		if(root->getNo()!=NULL){
			if(root->getNo()->getDato()==dato){
				return root;
			}
		}
		Nodo* aux=buscarPapa(dato,root->getSi() );
		if(aux!=NULL && (aux->getSi()!=NULL || aux->getNo()!=NULL) ){
			if(aux->getSi()!=NULL ){
				if(aux->getSi()->getDato()==dato){
					return aux;
				}
			}
			if(aux->getNo()!=NULL){
				if(aux->getNo()->getDato()==dato){
					return aux;
				}
			}
		}
		aux=buscarPapa(dato,root->getNo() );
		if(aux!=NULL && (aux->getSi()!=NULL || aux->getNo()!=NULL) ){
			if(aux->getSi()!=NULL ){
				if(aux->getSi()->getDato()==dato){
					return aux;
				}
			}
			if(aux->getNo()!=NULL){
				if(aux->getNo()->getDato()==dato){
					return aux;
				}
			}
		}
	}
	return NULL;
}//--o--
void Arbol::eliminaHijos(Nodo* root){
	if(root!=NULL){
		eliminaHijos(root->getSi() );
		eliminaHijos(root->getNo() );
		if(root->getSi()!=NULL){
			delete root->getSi();
		}
		if(root->getNo()!=NULL){
			delete root->getNo();
		}		
	}
}
void Arbol::impInOrden(Nodo* r){
	if(r != NULL){
		impInOrden(r->getNo() );
		cout<<r->getDato() <<endl;
		impInOrden(r->getSi() );
	}
}
void Arbol::impPosOrden(Nodo* r){
	if(r != NULL){
		impPosOrden(r->getNo() );
		impPosOrden(r->getSi() );
		cout<<r->getDato() <<endl;
		
	}
}
void Arbol::impPreOrden(Nodo* r){
	if(r != NULL){
		cout<<r->getDato() <<endl;
		impPreOrden(r->getNo() );
		impInOrden(r->getSi()  );
	}
}
Nodo* Arbol::obtenerNodo(bool dir, Nodo* root){
	if(dir){
		return root->getSi();
	}
	return root->getNo();
}
void Arbol::save(string dato){
	try{
		ofstream archivo;
		archivo.open( "Datos.txt", ios::out | ios::app );
		if(archivo.fail() ){
			throw exception();
		}
		archivo<<1<<endl;
		archivo<<dato<<endl;
		archivo.close();
	}catch(...){
		cout<<"Algo paso... no se pudo guardar"<<endl;
	}

}
void Arbol::save(string dato,string dato2){
	try{
		ofstream archivo;
		archivo.open( "Datos.txt", ios::out | ios::app );
		if(archivo.fail() ){
			throw exception();
		}
		archivo<<2<<endl;
		archivo<<dato<<endl;
		archivo<<dato2<<endl;	
		
		archivo.close();
	}catch(...){
		cout<<"Algo paso... no se pudo guardar"<<endl;
	}

}
void Arbol::save(string dato,string dato2,string dato3){
	try{
		ofstream archivo;
		archivo.open( "Datos.txt", ios::out | ios::app );
		if(archivo.fail() ){
			throw exception();
		}
		archivo<<3<<endl;
		archivo<<dato<<endl;
		archivo<<dato2<<endl;
		archivo<<dato3<<endl;
		archivo.close();
	}catch(...){
		cout<<"Algo paso... no se pudo guardar"<<endl;
	}

}
void Arbol::saveNivel(string dato){
	try{
		ofstream archivo;
		archivo.open( "Datos.txt", ios::out | ios::app );
		if(archivo.fail() ){
			throw exception();
		}
		archivo<<4<<endl;
		archivo<<dato<<endl;
		archivo.close();
	}catch(...){
		cout<<"Algo paso... no se pudo guardar"<<endl;
	}
}
void Arbol::read(){
	try{
		ofstream preparacion("Carga.txt");
		preparacion.close();

		string dato,dato2,dato3;
		ofstream os;
		os.open( "Carga.txt", ios::out | ios::app );
		ifstream is("Datos.txt",ios::in);
		if(!is | !os){
			throw exception();
		}
		while(! is.eof() ){
			is>>dato;
			os<<dato<<endl;
		}
		is.clear();
		is.close();
		os.close();

		ofstream borrado("Datos.txt");
		borrado.close();
		//--o--
		ifstream iss("Carga.txt",ios::in);
		if(!iss){
			throw exception();
		}
		int opc;		
		while(!iss.eof() ){
			iss>>dato;
			opc=atoi(dato.c_str() );
			switch(opc){
				case 1:
					iss>>dato;
					this->insertar(dato);
					break;
					   
				case 2:
					iss>>dato;
					iss>>dato2;
					this->insertar(dato,dato2);
					break;
					   
				case 3:
					iss>>dato;
					iss>>dato2;
					iss>>dato3;
					this->insertar(dato,dato2,dato3);
					break;

				case 4:
					iss>>dato;
					this->bajarNivel(dato);
					break;					   

			}//end switch

		}//end while
		iss.close();

	}catch(...){
		cout<<"Algo paso... no se pudo cargar"<<endl;
	}
}
bool Arbol::existe(string dato){
	Nodo* busq=this->buscarElemento(dato,raiz);
	if(busq!=NULL){
		if(busq->getDato()==dato){
			return true;
		}
	}
	return false;
}
bool Arbol::bajarNivel(string dato){
	if(this->existe(dato) ){		
		Nodo* elemento=this->buscarElemento(dato,raiz);
		if(elemento->getNo()!=NULL){
			this->saveNivel(dato);
			if(raiz->getDato()==dato){
				Nodo* hijo=elemento->getNo();//abajo de elemento
				elemento->setNo(hijo->getNo()  );
				raiz=hijo;
				hijo->setNo(elemento );		
				return true;
			}else{
				Nodo* papa=this->buscarPapa(dato,raiz);//arriba de elemento
				Nodo* hijo=elemento->getNo();//abajo de elemento
				elemento->setNo(hijo->getNo()  );
				papa->setNo(hijo );				
				hijo->setNo(elemento );				
				return true;
			}
		}
		return false;
	}
	return false;
}
Arbol::~Arbol(void){
	if(!vacio() ){
		eliminaHijos(raiz);
		delete raiz;
	}
}
