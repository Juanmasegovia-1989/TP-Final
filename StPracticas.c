#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "StPaciente.h"
#include "StPracticas.h"
#include "StLaboratorio.h"
#include "menuOpciones.h"
#define ARCHIVO "archivo.bin"
#define AR_Paciente "paciente.dat"
#define DIM_ARRAY 30
#define ESC 27
#include <string.h>
#define ARCHIVOPRACTICAS "practicas.dat"
#define ARCHIVOLABORATORIOS "laboratorios.dat"


stPracticas cargaPractica ()
{
    stPracticas practica;

    printf("Ingrese el nombre de la practica: \n");
    gets(practica.nombre);
    printf("Ingrese el costo de la practica: \n");
    scanf("%d", &practica.costo);
    practica.baja = 0;

    return practica;
}
void cargaPracticas(char archi[])
{
    stPracticas aux;
    FILE * dat = fopen(archi, "ab");

    if(archi != NULL );
    {
        int contador = ultimoIdprac(archi);
        do
        {
            contador++;
            system("cls");
            aux = cargaPractica();
            fflush(stdin);
            if (repiteNombre(dat, aux)==1)
            {
                printf("El nombre ingresado ya se encuentra en el sistema\n");
                printf("Ingrese de nuevo los datos \n ");
                aux = cargaPractica();
                fflush(stdin);
            }
            fflush(stdin);
            aux.idPractica = contador;
            fwrite(&aux, sizeof(stPracticas), 1, dat);
            printf("\n Ingrese ESC para salir o cualquier tecla para seguir cargando practicas");

        }
        while(getch()!= 27);
        fclose(dat);
    }
}
void mostrarPractica(stPracticas aux)
{
    printf("\n idPractica..............%d", aux.idPractica);
    printf("\n Nombre..................%s", aux.nombre);
    printf("\n Costo...................%d", aux.costo);
    if(aux.baja!=0)
    {
        printf("\n La practica esta eliminada \n");
    }else{
    printf("\n La practica esta activa \n");
    }
}
void mostrarPracticas(char archi[])
{
    FILE * dat = fopen(archi, "rb");
    stPracticas a;
    system("cls");

    if(dat!=NULL)
    {
        while(fread(&a, sizeof(stPracticas), 1, dat)>0)
        {
            mostrarPractica(a);
            printf("\n -----------------------------------------------\n ");
        }fclose(dat);
    }
}
int ultimoIdprac(char archi[])
{
    int ultId = 0;
    stPracticas aux;

    FILE * dat = fopen(archi, "rb");

    if(dat!=NULL)
    {
        fseek(dat, -1*sizeof(stPracticas), SEEK_END);
        if(fread(&aux, sizeof(stPracticas),1,dat)>0)
        {
            ultId= aux.idPractica;
        }fclose(dat);
    }
    return ultId;
}
int modificarxid(char archi[])
{
    int id;
    printf("Ingrese el ID de la practica que desea modificar datos: ");
    scanf("%d", &id);
    return id;
}
void modificarPractica (char archi[])
{
    int id = modificarxid(archi);
    stPracticas aux;
    int flag = 0;

    FILE * dat = fopen(archi, "r+b");
    if (dat != NULL)
    {
        while((!feof(dat))&& (flag == 0))
        {
            fread(&aux, sizeof(stPracticas), 1, dat);
            if(aux.idPractica == id)
            {
                mostrarPractica(aux);
                printf("\n Ingrese el nuevo nombre de la practica %d: \n", id);
                fflush(stdin);
                gets(aux.nombre);
                printf("Ingrese el nuevo costo de la practica %d: \n", id);
                scanf("%d", &aux.costo);
                fseek(dat, -1*sizeof(stPracticas), SEEK_CUR);
                fwrite(&aux, sizeof(stPracticas), 1, dat);
                flag = 1;
            }
        }fclose(dat);
    }
}
int repiteNombre (char archi[], stPracticas aux)
{
    FILE * dat = fopen(archi, "rb");
    rewind(dat);
    stPracticas aux1;
    int flag = 0;

    if((dat!=NULL)){

    while (fread(&aux1, sizeof(stPracticas), 1, dat)>0)
    {
        if (strcmpi(aux.nombre, aux1.nombre)==0)
        {
            flag = 1;
        }
    }
    return flag;
    fclose(dat);
    }
}
void menuPracticas ()
{
    int opc;
    char salir;

    printf("\n PRESIONE ESC PARA SALIR Y VOLVER AL MENU ANTERIOR \n");
    salir=getch();

    while (salir!=ESC){
    printf("\t \t MENU PRACTICAS \n");
    printf("\t \t 1. Listado de practicas \n");
    printf("\t \t 2. Modificar practicas \n");
    printf("\t \t 3. Agregar practicas \n ");
    scanf("%d", &opc);

    switch(opc)
    {
        case 1: system("cls");
                mostrarPracticas(ARCHIVOPRACTICAS);
                break;

        case 2: system("cls");
                modificarPractica(ARCHIVOPRACTICAS);
                break;

        case 3: system("cls");
                fflush(stdin);
                cargaPracticas(ARCHIVOPRACTICAS);
                fflush(stdin);
                break;

        default: system("cls");
                printf("OPCION NO VALIDA");
                break;
    }
}
}
