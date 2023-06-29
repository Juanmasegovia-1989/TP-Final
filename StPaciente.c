#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "StPaciente.h"
#include "StPracticas.h"
#include "StLaboratorio.h"
#include "menuOpciones.h"
#define ARCHIVO "archivo.bin"
#define AR_Paciente "pacientes.bin"
#define DIM_ARRAY 30
#define ESC 27
#include <string.h>
#define ARCHIVOPRACTICAS "practicas.dat"
#define ARCHIVOLABORATORIOS "laboratorios.dat"

StPaciente cargaPacientes ()
{
    StPaciente paciente;

    printf ("\n\n\t\t>>>>> INGRESO NUEVO PACIENTE: <<<<<<\n");

    printf ("\n NOMBRE: \n");
    fflush (stdin);
    gets (paciente.nombre);
    printf ("\n APELLIDO: \n");
    fflush (stdin);
    gets (paciente.apellido);
    printf ("\n DNI:\n");
    fflush (stdin);
    scanf ("%d", &paciente.dni);
    printf ("\n Nro. CELULAR:\n");
    fflush (stdin);
    scanf ("%d", &paciente.movil);
    paciente.eliminado =0;

    return paciente;
}
void imprimirUnPaciente(StPaciente paciente)
{

    printf("\n\t>>>>> DATOS PACIENTE: <<<<<<\n");
    printf("\n      ID #: ...............%d",paciente.idPaciente);
    printf("\n    NOMBRE: ...............%s", paciente.nombre);
    printf("\n  APELLIDO: ...............%s", paciente.apellido);
    printf("\n       DNI: ...............%d", paciente.dni);
    printf("\n   Nro.CEL: ...............%d", paciente.movil);
    if(paciente.eliminado==0)
    {
        printf("\n EL PACIENTE ESTA ACTIVO ");
    }else{
    printf("\n EL PACIENTE ESTA INACTIVO");
    }
}
void cargarArchivoPacientes(char archivopacientes[])
{
    char opc =0;
    StPaciente paciente;
    FILE * Arc=fopen(archivopacientes, "a+b");
    if(Arc==NULL)
    {
        Arc=fopen(archivopacientes, "w");
    }
    if(Arc!=NULL)
    {
    int contador= ultimoIdpac(archivopacientes);

        while(opc != ESC)
        {
            contador++;
            paciente =cargaPacientes();
            paciente.idPaciente=contador;

            fwrite(&paciente, sizeof(StPaciente), 1, Arc);
            //system("cls");
            opc =getche ();
        }

        fclose(Arc);
    }
}
int ultimoIdpac (char archivopacientes[])
{
    int endId = 0;

    FILE* Arc = fopen(archivopacientes, "rb");

    if (Arc)
        {
        StPaciente ultimoPaciente;

        fseek(Arc, -1 * sizeof(StPaciente), SEEK_END);

        if (fread(&ultimoPaciente, sizeof(StPaciente), 1, Arc) > 0)
            {
            endId = ultimoPaciente.idPaciente;
            }

        fclose(Arc);
        }

    return endId;
}
void mostrarArchivoPacientes (char archivopacientes[])
{

FILE* Arc = fopen (archivopacientes, "rb");
StPaciente paciente;
   if (Arc!=NULL)
   {
       while (fread (&paciente, sizeof(StPaciente),1,Arc)>0)
       {
           printf("\n=========================================\n");
           imprimirUnPaciente(paciente);
       }
   }
   else
   {
       printf ("\n ERROR en archivo");
   }

   fclose (Arc);
}
void buscarxDni(char archivopacientes[], int dni)
{

FILE *arc=fopen(archivopacientes,"rb");
    StPaciente paciente;

    if (arc!=NULL){
            fread(&paciente,sizeof(StPaciente),1,arc);
       while ((!feof(arc))&&(paciente.dni!=dni)){
            fread(&paciente,sizeof(StPaciente),1,arc);
       }
       if ( dni ==paciente.dni){

            imprimirUnPaciente(paciente);


        puts("\n ----------------------------------");
}

       else
       {

         printf ("\n ERROR en archivo");
       }
    }
    fclose(arc);
}
void buscarApellidoNombre(char archivopacientes[], char nombre[], char apellido[])
{

FILE *arc=fopen(archivopacientes,"rb");
    StPaciente paciente;

    if (arc!=NULL){
            fread(&paciente,sizeof(StPaciente),1,arc);
       while (fread(&paciente,sizeof(StPaciente),1,arc)>0){

       if (strcmpi(apellido, paciente.apellido)==0){


            if (strcmpi(nombre, paciente.nombre)==0){

            imprimirUnPaciente(paciente);


        puts("\n ----------------------------------");
      }
       }
       else
       {

         printf ("\n ERROR en archivo");
       }
    }
    fclose(arc);
}
}

