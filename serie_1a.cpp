//Capturar los datos

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct nodo{
    char nombre[20];
    int edad;
    char telefono[20];
    struct nodo *ptrSig;
    struct nodo *ptrAnt;
};

typedef struct nodo nodo;

nodo *ptrUlt=NULL,*ptrPri=NULL;

void agregar();
void eliminarFin();
void mostrar();

int main(){
    int opc;
    do{
        printf("----Agenda----\n");
        printf("1.Agregar\n2.Consultar\n3.Eliminar\n4.Salir\n");
        scanf("%d",&opc);
        switch(opc){
            case 1: agregar();break;
            case 2: mostrar();break;
            case 3: eliminarFin();break;
            case 4: break;
            default: printf("No esta esa opci%cn en el menu\n",162);break;
        }
    }while(opc!=4);
}
void agregar(){
    nodo *ptrNuevo;
    ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
    printf("Dame el nombre de tu cuate ");
    fflush(stdin);
    gets(ptrNuevo->nombre);
    printf("Dame su edad ");
    scanf("%d",&ptrNuevo->edad);
    printf("Dame su telefono ");
    fflush(stdin);
    gets(ptrNuevo->telefono);
    printf("\n");
    if(ptrPri==NULL){
        ptrPri=ptrNuevo;
        ptrUlt=ptrNuevo;
        ptrPri->ptrSig=NULL;
    }else{
       ptrUlt->ptrSig=ptrNuevo;
       ptrNuevo->ptrAnt=ptrUlt;
       ptrUlt=ptrNuevo;
       ptrUlt->ptrSig=NULL;
    }
}
void eliminarFin(){
    if(ptrPri==NULL)
        printf("Se encuantra vacio, no se puede eliminar.");
    else{
        ptrUlt=ptrUlt->ptrAnt;
        ptrUlt->ptrSig=NULL;
    }
}
void mostrar(){
    nodo *ptrAux;
    if(ptrPri==NULL)
        printf("Se encuantra vacio");
    else{
        ptrAux=ptrPri;
        do{
            printf("Nombre:%s Edad:%d a%cos Tel:%s\n",ptrAux->nombre,ptrAux->edad,164,ptrAux->telefono);
            ptrAux=ptrAux->ptrSig;
        }while(ptrAux!=ptrUlt->ptrSig);
    }
    printf("\n");
}