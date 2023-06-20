#ifndef ASTRONAUTAS_H_INCLUDED
#define ASTRONAUTAS_H_INCLUDED

typedef struct
{

    int ID;
    char nombre[40];
    char apellido[40];
    char apodo[40];
    int edad;
    char nacionalidad[40];
    char especialidad[40];
    float horasDeVueloAcumuladas;
    int misionesEspecialesRealizadas;
    float horasAcumuladasEnElEspacioInternacioal;
    int estado; ///(1- Activo 2- Retirado  3 - En viaje 4 - Baja en mision)

} stAstronauta ;

void altaAstronauta();
void darDeBajaAstronauta();
void modificacionAstronauta();
void mostrarListado();

int verificacionDeIdAstronauta(int astronautaIDverficacion);




#endif // ASTRONAUTAS_H_INCLUDED
