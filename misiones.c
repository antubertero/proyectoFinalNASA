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
    int opcionDeViaje;
    int confirmarDespege;

    FILE* archivo;
    archivo=fopen("listaMisiones.bin", "wb+");
    stMision mision;

    int i=0;

    if(archivo != NULL)
    {
        printf("Ingrese el id");
        scanf("%i", &mision.ID);

        printf("Ingrese el id de la nave que desea usar \n"); ///FALTA VERIFICAR ESTADO
        scanf("%i", &estadoVerificacion);

        estado=chequeoEstadoNave(estadoVerificacion);

        ///SWITCH VERIFICACION NAVE

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



        printf("\nIndicar el destino:  \n 1) Orbita terrestre\n 2) Luna\n3) marte\n 4) Jupiter\n 5) Saturno\n6) Urano\n 7) Neptuno\n\n   Ingresar opcion: ");
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
            }

            break;

        case 2:

            printf("\n Viaje a la Luna \n La hora de viaje aproximada es de 72hs. \n Ingresar UNO para confirmar: ");
            scanf("%i", &confirmarDespege);

            if(confirmarDespege==1)
            {
                mision.destino=2;
            }

            break;

        case 3:
            printf("\n Viaje a Marte \n La hora de viaje aproximada es de 7 meses / 5.226 horas. \n Ingresar UNO para confirmar: ");
            scanf("%i", &confirmarDespege);

            if(confirmarDespege==1)
            {
                mision.destino=3;
            }

            break;

        case 4:
            printf("\n Viaje a Jupiter \n La hora de viaje aproximada es de 30 meses / 21.900 horas. \n Ingresar UNO para confirmar: ");
            scanf("%i", &confirmarDespege);

            if(confirmarDespege==1)
            {
                mision.destino=4;
            }

            break;

        case 5:
            printf("\n Viaje a Saturno \n La hora de viaje aproximada es de 78 meses / 56.940 horas. \n Ingresar UNO para confirmar: ");
            scanf("%i", &confirmarDespege);


            if(confirmarDespege==1)
            {
                mision.destino=5;
            }

            break;


        case 6:

            printf("\n Viaje a Urano \n La hora de viaje aproximada es de 132 meses / 96,360 horas. \n Ingresar UNO para confirmar: ");
            scanf("%i", &confirmarDespege);

            if(confirmarDespege==1)
            {
                mision.destino=6;
            }

            break;


        case 7:

            printf("\n Viaje a Neptuno \n La hora de viaje aproximada es de 156 meses / 113.880 horas. \n Ingresar UNO para confirmar: ");
            scanf("%i", &confirmarDespege);

            if(confirmarDespege==1)
            {
                mision.destino=7;
            }

            break;


        }

        printf("Ingrese el cargamento \n");
        fflush(stdin);
        scanf("%s", &mision.cargamento);

        ///CARGA TRIPULANTE 1
        printf("Ingrese el id del primer tripulante \n"); ///FALTA VERIFICAR ESTADO
        scanf("%i", &tripulante);

        verificacion=chequeoAstronauta(tripulante);
        switch(verificacion)
        {
        case 1:
            printf("ASTRONAUTA ASIGNADO! \n");
            tripulante=mision.IDtripulante_1;
            break;

        case 2:
            printf("EL ASATRONAUTA ESTA RETIRADO! \n");
            printf("INGRESE OTRO ID \n");
            scanf("%i", &tripulante);
            verificacion=chequeoAstronauta(tripulante);
            if(verificacion==1)
            {
                printf("ASTRONAUTA ASIGNADO CON EXITO!! \n");
                tripulante=mision.IDtripulante_1;

                break;
            }
        }
        ///CARGAR TRIPULANTE 2

        printf("Ingrese el id del segundo tripulante \n"); ///FALTA VERIFICAR ESTADO
        scanf("%i", &tripulante);

        verificacion=chequeoAstronauta(tripulante);
        switch(verificacion)
        {
        case 1:
            printf("ASTRONAUTA ASIGNADO! \n");
            tripulante=mision.IDtripulante_2;
            break;

        case 2:
            printf("EL ASATRONAUTA ESTA RETIRADO! \n");
            printf("INGRESE OTRO ID \n");
            scanf("%i", &tripulante);
            verificacion=chequeoAstronauta(tripulante);
            if(verificacion==1)
            {
                printf("ASTRONAUTA ASIGNADO CON EXITO!! \n");
                tripulante=mision.IDtripulante_2;

                break;
            }
        }

        ///CARGAR TRIPULANTE 3

        printf("Ingrese el id del tercer tripulante \n"); ///FALTA VERIFICAR ESTADO
        scanf("%i", &tripulante);

        verificacion=chequeoAstronauta(tripulante);
        switch(verificacion)
        {
        case 1:
            printf("ASTRONAUTA ASIGNADO! \n");
            tripulante=mision.IDtripulante_3;
            break;

        case 2:
            printf("EL ASATRONAUTA ESTA RETIRADO! \n");
            printf("INGRESE OTRO ID \n");
            scanf("%i", &tripulante);
            verificacion=chequeoAstronauta(tripulante);
            if(verificacion==1)
            {
                printf("ASTRONAUTA ASIGNADO CON EXITO!! \n");
                tripulante=mision.IDtripulante_3;

                break;
            }
        }

        printf("Ingrese detalles de la mision \n");
        fflush(stdin);
        scanf("%s", &mision.detalleDeLaMision);

        mision.estado=1;

        fwrite(&mision, sizeof(stMision), 1, archivo);
        fclose(archivo);
    }
    else
    {

        printf("\nNO SE PUEDO ABRIR EL ARCHIVO");


    }




}

