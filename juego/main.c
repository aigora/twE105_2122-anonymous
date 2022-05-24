#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>



typedef struct //Estructura con los diferentes objetos que puedes ir consiguiendo y fabricando.
{
    int palo, cinta, cristal, chocolate, piedra, hacha, cuchillo, martillo, llaves;

}objetos;

//PONER COMO PUNTEROS DENTRO DE LAS FUNCIONES.
int Nventanas[7]; //DENTRO DE LA FUNCIÓN IR Y DE ZOMBIES (METER COMO PUNTERO).
int Ncajones[7]; //DENTRO DE CAJONES, DE IR Y DE
//int salud = 50;

// DECLARACIÓN DE LAS FUNCIONES
void juego();//L.74
void observar(int eleccion, objetos mochila, int *salud1);//L.112
void mostrarmochila(objetos mochila);//L.133
void mostrarherramientas(objetos mochila);//L.136
void mapa();//L.143
void salud_(int *salud2);//L.149
objetos ir(objetos mochila, int *salud);//L.154
int bano(int salud);//L.189
objetos carpinteria(objetos mochila);//L.212
objetos crear(objetos mochila);//L.240
objetos cajones(objetos cajon);
objetos agarrar(objetos mochila);
objetos cofre(objetos mochila);
//objetos comedor(objetos mochila, int *salud4);
void zombies(objetos mochila,int i, int *salud5);


void ventanaycajones();

int main()
{
    system("color 02");
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

void juego(){
    int Nventanas[3]; //Hay ventanas en la carpintería, baño y jardín.
    int Ncajones[2]; //Hay cajones en el dormitorio y en la carpintería.
    int salud = 50;
    int eleccion, salir = 1;
    objetos mochila;
    mochila.palo = 5;
    mochila.cinta = 5;
    mochila.cristal = 5;
    mochila.chocolate = 0;
    mochila.piedra = 5;
    mochila.hacha = 0;
    mochila.cuchillo = 0;
    mochila.martillo = 0;
    mochila.llaves = 0;
    while(salir == 1)
    {
        printf("¿Qué quieres hacer?\n[0]Observar [1]Ir [2]Salir\n");
        scanf("%i", &eleccion);
        switch(eleccion)
        {
        case 0:
            printf("que quieres observar?\n[0]Mochila [1]Herramientas [2]Mapa [3]salud\n");
            scanf("%i", &eleccion);
            observar(eleccion, mochila, salud);
            break;
        case 1:
            mochila = ir(mochila, &salud);
            break;
        case 2:
            salir = 0;
            break;
        }

    }
    printf("Saliendo...");

}

//Funciones de observar
void observar(int eleccion, objetos mochila, int *salud1){
    switch(eleccion)
    {
    case 0:
        mostrarmochila(mochila);
        break;
    case 1:
        mostrarherramientas(mochila);
        break;
    case 2:
        mapa();
        break;
    case 3:
        salud_(&salud1);
        break;

    }
}

void mostrarmochila(objetos mochila){
    printf("palos = (%i), cintas = (%i), cristales = (%i), chocolate = (%i), piedras = (%i)\n", mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra);

}

void mostrarherramientas(objetos mochila){
    printf("hacha = %i, cuchillo = %i\n", mochila.hacha, mochila.cuchillo);

}

void mapa(){
    printf("            ___            ___ \n    | |____| 1 |__________|   |          1-Jardín\n    |  _   ______   ______  5 |          2-Baño\n    | |_| |  ___ | |      |___|          3-Carpintería\n    |  ___| |   || |______               4-Dormitorio\n ___| |_____| 4 ||        |              5-Salida\n|  2   _________||    3   |    \n|_____|          |________|    \n\n\n");

}

void salud_(int *salud2){
    printf("Tienes %i puntos de vida\n", *salud2);
}

//Funciones de ir
objetos ir(objetos mochila, int *salud3){ // METER VARIABLES GLOBALES VENTANAS, CAJONES COMO PUNTEROS
    int eleccion;
    printf("¿A donde quieres ir?\n");
    scanf("%i", &eleccion);
    switch(eleccion)
    {
    case 1:
        printf("Estás en el jardín.\nTe encuentras delante de un ciprés de 100 años, puedes sacar madera para vallar las ventanas y que no salgan zombies.\n");
        //mochila = comedor(mochila, salud3);//cambiar funcion comedor (jardin)
        zombies(mochila,1, salud3);
        break;
    case 2:
        printf("Estás en el baño.\nAquí puedes recuperar salud relajándote en las duchas.\n");
        int vida = bano(*salud3);
        *salud3 = *salud3 + vida;
        zombies(mochila,6, salud3);

        break;
    case 3:
        printf("Estás en la carpintería.\nAquí puedes fabricar distintos objetos.\n");
        mochila = carpinteria(mochila);
        zombies(mochila,3, salud3);
        break;
    case 4:
        printf("Estás en el dormitorio.\nAquí reapareces cuando mueres\n");
        //meter funcion de dormitorio
        break;
    case 5:
        printf("Ahí esta la salida. Investiga como puedes llegar hasta ahí y abrir la puerta\n");
        zombies(mochila,8, salud3);
        break;
    }
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};


}

int bano(int salud){  //METER VARIABLES GLOBALES SALUD.
    int eleccion, vida;
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
            printf("Salud = %i\n", salud);
            sleep(1);
        }

        //printf("%i", *salud);
        break;
    case 1:
        break;
    }


}

