//Implementar una cola doble que se llenara con 100 numeros aleatorios entre el 10 y 20
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct nodo{
    int Dato;
    struct nodo *ptrSig;
    struct nodo *ptrAnt;
};

typedef struct nodo nodo;

nodo *ptrPri=NULL,*ptrUlt=NULL,*ptrPos;
int j=0;

void generar();
void mostrarIni();
void moverDer();
void moverIzq();

int main(){
    int op;
    do{
        printf("---Menu---\n");
        printf("1.Generar.\n2.Mostrar.\n3.Salir\n");
        printf("Dame la opci%cn: ",162);
        scanf("%d",&op);
        switch(op){
            case 1: generar();break;
            case 2: mostrarIni();break;
            case 3: break;
            default: printf("Dame un valor de la lista\n");
        }
        printf("\n");
    }while(op!=3);
}
void generar(){
    srand(time(NULL));
    for(int i=1;i<=100;i++){//Genera numeros hasta n
        nodo *ptrNuevo=(nodo*)malloc(sizeof(nodo));
        ptrNuevo->Dato=rand()%20+10;//Valor de nodo nuevo
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
            printf("[%d] ",ptrAux->Dato);
            ptrAux=ptrAux->ptrSig;
        }while(ptrAux!=NULL);
    }
    printf("\n");
}