void modificaUnPaciente(int flag )
{
    char opc;
    FILE *arc=fopen(archivopacientes,"ab");
    StPaciente paciente;
    if (arc != NULL)
    {
     if (flag == 0)
    {
        char nombre[30];
        char apellido[30];
        printf("Ingrese el nombre a buscar \n");
        gets(nombre);
        printf("Ingrese el apellido a buscar \n");
        gets(apellido);
        buscarApellidoNombre(AR_Paciente, nombre, apellido);
        fseek(arc, (-1) * sizeof(StPaciente), SEEK_CUR);
    }
    else
    {
        printf("Ingrese el DNI que quiere buscar \n");
        scanf("%d", &dni);
        buscarxDni(AR_Paciente, dni);
        buscarxDni(AR_Paciente, dni);
        fseek(arc, (-1) * sizeof(StPaciente), SEEK_CUR);
    }
    printf(" Desea modificar nombre y apellido S/N \n\n");
    opc=getch();
    if ( strcmpi(opc,'s')
    {
        printf ("\n NOMBRE: \n");
        fflush (stdin);
        gets (paciente.nombre);
    }
    if ( strcmpi(opc,'s')
    {
    printf ("\n APELLIDO: \n");
    fflush (stdin);
    gets (paciente.apellido);
    }
    if ( strcmpi(opc,'s')
    {
    printf ("\n DNI:\n");
    fflush (stdin);
    scanf ("%d", &paciente.dni);
    }
    paciente.eliminado =0;
    fwrite(&paciente, sizeof(StPaciente),1,arc);
    system("cls");
    }
    else
    {
        printf("\n ERROR \n");
    }
    fclose(arc);
}

void modificarPacientes ( char archivopacientes[])
{
    int opc=0;
    char salir;
    int flag;

    printf("\n PRESIONE ESC PARA SALIR Y VOLVER AL MENU ANTERIOR \m");
    salir=getch();

    while ( salir!=ESC)
    {
        printf(" \t \t MENU BUSQUEDA PARA MODIFICAR \n");
        printf("\t \t 1. Busqueda por APELLIDO y NOMBRE \n");
        printf("\t \t 2. Busqueda por DNI \n");
        printf("\t \t 3. Volver MENU ANTERIOR \n");

        scanf("%d", opc);

        switch(opc)
        {
        case 1:
            system("cls");
            fflush(stdin);
            flag=0;
            modificaUnPaciente (flag);
            break;

        case 2:
            flag=1;
            modificaUnPaciente (flag)
            break;

        case 3:
            system("cls");
            fflush(stdin);
            menuPacientes();
            fflush(stdin);
            break;

        default:
            system("cls");
            printf("OPCION NO VALIDA");
            break;
        }
    }

}



void menuPacientes()
{
    int opc=0;
    char salir;

    printf("\n PRESIONE ESC PARA SALIR Y VOLVER AL MENU ANTERIOR \m");
    salir=getch();

    while (salir!=ESC){

    printf("\t \t MENU PACIENTES \n");
    printf("\t \t 1. Listado de pacientes \n");
    printf("\t \t 2. Modificar pacientes \n");
    printf("\t \t 3. Agregar pacientes \n ");
    printf("\t \t 4. Baja de pacientes \n ");
    printf("\t \t 5. Buscar paciente por DNI \n ");
    printf("\t \t 6. Buscar paciente por apellido \n ");
    printf("\t \t 7. Volver al MENU ANTERIOR \n ");
    scanf("%d", &opc);

    switch(opc)
    {
        case 1: system("cls");
                mostrarArchivoPacientes(AR_Paciente);
                break;

        case 2: system("cls");
                fflush(stdin);
                modificarPacientes(AR_Paciente);
                fflush(stdin);
                break;

        case 3: system("cls");
                fflush(stdin);
                cargarArchivoPacientes(ARCHIVOPRACTICAS);
                fflush(stdin);
                break;

        case 4: system("cls");
                fflush(stdin);
                ///funcion baja de paciente
                fflush(stdin);
                break;

        case 5: system("cls");
                int dni;
                printf("Ingrese el DNI que quiere buscar \n");
                scanf("%d", &dni);
                buscarxDni(AR_Paciente, dni);
                break;

        case 6: system("cls");
                char nombre[30];
                char apellido[30];
                printf("Ingrese el nombre a buscar \n");
                gets(nombre);
                printf("Ingrese el apellido a buscar \n");
                gets(apellido);
                buscarApellidoNombre(AR_Paciente, nombre, apellido);
                break;

        case 7: fflush(stdin);
                ///ACA VA LA DIRECCION DEL MENU PPAL
                fflush(stdin);
                system("cls");
                break;


        default: system("cls");
                printf("OPCION NO VALIDA");
                break;
    }
    }
}