objetos carpinteria(objetos mochila){ // METER VARIABLES GLOBALES VENTANAS Y CAJONES.
    int eleccion;
    printf("Hay %i ventanas y %i cajones\n", Nventanas[2], Ncajones[2]);
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

    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};;
}

objetos crear(objetos mochila){ //USADA DENTRO DE CARPINTERÍA PARA HACER LAS HERRAMINETAS.
    int eleccion, x = 5, creacion = 0;
    printf("¿Qué quieres crear?\n[0]hacha [1]cuchillo [2]martillo\n");
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
    case 2: //CREAR MARTILLO.
        break;
        }
        if(creacion == 1){
            while(x > -1){
                system("cls");
                printf("Creando: %i...", x);
                sleep(1); //mirar si usa el windows.h

                x--;
              }
              system("cls");
              printf("Creado\n");
              x = 5;
        }
        creacion = 0;

    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};

}










objetos cajones(objetos cajon)
{

    cajon.palo = rand() % 3;
    cajon.cinta = rand() % 3;
    cajon.cristal = rand() % 3;
    cajon.chocolate = rand() % 3;
    cajon.piedra = rand() % 3;
    return (objetos) {cajon.palo, cajon.cinta, cajon.cristal, cajon.chocolate, cajon.piedra};

}
objetos agarrar(objetos mochila)//segurmante se quite
{

    objetos cajon;
    cajon = cajones(mochila);
    int coger;
    printf("los objetos que hay en el cajon son: palos = (%i), cintas = (%i), cristales = (%i), chocolate = (%i), piedras = (%i)\n", cajon.palo, cajon.cinta, cajon.cristal, cajon.chocolate, cajon.piedra);
    printf("los quieres coger o dejar?\ncoger todo[0] coger por eleccion[1]\n");
    jump:
    scanf("%i", &coger);
    if(coger == 0)
    {
        mochila.palo =+ cajon.palo;
        mochila.cinta =+ cajon.cinta;
        mochila.cristal =+ cajon.cristal;
        mochila.chocolate =+ cajon.chocolate;
        mochila.piedra =+ cajon.piedra;

    }
    else if(coger == 1)
    {
        int dejar;
        int algomas;
        printf("que objetos quieres coger?(elija de uno en uno)\n[0]palo [1]cinta [2]cristal [3]chocolate [4]piedra\n");
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
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate};
}


objetos cofre(objetos mochila)//cambiar para que te de un numero de la clave.
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
        cofre.piedra = rand() % 10;
        while(eleccion != 7){
        printf("palos = (%i), cintas = (%i), cristales = (%i), chocolate = (%i), piedras = (%i)\n", cofre.palo, cofre.cinta, cofre.cristal, cofre.chocolate, cofre.piedra);
        printf("¿Que quieres coger?\n[0]Todo [1]Palos [2]Cinta [3]Cristal [4]Chocolate [5]Piedra [6]Termianar\n");
        scanf("%i", &eleccion);
        switch(eleccion)
        {
        case 0:
             mochila.palo += cofre.palo;
             mochila.cinta += cofre.cinta;
             mochila.cristal += cofre.cristal;
             mochila.chocolate += cofre.chocolate;
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
            mochila.piedra += cofre.piedra;
            cofre.piedra = 0;
            break;
        case 6:
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
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};

}

void ventanaycajones(){  // METER VARIABLES GLOBALES VENTANAS Y CAJONES COMO PUNTEROS
                      //QUITAR QUE EL BAÑO TENGA VENTANAS Y CAJONES.
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

/*objetos comedor(objetos mochila,int *salud4){   //METER VARIABLES GLOBALES VENTANAS Y CAJONES. Cambiar por jardín.
    int eleccion;
    printf("Hay %i ventanas y %i cajones", Nventanas[0], Ncajones[0]);
    printf("¿Qué quieres hacer?\n[0]Comer [1]Tapar ventanas [2]Abrir cajones\n");
    scanf("%i", &eleccion);
    switch(eleccion)
    {
    case 0:
        if(*salud4 < 100 && mochila.chocolate > 0){
            printf("¿Quieres consumir una chocolatina?\n[0]Sí [1]No\n");
            scanf("%i", &eleccion);
            if(eleccion == 0){
                mochila.chocolate--;
                *salud4 += 25;
                if(*salud4 > 100)
                    *salud4 = 100;
            }
            printf("%i", *salud4);

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

    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};;
    }*/

void zombies(objetos mochila,int i, int *salud5) // METER VENTANAS Y SALUD.
{
    int vidazombie = rand() % (51) + 50 ;
    if(Nventanas[i] > 0)
    {
        int r = rand() % 1;
    if(r == 0){
        printf("¡CUIDADO! Ha aparecido un zombie delante de ti con %i de vida.\n¿Qué quieres hacer?\n", vidazombie);
        int eleccion;
        int huir = 1;
        while(huir == 1){
        printf("[0]Atacar [1]Intentar huir(50 de probabilidades)\n");
        scanf("%i", &eleccion);
        switch(eleccion)
        {
        case 0:
            switch(eleccion)
            {
            case 0:
                if(mochila.cuchillo == 1){
                vidazombie -= 30;
                *salud5 -= rand() % (10) + 5;
                if(vidazombie <= 0){
                    huir = 0;
                    break;
                }
                printf("Ahora tienes %i puntos de salud y el zombie %i\n", *salud5, vidazombie);
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
        printf("Perfecto, has matado al zombie y has escapado.\n\n");
        sleep(5);
        system("cls");
    }

    }

}
