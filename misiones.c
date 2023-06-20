#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>

#include "astronautas.h"
#include "naves.h"
#include "misiones.h"



void altaMision()
{
    int tripulante;
    int verificacion;
    int estado;
    int estadoVerificacion;

    FILE* archivo;
    archivo=fopen("listaAstronauta.bin", "wb+");
    stMision mision;

    int i=0;

    if(archivo != NULL)
    {
        printf("Ingrese el id");
        scanf("%i", &mision.ID);

        printf("Ingrese el id de la nave que desea usar \n"); ///FALTA VERIFICAR ESTADO
        scanf("%i", &estadoVerificacion);

        estado=chequeoEstadoNave(estadoVerificacion);
        switch(estado)
        {
        case 0:
            printf("NAVE EN MANTENIMIENTO");
            altaMision();
            break;

        case 1:
            printf("LA NAVE ESTA DISPONIBLE");
            mision.IDnave=estadoVerificacion;
            ///cambiar estado de la nave
            break;

        case 2:
            printf("NAVE EN MISION");
            altaMision();
            break;

        case 3:
            printf("LA NAVE SE DIO DE BAJA");
            altaMision();
            break;
        }


        printf("Ingrese el destino \n");
        fflush(stdin);
        scanf("%s", &mision.destino);

        printf("Ingrese el cargamento \n");
        fflush(stdin);
        scanf("%s", &mision.cargamento);

        for(i=0; i=3; i++)
        {
            printf("Ingrese el id del tripulante \n"); ///FALTA VERIFICAR ESTADO
            scanf("%i", &tripulante);

            verificacion=chequeoAstronauta(tripulante);
            switch(verificacion)
            {
            case 1:
                printf("ASTRONAUTA ASIGNADO! \n");
                tripulante=mision.tripulantes[i];
                break;

            case 2:
                printf("EL ASATRONAUTA ESTA RETIRADO! \n");
                printf("INGRESE OTRO ID \n");
                scanf("%i", &tripulante);
                tripulante=mision.tripulantes[i];
                if(tripulante==1)
                {
                    printf("ASTRONAUTA ASIGNADO CON EXITO!! \n");
                    tripulante=mision.tripulantes[i];

                    break;
                }
            }

        }

        printf("Ingrese detalles de la mision \n");
        fflush(stdin);
        scanf("%s", &mision.detalleDeLaMision);

        fwrite(&mision, sizeof(stMision), 1, archivo);
        fclose(archivo);
    }
    else
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO");
        MenuPrincipal();
    }



}

void listadoMisiones()
{
    printf("\n LISTA DE MISIONES \n");

    FILE* buffer;
    stMision mision;

    int i=0;
    int contador = 1;

    buffer = fopen("listaAstronauta.bin", "rb");

    if (archivo != NULL)
    {
        while (fread(&mision, sizeof(stMision), 1, buffer) == 1)
        {

            printf("\n\nLISTADO:\n\n");
            printf("MISION %i -> ID: %i \n -> NAVE: %i \n -> DESTINO: %s \n -> CARGAMENTO: %s \n -> TRIPULANTE 1: %s\n -> TRIPULANTE 2: %s\n -> TRIPULANTE 3: %s\n ----------------------------------------------------------\n", contador,mision.ID, mision.IDnave, mision.destino, mision.cargamento, mision.tripulantes[i], mision.tripulantes[i+1], mision.tripulantes[i+2]);
            contador++;
        }

        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }
}

void contasultaIDmision()
{
    int consulta;
    stMision mision;
    FILE* buffer;
    buffer=fopen("listaAstronauta.bin", "rb")
           if (buffer != NULL)
    {
        printf("Ingrese el ID de la mision que desea ver \n");
        scanf("%i", &consulta);

        while ((fread(&mision, sizeof(stMision), 1, buffer))==1)
        {
            if(mision.ID == consulta)
            {
                printf("MISION CON ID %i -> nave: %i \n -> DESTINO: %s \n -> CARGAMENTO: %s \n -> TRIPULANTE 1: %s\n -> TRIPULANTE 2: %s\n -> TRIPULANTE 3: %s\n ----------------------------------------------------------\n",mision.ID, mision.IDnave, mision.destino, mision.cargamento, mision.tripulantes[i], mision.tripulantes[i+1], mision.tripulantes[i+2]);
            }
            else
            {
                printf("LA MISION NO FUE ENCONTRADA \n");
            }
        }
    }
}




