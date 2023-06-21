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
    printf("\n      ID #: ............... %d",paciente.idPaciente);
    printf("\n    NOMBRE: ...............%s", paciente.nombre);
    printf("\n  APELLIDO: ...............%s", paciente.apellido);
    printf("\n       DNI: ............... %d", paciente.dni);
    printf("\n   Nro.CEL: ............... %d", paciente.movil);
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
    int contador= ultimoId(archivopacientes);

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

int ultimoId (char archivopacientes[])
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
int i=0;
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
void buscarxDni(char archivopacientes[], int dni){

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
void buscarApellidoNombre(char archivopacientes[], char nombre, char apellido){

FILE *arc=fopen(archivopacientes,"rb");
    StPaciente paciente;

    if (arc!=NULL){
            fread(&paciente,sizeof(StPaciente),1,arc);
       while ((!feof(arc))&&(paciente.apellido!=apellido)&&(paciente.nombre!=nombre)){
            fread(&paciente,sizeof(StPaciente),1,arc);
       }
       if ( apellido ==paciente.apellido){


            if ( nombre ==paciente.nombre){

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
}
