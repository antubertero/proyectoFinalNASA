#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>

#include "astronautas.h"
#include "naves.h"
#include "misiones.h"



///------------------------------------------------------------------------------------------------
///MENU ASTRONAUTA
///------------------------------------------------------------------------------------------------

///FUNCION PARA DAR DE ALTA AL ASTRONAUTA

void altaAstronauta()
{

    system("cls"); /// limpia la pantalla

    printf("\nAstronauta Alta:\n\n");

    FILE *archivo;
    stAstronauta astronauta;
    int astronautaIDverficacion, resultadoVerificado;


    archivo = fopen("listaAstronauta.bin","ab"); /// se tendria que dar la opcion de poder volver a dar de alta. en este caso no se tendiran que volver a cargar los datos anteriores. modificar mas adelante

    if(archivo != NULL)
    {



        printf("\nIngresar los datos del nuevo astronauta:\n\n");
        printf("ID: ");
        scanf("%i", &astronautaIDverficacion);
        resultadoVerificado = verificacionDeIdAstronauta(astronautaIDverficacion);

        if(resultadoVerificado == 0){


           astronauta.ID = astronautaIDverficacion;


        }else{
        system("cls"); /// limpia la pantalla
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        printf("\nLa id YA EXISTE\n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        fclose(archivo);
        altaAstronauta();

        }

        fflush(stdin);
        printf("\nIngresar el nombre:  ");
        scanf("%s", &astronauta.nombre);
        printf("\nIngresar el apellido de %s:  ", astronauta.nombre);
        scanf("%s", &astronauta.apellido);
        printf("\nIngresar el apodo de %s %s : ", astronauta.apellido, astronauta.nombre);
        scanf("%s", &astronauta.apodo);
        printf("\nIngresar la edad de %s:  ", astronauta.apodo);
        fflush(stdin);
        scanf("%i", &astronauta.edad);
        fflush(stdin);
        printf("\nIngresar la nacionalidad  : ");
        scanf("%s", &astronauta.nacionalidad);
        printf("\nIngresar la especialidad: ");
        scanf("%s", &astronauta.especialidad);
        fflush(stdin);

        /// los siguientes datos son iguales a cero ya que es nuevo y no tiene experiencia en el espacion.

        astronauta.horasDeVueloAcumuladas = 0;
        astronauta.misionesEspecialesRealizadas = 0;
        astronauta.horasAcumuladasEnElEspacioInternacioal = 0;
        astronauta.estado = 1; /// activo. dado de alta

        fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);








        fclose(archivo);

        imprimirPuntosSuspensivosCarga();
        printf("\n\nLOS DATOS SE CARGARON CON EXITO \n\n %s  FORMA PARTE DEL EQUIPO SPACEX\n\n", astronauta.apodo);
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    }
    else
    {

        printf("\nNo se pudo abrir el archivo\n");

    }


    MenuPrincipal();

}

///FUNCION PARA DAR DE BAJA AL ASTRONAUTA

void darDeBajaAstronauta()
{
    int IDBuscado, salida =0;
    stAstronauta astronauta;

    system("cls"); /// limpia la pantalla

    printf("\nAstronauta BAJA:\n\nIngresar un CERO para volver al menu\n");
    printf("\nIngresar el ID: ");
    scanf("%i", &IDBuscado);
    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    if(IDBuscado == 0)
    {
        MenuPrincipal();
    }

    FILE* archivo;
    int validacion;

    archivo = fopen("listaAstronauta.bin", "r+b");

    if(archivo != NULL)
    {
        while(fread(&astronauta, sizeof(astronauta), 1, archivo) != NULL && salida == 0)
        {
            if(astronauta.ID == IDBuscado)
            {
                printf("\nAstronauta encontrado\n");
                printf("\n\nATENCION !! SE DARA DE BAJA AL ASTRONAUTA %s\n\nIngresar un cero para confirmar, ingresar cualquier otro valor para cancelar la baja\n", astronauta.apodo);
                scanf("%i", &validacion);
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                if(validacion == 0)
                {

                    astronauta.estado = 2; /// 2 dado de baja
                    printf("El astronauta con el ID %i fue dado de baja\n", IDBuscado);
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    fseek(archivo, -sizeof(stAstronauta), SEEK_CUR);
                    fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);
                    salida = 1;
                }
                else
                {

                    printf("\nLa baja se cancelo\n");
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    MenuPrincipal();
                }
            }
            else
            {

                printf("El ID ingresado no se encontr� en el archivo\n");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                darDeBajaAstronauta();
            }
        }

        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    MenuPrincipal();
}

/// FUNCION PARA MODIFICAR EL ASTRONATA

