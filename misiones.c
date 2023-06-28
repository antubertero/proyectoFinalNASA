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
    system("cls"); /// limpia la pantalla
    printf("\n----------------\nINICIO DE MISION:\n----------------\n\n");

    int tripulante;
    int verificacion;
    int estado;
    int opcionDeViaje;
    int confirmarDespege;
    int estadoDeNaveCambiado = 0;
    int entrada = 0;
    int misionCheck, verificacionSalida;
    int IDnaveIngresado;




    int i=0;


    printf("\nIngrese el ID que le quieres asignar a la mision\n\nIngresar ID: ");
    scanf("%i", &misionCheck);


    int resultadoVerificacionID = verificacionDeIDMISION(misionCheck);

    if(resultadoVerificacionID == 0)
    {

        printf("\nIngrese el ID de la nave que desea usar : ");
        scanf("%i", &IDnaveIngresado);

        estado=chequeoEstadoNave(IDnaveIngresado);
        ///--------
        ///SWITCH VERIFICACION NAVE



        switch(estado)
        {
        case -1:
            system("cls"); /// limpia la pantalla
            printf("\n\nLa ID de la nave NO existe.");
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
            MenuPrincipal();
            break;


        case 0:
            system("cls"); /// limpia la pantalla
            printf("\n\nNAVE EN MANTENIMIENTO");

            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


            altaMision();
            break;

        case 1:

            printf("\n\nLA NAVE ESTA DISPONIBLE");
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

            entrada = 1;
            estadoDeNaveCambiado = 1;
            break;

        case 2:
            system("cls"); /// limpia la pantalla
            printf("\n\nNAVE EN MISION");
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

            altaMision();
            break;

        case 3:
            system("cls"); /// limpia la pantalla
            printf("LA NAVE SE DIO DE BAJA");
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

            altaMision();
            break;

        case 4:
            system("cls"); /// limpia la pantalla
            printf("LA NAVE YA TIENE UNA MISION ASIGNADA");
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
            altaMision();
            break;

        }


        ///-------





        FILE* archivo;

        stMision mision;

        archivo=fopen("ListaMisiones.bin", "ab");
        if(archivo != NULL)
        {





            mision.ID = misionCheck;


            int salidaConfirmacionDeViaje = 0;

            while(salidaConfirmacionDeViaje == 0)
            {

                printf("\nIndicar el destino:  \n\n 1) Orbita terrestre\n 2) Luna\n 3) marte\n 4) Jupiter\n 5) Saturno\n 6) Urano\n 7) Neptuno\n\n   Ingresar opcion: ");
                scanf("%i", &opcionDeViaje);

                ///SWITCH ELEGIR DESTINO

                switch(opcionDeViaje)
                {

                case 1:

                    printf("\n Viaje a la orbita terrestre \n La hora de viaje aproximada es de 9hs. \n Ingresar UNO para confirmar: ");
                    scanf("%i", &confirmarDespege);

                    if(confirmarDespege==1)
                    {
                        mision.destino=1;
                        salidaConfirmacionDeViaje = 1;

                    }
                    else
                    {

                        printf("\nNo se confirmo el destino \n\nLa carga de la mision no fue confirmada ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                        printf("\nIngresar nuevamente el destino ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


                    }

                    break;

                case 2:

                    printf("\n Viaje a la Luna \n La hora de viaje aproximada es de 72hs. \n Ingresar UNO para confirmar: ");
                    scanf("%i", &confirmarDespege);

                    if(confirmarDespege==1)
                    {
                        mision.destino=2;
                        salidaConfirmacionDeViaje = 1;
                    }
                    else
                    {

                        printf("\nNo se confirmo el destino \n\nLa carga de la mision no fue confirmada ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                        printf("\nIngresar nuevamente el destino ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


                    }


                    break;

                case 3:
                    printf("\n Viaje a Marte \n La hora de viaje aproximada es de 7 meses / 5.226 horas. \n Ingresar UNO para confirmar: ");
                    scanf("%i", &confirmarDespege);

                    if(confirmarDespege==1)
                    {
                        mision.destino=3;
                        salidaConfirmacionDeViaje = 1;
                    }
                    else
                    {

                        printf("\nNo se confirmo el destino \n\nLa carga de la mision no fue confirmada ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                        printf("\nIngresar nuevamente el destino ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


                    }


                    break;

                case 4:
                    printf("\n Viaje a Jupiter \n La hora de viaje aproximada es de 30 meses / 21.900 horas. \n Ingresar UNO para confirmar: ");
                    scanf("%i", &confirmarDespege);

                    if(confirmarDespege==1)
                    {
                        mision.destino=4;
                        salidaConfirmacionDeViaje = 1;
                    }
                    else
                    {

                        printf("\nNo se confirmo el destino \n\nLa carga de la mision no fue confirmada ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                        printf("\nIngresar nuevamente el destino ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


                    }



                    break;

                case 5:
                    printf("\n Viaje a Saturno \n La hora de viaje aproximada es de 78 meses / 56.940 horas. \n Ingresar UNO para confirmar: ");
                    scanf("%i", &confirmarDespege);


                    if(confirmarDespege==1)
                    {
                        mision.destino=5;
                        salidaConfirmacionDeViaje = 1;
                    }
                    else
                    {

                        printf("\nNo se confirmo el destino \n\nLa carga de la mision no fue confirmada ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                        printf("\nIngresar nuevamente el destino ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


                    }


                    break;


                case 6:

                    printf("\n Viaje a Urano \n La hora de viaje aproximada es de 132 meses / 96,360 horas. \n Ingresar UNO para confirmar: ");
                    scanf("%i", &confirmarDespege);

                    if(confirmarDespege==1)
                    {
                        mision.destino=6;
                        salidaConfirmacionDeViaje = 1;
                    }
                    else
                    {

                        printf("\nNo se confirmo el destino \n\nLa carga de la mision no fue confirmada ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                        printf("\nIngresar nuevamente el destino ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


                    }


                    break;


                case 7:

                    printf("\n Viaje a Neptuno \n La hora de viaje aproximada es de 156 meses / 113.880 horas. \n Ingresar UNO para confirmar: ");
                    scanf("%i", &confirmarDespege);

                    if(confirmarDespege==1)
                    {
                        mision.destino=7;
                        salidaConfirmacionDeViaje = 1;
                    }
                    else
                    {

                        printf("\nNo se confirmo el destino \n\nLa carga de la mision no fue confirmada ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                        printf("\nIngresar nuevamente el destino ");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


                    }


                    break;


                }

            }



            printf("\n\nDestino cargado con exito \n\n");



            printf("Ingrese el cargamento :\n");
            fflush(stdin);
            scanf("%s", &mision.cargamento);
            fflush(stdin);
            printf("Ingrese detalles de la mision \n");
            fflush(stdin);
            scanf("%s", &mision.detalleDeLaMision);
            fflush(stdin);
            ///CARGA TRIPULANTE
            int salidaDeCargaDeTripulantes = 0;

            while(salidaDeCargaDeTripulantes < 3)
            {

                printf("Ingrese el ID del tripulante %i : \n", salidaDeCargaDeTripulantes+1); ///FALTA VERIFICAR ESTADO
                scanf("%i", &tripulante);

                verificacion=chequeoAstronauta(tripulante);
                switch(verificacion)
                {
                case 1:
                    printf("\nASTRONAUTA ASIGNADO! \n");

                    if(salidaDeCargaDeTripulantes == 0)
                    {

                        mision.IDtripulante_1 = tripulante;
                        modificarEstadoDeAstronautaAMisionAsignada(mision.IDtripulante_1);

                    }
                    else if(salidaDeCargaDeTripulantes == 1)
                    {

                        mision.IDtripulante_2 = tripulante;
                        modificarEstadoDeAstronautaAMisionAsignada(mision.IDtripulante_2);

                    }
                    else if(salidaDeCargaDeTripulantes == 2)
                    {

                        mision.IDtripulante_3 = tripulante;
                        modificarEstadoDeAstronautaAMisionAsignada(mision.IDtripulante_3);

                    }
                    salidaDeCargaDeTripulantes++;
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    break;

                case 2:
                    printf("EL ASATRONAUTA ESTA RETIRADO! \n");
                    printf("INGRESE OTRO ID \n");
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    break;

                case 3:
                    printf("EL ASATRONAUTA YA ESTA EN OTRA MISION! \n");
                    printf("INGRESE OTRO ID \n");
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    break;


                case 4:
                    printf("EL ASATRONAUTA ESTA DE BAJA! \n");
                    printf("INGRESE OTRO ID \n");
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    break;


                }
            }



            cambiarEstadoDeLaNaveAMisionAsignada(IDnaveIngresado);



            mision.estado=1;
            mision.IDnave = IDnaveIngresado;

            fwrite(&mision, sizeof(stMision), 1, archivo);
            fclose(archivo);

            system("cls"); /// limpia la pantalla

            printf("\n\nLA MISION FUE CARGADA CON EXITO\n");
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos



        }
        else
        {

            printf("\nNO SE PUEDO ABRIR EL ARCHIVO");


        }

        if(estadoDeNaveCambiado == 1)
        {
            stNave nave;
            FILE* archivo1;
            int validacion =0;

            archivo1 = fopen("listaNave.bin", "r+b");
            if(archivo1 != NULL)
            {

                while(fread(&nave, sizeof(stNave), 1, archivo1) > 0 && validacion == 0)
                {
                    if(nave.ID == IDnaveIngresado)
                    {

                        nave.estado = 2;
                        validacion = 1;

                    }

                }


            }
            else
            {
                printf("\nNo se pudo abrir el archivo");

            }
        }
        MenuPrincipal();

    }
    else
    {
        system("cls"); /// limpia la pantalla
        printf("\n\nLa ID de la mision ya existe y no esta disponible\n");

        printf("\ningresar cualquier valor para salir  o 1 para vovler a intentar:  ");
        scanf("%i", &verificacionSalida);
        if(verificacionSalida == 1 )
        {
            altaMision();

        }
        else
        {

            MenuPrincipal();

        }


    }



}

void listadoMisiones()
{

    system("cls"); /// limpia la pantalla


    printf("\n----------------\nLISTADO DE MISION:\n----------------\n\n");

    FILE* archivo;
    stMision mision;

    int i=0;
    int contador = 1;

    archivo = fopen("ListaMisiones.bin", "rb");

    if(archivo != NULL)
    {
        while (fread(&mision, sizeof(stMision), 1, archivo) == 1 )
        {







            printf("\n\nLISTADO:\n\n");
            printf("MISION %i -> ID: %i \n", contador,mision.ID);
            printf("-> NAVE: %i \n", mision.IDnave);
            switch(mision.destino)
            {
            case 1:
                printf("-> DESTINO: Orbita Terrestre\n");
                break;

            case 2:
                printf("-> DESTINO: Luna\n");
                break;

            case 3:
                printf("-> DESTINO: Marte\n");
                break;

            case 4:
                printf("-> DESTINO: Jupiter\n");
                break;

            case 5:
                printf("-> DESTINO: Saturno\n");
                break;

            case 6:
                printf("-> DESTINO: Urano\n");
                break;

            case 7:
                printf("-> DESTINO: Neptuno\n");
                break;
            }
            printf("-> CARGAMENTO: %s \n", mision.cargamento);
            printf("-> ID TRIPULANTE 1: %i\n", mision.IDtripulante_1);
            printf("-> ID TRIPULANTE 2: %i\n", mision.IDtripulante_2);
            printf("-> ID TRIPULANTE 3: %i\n ----------------------------------------------------------\n",  mision.IDtripulante_3);
            printf("-> ESTADO DE LA MISION: "); /// ( 1 = Listo,2 = En vuelo, 3 = Retornada, 4 =  Cancelada,  5 = Fallida 6 - finalizada)
            switch(mision.estado)
            {

            case 0:

                printf("En mantenimiento");
                break;

            case 1 :
                printf("Listo");
                break;

            case 2 :
                printf("En vuelo");
                break;

            case 3 :
                printf("Retornada");
                break;

            case 4 :
                printf("Cancelada");
                break;

            case 5 :
                printf("Fallida");
                break;

            case 6:
                printf("finalizada");
                break;



            }
            printf("\n ----------------------------------------------------------\n");

            contador++;
        }


        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    fflush(stdin);
    int irMenu;
    printf("\n\nIngresar un valor para volver al menu:  ");
    scanf("%i", &irMenu);


    MenuPrincipal();




}

void contasultaIDmision()
{
    system("cls"); /// limpia la pantalla
    printf("\n----------------\nCONSULTA POR ID MISION:\n----------------\n\n");
    int consulta;
    stMision mision;
    int salida = 0;
    FILE* buffer;
    buffer = fopen("ListaMisiones.bin", "rb");
    if (buffer != NULL)
    {
        printf("\nIngrese el ID de la misión que desea ver: ");
        scanf("%i", &consulta);

        int misionEncontrada = 0; // Variable para indicar si se encontró una misión con el ID dado

        while (fread(&mision, sizeof(stMision), 1, buffer) > 0 && salida == 0 )
        {
            if (mision.ID == consulta)
            {
                printf("MISION CON ID %i:\n", mision.ID);
                printf("Nave: %i\n", mision.IDnave);
                switch(mision.destino)
                {
                case 1:
                    printf("-> DESTINO: Orbita Terrestre\n");
                    break;

                case 2:
                    printf("-> DESTINO: Luna\n");
                    break;

                case 3:
                    printf("-> DESTINO: Marte\n");
                    break;

                case 4:
                    printf("-> DESTINO: Jupiter\n");
                    break;

                case 5:
                    printf("-> DESTINO: Saturno\n");
                    break;

                case 6:
                    printf("-> DESTINO: Urano\n");
                    break;

                case 7:
                    printf("-> DESTINO: Neptuno\n");
                    break;
                }
                printf("Cargamento: %s\n", mision.cargamento);
                printf("Tripulante 1: %i\n", mision.IDtripulante_1);
                printf("Tripulante 2: %i\n", mision.IDtripulante_2);
                printf("Tripulante 3: %i\n", mision.IDtripulante_3);


                printf("ESTADO DE LA MISION: "); /// ( 1 = Listo,2 = En vuelo, 3 = Retornada, 4 =  Cancelada,  5 = Fallida 6 - finalizada)
                switch(mision.estado)
                {

                case 0:

                    printf("En mantenimiento");
                    break;

                case 1 :
                    printf("Listo");
                    break;

                case 2 :
                    printf("En vuelo");
                    break;

                case 3 :
                    printf("Retornada");
                    break;

                case 4 :
                    printf("Cancelada");
                    break;

                case 5 :
                    printf("Fallida");
                    break;

                case 6:
                    printf("finalizada");
                    break;



                }

                Sleep(5000); /// proceso espere durante aproximadamente 5 segundos

                misionEncontrada = 1;
                salida = 1;
                break; // Se encontró la misión, se puede salir del bucle
            }
        }

        fclose(buffer);

        if (misionEncontrada == 0)
        {
            system("cls"); /// limpia la pantalla
            printf("\n\nLA MISION NO FUE ENCONTRADA\n\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    int irMenu;
    printf("\n\nIngresar un valor para volver al menu:  ");
    scanf("%i", &irMenu);
    MenuPrincipal();

}


void bajaMision()
{

    system("cls"); /// limpia la pantalla
    printf("\n----------------\nBAJA MISION:\n----------------\n\n");
    int condicion1=0;


    int id1, id2, id3, idNave, desicion;


    stNave nave;
    stMision mision;



    int cancelarID;
    int estadoPermitido;

    printf("Ingrese el ID de la mision que desea cancelar \n");
    scanf("%i", &cancelarID);

    int validacion = estadoDeLaMision(cancelarID);


    if(validacion == 1)
    {

        FILE* buffer;
        buffer=fopen("ListaMisiones.bin", "r+b");
        if(buffer != NULL)
        {


            while (fread(&mision, sizeof(stMision), 1, buffer) > 0)
            {
                if (mision.ID == cancelarID)
                {




                    printf("\nID ENCONTRADA\n\n");




                    printf("\n\nESTA SEGURO QUE DESEA CANCELAR LA MISION? \n 1->SI   2->NO\n\nIGRESAR OPCION: ");
                    scanf("%i", &desicion);

                    if(desicion==1)
                    {
                        mision.estado=4;
                        idNave = mision.IDnave;

                        mision.IDnave = 0;
                        id1 = mision.IDtripulante_1;
                        id2 = mision.IDtripulante_2;
                        id3 = mision.IDtripulante_3;
                        fseek(buffer, -sizeof(stMision), SEEK_CUR);
                        fwrite(&mision, sizeof(stMision), 1, buffer);
                        fclose(buffer);

                    }
                    else
                    {
                        fclose(buffer);
                        printf("\n\nUsted ingreso no\nSe volvera al menu\n");

                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                        MenuPrincipal();

                    }
                }


            }


            fclose(buffer);
        }
        else
        {
            printf("\nNO SE PUDO ABRIR EL ARCHIVO \n");

        }


        if(desicion == 1)
        {

            modificacionDeAstronautaMisionCancelada(id1);
            modificacionDeAstronautaMisionCancelada(id2);
            modificacionDeAstronautaMisionCancelada(id3);

            modificarEstadoDeLaNavePorMisionCancelada(idNave);
            system("cls"); /// limpia la pantalla
            printf("\n\nLA BAJA DE LA MISION FUE EXITOSA ");
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        }




    }
    else if(validacion == 6)
    {

        system("cls"); /// limpia la pantalla
        printf("\nLA MISION YA ESTA FINALIZADA");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    }
    else if(validacion == -1)
    {
        system("cls"); /// limpia la pantalla
        printf("\nLa id ingresada no existe");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    }
    else
    {
        system("cls"); /// limpia la pantalla
        printf("\nLa mision no esta en condiciones de dar de baja ");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    }

    MenuPrincipal();


}




///-----------------------------------------------------------


void despegueDeMision()
{
    system("cls"); /// limpia la pantalla
    printf("\n----------------\nDESPEGUE DE MISION:\n----------------\n\n");

    int misionID, confirmarDespege;

    int idNave;
    int misionFaliidaConfirmacion = 0;

    stMision misiones;

    fflush(stdin);

    printf("\nINICIO DE LA MISION\n\n\ningresar La ID de la mision:\n");
    scanf("%i",&misionID);


    int validacion = verificacionDeMisionEntrada(misionID);








    if(validacion == 1 )
    {

        int tipoDeNaveDespegue = detectarModeloDeLaNaveConIDMision(misionID);

        int destino = retornarHorasSegunDestinoDeLaMision(misionID);

        printf("\n\nLa mision esta en condiciones de iniciar:\n");

        int piloto1ID, piloto2ID, piloto3ID;


        idNave = retornarIDnaveconLaIDmision(misionID); /// esta BIEN



        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

        piloto1ID = retornarIdDePiolotoConIDdeMision(misionID, 1);
        piloto2ID = retornarIdDePiolotoConIDdeMision(misionID, 2);
        piloto3ID = retornarIdDePiolotoConIDdeMision(misionID, 3);



        printf("\nIngresar UNO para confirmar el despeque: \n\n      confirmar despegue:  ");
        scanf("%i", &confirmarDespege);
        fflush(stdin);

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
                    estadoDenaveBaja(idNave);
                    misionFaliidaConfirmacion = 1;

                }
                else if(estadoDeDespegue == 2)
                {

                    system("cls"); /// limpia la pantall
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    printf("\nEL DESPEGUE FUE EXITOSO\n\n SE COMLETARA DE FORMA EXITOSA LA MISION");
                    altaAstronautaMisionViaje(piloto1ID, destino);
                    altaAstronautaMisionViaje(piloto2ID, destino);
                    altaAstronautaMisionViaje(piloto3ID, destino);
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    estadoDenaveEnMision(idNave, destino);
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
                    estadoDenaveBaja(idNave);
                    misionFaliidaConfirmacion = 1;

                }
                else if(estadoDeDespegue == 2)
                {

                    system("cls"); /// limpia la pantall
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    printf("\nEL DESPEGUE FUE EXITOSO\n\n SE COMLETARA DE FORMA EXITOSA LA MISION");
                    altaAstronautaMisionViaje(piloto1ID, destino);
                    altaAstronautaMisionViaje(piloto2ID, destino);
                    altaAstronautaMisionViaje(piloto3ID, destino);
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    estadoDenaveEnMision(idNave, destino);


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
                    estadoDenaveBaja(idNave);
                    misionFaliidaConfirmacion = 1;


                }
                else if(estadoDeDespegue == 2)
                {

                    system("cls"); /// limpia la pantall
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    printf("\nEL DESPEGUE FUE EXITOSO\n\n SE COMLETARA DE FORMA EXITOSA LA MISION");
                    altaAstronautaMisionViaje(piloto1ID, destino);
                    altaAstronautaMisionViaje(piloto2ID, destino);
                    altaAstronautaMisionViaje(piloto3ID, destino);
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                    estadoDenaveEnMision(idNave, destino);


                }
            }


            FILE* archivo;
            int salidaListado =0;

            archivo = fopen("ListaMisiones.bin","r+b");

            if(archivo != NULL)
            {

                while(fread(&misiones, sizeof(stMision), 1, archivo)>0 && salidaListado == 0)
                {

                    if(misionID == misiones.ID)
                    {

                        if(misionFaliidaConfirmacion == 0)
                        {

                            misiones.estado = 2;

                        }
                        else if(misionFaliidaConfirmacion == 1)
                        {

                            misiones.estado = 5;

                        }
                        fseek(archivo, -sizeof(stMision), SEEK_CUR);
                        fwrite(&misiones, sizeof(stMision), 1, archivo);
                        fclose(archivo);

                        salidaListado =1;



                    }


                }




                fclose(archivo);




            }
            else
            {

                printf("\nNo se pudo abrir el archivo\n");


            }


        }
        else
        {

            printf("\n SE DIO DE BAJA LA MISION\N");
            system("cls"); /// limpia la pantall
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


        }



    }
    else if(validacion == 0)
    {
        system("cls"); /// limpia la pantalla
        printf("\nLA ID NO EXISTE\n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

        MenuPrincipal();



    }
    else
    {

        system("cls"); /// limpia la pantalla
        printf("\nLa mision no esta en condiciones de iniciar \n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

        MenuPrincipal();



    }

    MenuPrincipal();




}



void retornoDeLaMision()
{


    int misionID, confirmarDespege;
    int piloto1ID, piloto2ID, piloto3ID;
    int idNave;
    int destino;



    stMision misiones;

    fflush(stdin);
    system("cls"); /// limpia la pantalla
    printf("\n----------------\nRETORNO DE LA MISION:\n----------------\n\n\n\ningresar La id de la mision:\n");
    scanf("%i",&misionID);

    fflush(stdin);

    int validacion = verificacionDeMisionEntrada(misionID);



    if(validacion == 2)   /// dos es en vuelo
    {

        destino = retornarHorasSegunDestinoDeLaMision(misionID);
        piloto1ID = retornarIdDePiolotoConIDdeMision(misionID, 1);
        piloto2ID = retornarIdDePiolotoConIDdeMision(misionID, 2);
        piloto3ID = retornarIdDePiolotoConIDdeMision(misionID, 3);


        idNave = retornarIDnaveconLaIDmision(misionID); /// esta BIEN

        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
        retornoAstronautaMisionViaje(piloto1ID, destino);
        retornoAstronautaMisionViaje(piloto2ID, destino);
        retornoAstronautaMisionViaje(piloto3ID, destino);


        estadoDenaveEnretorno(idNave, destino);




        FILE* archivo;

        archivo = fopen("ListaMisiones.bin","r+b");

        if(archivo != NULL)
        {

            while(fread(&misiones, sizeof(stMision), 1, archivo)>0)
            {

                if(misionID == misiones.ID)
                {

                    system("cls"); /// limpia la pantalla

                    printf("\nLA NAVE ESTA RETORNANDO\n");

                    misiones.estado = 6;  /// 6 es igual a finalizada



                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    fseek(archivo, -sizeof(stMision), SEEK_CUR);
                    fwrite(&misiones, sizeof(stMision), 1, archivo);

                    system("cls"); /// limpia la pantalla
                    printf("\nLA NAVE RETORNO CON EXITO, ESTARA EN MANTENIMIENTO\n");

                    fclose(archivo);
                    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                }


            }

            fclose(archivo);


        }
        else
        {

            printf("\nNo se pudo abriri el archivo");

        }



    }
    else if(validacion == 0 || validacion == 1 || validacion == 3  || validacion == 5 || validacion == 6) /// ( 1 = Listo,2 = En vuelo, 3 = Retornada, 4 =  Cancelada,  5 = Fallida 6 = finalizada)
    {
        system("cls"); /// limpia la pantalla
        printf("\nNo esta en condiciones de retornar la nave\n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


    }
    else
    {

        system("cls"); /// limpia la pantalla
        printf("\n\nId de la mision inexistente\n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    }







    MenuPrincipal();

}


void sacarDeMantenimiento()
{

    int valorID, confirmarSalidaDeMantenimiento;
    system("cls"); /// limpia la pantalla
    printf("\n----------------\nTALLER SPACEX:\n----------------\n\n\n");
    printf("\n\nIngresar la id de la nave que quieras poner en servivio\n\n INGRESAR VALOR:  ");
    scanf("%i", &valorID);

    int estadoNave = verificacionDeEstadoDeLaNave(valorID);

    Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

    if(estadoNave == 0)
    {

        printf("\n\nLa nave con la ID: %i , esta en mantenimeinto:\n\nIngresar un UNO para ponerlo en servicio: \n        Ingresar opcion: ", valorID);
        scanf("%i", &confirmarSalidaDeMantenimiento);
        if(confirmarSalidaDeMantenimiento == 1)
        {

            /// modificar estado de la nave, para que se pueda volve a usar
            stNave nave;

            FILE* archivo;
            archivo = fopen("listaNave.bin","r+b");
            if(archivo != NULL)
            {

                while(fread(&nave, sizeof(stNave), 1, archivo)>0)
                {

                    if(valorID == nave.ID)
                    {

                        nave.estado = 1;
                        fseek(archivo, -sizeof(stNave), SEEK_CUR);
                        fwrite(&nave, sizeof(stNave), 1, archivo);
                        fclose(archivo);
                        system("cls"); /// limpia la pantalla
                        printf("\nLa nave fue dada de alta con exito");
                        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos

                    }


                }
                fclose(archivo);

            }
            else
            {

                printf("\nNo se pudo abrir el archivo");

            }




            establecerMisionEnFinalizada(valorID);

        }
        else
        {
            system("cls"); /// limpia la pantalla


            printf("\nNo se confirmo la operacion.");
            Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
            MenuPrincipal();

        }




        MenuPrincipal();


    }
    else if(estadoNave == -1)
    {

        system("cls"); /// limpia la pantalla
        printf("\nLa ID de la nave no existe no se puede dar de baja \n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos


    }
    else
    {

        system("cls"); /// limpia la pantalla
        printf("\nLa nave no esta en condiciones de dar de baja\n");
        Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
    }

    MenuPrincipal();



}


///---------------------

int estadoDeLaMision(int ID)
{
    int salida =-1;
    FILE* archivo;
    stMision mision;

    archivo = fopen("ListaMisiones.bin", "rb");

    if (archivo != NULL)
    {
        while(fread(&mision, sizeof(stMision), 1, archivo)>0)
        {
            if (ID == mision.ID)
            {
                salida = mision.estado;
                fclose(archivo);

            }
        }

        fclose(archivo);
    }


    return salida;
}



int chequeoEstadoNave (int id)
{
    stNave nave;
    int estado= -1;
    FILE *archi;
    int salida =0;

    archi=fopen("listaNave.bin","rb");

    if(archi!= NULL)
    {
        while((fread(&nave, sizeof (stNave), 1, archi))>0 )
        {
            if (id == nave.ID)
            {
                estado=nave.estado;
                salida =1;



            }
        }
        fclose(archi);
    }

    return estado;
}

int chequeoAstronauta(int id)
{
    int estado;
    int salida = 0;
    stAstronauta astronauta;
    FILE* archivo;
    archivo = fopen("listaAstronauta.bin", "rb");
    if (archivo != NULL)
    {
        while (fread(&astronauta, sizeof(stAstronauta), 1, archivo) > 0 && salida == 0)
        {
            if (id == astronauta.ID)
            {
                estado = astronauta.estado;
                salida = 1;
            }
        }

        fclose(archivo);
    }

    return estado;
}


void establecerAlAstronautaEnModoListoParaOtraMision(int ID)
{


    FILE* archivo;
    stAstronauta astronauta;
    archivo = fopen("listaAstronauta.bin", "r+b");

    if(archivo != NULL)
    {

        while(fread(&astronauta, sizeof(stAstronauta), 1, archivo)> 0)
        {

            if(ID == astronauta.ID)
            {

                astronauta.estado = 1;
                fseek(archivo, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);
                fclose(archivo);

            }

        }
        fclose(archivo);

    }
    else
    {

        printf("\nNo se pudo abrir el archivo\n");

    }




}


void cambiarElEstadoDeLaNaveMantenimiento(int ID)
{


    FILE* archivo;
    stNave nave;
    archivo = fopen("listaNave.bin.bin", "r+b");

    if(archivo != NULL)
    {

        while(fread(&nave, sizeof(stNave), 1, archivo)> 0)
        {

            if(ID == nave.ID)
            {

                nave.estado = 0;
                fseek(archivo, -sizeof(stNave), SEEK_CUR);
                fwrite(&nave, sizeof(stNave), 1, archivo);
                fclose(archivo);

            }

        }
        fclose(archivo);

    }
    else
    {

        printf("\nNo se pudo abrir el archivo\n");

    }



}

void modificarEstadoDeAstronautaAMisionAsignada(int ID)
{


    stAstronauta astronauta;

    FILE* archivo;


    archivo = fopen("listaAstronauta.bin","r+b");

    if(archivo != NULL)
    {


        while(fread(&astronauta, sizeof(stAstronauta), 1, archivo)>0)
        {

            if(astronauta.ID == ID)
            {

                astronauta.estado = 5;
                fseek(archivo, -sizeof(stAstronauta),SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);
                fclose(archivo);

            }

        }
        fclose(archivo);



    }

}

void cambiarEstadoDeLaNaveAMisionAsignada(int ID)
{

    stNave nave;

    FILE* archivo;


    archivo = fopen("listaNave.bin","r+b");

    if(archivo != NULL)
    {


        while(fread(&nave, sizeof(stNave), 1, archivo)>0)
        {

            if(nave.ID == ID)
            {

                nave.estado = 4;
                fseek(archivo, -sizeof(stNave),SEEK_CUR);
                fwrite(&nave, sizeof(stNave), 1, archivo);
                fclose(archivo);

            }

        }
        fclose(archivo);



    }


}

///----------------------

void modificacionDeAstronautaMisionCancelada(int ID)
{


    stAstronauta astronauta;
    ///MODIFICO ESTADO ASTRONAUTAS
    FILE* archi;
    archi=fopen("listaAstronauta.bin", "r+b");
    if(archi != NULL)
    {
        while(fread(&astronauta, sizeof(stAstronauta), 1, archi)>0)
        {
            if( ID==astronauta.ID)
            {
                astronauta.estado=1;
                fseek(archi, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archi);
                fclose(archi);
            }


        }
        fclose(archi);

    }
    else
    {

        printf("No se pudo abrir el archivo ");

    }


}


void modificarEstadoDeLaNavePorMisionCancelada(int ID)
{


    stNave nave;
    FILE* archivo;
    archivo = fopen("listaNave.bin", "r+b");
    if (archivo != NULL)
    {
        while (fread(&nave, sizeof(stNave), 1, archivo) > 0  )
        {
            if (ID == nave.ID)
            {
                nave.estado = 1;

                fseek(archivo, -sizeof(stNave), SEEK_CUR);
                fwrite(&nave, sizeof(stNave), 1, archivo);
                fclose(archivo);

            }
        }

        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }
    system("cls"); /// limpia la pantalla



}


int estadoDeDespegueResultado()
{
    srand(time(NULL));  // Inicializar la semilla aleatoria

    int resultado = rand() % 10;  // Generar un número aleatorio entre 0 y 9

    if (resultado < 2)
    {
        return 3;  // Despegue fallido (20% de las veces)
    }
    else
    {
        return 2;  // Despegue exitoso (80% de las veces)
    }
}

int retornarHorasSegunDestinoDeLaMision(int misionID)
{
    FILE* archivo;
    stMision mision;
    int salida = 0;
    archivo = fopen("ListaMisiones.bin", "rb");

    if (archivo != NULL)
    {
        while (fread(&mision, sizeof(stMision), 1, archivo) > 0)
        {
            if (misionID == mision.ID)
            {
                switch (mision.destino)
                {
                case 1:
                    salida = 9;
                    break;
                case 2:
                    salida = 72;
                    break;
                case 3:
                    salida = 5226;
                    break;
                case 4:
                    salida = 21900;
                    break;
                case 5:
                    salida = 56940;
                    break;
                case 6:
                    salida = 96360;
                    break;
                case 7:
                    salida = 113880;
                    break;
                }
                break;  // Salir del bucle una vez que se encuentra la coincidencia
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



void establecerMisionEnFinalizada(int valorID)
{


    FILE* archivo;

    stMision mision;

    int salida;

    archivo = fopen("ListaMisiones.bin","rb");

    if(archivo != NULL)
    {

        while(fread(&mision, sizeof(stMision), 1, archivo)>0)
        {

            if(valorID == mision.IDnave)
            {

                mision.estado = 6;
                fseek(archivo, -sizeof(stMision), SEEK_CUR);
                fwrite(&mision, sizeof(stMision), 1, archivo);
                fclose(archivo);

            }


        }
        fclose(archivo);

    }
    else
    {

        printf("No se pudo ejecutar el archivo");

    }






}


/// VERIFICAR QUE LA ID DE LA MISION NO EXISTA

int verificacionDeIDMISION(int entrada)
{

    FILE* archivo;

    stMision misiones;
    int salida = 0;

    archivo = fopen("ListaMisiones.bin", "rb");

    if(archivo != NULL)
    {

        while(fread(&misiones, sizeof(stMision), 1, archivo)>0)
        {

            if(entrada == misiones.ID)
            {

                salida = 1;

            }

        }

        fclose(archivo);

    }
    return salida;

}


/// ID NAVE TENIENDO EL DATO DE LA ID MISION

int retornarIDnaveconLaIDmision(int misionID)
{

    FILE* archivo;

    stMision mision;

    int salida;

    archivo = fopen("ListaMisiones.bin","rb");

    if(archivo != NULL)
    {

        while(fread(&mision, sizeof(stMision), 1, archivo)>0)
        {

            if(misionID == mision.ID)
            {

                salida = mision.IDnave;

            }


        }
        fclose(archivo);

    }
    else
    {

        printf("No se pudo ejecutar el archivo");

    }

    return salida;

}


/// bajaDeNAVE

void estadoDenaveBaja(int idNave)
{


    FILE* archivo;

    stNave nave;

    int condicion = 0;



    archivo = fopen("listaNave.bin", "r+b");

    if(archivo != NULL)
    {

        while(fread(&nave, sizeof(stNave), 1, archivo)>0 && condicion == 0)
        {

            if(idNave == nave.ID)
            {

                nave.estado = 3;
                condicion = 1;
                fseek(archivo, -sizeof(stNave), SEEK_CUR);
                fwrite(&nave, sizeof(stNave), 1, archivo);
                fclose(archivo);

            }




        }
        fclose(archivo);


    }
    else
    {

        printf("\nNo se pudo ejecutar el archivo\n");

    }


}

/// ESTADO DE NAVE EN MISION, suma de horas de vuelo

void estadoDenaveEnMision(int idNave, int destino)
{

    FILE* archivo;

    stNave nave;

    int condicion = 0;



    archivo = fopen("listaNave.bin", "r+b");

    if(archivo != NULL)
    {

        while(fread(&nave, sizeof(stNave), 1, archivo)>0 && condicion == 0)
        {

            if(idNave == nave.ID)
            {

                nave.estado = 2;
                condicion = 1;
                nave.horasDeVueloAcumuladas = nave.horasDeVueloAcumuladas + destino;
                nave.cantidadDeVuelosRealizados++;

                fseek(archivo, -sizeof(stNave), SEEK_CUR);
                fwrite(&nave, sizeof(stNave), 1, archivo);
                fclose(archivo);

            }




        }
        fclose(archivo);



    }
    else
    {

        printf("\nNo se pudo ejecutar el archivo\n");

    }


}

void estadoDenaveEnretorno(int idNave,int destino)
{

    FILE* archivo;

    stNave nave;

    int condicion = 0;



    archivo = fopen("listaNave.bin", "r+b");

    if(archivo != NULL)
    {

        while(fread(&nave, sizeof(stNave), 1, archivo)>0 && condicion == 0)
        {

            if(idNave == nave.ID)
            {

                nave.estado = 0;
                condicion = 1;
                nave.horasDeVueloAcumuladas = nave.horasDeVueloAcumuladas + destino;
                nave.cantidadDeVuelosRealizados++;

                fseek(archivo, -sizeof(stNave), SEEK_CUR);
                fwrite(&nave, sizeof(stNave), 1, archivo);
                fclose(archivo);

            }




        }
        fclose(archivo);



    }
    else
    {

        printf("\nNo se pudo ejecutar el archivo\n");

    }


}



/// RETORNAR LA ID DEL PILOTO CON LA ID DE MISION

int retornarIdDePiolotoConIDdeMision(int misionID, int NumeroPiloto)
{

    int salida;

    FILE* archivo;
    int salidaWhile = 0;

    stMision mision;

    archivo = fopen("ListaMisiones.bin", "rb");

    if(archivo != NULL)
    {

        while(fread(&mision, sizeof(stMision), 1, archivo)>0 && salidaWhile == 0)
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
                salidaWhile = 1;

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

int detectarModeloDeLaNaveConIDMision(int misionID)
{
    FILE* archivo;
    stMision mision;
    int idNave;
    int salida = 0;
    int validacion = 0;
    archivo = fopen("ListaMisiones.bin", "rb");
    if (archivo != NULL)
    {
        while (fread(&mision, sizeof(stMision), 1, archivo) > 0 && validacion == 0)
        {

            if (misionID == mision.ID)
            {
                idNave = mision.IDnave;
                salida = detectarModeloDeNave(idNave);
                validacion = 1;
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

void altaAstronautaMisionViaje(int astronautaID, int destino)
{
    FILE* archivo;
    archivo = fopen("listaAstronauta.bin", "r+b");
    stAstronauta astronauta;
    int condicion = 0;



    if (archivo != NULL)
    {
        while (fread(&astronauta, sizeof(stAstronauta), 1, archivo) > 0)
        {
            if (astronauta.ID == astronautaID)
            {
                astronauta.estado = 3;


                astronauta.horasDeVueloAcumuladas = astronauta.horasDeVueloAcumuladas + destino; /// problemas en esta parte
                astronauta.horasAcumuladasEnElEspacioInternacioal = astronauta.horasAcumuladasEnElEspacioInternacioal + destino;
                astronauta.misionesEspecialesRealizadas ++;


                fseek(archivo, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);
                fclose(archivo);
            }
        }

        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }
}

void retornoAstronautaMisionViaje(int astronautaID, int destino)
{


    FILE* archivo;
    archivo = fopen("listaAstronauta.bin", "r+b");
    stAstronauta astronauta;
    int condicion = 0;
    int suma1, suma2;



    if (archivo != NULL)
    {
        while (fread(&astronauta, sizeof(stAstronauta), 1, archivo) > 0)
        {
            if (astronauta.ID == astronautaID)
            {
                suma1 = astronauta.horasDeVueloAcumuladas;
                suma2 = astronauta.horasAcumuladasEnElEspacioInternacioal;

                astronauta.estado = 1;


                astronauta.horasDeVueloAcumuladas = suma1 + destino; /// problemas en esta parte
                astronauta.horasAcumuladasEnElEspacioInternacioal = suma2 + destino;



                fseek(archivo, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);
                fclose(archivo);
            }
        }

        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }








}

/// BAJA DE ASTONAUTA POR MISION FALLIDA

void bajaDeAstronautaPorMuerte(int astronautaID)
{


    FILE* archivo;



    archivo = fopen("listaAstronauta.bin","r+b");

    stAstronauta astronauta;

    if(archivo != NULL)
    {





        while(fread(&astronauta, sizeof(stAstronauta), 1, archivo)>0 )
        {

            if(astronauta.ID == astronautaID)
            {

                astronauta.estado = 4;


                fseek(archivo, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);
                fclose(archivo);


            }

        }




        fclose(archivo);




    }
    else
    {

        printf("\nNo se pudo abirir el archivo\n");

    }




}


/// FUNCION PARA VERIFICAR EL TIPO DE NAVE

int detectarModeloDeNave(int idNave)
{
    FILE* archivo;
    archivo = fopen("listaNave.bin", "rb");
    stNave nave;
    int salida = 0;
    if (archivo != NULL)
    {
        while (fread(&nave, sizeof(stNave), 1, archivo) > 0 && idNave != nave.ID)
        {
        }
        if (idNave == nave.ID)
        {
            salida = nave.tipoDeNave;
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
    int salida = -1;

    FILE* archivo;
    stMision misiones;

    archivo = fopen("ListaMisiones.bin", "rb");

    if (archivo != NULL)
    {
        while (fread(&misiones, sizeof(stMision), 1, archivo) > 0)
        {
            if (idMisionVerificacion == misiones.ID)
            {
                salida = misiones.estado;
                break;
            }
        }

        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    return salida;  // Retorna el estado de la misión (o -1 si no se encontró)
}
/// verificacion ESTADO NAVA

int verificacionDeEstadoDeLaNave(int verificado)
{


    FILE* archivo;

    stNave nave;

    int salida = -1;

    archivo = fopen("listaNave.bin","rb");

    if(archivo != NULL)
    {

        while(fread(&nave, sizeof(stNave), 1, archivo)>0)
        {


            if(nave.ID == verificado)
            {




                salida = nave.estado;
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
