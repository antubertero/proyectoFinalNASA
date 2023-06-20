#ifndef NAVES_H_INCLUDED
#define NAVES_H_INCLUDED
typedef struct
{

    int ID;
    int  tipoDeNave;  /// 1 = Starship  - 2 = Falcon 9  -   3 = Falcon Heavy
    int cantidadDeVuelosRealizados;
    float horasDeVueloAcumuladas;
    int estado; ///  (0- mantenimiento 1- Lista para su uso 2- Actualmente en misi�n 3- De baja)


} stNave;

/// FUNCIONES MENU

void altaNave();
void bajaNave();
void listadoNaves();
void consultPorIDNAVE();
void modificacionDeNave();

/// DIBUJOS DE NAVES
void imprimirStarship();

void imprimirFalcon9();

void imprimirFalconHeavy();


#endif // NAVES_H_INCLUDED
