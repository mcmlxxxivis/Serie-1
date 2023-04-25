//Apartir del ejercicio 1 se vaciara, eliminado el numero mayor comparado entre el numero que esta al inicio y el numero que etsa al final

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct nodo{
    int dato;
    struct nodo *ptrSig;
    struct nodo *ptrAnt;
};

typedef struct nodo nodo;

nodo *ptrPri=NULL,*ptrUlt=NULL,*ptrPos;

void generar();
void mostrarIni();
void eliminarMay();

int main(){
    int op;
    do{
        printf("---Menu---\n");
        printf("1.Generar.\n2.Mostrar.\n3.Eliminar valor mas grande\n4.Salir\n");
        printf("Dame la opci%cn: ",162);
        scanf("%d",&op);
        switch(op){
            case 1: generar();break;
            case 2: mostrarIni();break;
            case 3: eliminarMay();break;
            case 4: break;
            default: printf("Dame un valor de la lista\n");
        }
        printf("\n");
    }while(op!=4);
}
void generar(){
    srand(time(NULL));
    for(int i=1;i<=100;i++){//Genera numeros hasta n
        nodo *ptrNuevo=(nodo*)malloc(sizeof(nodo));
        ptrNuevo->dato=rand()%20+10;//Valor de nodo nuevo
        if(ptrPri==NULL){
            ptrPri=ptrNuevo;
            ptrUlt=ptrNuevo;
            ptrPri->ptrAnt=NULL;
            ptrPri->ptrSig=NULL;
        }else{
            ptrPri->ptrAnt=ptrNuevo;
            ptrNuevo->ptrSig=ptrPri;
            ptrPri=ptrNuevo;
            ptrPri->ptrAnt=NULL;
        }
        ptrUlt->ptrSig=NULL;
    }
}
void mostrarIni(){
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
    printf("\n");
}
void eliminarMay(){
	nodo *ptrAux;
	if(ptrPri==NULL){
		printf("La cola esta vacia");
	}else if(ptrPri->dato>ptrUlt->dato){
		ptrAux=ptrPri;
		ptrPri=ptrAux->ptrSig;
		free(ptrAux);
	}else{
		ptrAux=ptrPri;
		while(ptrAux->ptrSig!=ptrUlt){
			ptrAux=ptrAux->ptrSig;
		}
		ptrUlt=ptrAux;
		ptrAux=ptrUlt->ptrSig;
		free(ptrAux);
		ptrUlt->ptrSig=NULL;
	}
}











