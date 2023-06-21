#ifndef STLABORATORIO_H_INCLUDED
#define STLABORATORIO_H_INCLUDED
typedef struct
{
int idLab; /// campo único y autoincremental
int idPaciente;
int anio;
int mes; /// 1 a 12
int dia; /// 1 a … dependiendo del mes
int PracticaRealizada; /// con códigos entre 1 y 10
} StLaboratorios;












#endif // STLABORATORIO_H_INCLUDED
