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



StLaboratorios cargaLaboratorio()
{
    StLaboratorios laboratorio;

    printf("Ingrese el ID del paciente \n");
    scanf("%d", &laboratorio.idPaciente);
    printf("Ingrese el anio \n");
    scanf("%d", &laboratorio.anio);
    printf("Ingrese el mes (en numeros) \n");
    scanf("%d", &laboratorio.mes);
    printf("Ingrese el dia \n");
    scanf("%d", &laboratorio.dia);
    printf("Ingrese el ID de la practica realizada \n");
    scanf("%d", &laboratorio.PracticaRealizada);

}
void cargaLaboratorios(char archi[])
{
    StLaboratorios aux;
    FILE * dat = fopen(archi, "ab");

    if(archi != NULL );
    {
        int contador = ultimoId(archi);
        do
        {
            contador++;
            system("cls");
            aux = cargaLaboratorio();
            fflush(stdin);
            aux.idLab = contador;
            fwrite(&aux, sizeof(StLaboratorios), 1, dat);
            printf("\n Ingrese ESC para salir o cualquier tecla para seguir cargando");

        }
        while(getch()!= 27);
        fclose(dat);
    }
}
int ultimoId(char archi[])
{
    int ultId = 0;
    StLaboratorios aux;

    FILE * dat = fopen(archi, "rb");

    if(dat!=NULL)
    {
        fseek(dat, -1*sizeof(StLaboratorios), SEEK_END);
        if(fread(&aux, sizeof(StLaboratorios),1,dat)>0)
        {
            ultId= aux.idLab;
        }fclose(dat);
    }
    return ultId;
}
void mostrarLaboratorio(StLaboratorios aux)
{
    printf("\n ID laboratorio: %d ", aux.idLab);
    printf("\n ID paciente: %d", aux.idPaciente);
    printf("\n Anio: %d", aux.anio);
    printf("\n Mes: %d", aux.mes);
    printf("\n Dia: %d", aux.dia);
    printf("\n ID de la practica realizada: ", aux.PracticaRealizada);

    if(aux.baja!=0)
    {
        printf("El laboratorio esta eliminado \n");
    }else{
    printf("El laboratorio esta activo \n");
    }
}
void mostrarLaboratorios(char archi [])
{
    FILE * dat = fopen(archi, "rb");
    StLaboratorios a;
    system("cls");

    if(dat!=NULL)
    {
        while(fread(&a, sizeof(StLaboratorios), 1, dat)>0)
        {
            mostrarLaboratorio(a);
            printf("\n -----------------------------------------------\n ");
        }fclose(dat);
    }
}
void modificarLaboratorios (char archi[])
{
    int id = modificarxid(archi);
    StLaboratorios aux;
    int flag = 0;

    FILE * dat = fopen(archi, "r+b");
    if (dat != NULL)
    {
        while((!feof(dat))&& (flag == 0))
        {
            fread(&aux, sizeof(StLaboratorios), 1, dat);
            if(aux.idLab == id)
            {
                mostrarLaboratorio(aux);
                aux = cargaLaboratorio();
                fseek(dat, -1*sizeof(stPracticas), SEEK_CUR);
                fwrite(&aux, sizeof(stPracticas), 1, dat);
                flag = 1;
            }
        }fclose(dat);
    }
}
void menuLaboratorios ()
{
    int opc;

    char salir;

    printf("\n PRESIONE ESC PARA SALIR Y VOLVER AL MENU ANTERIOR \n");
    salir=getch();

    while (salir!=ESC){
        printf("\t \t MENU LABORATORIOS \n");
        printf("\t \t 1. Listado de laboratorios \n");
        printf("\t \t 2. Modificar laboratorios \n");
        printf("\t \t 3. Agregar laboratorios \n ");
        printf("\t \t 4. Baja de laboratorios \n ");
        scanf("%d", &opc);

        switch(opc)
        {
        case 1:
            system("cls");
            mostrarLaboratorios(ARCHIVOLABORATORIOS);
            break;

        case 2:
            system("cls");
            modificarLaboratorios(ARCHIVOLABORATORIOS);
            break;

        case 3:
            system("cls");
            fflush(stdin);
            cargaLaboratorios(ARCHIVOLABORATORIOS);
            fflush(stdin);
            break;
        case 4:
            system("cls");
            fflush(stdin);
            ///funcion eliminado logico de labo
            fflush(stdin);
            break;

        default:
            system("cls");
            printf("OPCION NO VALIDA");
            break;
        }
    }
}
