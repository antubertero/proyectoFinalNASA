#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>

#include "naves.h"
#include "astronautas.h"
///constantes



///PROTOTIPADOS ASTRONAUTA

void altaAstronauta();
void darDeBajaAstronauta();
void modificacionAstronauta();
void mostrarListado();






///MAIN

int main()
{


    MenuPrincipal();



    return 0;
}

///MENU PRINCIPAL

void MenuPrincipal()
{
    int opcion;
    int opcion3;

    system("cls"); /// limpia la pantalla

    printf("BIENVENIDO A LA NASA \n");
    do
    {
        printf("Menu Principal : \n");
        printf("1-Astronautas \n");
        printf("2-Naves\n");
        printf("3-Misiones\n");
        printf("4-Salir\n");

        printf("  \n Ingresar opcion: ");
        scanf("%i",&opcion);

        switch(opcion) //// ANIDAMOS SWITCH DENTRO DE SWITCH PARA GENERAR UN MENU DE OPCIONES ORIENTATIVO.
        {
        case 1:
        {
            system("cls"); /// limpia la pantalla

            int opcion2=0;
            printf("ASTRONAUTAS : \n");
            printf(" 1-Alta \n 2-Baja \n 3-Modificacion \n 4-Consulta \n 5-Listado \n 0-Volver \n\nIngresar opcion:  ");
            scanf("%i",&opcion2);
            switch (opcion2)
            {
            case 1:
                printf("Ingrese un astronauta para dar de ALTA \n");
                /// LLAMAR A LA FUNCION ALTA ASTRONAUTA. HAY QUE CREARLA
                altaAstronauta();

                break;

            case 2 :
                printf("Ingrese un astronauta para dar de BAJA \n");
                /// LLAMAR FUNCION BAJA ASTRONAUTA. HAY QUE CREARLA
                darDeBajaAstronauta();
                break;

            case 3:
                printf("Ingrese un astronauta para MODIFICAR \n");
                /// LLAMAR FUNCION MODIFICACION ASTRONAUTA.
                modificacionAstronauta();
                break;

            case 4:
                printf("Ingrese un ID de astronauta para consultar \n");
                ///LLAMAR FUNCION BUSQUEDA DE ID
                consultaPorID();
                break;

            case 5:
                printf("Listado de astronautas: \n");
                ///LLAMAR FUNCION PARA MOSTRAR TODOS LOS ASTRONAUTAS CARGADOS
                mostrarListado();
                break;

            case 0:
                MenuPrincipal(); ///LLAMAMOS FUNCION MENU PRINCIPAL PARA VOLVER AL PRIMER MENU ESTABLECIDO
                break;
            }
        }
        break;

        case 2:
        {
            system("cls"); /// limpia la pantalla

            int opcion2=0;
            printf("NAVES: \n");
            printf(" 1-Alta \n 2-Baja \n 3-Modificacion \n 4-Consulta \n 5-Listado \n 0-Volver \n\nIngresar opcion:  ");
            scanf("%i",&opcion2);
            switch (opcion2)
            {
            case 1:
                printf("Ingrese una nave para dar de ALTA \n");
                /// LLAMAR A LA FUNCION ALTA NAVE. HAY QUE CREARLA
                altaNave();
                break;

            case 2 :
                printf("Ingrese una nave para dar de BAJA \n");
                /// LLAMAR FUNCION BAJA NAVE. HAY QUE CREARLA
                bajaNave();
                break;

            case 3:
                printf("Ingrese una nave para MODIFICAR \n");
                /// LLAMAR FUNCION MODIFICACION NAVES.
                modificacionDeNave();
                break;

            case 4:
                printf("Ingrese una nave de astronauta para consultar \n");
                ///LLAMAR FUNCION BUSQUEDA DE ID
                consultPorIDNAVE();
                break;

            case 5:
                printf("Listado de naves: \n");
                listadoNaves();
                ///LLAMAR FUNCION PARA MOSTRAR TODOS LAS NAVES CARGADOS
                break;

            case 0:
                MenuPrincipal(); ///LLAMAMOS FUNCION MENU PRINCIPAL PARA VOLVER AL PRIMER MENU ESTABLECIDO
                break;
            }
        }
        break;

        case 3:
        {

            system("cls"); /// limpia la pantalla

            int opcion2=0;
            printf("MISIONES \n 1-Alta \n 2-Baja \n 3-Modificacion \n 4-Consulta \n 5-Listado \n 0-Volver\n\nIngresar opcion:  ");
            scanf("%i",&opcion2);
            switch(opcion2)
            {

            case 1:
                printf("Alta de mision \n");
                altaMision(); /// VALIDAR SI LA NAVE ESTA LISTA PARA DESPEGAR
                break;

            case 2:
                printf("Baja de mision \n"); /// HAY QUE VALIDAR Q NO ESTE ACTIVA
                break;

            case 3:


                printf("Modidicacion de ESTADO de mision \n");

                printf("\n1)Despegue\n2)retorno\n\nIngresar opcion:  ");
                scanf("%i", &opcion3);

                switch(opcion3)
                {

                case 1 :

                    despegueDeMision();

                    break;

                case 2 :

                    /// hacer funcion retorno
                    break;
                }
                break;

            case 4:
                printf("Ingrese un ID de mision para consultar \n");
                contasultaIDmision();
                ///FUNCION MOSTRAR UNA MISION DETERMINADA
                break;

            case 5:
                printf("Listado de misiones : \n");
                listadoMisiones();

                break;

            case 0:
                MenuPrincipal(); ///LLAMAMOS FUNCION MENU PRINCIPAL PARA VOLVER AL PRIMER MENU ESTABLECIDO
                break;
            }
        }
        break;
        }/// FIN SWITCH PRINCIPAL
    }
    while(!opcion == 4);

    system("cls"); /// limpia la pantalla
    printf("\n\n\n\n         GRACIAS POR CONFIAR EN NOSOTROS \n\n\n\n");
    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos



}

/// GRAFICA MENU

void imprimirPuntosSuspensivosCarga()
{
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("...");
        fflush(stdout);
        Sleep(1000);
        printf("\r   \b\b\b");
        fflush(stdout);
        Sleep(1000);
    }
}
