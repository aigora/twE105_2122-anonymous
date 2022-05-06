#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>



typedef struct //Estructura con los diferentes objetos que puedes ir consiguiendo y fabricando.
{
    int palo, cinta, cristal, chocolate, bebida, piedra, hacha, ganzua, cuchillo, hoz, martillo, llaves;

}objetos;

//PONER COMO PUNTEROS DENTRO DE LAS FUNCIONES.
int Nventanas[7]; //DENTRO DE LA FUNCIÓN IR Y DE ZOMBIES (METER COMO PUNTERO).
int Ncajones[7]; //DENTRO DE CAJONES, DE IR Y DE
int salud = 50;
// DECLARACIÓN DE LAS FUNCIONES
objetos cajones(objetos cajon);
objetos agarrar(objetos mochila);
objetos crear(objetos mochila);
objetos cofre(objetos mochila);
objetos carpinteria(objetos mochila);
objetos ir(objetos mochila);
objetos comedor(objetos mochila);
void zombies(objetos mochila,int i);
void mostrarmochila(objetos mochila);
void mostrarherramientas(objetos mochila);
void mapa();
void observar(int eleccion, objetos mochila);
void ventanaycajones();
void bano();
void salud_();
void juego();

int main()
{
    srand(time(0));
    ventanaycajones();
    setlocale (LC_CTYPE,"spanish");  //PONER EL TEXTO EN ESPAÑOL.

    int x = 0;
    jump: while(x == 1){
        system("cls");
        x = 0;
    }
    int menu;          //MENÚ DE INICIO
    int opciones;
    printf("ESCAPA COMO PUEDAS\n Bienvenido al juego, ¿Qué deseas hacer?\n");
    printf(" [1]JUGAR\n [2]OPCIONES\n [3]SALIR\n");
    scanf("%i", &menu);

    switch(menu){
    case 1:
        juego();
        break;
    case 2:
    printf(" [1]DIFICULTAD\n [2]TIEMPO\n");
    scanf("%i", &opciones);
    break;
    case 3:
        break;

    default:
        x = 1;
        goto jump;
    }

    return 0;
}

