#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "StPaciente.h"
#include "StPracticas.h"
#include "StLaboratorio.h"
#include "menuOpciones.h"
#define ARCHIVO "archivo.bin"
#define AR_Paciente "pacientes.dat"
#define DIM_ARRAY 30
#define ESC 27
#include <string.h>

int main()
{
    int dni=0;
    char nombre, apellido;
    //cargarArchivoPacientes(AR_Paciente);
    mostrarArchivoPacientes (AR_Paciente);

    printf ("\n\n Ingrese DNI a buscar: \n");
    fflush (stdin);
    scanf ("%d",&dni);
    buscarxDni(AR_Paciente, dni);

   /* printf ("\n\n Ingrese apellido: \n");
    fflush (stdin);
    gets (apellido);
    printf ("\n\n Ingrese nombre: \n");
    fflush (stdin);
    gets (nombre);
    void buscarApellidoNombre(AR_Paciente,apellido,nombre);*/
    return 0;
}
