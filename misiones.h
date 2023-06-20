#ifndef MISIONES_H_INCLUDED
#define MISIONES_H_INCLUDED

typedef struct
{

    int ID;
    int IDnave;
    int estado; /// ( 1 = Listo,2 = En vuelo, 3 = Retornada, 4 =  Cancelada,  5 = Fallida)
    int destino;
    char cargamento[30];
    int IDtripulante_1;
    int IDtripulante_2;
    int IDtripulante_3;
    char detalleDeLaMision[100];


} stMision;


/// FUNCIONES DE MENU


void altaAstronautaMisionViaje(int astronautaID[]);
void bajaDeAstronautaPorMuerte(int astronautaID[]);
int estadoDeDespegueResultado();
int detectarModeloDeNave(int idNave);
int verificacionDeEstadoDeAstronauta(int idCargaAstronauta);
int verificacionDeMisionEntrada(int idMisionVerificacion);
int verificacionDeEstadoDeLaNave(int verificado);



#endif // MISIONES_H_INCLUDED
