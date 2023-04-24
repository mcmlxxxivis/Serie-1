//Programa que al eliminar un elemento de una cola este se agregue en automatico a una pila

#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int Dato;
    struct nodo *ptrSig;
    struct nodo *ptrAnt;
};

typedef struct nodo nodo;

nodo *ptrPriCola=NULL,*ptrUltCola=NULL,*ptrPriPila=NULL,*ptrUltPila=NULL;

void agregar();
void mostrarCola();
void mostrarPila();
void eliminarCola();
void eliminarPila();

main(){
     int op;
    do{
        printf("---Menu---\n");
        printf("1.Agregar.\n2.Mostrar cola.\n3.Mostrara pila.\n4.Eliminar de cola.\n5.Eliminae de pila.\n6.Salir\n");
        printf("Dame la opci%cn: ",162);
        scanf("%d",&op);
        switch(op){
            case 1: agregar();break;
            case 2: mostrarCola();break;
            case 3: mostrarPila();break;
            case 4: eliminarCola();break;
            case 5: eliminarPila();break;
            case 6: break;
            default: printf("Dame un valor de la lista\n");
        }
        printf("\n");
    }while(op!=6);
}
void agregar(){
    nodo *ptrNuevo;
    ptrNuevo=(nodo*)malloc(sizeof(nodo));
    printf("Dame el dato: ");
    scanf("%d",&ptrNuevo->Dato);
    if(ptrPriCola==NULL){
        ptrPriCola=ptrNuevo;
        ptrUltCola=ptrNuevo;
        ptrPriCola->ptrSig=NULL;
    }else{
       ptrUltCola->ptrSig=ptrNuevo;
       ptrNuevo->ptrAnt=ptrUltCola;
       ptrUltCola=ptrNuevo;
       ptrUltCola->ptrSig=NULL;
    }
}
void mostrarCola(){
    nodo *ptrAux;
    if(ptrPriCola==NULL)
        printf("Se encuantra vacio");
    else{
        ptrAux=ptrPriCola;
        do{
            printf("[%d] ",ptrAux->Dato);
            ptrAux=ptrAux->ptrSig;
        }while(ptrAux!=NULL);
    }
    printf("\n");
}
void mostrarPila(){
     nodo *ptrAux;
    if(ptrPriPila==NULL)
        printf("Se encuantra vacio");
    else{
        ptrAux=ptrPriPila;
        do{
            printf("[%d] ",ptrAux->Dato);
            ptrAux=ptrAux->ptrSig;
        }while(ptrAux!=NULL);
    }
    printf("\n");
}
void eliminarCola(){
    nodo *ptrNuevo;
    ptrNuevo=(nodo*)malloc(sizeof(nodo));
    if(ptrPriCola==NULL)
        printf("Se encuantra vacio, no se puede eliminar.");
    else{
        ptrNuevo=ptrPriCola;
        ptrPriCola=ptrPriCola->ptrSig;
        ptrPriCola->ptrAnt=NULL;
        if(ptrPriPila==NULL){
            ptrPriPila=ptrNuevo;
            ptrUltPila=ptrNuevo;
            ptrPriPila->ptrSig=NULL;
        }else{
            ptrUltPila->ptrSig=ptrNuevo;
            ptrNuevo->ptrAnt=ptrUltPila;
            ptrUltPila=ptrNuevo;
            ptrUltPila->ptrSig=NULL;
        }
    }
}
void eliminarPila(){
    if(ptrPriPila==NULL)
        printf("Se encuentra vacio, no se puede eliminar.");
    else{
        ptrUltPila=ptrUltPila->ptrAnt;
        ptrUltPila->ptrSig=NULL;
    }
}