///-----------------------------------------------------------


void despegueDeMision()
{

    int misionID, confirmarDespege;

    stMision misiones;

    fflush(stdin);

    printf("\nINICIO DE LA MISION\n\n\ningresar La id de la mision:\n");
    scanf("&i",&misionID);

    int validacion = verificacionDeMisionEntrada(misionID);


    if(validacion == 1 )
    {

        printf("\nLa nave esta en condiciones de despqgar:\n");

        int piloto1ID, piloto2ID, piloto3ID;

        piloto1ID = retornarIdDePiolotoConIDdeMision(misionID, 1);
        piloto2ID = retornarIdDePiolotoConIDdeMision(misionID, 2);
        piloto3ID = retornarIdDePiolotoConIDdeMision(misionID, 3);

        printf("\nIngresar UNO para confirmar el despeque:  ");
        scanf("%i", &confirmarDespege);

        if(confirmarDespege == 1)
        {

            system("cls"); /// limpia la pantalla
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

            printf("\n\n    EL INICIO DE LA MISION SE CONFIRMO\n\n");

            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


            system("cls"); /// limpia la pantalla

            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


            printf("\n PREPARANDO NAVE PARA EL DESPEGUE ");

            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

            /// FUNCION PARA SABER QUE MODELO DE NAVE ES SEGUN LA ID

            int tipoDeNaveDespegue = detectarModeloDeLaNaveConIDMision(misionID);


            int estadoDeDespegue;

            if(tipoDeNaveDespegue == 1)  /// Starship
            {

                system("cls"); /// limpia la pantalla

                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                printf("\nStarsip ACOPLADO");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                imprimirStarshipAcoplado();
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                printf("\nStarsip DESACOPLADO");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                imprimirStarshipDesacomplado();
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                printf("\nStarsip DESPEGANDO");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                imprimirStarshipDespegue();
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall

                estadoDeDespegue = estadoDeDespegueResultado();




                if(estadoDeDespegue == 3 )
                {

                    system("cls"); /// limpia la pantall
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    printf("\nEL DESPEGUE FALLO. \n\nMISON FALLIDA");

                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    bajaDeAstronautaPorMuerte(piloto1ID);
                    bajaDeAstronautaPorMuerte(piloto2ID);
                    bajaDeAstronautaPorMuerte(piloto3ID);


                }
                else if(estadoDeDespegue == 2)
                {

                    system("cls"); /// limpia la pantall
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    printf("\nEL DESPEGUE FUE EXITOSO\n\n SE COMLETARA DE FORMA EXITOSA LA MISION");
                    altaAstronautaMisionViaje(piloto1ID);
                    altaAstronautaMisionViaje(piloto2ID);
                    altaAstronautaMisionViaje(piloto3ID);
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                }




            }
            else if(tipoDeNaveDespegue == 2)   /// Falcon 9
            {

                system("cls"); /// limpia la pantalla
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                printf("\nStarsip ACOPLADO");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                imprimirFalcon9Acoplado();
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                printf("\nStarsip DESACOPLADO");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                imprimirFalcon9Desacoplado();
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                printf("\nStarsip DESPEGANDO");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                imprimirFalcon9Despegue();
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall

                estadoDeDespegue = estadoDeDespegueResultado();

                if(estadoDeDespegue == 3 )
                {

                    system("cls"); /// limpia la pantall
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    printf("\nEL DESPEGUE FALLO. \n\nMISON FALLIDA");

                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    bajaDeAstronautaPorMuerte(piloto1ID);
                    bajaDeAstronautaPorMuerte(piloto2ID);
                    bajaDeAstronautaPorMuerte(piloto3ID);


                }
                else if(estadoDeDespegue == 2)
                {

                    system("cls"); /// limpia la pantall
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    printf("\nEL DESPEGUE FUE EXITOSO\n\n SE COMLETARA DE FORMA EXITOSA LA MISION");
                    altaAstronautaMisionViaje(piloto1ID);
                    altaAstronautaMisionViaje(piloto2ID);
                    altaAstronautaMisionViaje(piloto3ID);
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


                }



            }
            else if(tipoDeNaveDespegue == 3)   /// imprimirFalconHeavy misiones
            {


                system("cls"); /// limpia la pantalla

                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                printf("\nStarsip ACOPLADO");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                imprimirFalconHeavyAclopado();
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                printf("\nStarsip DESACOPLADO");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                imprimirFalconHeavyDesacoplado();
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                printf("\nStarsip DESPEGANDO");
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                imprimirFalconHeavyDespegue();
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                system("cls"); /// limpia la pantall

                estadoDeDespegue = estadoDeDespegueResultado();

                if(estadoDeDespegue == 3 )
                {

                    system("cls"); /// limpia la pantall
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    printf("\nEL DESPEGUE FALLO. \n\nMISON FALLIDA");

                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    bajaDeAstronautaPorMuerte(piloto1ID);
                    bajaDeAstronautaPorMuerte(piloto2ID);
                    bajaDeAstronautaPorMuerte(piloto3ID);


                }
                else if(estadoDeDespegue == 2)
                {

                    system("cls"); /// limpia la pantall
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    printf("\nEL DESPEGUE FUE EXITOSO\n\n SE COMLETARA DE FORMA EXITOSA LA MISION");
                    altaAstronautaMisionViaje(piloto1ID);
                    altaAstronautaMisionViaje(piloto2ID);
                    altaAstronautaMisionViaje(piloto3ID);
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos



                }
            }





        }
        else
        {


            printf("\n SE DIO DE BAJA LA MISION\N");
            system("cls"); /// limpia la pantall
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
            MenuPrincipal();

        }


    }
    else
    {

        printf("\nLa id de mision no existe\n");
        MenuPrincipal();

    }
}
///---------------------

