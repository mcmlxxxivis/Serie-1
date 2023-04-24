//Del 1 al 100 guardar los numeros pares al inicio de una cola doble y los impares al final de la misma cola doble 

#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int Dato;
    struct nodo *ptrSig;
    struct nodo *ptrAnt;
};

typedef struct nodo nodo;

nodo *ptrPri=NULL,*ptrUlt=NULL;

void agregarIni();
void agregarFin();
void mostrarIni();
void mostrarFin();
void eliminarFin();
void eliminarIni();


int main(){
    int op;
    do{
        printf("---Menu---\n");
        printf("1.Agregar al inicio.\n2.Agregar al final.\n3.Mostrar de incio a fin.\n4.Mostrar de fin a inicio.\n5.Eliminar del fin.\n6.Eliminae del inicio.\n7.Salir\n");
        printf("Dame la opci%cn: ",162);
        scanf("%d",&op);
        switch(op){
            case 1: agregarIni();break;
            case 2: agregarFin();break;
            case 3: mostrarIni();break;
            case 4: mostrarFin();break;
            case 5: eliminarFin();break;
            case 6: eliminarIni();break;
            case 7: break;
            default: printf("Dame un valor de la lista\n");
        }
        printf("\n");
    }while(op!=7);
}
void agregarIni(){
    nodo *ptrNuevo=(nodo*)malloc(sizeof(nodo));
    printf("Dame el dato: ");
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
void agregarFin(){
    nodo *ptrNuevo=(nodo*)malloc(sizeof(nodo));
    printf("Dame el dato: ");
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
void mostrarFin(){
    nodo *ptrAux;
    if(ptrUlt==NULL)
        printf("Se encuantra vacio");
    else{
        ptrAux=ptrUlt;
        do{
            printf("[%d] ",ptrAux->Dato);
            ptrAux=ptrAux->ptrAnt;
        }while(ptrAux!=NULL);
    }
    printf("\n");
}
void eliminarFin(){
  if(ptrPri==NULL)
        printf("Se encuantra vacio, no se puede eliminar.");
    else{
        ptrUlt=ptrUlt->ptrAnt;
        ptrUlt->ptrSig=NULL;
    }
}
void eliminarIni(){
   if(ptrPri==NULL)
        printf("Se encuantra vacio, no se puede eliminar.");
    else{
        ptrPri=ptrPri->ptrSig;
        ptrPri->ptrAnt=NULL;
    }
}