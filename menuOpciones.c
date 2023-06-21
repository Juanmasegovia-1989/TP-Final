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

  / void menuPrincipal ()
 {
        int opcion;
        printf("\n\t>>>>> MENU PRINCIPAL: <<<<<<\n");
        printf( "\n   1. Pacientes.");
        printf( "\n   2. Practicas.");
        printf( "\n   3. Laboratorio." );
        printf( "\n   4. Salir." );
        printf( "\n\n   Introduzca opcion (1-4): ");

        scanf( "%d", &opcion );
        switch ( opcion )
        {
        default: system("cls");
            printf("Ingrese una opcion valida \n");
            menuPrincipal();
            break;
            case 1: system("cls");
                    MenuPacientes();
                    break;

            case 2: system("cls");
                    MenuPracticas();
                    break;

            case 3: system("cls");
                    MenuLaboratorios();
                    break;

            case 4: printf("\n   Salir \n\n\n\n");
                    break;
        }    opcion;

 }*/
