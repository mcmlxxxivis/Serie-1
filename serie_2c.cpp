//Implementa una cola circular para mostrar un letrero de nombres, despues ultimo se mostrara el primero

#include<stdio.h>
#include<stdlib.h>

struct nodo{
	char nombre[20];
	nodo *siguiente;
	nodo *anterior;
};

void ingresarIni(),ingresarFin(),mostrarIni(),mostrarFin();

nodo *ptrUlt=NULL;
nodo *ptrPri=NULL;

int main(){
	int op;
	do{
		printf("---Cartel---\n");
		printf("1.- Ingresar el nombre del inicio\n");
		printf("2.- Ingresar el nombre del fin\n");
		printf("3.- Mostrar el cartel de fin a inicio\n");
		printf("4.- Mostrar el cartel de inicio a fin\n");
		printf("5.- Salir c:\n");
		scanf("%d",&op);
		switch (op){
			case 1: ingresarIni();break;
			case 2: ingresarFin();break;
			case 3: mostrarIni();break;
			case 4: mostrarFin();break;
			case 5: break;
			default: printf("No esta esa opci%cn en el menu\n",162);break;
		}
	}while(op!=5);
}
void ingresarIni(){
	nodo *ptrNuevo=(nodo*)malloc(sizeof(nodo));
	printf("Dame el nombre a ingresar: ");
	fflush(stdin);
	gets(ptrNuevo->nombre);
	if(ptrPri==NULL){
		ptrPri=ptrNuevo;
		ptrUlt = ptrNuevo;
		ptrPri->siguiente = NULL;
		ptrPri->anterior = NULL;
	}
	else{
		ptrPri->anterior=ptrNuevo;
		ptrNuevo->siguiente=ptrPri;
		ptrPri=ptrNuevo;
		ptrPri->anterior=ptrUlt;
	}
	ptrUlt->siguiente=ptrPri;
}
void ingresarFin(){
	nodo *ptrNuevo=(nodo*)malloc(sizeof(nodo));
	printf("Dame el nombre a ingresar: ");
	fflush(stdin);
	gets(ptrNuevo->nombre);
	if(ptrPri==NULL){
		ptrPri=ptrNuevo;
		ptrUlt = ptrNuevo;
		ptrPri->siguiente = NULL;
		ptrPri->anterior = NULL;
	}else{
		ptrUlt->siguiente=ptrNuevo;
		ptrNuevo->anterior=ptrUlt;
		ptrUlt=ptrNuevo;
		ptrUlt->siguiente=ptrPri;
	}
	ptrPri->anterior=ptrUlt;
}
void mostrarIni(){
	nodo *ptrAux;
	if(ptrPri==NULL)
		printf("El cartel est%c vac%co\n",160,161);
	else{
	ptrAux=ptrPri;
		do{
			printf("[%s]",ptrAux->nombre);
			ptrAux=ptrAux->siguiente;
            printf("\t");
		}while(ptrAux!=ptrUlt->siguiente);
	}
    printf("\n");
}
void mostrarFin(){
	nodo *ptrAux;
	if(ptrPri==NULL)
		printf("El cartel est%c vac%co\n",160,161);
	else{
		ptrAux=ptrUlt;
		do{
			printf("[%s]",ptrAux->nombre);
			ptrAux=ptrAux->anterior;
            printf("\t");
		}while(ptrAux!=ptrPri->anterior);
	}
    printf("\n");
}