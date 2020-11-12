#include "Interfaz.h"


Interfaz::Interfaz(void){
	sistema= new Sistema();
	this->Correr();
}
void Interfaz::gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x; coord.Y = y;
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hStdOut, coord);
	}
int Interfaz::getKey(void){
	int Tecla=getch(); 
		if(Tecla==0xE0 || Tecla==0) 
			Tecla=getch(); 
	return Tecla; 
}
void Interfaz::setColor(unsigned short color){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,color);
}
void Interfaz::Portada(void){
	system("title Proyecto II Natasha Arteaga y Jorge Lopez ");
	system("color f4");//fondo letra
	gotoxy(0,0);
	cout<<endl<<endl<<'\t'<<'\t'<<"\t+++++UNIVERSIDAD NACIONAL+++++"<<endl<<endl;		
	cout<<"\t\t\t     Estrucruras de Datos"<<endl<<endl;
	cout<<"\t\t\t          Profesor:"<<endl;
	cout<<"\t\t\t       Santiago Caamano "<<endl<<endl;
	cout<<"\t\t\t        Estudiantes:"<<endl;
	cout<<"\t\t\t      Natasha Arteaga"<<endl;
	cout<<"\t\t\t     Jorge Lopez Courrau"<<endl<<endl;
	Sleep(5000);
}
void Interfaz::Correr(void){
	this->Portada();
	this->MenuPrincipal();
}
void Interfaz::MenuPrincipal(void){
	int b=1;
	int men=0;
	system("cls");
	while(men!=27){					
		setColor(10);
		system("cls");
		cout<<"\n\n\t\t\t     Menu Principal"
			<<"\n\n\t\t\t        Opciones \n\n";
		if(b==1){cout<<"\t";setColor(112);cout<<"1-> Iniciar\n";
		}else{
		cout<<"\t1-> Iniciar\n";
		}
		setColor(10);
		if(b==2){cout<<"\t";setColor(112);cout<<"2-> Bajar Nivel\n";
		}else{
			cout<<"\t2-> Bajar Nivel\n";
		}			
		setColor(10);
		if(b==3){cout<<"\t";setColor(112);cout<<"3-> Mostrar Arbol en Orden\n";
		}else{
			cout<<"\t3-> Mostrar Arbol en Orden\n";
		}			
		setColor(10);
		if(b==4){cout<<"\t";setColor(112);cout<<"4-> Mostrar Arbol en PosOrden\n";
		}else{
			cout<<"\t4-> Mostrar Arbol en PosOrden\n";
		}			
		setColor(10);
		if(b==5){cout<<"\t";setColor(112);cout<<"5-> Mostrar Arbol en PreOrden\n";
		}else{
			cout<<"\t5-> Mostrar Arbol en PreOrden\n";
		}			
		setColor(10);
		//
		if(b==6){cout<<"\t";setColor(112);}
		cout<<"\n\n\tUtilice las teclas "<<char(24)<<" "<<char(25)<<" y press enter para seleccionar\n"
			<<"\n\t\t\tPara salir press ESC\n";
		men=getKey();
		if(men==ARR||men==ABJ||men==ESC||men==ENT){
			if(men==ARR){b--;}
			if(men==ABJ){b++;}
			if(men==ESC){gotoxy(0,0);}
			if(men==ENT){
				switch(b){
				case 1:{
					system("cls");
					iniciar();
					system("cls");
					break;
						}//case 1
				case 2:{
					system("cls");
					this->bajarNivel();
					system("cls");
					break;
						}//case 2
				case 3:{
					system("cls");
					sistema->mostrarEnOrden();
					system("pause");
					system("cls");
					break;
					   }//case 3
				case 4:{
					system("cls");
					sistema->mostrarEnPosOrden();
					system("pause");
					system("cls");
					break;
					   }//case 4
				case 5:{
					system("cls");
					sistema->mostrarEnPreOrden();
					system("pause");
					system("cls");
					break;
					   }//case 5

				}//end switch
			}
		}
		else{cout<<'\a';}//if(men==ARR||men==ABJ||men==ESC||men==ENT){
		if(b==0){b=5;}
		if(b==6){b=1;}
	}//end while(men!=27)
	system("cls");
}
string Interfaz::ingresaSTring(string texto){
	string dato;
	bool correcto;
	system("cls");
	do{
		cout<<"\n\t "<<texto<<"\n\n";
		cout<<"\t\t---->> ";
		correcto=true;
		dato="";
		if(!(cin>>dato ) ){
			cin.clear();
			cin.ignore(255,'\n');
			correcto=false;
			system("cls");
			cout<<'\a';
			cout<< "\n\n\n\n\n\n\t\t\tTiene que digitar una opcion valida \n"<<
					"\t\t\t          Intente de nuevo.";
			cin.get();
			system("cls");
		}
	}while(correcto==false);
	//--o--
	system("cls");
	return dato;
}
void Interfaz::iniciar(){
	Nodo* root=sistema->getRaiz();
	bool direccion;
	string mensaje;
	string animalActual;
	bool correcto=true;
	while(correcto){
		system("cls");
		animalActual=root->getDato();
		mensaje="Su Animal es "+root->getDato()+"?";
		direccion=siNo(mensaje);
		if(direccion){
			if(root->getSi()==NULL){
				correcto=false;
			}else{
				root=root->getSi();
			}			
		}else{
			if(root->getNo()==NULL){
				correcto=false;
			}else{
				root=root->getNo();
			}	
		}
	}//end while
	if(direccion){
		cout<<"\n\n\n\n\t\t\tEl Sistema ha Acertado con Exito\n\n";
		system("pause");
	}else{
		cout<<"\n\n\n\n\t\t\tEl Sistema ha Fallado\n"
			<<"\t\t\tPor favor ayudenos a mejorar\n\n";
		Sleep(2000);
		string animal=ingresaSTring("Cual era su Animal?");
		string caract=ingresaSTring("cual es la caracteristica del animal?");
		sistema->agregar(animalActual,caract,animal);			
	}

}//end iniciar
bool Interfaz::siNo(string txt){
	int b=1;
	int men=0;
	system("cls");
	while(men!=27){					
		setColor(10);
		system("cls");
		cout<<"\n\n\t\t\t     "<<txt<<"\n\n";			
		if(b==1){cout<<"\t";setColor(112);cout<<"SI\n";
		}else{
		cout<<"\tSI\n";
		}
		setColor(10);
		if(b==2){cout<<"\t";setColor(112);cout<<"NO\n";
		}else{
			cout<<"\tNO\n";
		}			
		setColor(10);
		//
		if(b==3){cout<<"\t";setColor(112);}
		cout<<"\n\n\tUtilice las teclas "<<char(24)<<" "<<char(25)<<" y press enter para seleccionar\n";			
		men=getKey();
		if(men==ARR||men==ABJ||men==ESC||men==ENT){
			if(men==ARR){b--;}
			if(men==ABJ){b++;}
			//if(men==ESC){gotoxy(0,0);}
			if(men==ENT){
				switch(b){
				case 1:{
					return true;
					break;
						}//case 1
				case 2:{
					return false;
					break;
						}//case 2
				}//end switch
			}
		}
		else{cout<<'\a';}//if(men==ARR||men==ABJ||men==ESC||men==ENT){
		if(b==0){b=2;}
		if(b==3){b=1;}
	}//end while(men!=27)
	system("cls");
}
void Interfaz::bajarNivel(){
	string dato=ingresaSTring("Indique Cual desea bajar de nivel");
	if(sistema->bajarNIvel(dato) ){
		system("cls");
		cout<<"\n\n\n\n\n\t\t\t "<<dato <<" bajado UN NIVEL correctamente\n\n" <<endl;
		system("pause");
	}else{
		system("cls");
		cout<<"\n\n\n\n\n\t\t\t ERROR ingreso valor invalido\n\n\t\t\tVerifique que el dato exista y tenga nivel para bajar\n\n" <<endl;
		system("pause");
	}
}
Interfaz::~Interfaz(void){
	delete sistema;
}
