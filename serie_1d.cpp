//Implementa una lista ligada doble circular 

#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int Dato;
    struct nodo *ptrSig;
    struct nodo *ptrAnt;
};

typedef struct nodo nodo;

nodo *ptrPri=NULL,*ptrUlt=NULL;

void impUrgente();
void impNormal();
void mostrarIni();

int main(){
    int op,prioridad;
    do{
        printf("---Impresi%cn---\n",162);
        printf("1.Agregar a la cola.\n2.Imprimir.\n3.Salir\n");
        printf("Dame la opci%cn: ",162);
        scanf("%d",&op);
        switch(op){
            case 1: 
                do{
                    printf("Ingrese la prioridad\n");
                    printf("1.Urgente\n2.Normal\n");
                    scanf("%d",&prioridad);
                    switch(prioridad){
                        case 1: impUrgente();break;
                        case 2: impNormal();break;
                        default: printf("Dame un valor de la lista\n");
                    }
                }while(prioridad>2);break;
            case 2: mostrarIni();break;
            case 3: break;
            default: printf("Dame un valor de la lista\n");
        }
        printf("\n");
    }while(op!=3);
}
void impUrgente(){
    nodo *ptrNuevo=(nodo*)malloc(sizeof(nodo));
    printf("Dame el dato a imprimir: ");
    scanf("%d",&ptrNuevo->Dato);
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
}
void impNormal(){
    nodo *ptrNuevo=(nodo*)malloc(sizeof(nodo));
    printf("Dame el dato a imprimir: ");
    scanf("%d",&ptrNuevo->Dato);
    if(ptrPri==NULL){
        ptrPri=ptrNuevo;
        ptrUlt=ptrNuevo;
        ptrPri->ptrSig=NULL;
        ptrUlt->ptrAnt=NULL;
    }else{
       ptrUlt->ptrSig=ptrNuevo;
       ptrNuevo->ptrAnt=ptrUlt;
       ptrUlt=ptrNuevo;
       ptrUlt->ptrSig=NULL;
    }
}
void mostrarIni(){
    nodo *ptrAux;
    if(ptrPri==NULL)
        printf("No hay nada que imrpimir");
    else{
        ptrAux=ptrPri;
        do{
            printf("---Impresi%cn en curso---[%d] ",162,ptrAux->Dato);
            ptrAux=ptrAux->ptrSig;
            printf("\n");
        }while(ptrAux!=ptrUlt->ptrSig);
        do{
            ptrPri=ptrPri->ptrSig;
            ptrPri->ptrAnt=NULL;
        }while(ptrPri->ptrSig=NULL);
         ptrPri=NULL;
    }
    printf("\n");
}