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

    printf("\n----------------\nASTRONAUTA ALTA:\n----------------\n\n");

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

        if(resultadoVerificado == 0)
        {


            astronauta.ID = astronautaIDverficacion;


        }
        else
        {
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

        fflush(stdin);
        int confirmacionEdad = 0;
        int edadVerificacion;
        while(confirmacionEdad == 0)
        {

            printf("\nIngresar la edad: ");
            scanf("%i", &edadVerificacion);

            if(edadVerificacion > 17 && edadVerificacion<61)
            {

                astronauta.edad = edadVerificacion;
                confirmacionEdad = 1;

            }
            else
            {

                printf("\nLa edad NO cumple con los requisitos tiene que ser mayor o igual a 18 y menor o igual a 60\n\nIngresar nuevamente la edad: \n");

            }


        }

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
        system("cls"); /// limpia la pantalla
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

    printf("\n----------------\nBAJA ASTRONAUTA:\n----------------\n\nIngresar un CERO para volver al menu\n");
    printf("\nIngresar el ID: ");
    scanf("%i", &IDBuscado);
    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    if(IDBuscado == 0)
    {

        MenuPrincipal();

    }

    int entrada = estadoDeAstronauta(IDBuscado);

    if(entrada == 1)
    {



        FILE* archivo;
        int validacion;

        archivo = fopen("listaAstronauta.bin", "r+b");

        if(archivo != NULL)
        {
            while(fread(&astronauta, sizeof(astronauta), 1, archivo) >0 && salida == 0)
            {
                if(astronauta.ID == IDBuscado)
                {
                    system("cls"); /// limpia la pantalla
                    printf("\nID DE ASTRONAUTA ENCONTRADA\n");
                    printf("\n\nATENCION !! SE DARA DE BAJA AL ASTRONAUTA %s\n\nIngresar un UNO para confirmar, ingresar cualquier otro valor para cancelar la baja\n", astronauta.apodo);
                    scanf("%i", &validacion);
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    if(validacion == 1)
                    {

                        astronauta.estado = 2; /// 2 dado de baja
                        system("cls"); /// limpia la pantalla
                        printf("El astronauta con el ID %i fue dado de baja\n", IDBuscado);
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                        fseek(archivo, -sizeof(stAstronauta), SEEK_CUR);
                        fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);
                        salida = 1;
                    }
                    else
                    {

                        printf("\nLA BAJA SE CANCELO\n");
                        fclose(archivo);
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                        MenuPrincipal();
                    }
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
    else if(entrada == 2 || entrada == 3 || entrada == 4 || entrada == 5)
    {
        system("cls"); /// limpia la pantalla
        printf("\nEL astronauta no esta en condicines de dar de baja");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    }
    else if(entrada == -1)
    {
        system("cls"); /// limpia la pantalla
        printf("\nLa id ingresada no existe");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

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
    int entrada;

    system("cls"); /// limpia la pantalla

    printf("\n----------------\MODIFICACION DE ASTRONAUTA:\n----------------\n\n\n\n ");

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

    printf("\n\nIngresar el ID que deseas modificar: ");
    scanf("%i", &datoModificado);

    int validacion = estadoDeAstronauta(datoModificado);

    if(validacion == 1 )
    {

        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

        archivo = fopen("listaAstronauta.bin", "r+b");

        if (archivo != NULL)
        {
            while (fread(&astronauta, sizeof(stAstronauta), 1, archivo) == 1)
            {
                if (datoModificado == astronauta.ID)
                {
                    printf("\nAstronauta ECONTRADO, se puede modificar");

                    printf("\nIngresar el nombre: ");
                    scanf("%s", astronauta.nombre);
                    printf("Ingresar el apellido: ");
                    scanf("%s", astronauta.apellido);
                    printf("Ingresar el apodo: ");
                    scanf("%s", astronauta.apodo);
                    int confirmacionEdad = 0;
                    int edadVerificacion;
                    while(confirmacionEdad == 0)
                    {

                        printf("Ingresar la edad: ");
                        scanf("%i", &edadVerificacion);

                        if(edadVerificacion > 17 && edadVerificacion<61)
                        {


                            astronauta.edad = edadVerificacion;
                            confirmacionEdad = 1;

                        }
                        else
                        {

                            printf("\nLa edad cumple NO cumple con los requisitos tiene que ser mayor i igual a 18 y menor o igual a 60\n\nIngresar nuevamente la edad: \n");

                        }


                    }

                    printf("Ingresar la nacionalidad: ");
                    scanf("%s", astronauta.nacionalidad);
                    printf("Ingresar la especialidad: ");
                    scanf("%s", astronauta.especialidad);

                    fseek(archivo, -sizeof(stAstronauta), SEEK_CUR);
                    fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);

                    system("cls"); /// limpia la pantalla
                    printf("\n\nDATOS MODIFICADOS CON EXITO\n\n");
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    fclose(archivo);
                    verificador = 1;

                }
            }

            if(verificador == 0)
            {
                system("cls"); /// limpia la pantalla
                printf("\nNo se encontro el ID\n");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

            }


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
    else if(entrada == 2 || entrada == 3 || entrada == 4 || entrada == 5)
    {

        system("cls"); /// limpia la pantalla
        printf("\nEL astronauta no esta en condicines de dar de baja\n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    }
    else if(entrada == -1)
    {
        system("cls"); /// limpia la pantalla
        printf("\nLa id ingresada no existe\n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    }

    MenuPrincipal();





}

///FUNCION PARA MOSTRAR EL LISTADO

void mostrarListado()
{

    system("cls"); /// limpia la pantalla

    printf("\n----------------\nLISTADO DE ASTRONAUTAS:\n----------------\n\n");

    FILE* archivo;
    stAstronauta astronauta;

    int contador = 0;

    archivo = fopen("listaAstronauta.bin", "rb");

    if (archivo != NULL)
    {
        printf("\n\nLISTADO:\n\n");
        while (fread(&astronauta, sizeof(stAstronauta), 1, archivo) > 0) /// el ultimo de la lista lo muestra dos veces
        {


            printf("\n----------\n");
            printf("\n%i - \n=> ID : %i \n=> APELLIDO : %s\n=> NOMBRE=> %s\n", contador + 1, astronauta.ID, astronauta.apellido, astronauta.nombre); ///(1- Activo 2- Retirado  3 - En viaje 4 - Baja en mision)

            printf("\n=>ESTADO: ");
            switch(astronauta.estado)
            {

            case 1 :
                printf("Listo");
                break;

            case 2 :
                printf("Retirado");
                break;

            case 3 :
                printf("En viaje");
                break;

            case 4 :
                printf("Baja en mision");
                break;

            case 5:
                printf("Mision asignada");
                break;


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

    system("cls"); /// limpia la pantalla

    printf("\n----------------\nCONSULTA POR ID:\n----------------\n\n");

    FILE* archivo;

    int busquedaConsultar;

    stAstronauta astronauta;


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
                system("cls"); /// limpia la pantalla
                printf("\n\nSE ENCONTRO LA ID\n");

                printf("=> ID : %i \n=> APELLIDO: %s\n=> NOMBRE: %s\n", astronauta.ID, astronauta.apellido, astronauta.nombre);
                printf("\n=> APODO: %s\n=> EDAD: %i\n=> NACIONALIDAD: %s\n=> ESPECIALIDAD: %s", astronauta.apodo, astronauta.edad, astronauta.nacionalidad, astronauta.especialidad);
                printf("\n=> HORAS DE VUELO ACUMULADAS: %f\n=> HORAS DE VUELO ACUMULADAS EN EL ESPACIO INTERNACIONAL: %f\n=> MISIONES TOTALES: %i\n=> ESTADO: ", astronauta.horasDeVueloAcumuladas, astronauta.horasAcumuladasEnElEspacioInternacioal, astronauta.misionesEspecialesRealizadas);

                switch(astronauta.estado)
                {

                case 1 :
                    printf("Listo");
                    break;

                case 2 :
                    printf("Retirado");
                    break;

                case 3 :
                    printf("En viaje");
                    break;

                case 4 :
                    printf("Baja en mision");
                    break;
                case 5:
                    printf("Mision asignada");
                    break;


                }

                verificador = 1;


            }



        }

        if(verificador == 0)
        {

            system("cls"); /// limpia la pantalla
            printf("\n\nNO SE ENCONTRO LA ID\n");

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
    MenuPrincipal();

}




/// funciones adicionales

int estadoDeAstronauta(int IDBuscado)
{

    stAstronauta astronauta;
    int salida = -1;

    FILE* archivo;
    archivo = fopen("listaAstronauta.bin","rb");

    if(archivo != NULL)
    {

        while(fread(&astronauta, sizeof(stAstronauta), 1, archivo)>0)
        {

            if(IDBuscado == astronauta.ID)
            {

                salida = astronauta.estado;
                fclose(archivo);

            }

        }
        fclose(archivo);


    }
    else
    {

        printf("\nNo se pudo abrir el archivo\n");

    }


    return salida;

}


int verificacionDeIdAstronauta(int astronautaIDverficacion)
{

    FILE* archivo;

    stAstronauta astronauta;

    int salida = 0;

    archivo = fopen("listaAstronauta.bin", "rb");

    if(archivo != NULL)
    {

        while(fread(&astronauta, sizeof(stAstronauta), 1, archivo)>0)
        {

            if(astronautaIDverficacion == astronauta.ID)
            {

                salida = 1;

            }


        }

        fclose(archivo);

    }
    else
    {

        printf("\nNo se pudo ejecutar el archivo\n");

    }

    return salida;

}
