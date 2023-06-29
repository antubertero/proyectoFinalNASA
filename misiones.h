#ifndef MISIONES_H_INCLUDED
#define MISIONES_H_INCLUDED

typedef struct
{

    int ID;
    int IDnave;
    int estado; /// ( 1 = Listo,2 = En vuelo, 3 = Retornada, 4 =  Cancelada,  5 = Fallida 6 = finalizada)
    int destino;
    char cargamento[30];
    int IDtripulante_1;
    int IDtripulante_2;
    int IDtripulante_3;
    char detalleDeLaMision[100];


} stMision;


/// FUNCIONES DE MENU

void altaMision();
void listadoMisiones();
void contasultaIDmision();
void bajaMision();
void despegueDeMision();
void retornoDeLaMision();
int chequeoEstadoNave (int id);
int chequeoAstronauta(int id);
int retornarHorasSegunDestinoDeLaMision(int misionID);
int retornarIDnaveconLaIDmision(int misionID);
void estadoDenaveBaja(int idNave);
void estadoDenaveEnMision(int idnave, int destino);
int retornarIdDePiolotoConIDdeMision(int misionID, int NumeroPiloto);
int detectarModeloDeLaNaveConIDMision(int misionID);
void altaAstronautaMisionViaje(int astronautaID, int destino);
void bajaDeAstronautaPorMuerte(int astronautaID);
int detectarModeloDeNave(int idNave);
int verificacionDeEstadoDeAstronauta(int idCargaAstronauta);
int verificacionDeMisionEntrada(int idMisionVerificacion);
int verificacionDeEstadoDeLaNave(int verificado);
int verificacionDeIDMISION(int entrada);
int verificacionDeEstadoDeLaNave(int verificado);
void establecerAlAstronautaEnModoListoParaOtraMision(int ID);
void cambiarElEstadoDeLaNaveMantenimiento(int ID);
void retornoAstronautaMisionViaje(int astronautaID, int destino);
void estadoDenaveEnretorno(int idNave,int destino);
void modificarEstadoDeAstronautaAMisionAsignada(int ID);
void cambiarEstadoDeLaNaveAMisionAsignada(int ID);
void modificacionDeAstronautaMisionCancelada(int ID);
void modificarEstadoDeLaNavePorMisionCancelada(int ID);
int estadoDeLaMision(int ID);
int contadorDeAstronautasEnEstadoListo();




#endif // MISIONES_H_INCLUDED
