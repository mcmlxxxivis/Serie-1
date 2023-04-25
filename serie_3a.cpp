//Capturar los datos

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct nodo{
    int id;
    char nombre[20];
    int edad;
    float altura;
    char correo[30];
    struct nodo *ptrSig;
    struct nodo *ptrAnt;
};

typedef struct nodo nodo;

nodo *ptrUlt=NULL;
nodo *ptrPri=NULL;

void agregarIni();
void agregarFin();
void eliminarFin();
void eliminarIni();
void mostrar();

int main(){
    int opc;
    do{
        printf("----Agenda----\n");
        printf("1.Agregar al inicio\n2.Agregar al fina\n3.Consultar\n4.Eliminar del final\n5.Eliminar del inio\n6.Salir\n");
        scanf("%d",&opc);
        switch(opc){
            case 1: agregarIni();break;
            case 2: agregarFin();break;
            case 3: mostrar();break;
            case 4: eliminarFin();break;
            case 5: eliminarIni();break;
            case 6: break;
            default: printf("No esta esa opci%cn en el menu\n",162);break;
        }
    }while(opc!=6);
}
void agregarIni(){
    srand(time(NULL));
    nodo *ptrNuevo;
    ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
    ptrNuevo->id=rand()%1000+9999;
    printf("Dame el nombre de tu cuate ");
    fflush(stdin);
    gets(ptrNuevo->nombre);
    printf("Dame su edad ");
    scanf("%d",&ptrNuevo->edad);
    printf("Dame su altura ");
    scanf("%f",&ptrNuevo->altura);
     printf("Dame su correo ");
    fflush(stdin);
    gets(ptrNuevo->correo);
    printf("\n");
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
    srand(time(NULL));
    nodo *ptrNuevo;
    ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
    ptrNuevo->id=rand()%1000+9999;
    printf("Dame el nombre de tu cuate ");
    fflush(stdin);
    gets(ptrNuevo->nombre);
    printf("Dame su edad ");
    scanf("%d",&ptrNuevo->edad);
    printf("Dame su altura ");
    scanf("%f",&ptrNuevo->altura);
     printf("Dame su correo ");
    fflush(stdin);
    gets(ptrNuevo->correo);
    printf("\n");
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
void mostrar(){
    nodo *ptrAux;
    if(ptrPri==NULL)
        printf("Se encuantra vacio");
    else{
        ptrAux=ptrPri;
        do{
            printf("ID:%d Nombre:%s Edad:%d a%cos Peso:%g kg Correo:%s\n",ptrAux->id,ptrAux->nombre,ptrAux->edad,164,ptrAux->altura,ptrAux->correo);
            ptrAux=ptrAux->ptrSig;
        }while(ptrAux!=ptrUlt->ptrSig);
    }
    printf("\n");
}