void listadoMisiones()
{
    printf("\n LISTA DE MISIONES \n");

    FILE* archivo;
    stMision mision;

    int i=0;
    int contador = 1;

    archivo = fopen("listaAstronauta.bin", "rb");

    if(archivo != NULL)
    {
        while (fread(&mision, sizeof(stMision), 1, archivo) > 0)
        {

            printf("\n\nLISTADO:\n\n");
            printf("MISION %i -> ID: %i \n -> NAVE: %i \n -> DESTINO: %s \n -> CARGAMENTO: %s \n -> TRIPULANTE 1: %s\n -> TRIPULANTE 2: %s\n -> TRIPULANTE 3: %s\n ----------------------------------------------------------\n", contador,mision.ID, mision.IDnave, mision.destino, mision.cargamento, mision.IDtripulante_1, mision.IDtripulante_2,  mision.IDtripulante_3);
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
    buffer = fopen("listaAstronauta.bin", "rb");
    if (buffer != NULL)
    {
        printf("Ingrese el ID de la misión que desea ver: ");
        scanf("%i", &consulta);

        int misionEncontrada = 0; // Variable para indicar si se encontró una misión con el ID dado

        while (fread(&mision, sizeof(stMision), 1, buffer) == 1)
        {
            if (mision.ID == consulta)
            {
                printf("MISIÓN CON ID %i:\n", mision.ID);
                printf("Nave: %i\n", mision.IDnave);
                printf("Destino: %s\n", mision.destino);
                printf("Cargamento: %s\n", mision.cargamento);
                printf("Tripulante 1: %s\n", mision.IDtripulante_1);
                printf("Tripulante 2: %s\n", mision.IDtripulante_2);
                printf("Tripulante 3: %s\n", mision.IDtripulante_3);

                misionEncontrada = 1;
                break; // Se encontró la misión, se puede salir del bucle
            }
        }

        fclose(buffer);

        if (!misionEncontrada)
        {
            printf("LA MISION NO FUE ENCONTRADA\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }
}


void bajaMision()
{
    int id1;
    int id2;
    int id3;
    int idnave;
    int condicion1=0;
    int condicion2=0;


    stNave nave;
    stMision mision;
    stAstronauta astronauta;

    int desicion;
    int cancelar;

    FILE* buffer;
    buffer=fopen("ListaMisiones.bin", "r+b");
    if(buffer != NULL)
    {
        printf("Ingrese el ID de la mision que desea cancelar \n");
        scanf("%i", &cancelar);

        while (fread(&mision, sizeof(stMision), 1, buffer) > 1)
        {
            if (mision.ID == cancelar)
            {
                printf("MISION CON ID %i -> nave: %i \n -> DESTINO: %s \n -> CARGAMENTO: %s \n -> TRIPULANTE 1: %s\n -> TRIPULANTE 2: %s\n -> TRIPULANTE 3: %s\n ----------------------------------------------------------\n", mision.ID, mision.IDnave, mision.destino, mision.cargamento, mision.IDtripulante_1, mision.IDtripulante_2, mision.IDtripulante_3);
                condicion1 = 1;
                break; // Se encontró la misión, se puede salir del bucle
            }
        }

        if (!condicion1)
        {
            printf("LA MISION NO FUE ENCONTRADA \n");
        }

        printf("ESTA SEGURO QUE DESEA CANCELAR LA MISION? \n 1->SI   2->NO");
        scanf("%i", &desicion);
        if(desicion==1)
        {
            mision.estado=4;
        }

        idnave=mision.IDnave;
        id1=mision.IDtripulante_1;
        id2=mision.IDtripulante_2;
        id3=mision.IDtripulante_3;

        fwrite(&mision, sizeof(stMision), 1, buffer);
        fclose(buffer);
    }
    else
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO \n");
        MenuPrincipal();
    }

    ///MODIFICO ESTADO ASTRONAUTAS
    FILE* archi;
    archi=fopen("listaAstronauta.bin", "wb+");
    if(archi != NULL)
    {
        while(fread(&astronauta, sizeof(stAstronauta), 1, archi)==1)
        {
            if(id1==astronauta.ID)
            {
                astronauta.estado=1;
                fseek(archi, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archi);
            }

            if(id2==astronauta.ID)
            {
                astronauta.estado=1;
                fseek(archi, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archi);
            }

            if(id3==astronauta.ID)
            {
                astronauta.estado=1;
                fseek(archi, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archi);
            }
        }
        fclose(archi);
    }

    FILE* archivo;
    archivo = fopen("listaNave.bin", "rb+");
    if (archivo != NULL)
    {
        while (fread(&nave, sizeof(stNave), 1, archivo) == 1 && condicion2 == 0)
        {
            if (idnave == nave.ID)
            {
                nave.estado = 1;
                condicion2 = 1;
            }
        }
        fseek(archivo, -sizeof(stNave), SEEK_CUR);
        fwrite(&nave, sizeof(stNave), 1, archivo);
        fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

}




///-----------------------------------------------------------


void despegueDeMision()
{

    int misionID, confirmarDespege;

    int idNave;

    stMision misiones;

    fflush(stdin);

    printf("\nINICIO DE LA MISION\n\n\ningresar La id de la mision:\n");
    scanf("%i",&misionID);

    int validacion = verificacionDeMisionEntrada(misionID);
    int destino = retornarHorasSegunDestinoDeLaMision(misionID);

    int tipoDeNaveDespegue = detectarModeloDeLaNaveConIDMision(misionID);



    if(validacion == 1 )
    {

        printf("\nLa nave esta en condiciones de despqgar:\n");

        int piloto1ID, piloto2ID, piloto3ID;


        idNave = retornarIDnaveconLaIDmision(misionID);

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
                    estadoDenaveEnMision(idNave);
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
                    estadoDenaveEnMision(idNave);


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
                    estadoDenaveEnMision(idNave);


                }
            }


            FILE* archivo;

            archivo = fopen("listaMision.bin","r+b");

            if(archivo != NULL)
            {

                while(fread(&misiones, sizeof(stMision), 1, archivo)>0)
                {

                    if(misionID == misiones.ID)
                    {


                        misiones.estado = 2;



                    }


                }

                fclose(archivo);




            }
            else
            {


                printf("\n SE DIO DE BAJA LA MISION\N");
                system("cls"); /// limpia la pantall
                Sleep(3000); /// proceso espere durante aproximadamente 3 segundos
                MenuPrincipal();

            }


        }
        else if(validacion == 0)
            {

                printf("\nLA ID NO EXISTE\n");


            }

        else
        {

            printf("\nLa nave no esta en condicones de partir \n");
            MenuPrincipal();

        }
    }
}


void retornoDeLaMision()
{


    int misionID, confirmarDespege;

    stMision misiones;

    fflush(stdin);

    printf("\nINICIO DE LA MISION\n\n\ningresar La id de la mision:\n");
    scanf("&i",&misionID);

    int validacion = verificacionDeMisionEntrada(misionID);

    if(validacion == 2)   /// dos es en vuelo
    {


        FILE* archivo;

        archivo = fopen("listaMision.bin","r+b");

        if(archivo != NULL)
        {

            while(fread(&misiones, sizeof(stMision), 1, archivo)>0)
            {

                if(misionID == misiones.ID)
                {

                    system("cls"); /// limpia la pantalla

                    printf("\nLA NAVE ESRA RETORNANDO\n");

                    misiones.estado = 1;

                    system("cls"); /// limpia la pantalla

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
    else if(validacion == 0)
        {

            printf("\n\nId de la mision inexistente\n");

        }
    else
    {

        printf("\nNo esta en condiciones de retornar la nave\n");

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

/// retornar las hoiras de vuelo segun la mision

int retornarHorasSegunDestinoDeLaMision(int misionID)
{

    FILE* archivo;

    stMision mision;

    int salida = 0;

    archivo = fopen("listaMision.bin","rb" );


    if(archivo=! NULL)
    {

        while(fread(&mision, sizeof(stMision), 1, archivo)>0)
        {

            if(misionID == mision.ID)
            {


                switch(mision.destino)
                {

                case 1 :

                    salida  = 9;

                    break;

                case 2:

                    salida = 72;

                    break;

                case 3:

                    salida = 5226;

                case 4:

                    salida = 21900;

                case 5:

                    salida = 56940;

                case 6:

                    salida = 96360;

                case 7:

                    salida = 113880;



                }


            }


        }

        fclose(archivo);


    }
    else
    {

        printf("\nEl archivo no se pudo ejecuar\n");

    }

    return salida;


}




/// ID NAVE TENIENDO EL DATO DE LA ID MISION

int retornarIDnaveconLaIDmision(int misionID)
{

    FILE* archivo;

    stMision mision;

    int salida;

    archivo = fopen("listaMision.bin","rb");

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

            }




        }


    }
    else
    {

        printf("\nNo se pudo ejecutar el archivo\n");

    }


}

/// ESTADO DE NAVE EN MISION

void estadoDenaveEnMision(int idNave)
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

                fseek(archivo, -sizeof(stNave), SEEK_CUR);
                fwrite(&nave, sizeof(stNave), 1, archivo);

            }




        }


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

int detectarModeloDeLaNaveConIDMision(int misionID)
{

    FILE* archivo;

    stMision mision;

    int idNave;

    int salida=0;

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

void altaAstronautaMisionViaje(int astronautaID, int destino)
{

    FILE* archivo;

    archivo = fopen("listaAstronauta.bin","r+b");

    stAstronauta astronauta;

    int codicion = 0;

    if(archivo != NULL)
    {





        while(fread(&astronauta, sizeof(stAstronauta), 1, archivo)>0 && codicion == 0)
        {

            if(astronauta.ID == astronautaID)
            {

                astronauta.ID = 3;
                codicion = 1;
                astronauta.horasDeVueloAcumuladas = astronauta.horasDeVueloAcumuladas + destino;
                astronauta.horasAcumuladasEnElEspacioInternacioal = astronauta.horasAcumuladasEnElEspacioInternacioal + destino;

                fseek(archivo, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);


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

    int validacion = 0;

    archivo = fopen("listaAstronauta.bin","r+b");

    stAstronauta astronauta;

    if(archivo != NULL)
    {





        while(fread(&astronauta, sizeof(stAstronauta), 1, archivo)>0 && validacion == 0)
        {

            if(astronauta.ID == astronautaID)
            {

                astronauta.ID = 4;
                validacion =1;

                fseek(archivo, -sizeof(stAstronauta), SEEK_CUR);
                fwrite(&astronauta, sizeof(stAstronauta), 1, archivo);


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


                salida = misiones.estado;

            }


        }


        fclose(archivo);



    }
    else
    {

        printf("\nNo se pudo abrir el archivo\n");

    }
    return salida;  /// retorna el estado de la mision


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
