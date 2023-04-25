//Elaborar un programa que evalúe un número, si es par agregarlo a una pila, si es impar, agregarlo a una cola

#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
	struct nodo *ptrAnt;
};

typedef struct nodo nodo;

nodo *ptrPri=NULL,*ptrUlt=NULL;

void Ingresar();
void mostrar();

int main(){
	int op;
	do{
		printf("-----Menu-----\n");
		printf("1.Ingresar\n2.mostrar\n3.Salir\n");
		printf("Dame la opci%cn: ",162);
		scanf("%d",&op);
		switch(op){
			case 1: Ingresar(); break;
			case 2: mostrar(); break;
			case 3: break;
			default: printf("Ingrese una opcion correcta\n"); break;
		}
	}while(op!=3);
}

void Ingresar(){
	nodo *ptrNuevo=(nodo*)malloc(sizeof(nodo));
	printf("Ingrese un numero\n");
	scanf("%d",&ptrNuevo->dato);
	if (ptrNuevo->dato%2==0){
	    if (ptrPri==NULL){
			ptrPri=ptrNuevo;
			ptrUlt=ptrNuevo;
			ptrPri->ptrSig=NULL;
		}else{
			ptrUlt->ptrSig=ptrNuevo;
			ptrNuevo->ptrAnt=ptrUlt;
			ptrUlt=ptrNuevo;
			ptrUlt->ptrSig=NULL;
		}
	}else{
		if(ptrPri==NULL){
			ptrPri=ptrNuevo; 
			ptrUlt=ptrNuevo;
			ptrPri->ptrAnt=NULL;
			ptrUlt->ptrSig=NULL;
		} else{
			ptrPri->ptrAnt=ptrNuevo;
			ptrNuevo->ptrSig=ptrPri;
			ptrPri=ptrNuevo;
			ptrPri->ptrAnt=NULL;
		}
	}
}
void mostrar(){
		nodo *ptrAux;
    if(ptrPri==NULL)
        printf("Se encuantra vacio");
    else{
        ptrAux=ptrPri;
        do{
            printf("[%d] ",ptrAux->dato);
            ptrAux=ptrAux->ptrSig;
        }while(ptrAux!=NULL);
    }
    printf("\n\n");
}