int chequeoEstadoNave (int id)
{
    stNave nave;
    int estado;
    FILE *archi;
    archi=fopen("listaNave.bin","rb");
    if(archi!= NULL)
    {
        while((fread(&nave, sizeof (stNave), 1, archi))==1)
        {
            if (id== nave.ID)
            {
                estado=nave.estado;
                fclose(archi);
                return estado;
            }
        }
    }
}

int chequeoAstronauta(int id)
{
    int estado;
    stAstronauta astronauta;
    FILE *archivo;
    archivo=fopen("listaAstronauta.bin", "rb");
    if(archivo != NULL)
    {
        while((fread(&astronauta, sizeof(stAstronauta), 1, archivo))==1)
        {
            if(id=astronauta.ID)
            {
                estado=astronauta.estado;
                fclose(archivo);
                return estado;
            }
        }
    }
}





///----------------------

/// RETORNAR LA ID DEL PILOTO CON LA ID DE MISION

int retornarIdDePiolotoConIDdeMision(int misionID, int NumeroPiloto)
{

    int salida;

    FILE* archivo;

    stMision mision;

    archivo = fopen("listaMision.bin", "rb");

    if(archivo != NULL)
    {

        while(fread(&mision, sizeof(stMision), 1, archivo)>0)
        {

            if(mision.ID == misionID)
            {

                if(NumeroPiloto == 1 )
                {

                    salida = mision.IDtripulante_1;

                }
                else if(NumeroPiloto == 2)
                {

                    salida = mision.IDtripulante_2;

                }
                else if(NumeroPiloto == 3)
                {

                    salida = mision.IDtripulante_3;

                }

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

/// DETECTAR DE NAVE CON ID DE MISION

void detectarModeloDeLaNaveConIDMision(int misionID)
{

    FILE* archivo;

    stMision mision;

    int idNave;

    int salida;

    archivo = fopen("listaMision.bin","rb");

    if(archivo!=NULL)
    {

        while(fread(&mision, sizeof(stMision), 1, archivo)>0)
        {

            if(misionID == mision.ID)
            {

                idNave = mision.IDnave;

                salida = detectarModeloDeNave(idNave);

            }

        }

        fclose(archivo);


    }
    else
    {

        printf("\nEl archivo no se pudo ejecutar\n");

    }

    return salida;


}



/// DADA DE ALTA DE ASTRONAUTA ESTADO VIAJE

void altaAstronautaMisionViaje(int astronautaID[])
{

    FILE* archivo;

    archivo = fopen("listaAstronauta.bin","rb");

    stAstronauta astronauta;

    if(archivo != NULL)
    {





        while(fread(&astronauta, sizeof(stAstronauta), 1, archivo)>0)
        {

            if(astronauta.ID == astronautaID)
            {

                astronauta.ID = 3;



            }

        }




        fclose(archivo);




    }
    else
    {

        printf("\nNo se pudo abirir el archivo\n");

    }




}

/// BAJA DE ASTONAUTA POR MISION FALLIDA

void bajaDeAstronautaPorMuerte(int astronautaID[])
{


    FILE* archivo;

    archivo = fopen("listaAstronauta.bin","rb");

    stAstronauta astronauta;

    if(archivo != NULL)
    {





        while(fread(&astronauta, sizeof(stAstronauta), 1, archivo)>0)
        {

            if(astronauta.ID == astronautaID)
            {

                astronauta.ID = 4;



            }

        }




        fclose(archivo);




    }
    else
    {

        printf("\nNo se pudo abirir el archivo\n");

    }




}

/// ESTADO DE DESPEGUE

int estadoDeDespegueResultado()
{

    // Inicializar la semilla del generador de números aleatorios
    srand(time(NULL));

    // Generar un número aleatorio entre 0 y 9
    int numeroAleatorio = rand() % 10;

    // Retornar 1 si el número aleatorio es menor o igual a 7 (80% de probabilidad), de lo contrario, retornar 0
    if (numeroAleatorio <= 7)
        return 2;
    else
        return 3;


}

/// FUNCION PARA VERIFICAR EL TIPO DE NAVE

int detectarModeloDeNave(int idNave)
{

    FILE* archivo;

    archivo = fopen("listaNave.bin","rb");

    stNave nave;

    int salida = 0;

    if(archivo != NULL)
    {

        while(fread(&nave, sizeof(stNave), 1, archivo)>0)
        {

            if(idNave == nave.ID)
            {

                salida = nave.tipoDeNave;

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



/// VERIFICACION DE ESTADO DE ASTRONAUTA

int verificacionDeEstadoDeAstronauta(int idCargaAstronauta)
{

    FILE* archivo;

    stAstronauta astronauta;

    int salida = 0;

    archivo = fopen("listaAstronauta.bin","rb");

    if(archivo!= NULL)
    {

        while(fread((&astronauta), sizeof(stAstronauta), 1, archivo)>0)
        {

            if(idCargaAstronauta == astronauta.ID && astronauta.estado == 3 && astronauta.estado == 2)
            {

                salida = 1;

            }
            else if(astronauta.ID == idCargaAstronauta)
            {

                salida = 2;

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

///verificacion ESTADO ID MISION

int verificacionDeMisionEntrada(int idMisionVerificacion)
{

    int salida = 0;

    FILE* archivo;

    stMision misiones;

    archivo = fopen("listaMision.bin","rb");

    if(archivo !=NULL)
    {

        while(fread(&misiones, sizeof(stMision), 1, archivo)>0)
        {


            if(idMisionVerificacion == misiones.ID)
            {


                salida = 1;

            }


        }


        fclose(archivo);



    }
    else
    {

        printf("\nNo se pudo abrir el archivo\n");

    }
    return salida;  /// si retorna un 1 significa que la ID de la mision existe


}

/// verificacion ESTADO NAVA

int verificacionDeEstadoDeLaNave(int verificado)
{


    FILE* archivo;

    stNave nave;

    int salida = 0;

    archivo = fopen("listaNave.bin","rb");

    if(archivo != NULL)
    {

        while(fread(&nave, sizeof(stNave), 1, archivo)>0)
        {


            if(nave.ID == verificado)
            {

                if(nave.estado == 1)
                {

                    salida = 1;

                }

            }

        }

        fclose(archivo);


    }
    else
    {

        printf("\nNo se pudo abrir el archivo\n");

    }

    return salida; /// si retorna 0 no se puede usar. si retorna 1 se puede usar

}
