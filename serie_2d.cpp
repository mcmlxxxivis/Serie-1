//Implementa una cola circular para avanzar en un tablero circular de 30 casillas, los datos se tiran aleatoriamente.

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
        printf("1.Generar.\n2.Mostrar de incio a fin.\n3.Mover a la derecha.\n4.Mover a la izquierda.\n5.Salir\n");
        printf("Dame la opci%cn: ",162);
        scanf("%d",&op);
        switch(op){
            case 1: generar();break;
            case 2: mostrarIni();break;
            case 3: moverDer();break;
            case 4: moverIzq();break;
            case 5: break;
            default: printf("Dame un valor de la lista\n");
        }
        printf("\n");
    }while(op!=5);
}
void generar(){
    srand(time(NULL));
    for(int i=1;i<=30;i++){//Genera numeros hasta n
        nodo *ptrNuevo=(nodo*)malloc(sizeof(nodo));
        ptrNuevo->Dato=rand()%30+1;//Valor de nodo nuevo
        if(ptrPri==NULL){
            ptrPri=ptrNuevo;
            ptrUlt=ptrNuevo;
            ptrPri->ptrAnt=NULL;
            ptrPri->ptrSig=NULL;
        }else{
            ptrPri->ptrAnt=ptrNuevo;
            ptrNuevo->ptrSig=ptrPri;
            ptrPri=ptrNuevo;
            ptrPri->ptrAnt=ptrUlt;
        }
        ptrUlt->ptrSig=ptrPri;
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
        }while(ptrAux!=ptrUlt->ptrSig);
    }
    printf("\n");
}
void moverDer(){
    nodo *ptrAux;
    if(ptrPri==NULL)
        printf("Se encuantra vacio");
    else{
        if(j==0){
            ptrAux=ptrPri;
            printf("[%d] ",ptrAux->Dato);
            //ptrAux=ptrAux->ptrSig;
            ptrPos=ptrAux;
            j=j+1;
        }else{
            ptrAux=ptrPos;
            ptrAux=ptrAux->ptrSig;
            printf("[%d] ",ptrAux->Dato);
            ptrPos=ptrAux;
        }
    }    
    printf("\n");
}
void moverIzq(){
   nodo *ptrAux;
    if(ptrPri==NULL)
        printf("Se encuantra vacio");
    else{
        if(j==0){
            ptrAux=ptrPri;
            printf("[%d] ",ptrAux->Dato);
            //ptrAux=ptrAux->ptrAnt;
            ptrPos=ptrAux;
            j=j+1;
        }else{
            ptrAux=ptrPos;
            ptrAux=ptrAux->ptrAnt;
            printf("[%d] ",ptrAux->Dato);
            ptrPos=ptrAux;
        }
    }
    printf("\n"); 
}