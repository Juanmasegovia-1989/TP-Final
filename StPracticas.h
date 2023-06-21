#ifndef STPRACTICAS_H_INCLUDED
#define STPRACTICAS_H_INCLUDED
typedef struct
{
int idPractica; /// campo �nico y autoincremental
char nombre[30];
int costo; /// valores enteros entre 1000 y 10000 como m�nimos y m�ximos respectivamente
int baja; /// 0 si est� activo - 1 si est� eliminado
} StPracticas;

#endif // STPRACTICAS_H_INCLUDED
