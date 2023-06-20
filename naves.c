#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "naves.h"
#include <time.h>
#include "astronautas.h"
#include "misiones.h"
#include <windows.h>

///------------------------------------------------------------------------------------------------
///MENU NAVE
///------------------------------------------------------------------------------------------------

///ALTA NAVE
void altaNave()
{

    system("cls"); /// limpia la pantalla

    printf("\nAlta de nave \n\n");

    FILE* archivo;
    stNave nave;
    int opcionTipoDeNave, naveIDverficacion, resultadoVerificado;
    int valido = 0;

    archivo = fopen("listaNave.bin","ab");

    if(archivo != NULL)
    {

        printf("\nIngresar la ID de la nave:  ");
        scanf("%i", &naveIDverficacion);

        resultadoVerificado = verificacionDeIdnaves(naveIDverficacion);

        if(resultadoVerificado == 0){

            nave.ID = naveIDverficacion;



        }else{


         system("cls"); /// limpia la pantalla
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        printf("\nLa id YA EXISTE\n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        fclose(archivo);
        altaNave();



        }

        do
        {
            printf("\nIngresar el tipo de nave:\n");
            printf("    1) Starship\n");
            printf("    2) Falcon 9\n");
            printf("    3) Falcon Heavy\n");
            printf("Ingresar opcion: ");
            scanf("%i", &opcionTipoDeNave);

            if(opcionTipoDeNave > 0 && opcionTipoDeNave < 4)
            {
                nave.tipoDeNave = opcionTipoDeNave;
                valido = 1;
            }
            else
            {
                printf("\nOpcion no valida. Por favor, ingresa una opcion valida.\n");
            }



        }
        while(valido != 1);

        /// nave nueva no tiene vuelos.
        nave.cantidadDeVuelosRealizados = 0;
        nave.horasDeVueloAcumuladas = 0;
        nave.estado = 1; ///(0- mantenimiento 1- Lista para su uso 2- Actualmente en misi�n 3- De baja)

        fwrite(&nave, sizeof(stNave), 1, archivo);


        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        printf("\n\nNAVE CARGADA EXITOSAMENTE\n\n ");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos



        fclose(archivo);

    }
    else
    {

        printf("\nNo se pudo ejecutar el archivo\n");


    }

    MenuPrincipal();





}

///BAJA MAVE  //// algo funciona mal

void bajaNave()
{

    system("cls"); /// limpia la pantalla

    stNave nave;
    int IDbuscado;
    printf("\nBaja nave\n\nIngresar la ID de la nave\n\nIngresar opcion:  ");
    scanf("%i", &IDbuscado);

    FILE* archivo;
    int opcionConf, valido = 0, contador = 1, lugarMemoria;


    archivo = fopen("listaNave.bin", "r+b");


    if(archivo != NULL)
    {


        while(fread(&nave, sizeof(stNave), 1, archivo) > 0)
        {



            if(IDbuscado ==  nave.ID)
            {

                printf("\nID Encontrado\n\n1) dar de baja \n2)No dar de baja\nIngresar opcion:  ");
                scanf("%i",&opcionConf);
                if(opcionConf == 1)
                {

                    fseek(archivo, -sizeof(stNave), SEEK_SET);
                    /// hacer funcion que devuelva el lugar donde se encontro.

                    nave.estado = 3; /// baja
                    fwrite(&nave, sizeof(stNave), 1, archivo);
                    printf("\nLa nave se dio de baja con exito\n");
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    valido = 1;
                    fclose(archivo);

                    MenuPrincipal();

                }
                else
                {

                    printf("\nSe aborto la baja\n");
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    fclose(archivo);
                    MenuPrincipal();

                }

            }

        }

        if(valido == 0)  /// no se encontro la nave
        {

            printf("No se pudo encontrar la id Ingresada");
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
            fclose(archivo);
            MenuPrincipal();

        }
    }
    else
    {

        printf("\nNo se pudo ejecutar el archivo\n");

        MenuPrincipal();


    }



}

///LISTADO DE NAVES

void listadoNaves()
{
    system("cls"); /// limpia la pantalla
    printf("\n\nListado de naves\n");

    FILE* archivo;
    stNave nave;

    archivo = fopen("listaNave.bin","rb");

    if (archivo != NULL)
    {
        while (fread(&nave, sizeof(stNave), 1, archivo) > 0)
        {
            printf("\n-----------------------------------------------------\n\n");
            if(nave.tipoDeNave == 1 )  /// 1 = Starship  - 2 = Falcon 9  -   3 = Falcon Heavy
            {

                imprimirStarship();

            }
            else if(nave.tipoDeNave == 2)
            {

                imprimirFalcon9();

            }
            else if(nave.tipoDeNave == 3)
            {

                imprimirFalconHeavy();

            }


            printf("\n\n----\nID: %i \nTipo de nave: ", nave.ID);
            if (nave.tipoDeNave == 1)
            {
                printf("Starship\n");
            }
            else if (nave.tipoDeNave == 2)
            {
                printf("Falcon9\n");
            }
            else if (nave.tipoDeNave == 3)
            {
                printf("FalconHeavy\n");
            }

            printf("Cantidad de vuelos realizados: %i\nHoras de vuelo acumuladas: %f\nEstado: ", nave.cantidadDeVuelosRealizados, nave.horasDeVueloAcumuladas);

            if (nave.estado == 0)
            {
                printf("mantenimiento\n");
            }
            else if (nave.estado == 1)
            {
                printf("Lista para su uso\n");
            }
            else if (nave.estado == 2)
            {
                printf("Actualmente en misi�n\n");
            }
            else if (nave.estado == 3)
            {
                printf("De baja\n");
            }

            printf("\n\n");
        }

        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    Sleep(1000); /// proceso espere durante aproximadamente 10 segundos
    int salida;
    printf("\nIngresar cualquer NUMERO para volver al menu:   ");
    scanf("%i", &salida);
    salida =1;
    if(salida == 1)
    {

        MenuPrincipal();
    }


}

///CONSULTA POR ID


void consultPorIDNAVE()
{

    system("cls"); /// limpia la pantalla

    stNave nave;

    int idBuscado, validos = 0;

    FILE* archivo;

    archivo = fopen("listaNave.bin","rb");




    if(archivo != NULL)
    {

        printf("\nIngresar la ID de la nave que quieras BUSCAR:  \n\nIngresar opcion:  ");
        scanf("%i", &idBuscado);

        while(fread(&nave, sizeof(stNave), 1, archivo) > 0)
        {


            if(idBuscado == nave.ID)
            {

            printf("\n-----------------------------------------------------\n\n");
            if(nave.tipoDeNave == 1 )  /// 1 = Starship  - 2 = Falcon 9  -   3 = Falcon Heavy
            {

                imprimirStarship();

            }
            else if(nave.tipoDeNave == 2)
            {

                imprimirFalcon9();

            }
            else if(nave.tipoDeNave == 3)
            {

                imprimirFalconHeavy();

            }


                printf("\nID encontrado\n\n");
                printf("Tipo de nave: ");


                if (nave.tipoDeNave == 1)
                {
                    printf("Starship\n");
                }
                else if (nave.tipoDeNave == 2)
                {
                    printf("Falcon9\n");
                }
                else if (nave.tipoDeNave == 3)
                {
                    printf("FalconHeavy\n");
                }

                printf("Cantidad de vuelos realizados: %i\nHoras de vuelo acumuladas: %f\nEstado: ", nave.cantidadDeVuelosRealizados, nave.horasDeVueloAcumuladas);

                if (nave.estado == 0)
                {
                    printf("mantenimiento\n");
                }
                else if (nave.estado == 1)
                {
                    printf("Lista para su uso\n");
                }
                else if (nave.estado == 2)
                {
                    printf("Actualmente en misi�n\n");
                }
                else if (nave.estado == 3)
                {
                    printf("De baja\n");
                }

                printf("\n\n");

                validos = 1;





            }



        }

        if(validos == 0)
        {

            printf("\nNo se encontro el ID :  %i\n", idBuscado);



        }

        Sleep(10000); /// proceso espere durante aproximadamente 10 segundos
        fclose(archivo);
        MenuPrincipal();



    }
    else
    {

        printf("\nNo se pudo ejecutar el archivo\n");
        MenuPrincipal();



    }






    MenuPrincipal();





}


///MODIFICACION DE NAVE
void modificacionDeNave()  /// no funciona preguntar al profe
{

    system("cls"); /// limpia la pantalla

    FILE* archivo;

    int modificarID, valido = 0;

    stNave nave;

    archivo = fopen("listaNave.bin","r+b");

    if(archivo != NULL)
    {

        printf("\n\nIngresar la ID que quieres modificar:  ");
        scanf("%i", &modificarID);

        while(fread(&nave, sizeof(stNave), 1, archivo) > 0)
        {

            if(modificarID == nave.ID)  /// si esta en una mision no se puede modificar // modificar mas adelante
            {

                printf("\nID de nave encontrada\n\n");
                fflush(stdin);


                printf("Ingresar NUEVA ID: ");
                scanf("%i", &nave.ID);

                fseek(archivo, -sizeof(stNave), SEEK_CUR); /// no lo puedo hacer funcionar
                fread(&nave, sizeof(stNave), 1, archivo);

                printf("\nSe pudo modificar el archivo con exito");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos





                valido = 1;

            }
        }

        fclose(archivo);




    }
    else
    {

        printf("\nNo se pudo abrir el archivo");

    }

    if(valido == 0)
    {

        printf("\nNo se pudo encontar el id ingesado\n");


    }

    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
    MenuPrincipal();

}

///------------------------------------
/// funciones adicionales
///----------------------------

int verificacionDeIdnaves(int naveIDverficacion){

FILE* archivo;

stNave nave;

int salida = 0;

archivo = fopen("listaNave.bin", "rb");

if(archivo != NULL){

    while(fread(&nave, sizeof(stNave), 1, archivo)>0){

        if(naveIDverficacion == nave.ID){

            salida = 1;

        }


    }

    fclose(archivo);

}else{

printf("\nNo se pudo ejecutar el archivo\n");

}

return salida;

}



///-----------------------------
/// DIBUJOS DE LAS NAVES
///-----------------------------
///1
void imprimirStarship()
{
    const char* starship = "         / /\\ \\            \n"
                           "        / /  \\ \\           \n"
                           "       / /____\\ \\          \n"
                           "      / /|    |\\ \\         \n"
                           "      \\/ /====\\ \\/       \n"
                           "       | \\====/ |        \n"
                           "       | |    | |        \n"
                           "       | |    | |        \n"
                           "       | ||  || |        \n"
                           "       ||_|__|_||    \n"
                           "        |  ||  |         \n"
                           "        |__||__|     \n"
                           "       _ \\\\__// _       \n"
                           "      /_|  ||  |_\\    \n"
                           "     //===/||\\===\\\\      \n"
                           "    //____\\\\//____\\\\  \n";

    printf("%s", starship);
}

void imprimirStarshipAcoplado()
{
    const char* starship = "                                                   \n"
                            "                                 _____________     \n"
                            "                                 | _________ |      \n"
                            "                                 | |_______| |     \n"
                            "                                 |           |      \n"
                            "                                 |___________|         \n"
                            "                                    |     |         \n"
                            "         / /\\ \\_____________________|     |        \n"
                           "        / /  \\ \\____________________|     |        \n"
                           "       / /____\\ \\                   |     |       \n"
                           "      / /|    |\\ \\                  |     |       \n"
                           "      \\/ /====\\ \\/                  |     |        \n"
                           "       | \\====/ |                   |     |       \n"
                           "       | |    | |___________________|     |       \n"
                           "       | |    | |___________________|     |       \n"
                           "       | ||  || |                   |     |      \n"
                           "       ||_|__|_||                   |     |      \n"
                           "        |  ||  |                    |=====|     \n"
                           "        |__||__|                   /       \\     \n"
                           "       _ \\\\__// _                 /         \\   \n"
                           "      /_|  ||  |_\\               /           \\    \n"
                           "     //===/||\\===\\\\             /             \\ \n"
                           "    //____\\\\//____\\\\           /_______________\\     \n";


    printf("%s", starship);
}

void imprimirStarshipDesacomplado()
{
    const char* starship = "                                                   \n"
                            "                                 _____________     \n"
                            "                                 | _________ |      \n"
                            "                                 | |_______| |     \n"
                            "                                 |           |      \n"
                            "                                 |___________|         \n"
                            "                                    |     |         \n"
                            "         / /\\ \\                     |     |        \n"
                           "        / /  \\ \\                    |     |        \n"
                           "       / /____\\ \\                   |     |       \n"
                           "      / /|    |\\ \\                  |     |       \n"
                           "      \\/ /====\\ \\/                  |     |        \n"
                           "       | \\====/ |                   |     |       \n"
                           "       | |    | |                   |     |       \n"
                           "       | |    | |                   |     |       \n"
                           "       | ||  || |                   |     |      \n"
                           "       ||_|__|_||                   |     |      \n"
                           "        |  ||  |                    |=====|     \n"
                           "        |__||__|                   /       \\     \n"
                           "       _ \\\\__// _                 /         \\   \n"
                           "      /_|  ||  |_\\               /           \\    \n"
                           "     //===/||\\===\\\\             /             \\ \n"
                           "    //____\\\\//____\\\\           /_______________\\     \n";


    printf("%s", starship);
}

void imprimirStarshipDespegue()
{
    const char* starship = "         / /\\ \\            \n"
                           "        / /  \\ \\           \n"
                           "       / /____\\ \\          \n"
                           "      / /|    |\\ \\         \n"
                           "      \\/ /====\\ \\/       \n"
                           "       | \\====/ |        \n"
                           "       | |    | |        \n"
                           "       | |    | |        \n"
                           "       | ||  || |        \n"
                           "       ||_|__|_||    \n"
                           "        |  ||  |         \n"
                           "        |__||__|     \n"
                           "       _ \\\\__// _       \n"
                           "      /_|  ||  |_\\    \n"
                           "     //===/||\\===\\\\      \n"
                           "    //____\\\\//____\\\\  \n"
                            "    @@@@@@    @@@@@@         \n"
                            "     @@@@      @@@@         \n"
                            "    @ @ @ @  @ @ @ @         \n"
                            "     @ @ @    @ @ @          \n";

    printf("%s", starship);

}

///2
 void imprimirFalcon9() {
    const char* falcon9 = "         //\\\\                        \n"
                          "        //  \\\\                       \n"
                          "       //    \\\\                      \n"
                          "      //======\\\\                     \n"
                          "      ||      ||                     \n"
                          "      ||  /\\  ||                     \n"
                          "      ||  ||  ||                     \n"
                          "      || /==\\ ||                     \n"
                          "     /|| |  | ||\\                     \n"
                          "    //|| |  | ||\\\\                      \n"
                          "   // || |  | || \\\\                     \n"
                          "  //  || |  | ||  \\\\                    \n"
                          " //\\  || |  | ||  /\\\\                 \n"
                          "|/  \\ || |  | || /  \\|                 \n"
                          "||   \\||  \\/  ||/   ||                \n"
                          "||    ||      ||    ||                \n"
                          "||    ||      ||    ||                \n"
                          "||    ||      ||    ||                \n"
                          "||____||      ||____||               \n"
                          "||_   ||/\\  /\\||   _||                 \n"
                          "\\/ \\==/\\/\\/\\/\\/==/  \\/                   \n";

    printf("%s", falcon9);
}

void imprimirFalcon9Acoplado() {
    const char* falcon9 =
                          "                                                      \n"
                          "                                      _____________ \n"
                          "                                      | _________ | \n"
                          "         //\\\\                         | |_______| | \n"
                          "        //  \\\\                        |           |  \n"
                          "       //    \\\\                       |___________| \n"
                          "      //======\\\\                         |     |  \n"
                          "      ||      ||_________________________|     | \n"
                          "      ||  /\\  ||_________________________|     | \n"
                          "      ||  ||  ||                         |     | \n"
                          "      || /==\\ ||                         |     | \n"
                          "     /|| |  | ||\\                        |     |  \n"
                          "    //|| |  | ||\\\\                       |     |   \n"
                          "   // || |  | || \\\\                      |     |     \n"
                          "  //  || |  | ||  \\\\  ___________________|     |       \n"
                          " //\\  || |  | ||  /\\\\____________________|     |       \n"
                          "|/  \\ || |  | || /  \\|                   |     |      \n"
                          "||   \\||  \\/  ||/   ||                   |     |      \n"
                          "||    ||      ||    ||                   |=====|     \n"
                          "||    ||      ||    ||                  /       \\     \n"
                          "||    ||      ||    ||                 /         \\   \n"
                          "||____||      ||____||                /           \\    \n"
                          "||_   ||/\\  /\\||   _||               /             \\ \n"
                          "\\/ \\==/\\/\\/\\/\\/==/  \\/              /_______________\\     \n";

    printf("%s", falcon9);
}

void imprimirFalcon9Desacoplado() {
    const char* falcon9 =
                          "                                                      \n"
                          "                                      _____________ \n"
                          "                                      | _________ | \n"
                          "         //\\\\                         | |_______| | \n"
                          "        //  \\\\                        |           |  \n"
                          "       //    \\\\                       |___________| \n"
                          "      //======\\\\                         |     |  \n"
                          "      ||      ||                         |     | \n"
                          "      ||  /\\  ||                         |     | \n"
                          "      ||  ||  ||                         |     | \n"
                          "      || /==\\ ||                         |     | \n"
                          "     /|| |  | ||\\                        |     |  \n"
                          "    //|| |  | ||\\\\                       |     |   \n"
                          "   // || |  | || \\\\                      |     |     \n"
                          "  //  || |  | ||  \\\\                     |     |       \n"
                          " //\\  || |  | ||  /\\\\                    |     |       \n"
                          "|/  \\ || |  | || /  \\|                   |     |      \n"
                          "||   \\||  \\/  ||/   ||                   |     |      \n"
                          "||    ||      ||    ||                   |=====|     \n"
                          "||    ||      ||    ||                  /       \\     \n"
                          "||    ||      ||    ||                 /         \\   \n"
                          "||____||      ||____||                /           \\    \n"
                          "||_   ||/\\  /\\||   _||               /             \\ \n"
                          "\\/ \\==/\\/\\/\\/\\/==/  \\/              /_______________\\     \n";

    printf("%s", falcon9);
}

void imprimirFalcon9Despegue() {
    const char* falcon9 = "         //\\\\                        \n"
                          "        //  \\\\                       \n"
                          "       //    \\\\                      \n"
                          "      //======\\\\                     \n"
                          "      ||      ||                     \n"
                          "      ||  /\\  ||                     \n"
                          "      ||  ||  ||                     \n"
                          "      || /==\\ ||                     \n"
                          "     /|| |  | ||\\                     \n"
                          "    //|| |  | ||\\\\                      \n"
                          "   // || |  | || \\\\                     \n"
                          "  //  || |  | ||  \\\\                    \n"
                          " //\\  || |  | ||  /\\\\                 \n"
                          "|/  \\ || |  | || /  \\|                 \n"
                          "||   \\||  \\/  ||/   ||                \n"
                          "||    ||      ||    ||                \n"
                          "||    ||      ||    ||                \n"
                          "||    ||      ||    ||                \n"
                          "||____||      ||____||               \n"
                          "||_   ||/\\  /\\||   _||                 \n"
                          " @@@@@@        @@@@@@         \n"
                          "  @@@@          @@@@         \n"
                          " @ @ @ @      @ @ @ @         \n"
                          "  @ @ @        @ @ @          \n";

    printf("%s", falcon9);
}

///3

void imprimirFalconHeavy() {
    const char* falconHeavy = "          //\\\\                   \n"
                              "         //||\\\\                  \n"
                              "        // || \\\\                 \n"
                              "       //  /\\  \\\\                 \n"
                              "       || /__\\ ||                \n"
                              "       || |  | ||                \n"
                              "       || |  | ||                 \n"
                              "       || |__| ||                \n"
                              "       ||      ||                \n"
                              "      /||======||\\               \n"
                              "     //||      ||\\\\             \n"
                              "    // ||  ||  || \\\\            \n"
                              "   //  ||  ||  ||  \\\\           \n"
                              "   |   || /__\\ ||   |          \n"
                              "   |\\__||======||__/|          \n"
                              "   |__/||\\____/||\\__|          \n"
                              "    || \\/ |||| \\/ ||            \n"
                              "    \\/     ||     \\/            \n"
                              "           \\/                 \n";

    printf("%s", falconHeavy);
}

void imprimirFalconHeavyAclopado() {
    const char* falconHeavy = "                                                   \n"
                              "                                 _____________     \n"
                              "                                 | _________ |      \n"
                              "                                 | |_______| |     \n"
                              "                                 |           |      \n"
                              "          //\\\\                   |___________|         \n"
                              "         //||\\\\                     |     |         \n"
                              "        // || \\\\____________________|     |        \n"
                              "       //  /\\  \\\\___________________|     |        \n"
                              "       || /__\\ ||                   |     |       \n"
                              "       || |  | ||                   |     |       \n"
                              "       || |  | ||                   |     |       \n"
                              "       || |__| ||                   |     |       \n"
                              "       ||      ||___________________|     |       \n"
                              "      /||======||\\__________________|     |       \n"
                              "     //||      ||\\\\                 |     |      \n"
                              "    // ||  ||  || \\\\                |     |      \n"
                              "   //  ||  ||  ||  \\\\               |=====|     \n"
                              "   |   || /__\\ ||   |              /       \\     \n"
                              "   |\\__||======||__/|             /         \\   \n"
                              "   |__/||\\____/||\\__|            /           \\    \n"
                              "    || \\/ |||| \\/ ||            /             \\ \n"
                              "    \\/     ||     \\/           /_______________\\     \n"
                              "           \\/                 \n";

    printf("%s", falconHeavy);
}

void imprimirFalconHeavyDesacoplado() {
    const char* falconHeavy = "                                                   \n"
                              "                                 _____________     \n"
                              "                                 | _________ |      \n"
                              "                                 | |_______| |     \n"
                              "                                 |           |      \n"
                              "          //\\\\                   |___________|         \n"
                              "         //||\\\\                     |     |         \n"
                              "        // || \\\\                    |     |        \n"
                              "       //  /\\  \\\\                   |     |        \n"
                              "       || /__\\ ||                   |     |       \n"
                              "       || |  | ||                   |     |       \n"
                              "       || |  | ||                   |     |       \n"
                              "       || |__| ||                   |     |       \n"
                              "       ||      ||                   |     |       \n"
                              "      /||======||\\                  |     |       \n"
                              "     //||      ||\\\\                 |     |      \n"
                              "    // ||  ||  || \\\\                |     |      \n"
                              "   //  ||  ||  ||  \\\\               |=====|     \n"
                              "   |   || /__\\ ||   |              /       \\     \n"
                              "   |\\__||======||__/|             /         \\   \n"
                              "   |__/||\\____/||\\__|            /           \\    \n"
                              "    || \\/ |||| \\/ ||            /             \\ \n"
                              "    \\/     ||     \\/           /_______________\\     \n"
                              "           \\/                 \n";

    printf("%s", falconHeavy);
}


void imprimirFalconHeavyDespegue() {
    const char* falconHeavy = "          //\\\\                   \n"
                              "         //||\\\\                  \n"
                              "        // || \\\\                 \n"
                              "       //  /\\  \\\\                 \n"
                              "       || /__\\ ||                \n"
                              "       || |  | ||                \n"
                              "       || |  | ||                 \n"
                              "       || |__| ||                \n"
                              "       ||      ||                \n"
                              "      /||======||\\               \n"
                              "     //||      ||\\\\             \n"
                              "    // ||  ||  || \\\\            \n"
                              "   //  ||  ||  ||  \\\\           \n"
                              "   |   || /__\\ ||   |          \n"
                              "   |\\__||======||__/|          \n"
                              "   |__/||\\____/||\\__|          \n"
                              "    || \\/ |||| \\/ ||            \n"
                              "    \\/     ||     \\/            \n"
                              "           \\/                 \n"
                                " @@@@@@        @@@@@@         \n"
                                "  @@@@          @@@@         \n"
                                " @ @ @ @      @ @ @ @         \n"
                                "  @ @ @        @ @ @          \n";

    printf("%s", falconHeavy);
}