void modificacionAstronauta()
{
    stAstronauta astronauta;
    int datoModificado;
    int contador = 0;
    int verificador = 0;

    system("cls"); /// limpia la pantalla

    printf("\nModificaci�n de Astronauta:\n\n");

    FILE* archivo;

    archivo = fopen("listaAstronauta.bin", "rb");

    if (archivo != NULL)
    {
        while (fread(&astronauta, sizeof(stAstronauta), 1, archivo) == 1)
        {
            printf("\n\nLISTADO:\n\n");
            printf("%i - %i %s %s\n", contador + 1, astronauta.ID, astronauta.apellido, astronauta.nombre);
            contador++;
        }

        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    printf("\nIngresar el ID que deseas modificar: ");
    scanf("%i", &datoModificado);

    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    archivo = fopen("listaAstronauta.bin", "rb+");

    if (archivo != NULL)
    {
        while (fread(&astronauta, sizeof(stAstronauta), 1, archivo) == 1)
        {
            if (datoModificado == astronauta.ID)
            {
                printf("\nAstronauta encontrado, se puede modificar");

                printf("\nIngresar el nombre: ");
                scanf("%s", astronauta.nombre);
                printf("Ingresar el apellido: ");
                scanf("%s", astronauta.apellido);
                printf("Ingresar el apodo: ");
                scanf("%s", astronauta.apodo);
                printf("Ingresar la edad: ");
                scanf("%i", &astronauta.edad);
                printf("Ingresar la nacionalidad: ");
                scanf("%s", astronauta.nacionalidad);
                printf("Ingresar la especialidad: ");
                scanf("%s", astronauta.especialidad);

                fseek(archivo, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);

                printf("\n\nDATOS MODIFICADOS CON EXITO\n\n");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                fclose(archivo);
                verificador = 1;

            }
        }

        if(verificador == 0){

            printf("\nNo se encontr� el ID\n");

        }

        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        fclose(archivo);
        fflush(stdin);
        MenuPrincipal();
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }
    MenuPrincipal();

}

///FUNCION PARA MOSTRAR EL LISTADO

void mostrarListado()
{

    system("cls"); /// limpia la pantalla

    printf("\nListado de astronautas\n");

    FILE* archivo;
    stAstronauta astronauta;

    int contador = 0;

    archivo = fopen("listaAstronauta.bin", "rb");

    if (archivo != NULL)
    {
        while (fread(&astronauta, sizeof(stAstronauta), 1, archivo) > 0) /// el ultimo de la lista lo muestra dos veces
        {


            printf("\n\nLISTADO:\n\n");
            printf("%i - %i %s %s\n", contador + 1, astronauta.ID, astronauta.apellido, astronauta.nombre);

            printf("   ESTADO: ");
            if(astronauta.estado==1){
                printf("ACTIVO");

            }else if(astronauta.estado == 2){

            printf("RETIRADO");

            }



            contador++;



        }

        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
    printf("\nIngresar CERO para salir ");

    int opcion;
    scanf("%i", &opcion);
    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    if (opcion == 0)
    {
        MenuPrincipal();
    }
    else
    {
        printf("\nIngresaste un numero invalido\n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        MenuPrincipal();
    }
}

///CONSULTQA POR ID BUSQUEDA

void consultaPorID()
{



    FILE* archivo;

    int busquedaConsultar;

    stAstronauta astronauta;

    system("cls"); /// limpia la pantalla

    int verificador = 0;

    archivo = fopen("listaAstronauta.bin", "rb");

    if(archivo != NULL)
    {

        printf("\n\nIngresar el ID que quieras consultar\n\nIngresar opcion:  ");
        scanf("%i", &busquedaConsultar);
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        while(fread(&astronauta, sizeof(stAstronauta), 1, archivo) == 1 )
        {

            if(busquedaConsultar == astronauta.ID)
            {

                printf("\n\nSe encontro la ID\n");

                printf(" %i %s %s\n", astronauta.ID, astronauta.apellido, astronauta.nombre);
                printf("\nApodo: %s \nEdad: %i\nNacionalidad: %s\nEspecialidad: %s\nHoras de vuelo acumuladas: %i\nCantidad de misiones especiales: %i\nHoras Acumuladas en el espacio: %f\nEstado: %i", astronauta.apodo, astronauta.edad, astronauta.nacionalidad, astronauta.especialidad, astronauta.horasDeVueloAcumuladas, astronauta.misionesEspecialesRealizadas, astronauta.horasAcumuladasEnElEspacioInternacioal, astronauta.estado);
                verificador = 1;


            }



        }

        if(verificador == 0){

            printf("\nNo se encontro la ID\n");

        }

        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos



        fclose(archivo);

        int opcion;
        printf("\ningresar 1 para buscar otra ID, ingresar un 0 para volver al menu\n\nIngresar opcion:  ");
        scanf("%i", &opcion);
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        if(opcion == 1)
        {


            consultaPorID();

        }
        else
        {

            MenuPrincipal();

        }

    }
    else
    {

        printf("\nEl archivo no se pudo ejecutar");

    }

}




/// funciones adicionales


int verificacionDeIdAstronauta(int astronautaIDverficacion){

FILE* archivo;

stAstronauta astronauta;

int salida = 0;

archivo = fopen("listaAstronauta.bin", "rb");

if(archivo != NULL){

    while(fread(&astronauta, sizeof(stAstronauta), 1, archivo)>0){

        if(astronautaIDverficacion == astronauta.ID){

            salida = 1;

        }


    }

    fclose(archivo);

}else{

printf("\nNo se pudo ejecutar el archivo\n");

}

return salida;

}