void juego(){ // DECLARAR VARIABLES GLOBALES DENTRO DE ESTA FUNCIÓN.
    int eleccion;
    int salir = 1;
     objetos mochila;
    mochila.palo = 2;
    mochila.cinta = 1;
    mochila.cristal = 1;
    mochila.chocolate = 1;
    mochila.bebida = 1;
    mochila.piedra = 4;
    mochila.hacha = 0;
    mochila.ganzua = 0;
    mochila.cuchillo = 0;
    mochila.hoz = 0;
    mochila.martillo = 0;
    mochila.llaves = 3;
    while(salir == 1)
    {
        printf("que quieres hacer?\n[0]Observar [1]Coger objetos [2]Crear [3]Salir [4]Ir [5]Abrir cofre\n");
        scanf("%i", &eleccion);
        switch(eleccion)
        {
        case 0:
            printf("que quieres observar?\n[0]Mochila [1]Suelo [2]Mapa [3]Herramientas [4]salud\n");
            scanf("%i", &eleccion);
            observar(eleccion, mochila);
            break;
        case 1:
            mochila = agarrar(mochila);
            break;
        case 2:
            mochila = crear(mochila);
            break;
        case 3:
            salir = 0;
            break;
        case 4:
            mochila = ir(mochila);
            break;
        case 5:
            mochila = cofre(mochila);
            break;
        }

    }
    printf("Saliendo...");
}
objetos cajones(objetos cajon)
{

    cajon.palo = rand() % 3;
    cajon.cinta = rand() % 3;
    cajon.cristal = rand() % 3;
    cajon.chocolate = rand() % 3;
    cajon.bebida = rand() % 3;
    cajon.piedra = rand() % 3;
    return (objetos) {cajon.palo, cajon.cinta, cajon.cristal, cajon.chocolate, cajon.bebida, cajon.piedra};

}
objetos agarrar(objetos mochila)
{

    objetos cajon;
    cajon = cajones(mochila);
    int coger;
    printf("los objetos que hay en el cajon son: palos = (%i), cintas = (%i), cristales = (%i), chocolate = (%i), bebidas = (%i), piedras = (%i)\n", cajon.palo, cajon.cinta, cajon.cristal, cajon.chocolate, cajon.bebida, cajon.piedra);
    printf("los quieres coger o dejar?\ncoger todo[0] coger por eleccion[1]\n");
    jump:
    scanf("%i", &coger);
    if(coger == 0)
    {
        mochila.palo =+ cajon.palo;
        mochila.cinta =+ cajon.cinta;
        mochila.cristal =+ cajon.cristal;
        mochila.chocolate =+ cajon.chocolate;
        mochila.bebida =+ cajon.bebida;
        mochila.piedra =+ cajon.piedra;

    }
    else if(coger == 1)
    {
        int dejar;
        int algomas;
        printf("que objetos quieres coger?(elija de uno en uno)\n[0]palo [1]cinta [2]cristal [3]chocolate [4]bebida [5]piedra\n");
        scanf("%i", &dejar);
        switch(dejar)
        {
        case 0:
            mochila.palo =+ cajon.palo;
            cajon.palo = 0;
            break;
        case 1:
            mochila.cinta =+ cajon.cinta;
            cajon.cinta = 0;
            break;
        case 2:
            mochila.cristal =+ cajon.cristal;
            cajon.cristal = 0;
            break;
        case 3:
            mochila.chocolate =+ cajon.chocolate;
            cajon.chocolate = 0;
            break;
        case 4:
            mochila.bebida =+ cajon.bebida;
            cajon.bebida = 0;
            break;
        case 5:
            mochila.piedra =+ cajon.piedra;
            cajon.piedra = 0;
            break;


        }
        printf("algo mas?\n[0]si [1]no\n");
        scanf("%i", &algomas);
        if(algomas == 0){
            goto jump;//arreglar
        }
        else if(algomas == 1)
        {
            printf("okey");
        }


    }
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.bebida};
}
void mostrarmochila(objetos mochila)
{
    printf("palos = (%i), cintas = (%i), cristales = (%i), chocolate = (%i), bebidas = (%i), piedras = (%i)\n", mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.bebida, mochila.piedra);

}
void mostrarherramientas(objetos mochila){
    printf("hacha = %i, cuchillo = %i\n", mochila.hacha, mochila.cuchillo);

}
void mapa()
{
    printf("            ___      o     ___ \n    | |____| 1 |_____ooo _|   |\n    |  _   ______   _o2oo_  8 |\n    | |_| |  ___ | | ooo  |___|\n    |  ___| |   || |______     \n ___| |_____| 7 ||        |    \n|  6   _________||    3   |    \n|_____|  ________|        |    \n        |  __     ________|    \n        |5|  | 4 |             \n        | |  |___|             \n");

}
void observar(int eleccion, objetos mochila)
{
    switch(eleccion)
    {
    case 0:
        mostrarmochila(mochila);
        break;
    case 1:
        break;
    case 2:
        mapa();
        break;
    case 3:
        mostrarherramientas(mochila);
        break;
    case 4:
        salud_();
        break;

    }

}
objetos crear(objetos mochila)
{
    int eleccion;
    int x = 5;
    int creacion = 0;
    printf("que quieres crear?\n[0]hacha [1]ganzua [2]cuchillo [3]hoz [4]martillo\n");
    scanf("%i", &eleccion);
    switch(eleccion){
    case 0:
        if(mochila.palo > 1 && mochila.cinta > 0){
        if(mochila.piedra > 3){
        mochila.hacha = 1;
        creacion = 1;
        mochila.palo -= 2;
        mochila.cinta -= 1;
        mochila.piedra -= 4;
        }
        }
        else{
        printf("No tienes suficientes recursos\n");
        }
        break;
    case 1:
        //if() completar creacion de ganzua
        break;
    case 2:
        if(mochila.palo > 0 && mochila.piedra > 1){
        mochila.cuchillo = 1;
        creacion = 1;
        mochila.palo -= 1;
        mochila.piedra -= 2;
        }

        else{
            printf("No tienes suficientes recursos\n");
        }
        break;

        }
        if(creacion == 1){
            while(x > -1){
                system("cls");
                printf("Creando: %i...", x);
                sleep(1);

                x--;
              }
              system("cls");
              printf("Creado\n");
              x = 5;
        }
        creacion = 0;
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.bebida, mochila.piedra, mochila.hacha, mochila.ganzua, mochila.cuchillo, mochila.hoz, mochila.martillo};

}
objetos cofre(objetos mochila)
{
    int eleccion;
    printf("Necesitas 5 fragmentos de llaves\n");
    if(mochila.llaves == 5)
    {
        objetos cofre;
        printf("¿Deseas abrir el cofre?\n[0]Si [1]No\n");
        scanf("%i", &eleccion);
        if(eleccion == 0){
        cofre.palo = rand() % 10;
        cofre.cinta = rand() % 10;
        cofre.cristal = rand() % 10;
        cofre.chocolate = rand() % 10;
        cofre.bebida = rand() % 10;
        cofre.piedra = rand() % 10;
        while(eleccion != 7){
        printf("palos = (%i), cintas = (%i), cristales = (%i), chocolate = (%i), bebidas = (%i), piedras = (%i)\n", cofre.palo, cofre.cinta, cofre.cristal, cofre.chocolate, cofre.bebida, cofre.piedra);
        printf("¿Que quieres coger?\n[0]Todo [1]Palos [2]Cinta [3]Cristal [4]Chocolate [5]Bebida [6]Piedra [7]Termianar\n");
        scanf("%i", &eleccion);
        switch(eleccion)
        {
        case 0:
             mochila.palo += cofre.palo;
             mochila.cinta += cofre.cinta;
             mochila.cristal += cofre.cristal;
             mochila.chocolate += cofre.chocolate;
             mochila.bebida += cofre.bebida;
             mochila.piedra += cofre.piedra;

             break;
        case 1:
            mochila.palo += cofre.palo;
            cofre.palo = 0;
            break;
        case 2:
            mochila.cinta += cofre.cinta;
            cofre.cinta = 0;
            break;
        case 3:
            mochila.cristal += cofre.cristal;
            cofre.cristal = 0;
            break;
        case 4:
            mochila.chocolate += cofre.chocolate;
            cofre.chocolate = 0;
            break;
        case 5:
            mochila.bebida += cofre.bebida;
            cofre.bebida = 0;
            break;
        case 6:
            mochila.piedra += cofre.piedra;
            cofre.piedra = 0;
            break;
        case 7:
            break;

        }
        }

    }
    }
    else{
       printf("No tienes suficientes fragmentos\n");
       int resto = 5 - mochila.llaves;
       printf("te faltan %i fragmentos de llaves\n", resto);
    }
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.bebida, mochila.piedra, mochila.hacha, mochila.ganzua, mochila.cuchillo, mochila.hoz, mochila.martillo};

}
objetos ir(objetos mochila){ // METER VARIABLES GLOBALES SALUD, VENTANAS, CAJONES COMO PUNTEROSS
    int eleccion;
    printf("¿A donde quieres ir?");
    scanf("%i", &eleccion);
    switch(eleccion)
    {
    case 1:
        printf("Estás en el comedor.\nPuedes recuperar vida comiendo.\n");
        mochila = comedor(mochila);
        zombies(mochila,1);
        break;
    case 2:
        printf("Estás en el lago.\nNecesitas un traje de buceo para poder cruzarlo\n");
        zombies(mochila,2);
        break;
    case 3:
        printf("Estás en la carpintería.\nAquí puedes fabricar distintos objetos\n");
        mochila = carpinteria(mochila);
        zombies(mochila,3);
        break;
    case 4:
        printf("Estás en la armería.\nAquí puedes encontrar y fabricar armas.\n");
        zombies(mochila,4);
        break;
    case 5:
        printf("Estás en las escaleras.\nProximamente podrás visitar la siguiente planta.\n");
        zombies(mochila,5);
        break;
    case 6:
        printf("Estás en el baño.\nAquí puedes recuperar salud relajándote en las duchas.\n");
        bano();
        zombies(mochila,6);
        break;
    case 7:
        printf("Estás en el dormitorio.\nAquí reapareces cuando mueres\n");
        zombies(mochila,7);
        break;
    case 8:
        printf("Ahí esta la salida. Investiga como puedes llegar hasta ahí y abrir la puerta\n");
        zombies(mochila,8);
        break;

    }
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.bebida, mochila.piedra, mochila.hacha, mochila.ganzua, mochila.cuchillo, mochila.hoz, mochila.martillo};


}
void ventanaycajones() // METER VARIABLES GLOBALES VENTANAS Y CAJONES COMO PUNTEROS
{                       //QUITAR QUE EL BAÑO TENGA VENTANAS Y CAJONES.
    for(int i = 0; i < 7; i++)
    {
        if(i == 2)
        {
            Nventanas[i] = rand() % (4) + 1;  //CAMBIAR VECTORES A PUNTEROS
            Ncajones[i] = rand() % (4) + 1;
        }
        else if(i == 5)
        {
            Nventanas[i] = rand() % (2) + 1;
            Ncajones[i] = rand() % (4) + 1;
        }
        else{
            Nventanas[i] = rand() % (3) + 1;
            Ncajones[i] = rand() % (3) + 1;
        }
    }

}
objetos carpinteria(objetos mochila)    // METER VARIABLES GLOBALES VENTANAS Y CAJONES.
{

    int eleccion;
    printf("Hay %i ventanas y %i cajones", Nventanas[2], Ncajones[2]);
    printf("¿Qué quieres hacer?\n[0]Crear herrramientas [1]Tapar ventanas [2]Abrir cajones");

    scanf("%i", &eleccion);
    switch(eleccion)
    {
    case 0:
        mochila = crear(mochila);
        break;
    case 1:
        break;
    case 2:
        if(Ncajones[2] > 0){
        mochila = agarrar(mochila);
        Ncajones[2]--;
        }
        else{
            printf("No quedan cajones para abrir");
        }
        break;
    }

    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.bebida, mochila.piedra, mochila.hacha, mochila.ganzua, mochila.cuchillo, mochila.hoz, mochila.martillo};;


}
objetos comedor(objetos mochila)    //METER VARIABLES GLOBALES VENTANAS Y CAJONES.
{
    int eleccion;
    printf("Hay %i ventanas y %i cajones", Nventanas[0], Ncajones[0]);
    printf("¿Qué quieres hacer?\n[0]Comer [1]Tapar ventanas [2]Abrir cajones\n");
    scanf("%i", &eleccion);
    switch(eleccion)
    {
    case 0:
        if(salud < 100 && mochila.chocolate > 0){
            printf("¿Quieres consumir una chocolatina?\n[0]Sí [1]No\n");
            scanf("%i", &eleccion);
            if(eleccion == 0){
                mochila.chocolate--;
                salud += 25;
                if(salud > 100)
                    salud = 100;
            }
            printf("%i", salud);

        }
        else{
            printf("Tu salud está al maximo o no tienes suficiente alimento\n");
        }
        break;
        case 1:
        break;
    case 2:
        if(Ncajones[0] > 0){
        mochila = agarrar(mochila);
        Ncajones[0]--;
        }
        else{
            printf("No quedan cajones para abrir");
        }
        break;
    }

    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.bebida, mochila.piedra, mochila.hacha, mochila.ganzua, mochila.cuchillo, mochila.hoz, mochila.martillo};;
    }
void bano( )  //METER VARIABLES GLOBALES SALUD.
{
    int eleccion;
    int vida;
    printf("¿Quieres recuperar vida?\n(Ten en cuenta que cada punto de vida es un segundo de espera)\n[0]Sí [1]No\n");
    scanf("%i", &eleccion);
    switch(eleccion)
    {
    case 0:
        printf("¿Cuanta vida quiere recuperar?\n");
        scanf("%i", &vida);
        for(int i = 0; i < vida; i++){
            system("cls");
            salud++;
            printf("Salud = %i", salud);
            sleep(1);
        }
        break;
    case 1:
        break;
    }


}
void salud_()  // METER VARIABLES GLOBALES SALUD.
{
    printf("Tienes %i puntos de vida\n", salud);
}
void zombies(objetos mochila,int i) // METER VENTANAS Y SALUD.
{
    int vidazombie = rand() % (51) + 50 ;
    if(Nventanas[i] > 0)
    {
        int r = rand() % 4;
    if(r == 0){
        printf("¡CUIDADO! Ha aparecido un zombie delante tuya con %i de vida.\n¿Que quieres hacer?\n", vidazombie);
        int eleccion;
        int huir = 1;
        while(huir == 1){
        printf("[0]Atacar [1]Intentar huir(50 de probabilidades)\n");
        scanf("%i", &eleccion);
        switch(eleccion)
        {
        case 0:
            printf("¿Con que quieres atacar?\n[0]Cuchillo\n");
            switch(eleccion)
            {
            case 0:
                if(mochila.cuchillo == 1){
                vidazombie -= 30;
                salud -= 5;
                printf("Ahora tienes %i puntos de salud y el zombie %i\n", salud, vidazombie);
                }
                else{
                printf("No tienes cuchillo\n");
                }
                if(vidazombie<0){
                    huir = 0;//terminar
                }
            break;
            case 1:
                huir = 0;
                break;

            }
            break;

        }
        }
        printf("Perfecto, has matado al zombie y has escapado");
    }

    }

}


