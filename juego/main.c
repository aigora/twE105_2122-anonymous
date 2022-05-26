#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <unistd.h>

#define FILAS 3
#define COLUMNAS 3
#define TAMANIO_MATRIZ FILAS *COLUMNAS
#define JUGADOR_X 'X'
#define JUGADOR_O 'O'
#define JUGADOR_CPU_X JUGADOR_X
#define JUGADOR_CPU_O JUGADOR_O
#define ESPACIO_VACIO ' '
#define CONTEO_PARA_GANAR 3
// Modos de juego
#define JUGADOR_JUGADOR 1
#define JUGADOR_CPU 2
#define CPU_CPU 3
#define SALIR 4



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
objetos ir(objetos mochila, int *salud, int i, int *ventanas);//L.154
int bano(objetos mochila, int salud, int *ventanasbano);//L.189
objetos dormitorio(objetos mochila, int *salud7);
objetos carpinteria(objetos mochila, int *salud6, int *ventanascarpinteria);//L.212
objetos crear(objetos mochila);//L.240
objetos cajones(objetos cajon);
objetos agarrar(objetos mochila);
objetos cofre(objetos mochila);
objetos jardin(objetos mochila, int *salud4, int *ventanasjardin);
objetos zombies(objetos mochila,int i, int *salud5);

//codigo del tres en raya;
void clonarMatriz(char tableroOriginal[FILAS][COLUMNAS], char destino[FILAS][COLUMNAS]);
void limpiarTablero(char tablero[FILAS][COLUMNAS]);
void imprimirTablero(char tablero[FILAS][COLUMNAS]);
int coordenadasVacias(int y, int x, char tablero[FILAS][COLUMNAS]);
void colocarPieza(int y, int x, char pieza, char tablero[FILAS][COLUMNAS]);
int contarHaciaArriba(int x, int y, char jugador, char tablero[FILAS][COLUMNAS]);
int contarHaciaDerecha(int x, int y, char jugador, char tablero[FILAS][COLUMNAS]);
int contarHaciaArribaDerecha(int x, int y, char jugador, char tablero[FILAS][COLUMNAS]);
int contarHaciaAbajoDerecha(int x, int y, char jugador, char tablero[FILAS][COLUMNAS]);
int comprobarSiGana(char jugador, char tablero[FILAS][COLUMNAS]);
char oponenteDe(char jugador);
void hablar(char *mensaje, char jugador);
int empate(char tableroOriginal[FILAS][COLUMNAS]);
int aleatorio_en_rango(int minimo, int maximo);
void obtenerCoordenadasAleatorias(char jugador, char tableroOriginal[FILAS][COLUMNAS], int *yDestino, int *xDestino);
void coordenadasParaGanar(char jugador, char tableroOriginal[FILAS][COLUMNAS], int *yDestino, int *xDestino);
int contarSinSaberCoordenadas(char jugador, char copiaTablero[FILAS][COLUMNAS]);
void coordenadasParaMayorPuntaje(char jugador, char tableroOriginal[FILAS][COLUMNAS], int *yDestino, int *xDestino, int *conteo);
void elegirCoordenadasCpu(char jugador, char tablero[FILAS][COLUMNAS], int *yDestino, int *xDestino);
int iniciarJuego(int modo);
char jugadorAleatorio();
void tresenraya(int *i);


//void ventanaycajones();

int main()
{
    system("color 02");
    srand(time(0));

    setlocale (LC_CTYPE,"spanish");  //PONER EL TEXTO EN ESPAÑOL.

    int x = 0;
    jump: while(x == 1){
        system("cls");
        x = 0;
    }
    int menu;          //MENÚ DE INICIO
    int opciones;
    FILE *p;
    printf("ESCAPA COMO PUEDAS\n Bienvenido al juego, ¿Qué deseas hacer?\n");
    printf(" [1]Jugar\n [2]OPCIONES\n [3]SALIR\n");
    scanf("%i", &menu);
    system("cls");

    switch(menu){
    case 1:
        printf("¿Quieres cargar tu partida guardada o empezar una nueva?\n[1]Partida guardada [2]Partida nueva\n");
        scanf("%i", &menu);
        switch(menu)
        {
        case 1:
            juego(1);
            break;
        case 2:
            p = fopen("guardado.txt", "w");
        fprintf(p, "0,0,0,0,0,0,0,0,0,0,0,0");
        fclose(p);
        system("cls");
            juego(0);
            break;
        }
        break;
    case 2:
    printf("[1]Partida nueva [2]Volver\n");
    scanf("%i", &opciones);
    switch(opciones)
    {/*
    case 1:
        p = fopen("guardado.txt", "w");
        fprintf(p, "0,0,0,0,0,0,0,0,0,0,0,0");
        fclose(p);
        system("cls");
        goto jump;
        break;*/
    case 2:
        break;
    }
    break;
    case 3:
        break;

    default:
        x = 1;
        goto jump;
    }

    return 0;
}

void juego(int n){
    //int Nventanas[3]; //Hay ventanas en la carpintería, baño y jardín.
    //int Ncajones[2]; //Hay cajones en el dormitorio y en la carpintería.
    int salud;
    int eleccion, salir = 1;
    int ventanas[3];
    FILE *guardado;
    if(n == 0){
    salud = 50;
    for(int i = 0; i < 3; i++){
            ventanas[i] = rand() % (2) +2;
    }
    }
    objetos mochila;
    /*mochila.palo = 15;
    mochila.cinta = 15;
    mochila.cristal = 15;
    mochila.chocolate = 15;
    mochila.piedra = 15;
    mochila.hacha = 0;
    mochila.cuchillo = 0;
    mochila.martillo = 1;
    mochila.llaves = 0;*/
    if(n == 1){

    guardado = fopen("guardado.txt", "r");
    fscanf(guardado, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i", &mochila.palo, &mochila.cinta, &mochila.cristal, &mochila.chocolate, &mochila.piedra, &mochila.hacha, &mochila.cuchillo, &mochila.martillo, &salud, &ventanas[0], &ventanas[1], &ventanas[2]);
    fclose(guardado);
    }
    while(salir == 1)
    {
        printf("¿Qué quieres hacer?\n[0]Observar [1]Ir [2]Salir\n");
        scanf("%i", &eleccion);
        switch(eleccion)
        {
        case 0:
            printf("¿Qué quieres observar?\n[0]Mochila [1]Herramientas [2]Mapa [3]salud\n");
            scanf("%i", &eleccion);
            system("cls");
            observar(eleccion, mochila, salud);
            break;
        case 1:
            mochila = ir(mochila, &salud, 0, &ventanas);
            break;
        case 2:
            salir = 0;
            guardado = fopen("guardado.txt", "w");
            fprintf(guardado, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i", &mochila.palo, &mochila.cinta, &mochila.cristal, &mochila.chocolate, &mochila.piedra, &mochila.hacha, &mochila.cuchillo, &mochila.martillo, &salud, &ventanas[0], &ventanas[1], &ventanas[2]);
            break;
        case 3:

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
    printf("Hacha = %i\nCuchillo = %i\nMartillo = %i", mochila.hacha, mochila.cuchillo, mochila.martillo);

}

void mapa(){
     printf("\n               MAPA\n\n            ___            ___ \n    | |____| 1 |__________|   |          1-Jardín\n    |  _   ______   ______  5 |          2-Baño\n    | |_| |  ___ | |      |___|          3-Carpintería\n    |  ___| |   || |______               4-Dormitorio\n ___| |_____| 4 ||        |              5-Salida\n|  2   _________||    3   |    \n|_____|          |________|    \n\n\n");

}

void salud_(int *salud2){
    printf("Tienes %i puntos de vida\n", *salud2);
}

//Funciones de ir
objetos ir(objetos mochila, int *salud3, int i, int *ventanas){ // METER VARIABLES GLOBALES VENTANAS, CAJONES COMO PUNTEROS
    int eleccion;
    if(i != 1){
    printf("¿A donde quieres ir?\n");
    mapa();
    scanf("%i", &eleccion);
    system("cls");
    }
    else if(i == 1){
        eleccion = 4;
    }
    switch(eleccion)
    {
    case 1:
        printf("Estás en el jardín.\nTe encuentras delante de un ciprés de 100 años, puedes conseguir madera para arreglar las vallas rotas \n y que no entren zombies.\n");
        mochila = jardin(mochila, salud3, &*ventanas);//cambiar funcion comedor (jardin)

        break;
    case 2:
        printf("Estás en el baño.\nAquí puedes recuperar salud relajándote en las duchas.\n");
        int vida = bano(mochila, *salud3, &*ventanas);
        *salud3 = vida;
        break;
    case 3:
        printf("Estás en la carpintería.\nAquí puedes fabricar distintos objetos.\n");
        mochila = carpinteria(mochila, &*salud3, &*ventanas);
        break;
    case 4:
        jump1:
        printf("Estás en el dormitorio.\nAquí reapareces cuando mueres\n");
        mochila = dormitorio(mochila, &*salud3);
        break;
    case 5:
        printf("Ahí esta la salida. Investiga como puedes llegar hasta ahí y abrir la puerta\n");
        break;
    }
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};


}
objetos jardin(objetos mochila, int *salud4, int *ventanasjardin){   //METER VARIABLES GLOBALES VENTANAS Y CAJONES. Cambiar por jardín.
    int eleccion, n, num;
    printf("Hay %i vallas rotas. ", *ventanasjardin);
    printf("¿Qué quieres hacer?\n[0]Comer [1]Arreglar vallas [2]Conseguir madera\n");
    scanf("%i", &eleccion);
    switch(eleccion)
    {
    case 0:
        system("cls");
        if(*salud4 < 100 && mochila.chocolate > 0){
            printf("¿Quieres consumir una chocolatina?\n[0]Sí [1]No\n");
            scanf("%i", &eleccion);
            if(eleccion == 0){
                mochila.chocolate--;
                *salud4 += 25;
                if(*salud4 > 100)
                    *salud4 = 100;
            }
            printf("Tienes %i de salud.", *salud4);

        }
        else{
            printf("Tu salud está al maximo o no tienes suficiente alimento\n");
        }
        break;

        case 1:
            system("cls");
        if(*ventanasjardin > 0){
            if(mochila.palo > 2 && mochila.martillo == 1){
            *ventanasjardin = *ventanasjardin-1;
            printf("Has arreglado la valla, ahora quedan %i vallas rotas.\n", *ventanasjardin);
            }
            else {
        int maderanecesaria = 3 - mochila.palo;
        if(maderanecesaria < 0)
            maderanecesaria = 0;

        printf("No tinenes materiales suficientes, te falta %i de madera", maderanecesaria);
        if(mochila.martillo < 1){
            printf(" y un martillo");
        }
        printf(".\n");
            }
        }
        else{
            printf("No quedan vallas rotas que arreglar.\n");
        }
        break;
    case 2:
        system("cls");
       srand(time(NULL));
       n=rand()% 100+1;

      printf("Para conseguir madera tienes que adivinar un número del 1 al 100.\n");
       scanf("%d",&num);
       do {
        if(n>num){
           printf("Mas alto\n");
           scanf("%d",&num);}
           else if (n<num){
                    printf("Mas bajo\n");
                    scanf("%d",&num);}}
        while(n!=num);
        mochila.palo += 3;
        printf("Has conseguido 3 tablones de madera, ahora tienes %i.\n", mochila.palo);

        break;
    }
    mochila = zombies(mochila, *ventanasjardin, &*salud4);

    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};;
    }


int bano(objetos mochila, int salud, int *ventanasbano){
    int eleccion, vida;
    printf("Hay %i ventanas.\n", *(ventanasbano+1));
    printf("¿Quieres recuperar vida?\n(Ten en cuenta que cada punto de vida es un segundo de espera)\n[0]Sí [1]No\n[2]Tambien puedes vallar las ventanas del baño");
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
        break;
    case 1:
        break;
    case 2:
        if(*(ventanasbano+1) > 0){
            if(mochila.palo > 2 && mochila.martillo == 1){
            *(ventanasbano+1)= *(ventanasbano+1)-1 ;
            printf("Has vallado la ventana, ahora quedan %i ventanas.\n", *(ventanasbano+1));
            }
            else {
        int maderanecesaria = 3 - mochila.palo;
        if(maderanecesaria < 0)
            maderanecesaria = 0;

        printf("No tinenes materiales suficientes, te falta %i de madera", maderanecesaria);
        if(mochila.martillo < 1){
            printf(" y un martillo");
        }
        printf(".\n");
            }
        }
        else{
            printf("No quedan ventanas que vallar.\n");
        }
        break;
    }
    mochila = zombies(mochila, *ventanasbano, &salud);
    return salud;
}

objetos carpinteria(objetos mochila, int *salud6, int *ventanascarpinteria){ // METER VARIABLES GLOBALES VENTANAS Y CAJONES.
    int cajonescarpinteria, eleccion;
    cajonescarpinteria = rand() % (2) + 1;
    printf("Hay %i ventanas y %i cajones\n", *(ventanascarpinteria+2), cajonescarpinteria);
    printf("¿Qué quieres hacer?\n[0]Crear herramientas [1]Tapar ventanas [2]Abrir cajones\n");
    scanf("%i", &eleccion);
    switch(eleccion)
    {
    case 0:
        mochila = crear(mochila);
        break;
    case 1:
        if(*(ventanascarpinteria+2) > 0){
            if(mochila.palo > 2 && mochila.martillo == 1){
            *(ventanascarpinteria+2)= *(ventanascarpinteria+2)-1 ;
            printf("Has vallado la ventana, ahora quedan %i ventanas.\n", *(ventanascarpinteria+2));
            }
            else {
        int maderanecesaria = 3 - mochila.palo;
        if(maderanecesaria < 0)
            maderanecesaria = 0;

        printf("No tinenes materiales suficientes, te falta %i de madera", maderanecesaria);
        if(mochila.martillo < 1){
            printf(" y un martillo");
        }
        printf(".\n");
            }
        }
        else{
            printf("No quedan ventanas que vallar.\n");
        }
        break;
    case 2:
        if(cajonescarpinteria > 0){
        mochila = agarrar(mochila);
        cajonescarpinteria--;
        }
        else{
            printf("No quedan cajones para abrir");
        }
        break;
    }
    mochila = zombies(mochila, *(ventanascarpinteria+2), &*salud6);

    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};
}

objetos dormitorio(objetos mochila, int *salud7){
    int cajonesdormitorio, eleccion;

    cajonesdormitorio = rand() % (1) + 1;
    printf("Hay %i cajones\n", cajonesdormitorio);
    printf("¿Qué quieres hacer?\n[1]Abrir cajones [2]Usar dispensador [3]Salir\n");
    scanf("%i", &eleccion);
    switch(eleccion){
    case 1:
        if(cajonesdormitorio > 0){
        mochila = agarrar(mochila);
        cajonesdormitorio--;
        }
        else{
            printf("No quedan cajones para abrir");
        }
        break;
    case 2:
        printf("El dispensador te permite sacar materiales de forma ilimitada.\nPero antes debes ganarle a alguien en el 3 en raya.\n");
        int i;
        tresenraya(&i);
        printf("%i\n", i);
        if(i == 1){
            system("cls");
            printf("Perfecto. Ahora puedes abrir el dispensador.\n");
            mochila = agarrar(mochila);

        }
        if(i != 1){
            printf("Lo siento. Más suerte la próxima vez.\n");
            sleep(2);
        }
        break;
    case 3:
        break;
    }
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};
}
objetos crear(objetos mochila){ //USADA DENTRO DE CARPINTERÍA PARA HACER LAS HERRAMINETAS.
    int eleccion, x = 5, creacion = 0;
    printf("¿Qué quieres crear?\n[0]Hacha--> 2-Palos 1-Cinta 4-Piedras\n[1]Cuchillo--> 1-Palo 2-Cristales\n[2]Martillo--> 3-Palos 2-Cintas 4-Piedras\n");
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
        if(mochila.palo > 0 && mochila.cristal > 1){
        mochila.cuchillo = 1;
        creacion = 1;
        mochila.palo -= 1;
        mochila.cristal -= 2;
        }

        else{
            printf("No tienes suficientes recursos\n");
        }
        break;
    case 2:
        if(mochila.palo > 2 && mochila.cinta > 1){
        if(mochila.piedra > 3){
        mochila.martillo = 1;
        creacion = 1;
        mochila.palo -= 3;
        mochila.cinta -= 2;
        mochila.piedra -= 4;
        }
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
    printf("Los quieres coger o dejar?\nCoger todo[0] Coger por elección[1]\n");
    jump:
    scanf("%i", &coger);
    if(coger == 0)
    {
        mochila.palo += cajon.palo;
        mochila.cinta += cajon.cinta;
        mochila.cristal += cajon.cristal;
        mochila.chocolate += cajon.chocolate;
        mochila.piedra += cajon.piedra;

    }
    else if(coger == 1)
    {
        int dejar;
        int algomas;
        printf("¿Qué objetos quieres coger? (Elija de uno en uno.)\n[0]Palo [1]Cinta [2]Cristal [3]Chocolate [4]Piedra\n");
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
       printf("¿Algo más?\n[0]Sí [1]No\n");
        scanf("%i", &algomas);
        if(algomas == 0){
            goto jump;//arreglar
        }
        else if(algomas == 1)
        {
            system("cls");
            printf("Okey ");
        }


    }
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};
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

/*void ventanaycajones(){  // METER VARIABLES GLOBALES VENTANAS Y CAJONES COMO PUNTEROS
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

}*/


objetos zombies(objetos mochila,int ventanas, int *salud5) // METER VENTANAS Y SALUD.
{
    int i = 1;
    int huir;
    int vidazombie = rand() % (51) + 50 ;
    if(ventanas > 0)
    {
        int r = rand() % 1;
    if(r == 0){
        printf("¡CUIDADO! Ha aparecido un zombie delante de ti con %i de vida.\n¿Qué quieres hacer?\n", vidazombie);
        int eleccion;
        huir = 1;
        int huida;
        while(huir == 1){
        printf("[0]Atacar [1]Intentar huir(50 de probabilidades)\n");
        scanf("%i", &eleccion);
        switch(eleccion)
        {
        case 0:
            //{
            //case 0:
                if(mochila.cuchillo == 1){
                vidazombie -= 30;

                *salud5 -= rand() % (15) + 5;
                if(vidazombie <= 0){
                    huir = 0;
                    break;
                }
                if(*salud5 <= 0){
                    mochila.palo = 0;
                    mochila.cinta = 0;
                    mochila.cristal = 0;
                    mochila.chocolate = 0;
                    mochila.piedra = 0;
                    *salud5 = 50;
                    printf("Has muerto.\n");
                    sleep(5);
                    system("cls");
                    printf("Te despiertas con mareos en la cama del cuarto.\nPor desgracia no sabes donde has dejado tus objetos, solo te quedan las herramientas.");

                }
                printf("Ahora tienes %i puntos de salud y el zombie %i\n", *salud5, vidazombie);
                }
                else{
                printf("No tienes cuchillo\n");
                huir = 1;
                }
                if(vidazombie<0){
                    huir = 0;//terminar
                }
            break;
            case 1:
                huida = rand() %  2;
                printf("%i", huida);
                if(huida == 1){
                printf("Has conseguido huir. Ten más cuidado las próxima vez.\nPor desgracia te ha raspado el brazo y has perdido 10 de vida.\n");
                *salud5 -=10;
                huir = 0;
                if(*salud5 <= 0){
                    mochila.palo = 0;
                    mochila.cinta = 0;
                    mochila.cristal = 0;
                    mochila.chocolate = 0;
                    mochila.piedra = 0;
                    *salud5 = 50;
                    printf("Has muerto.\n");
                    sleep(5);
                    system("cls");
                    printf("Te despiertas con mareos en la cama del cuarto.\nPor desgracia no sabes donde has dejado tus objetos, solo te quedan las herramientas.");
                }
                }
                if(huida != 1){
                printf("No has conseguido escapar. Te ha mordido y has perdido 30 puntos de vida.\n");
                *salud5 -= 30;
                if(*salud5 <= 0){
                    mochila.palo = 0;
                    mochila.cinta = 0;
                    mochila.cristal = 0;
                    mochila.chocolate = 0;
                    mochila.piedra = 0;
                    *salud5 = 50;
                    printf("Has muerto.\n");
                    sleep(5);
                    system("cls");
                    printf("Te despiertas con mareos en la cama del cuarto.\nPor desgracia no sabes donde has dejado tus objetos, solo te quedan las herramientas.");

                }
                }
                huir = 1;
                break;

            }
            break;

        }

        }
        if(i == 0){
        printf("Perfecto, has matado al zombie y has escapado.\n\n");
        sleep(5);
        system("cls");
        }
        else if(i == 1){
                sleep(2);
        }
        else if(i == 2){
                sleep(5);
            //ir(mochila, *salud5, 1,);
        }
    }

    //}
    return (objetos) {mochila.palo, mochila.cinta, mochila.cristal, mochila.chocolate, mochila.piedra, mochila.hacha, mochila.cuchillo, mochila.martillo};

}

void clonarMatriz(char tableroOriginal[FILAS][COLUMNAS], char destino[FILAS][COLUMNAS])
{
    memcpy(destino, tableroOriginal, TAMANIO_MATRIZ);
}

// Establece todo el tablero en espacios vacíos
// Pd: quién te conoce memset
void limpiarTablero(char tablero[FILAS][COLUMNAS])
{
    int y;
    for (y = 0; y < FILAS; y++)
    {
        int x;
        for (x = 0; x < COLUMNAS; x++)
        {
            tablero[y][x] = ESPACIO_VACIO;
        }
    }
}

// Imprime el tablero de juego
void imprimirTablero(char tablero[FILAS][COLUMNAS])
{
    printf("\n");
    int y;
    int x;
    // Imprimir encabezado
    printf("| ");
    for (x = 0; x < COLUMNAS; x++)
    {
        printf("|%d", x + 1);
    }
    printf("|\n");
    for (y = 0; y < FILAS; y++)
    {
        printf("|%d", y + 1);
        for (x = 0; x < COLUMNAS; x++)
        {
            printf("|%c", tablero[y][x]);
        }
        printf("|\n");
    }
}

// Indica si el tablero está vacío en las coordenadas indicadas
int coordenadasVacias(int y, int x, char tablero[FILAS][COLUMNAS])
{
    return tablero[y][x] == ESPACIO_VACIO;
}

// Coloca la X o O en las coordenadas especificadas
void colocarPieza(int y, int x, char pieza, char tablero[FILAS][COLUMNAS])
{
    if (y < 0 || y >= FILAS)
    {
        printf("Fila incorrecta");
        return;
    }

    if (x < 0 || x >= COLUMNAS)
    {
        printf("Columna incorrecta");
        return;
    }
    if (pieza != JUGADOR_O && pieza != JUGADOR_X)
    {
        printf("La pieza debe ser %c o %c", JUGADOR_O, JUGADOR_X);
        return;
    }
    if (!coordenadasVacias(y, x, tablero))
    {
        printf("Coordenadas ya ocupadas");
        return;
    }
    tablero[y][x] = pieza;
}
/*
Funciones de conteo. Simplemente cuentan cuántas piezas del mismo jugador están
alineadas
*/

int contarHaciaArriba(int x, int y, char jugador, char tablero[FILAS][COLUMNAS])
{
    int yInicio = (y - CONTEO_PARA_GANAR >= 0) ? y - CONTEO_PARA_GANAR + 1 : 0;
    int contador = 0;
    for (; yInicio <= y; yInicio++)
    {
        if (tablero[yInicio][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
    }
    return contador;
}

int contarHaciaDerecha(int x, int y, char jugador, char tablero[FILAS][COLUMNAS])
{
    int xFin = (x + CONTEO_PARA_GANAR < COLUMNAS) ? x + CONTEO_PARA_GANAR - 1 : COLUMNAS - 1;
    int contador = 0;
    for (; x <= xFin; x++)
    {
        if (tablero[y][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
    }
    return contador;
}

int contarHaciaArribaDerecha(int x, int y, char jugador, char tablero[FILAS][COLUMNAS])
{
    int xFin = (x + CONTEO_PARA_GANAR < COLUMNAS) ? x + CONTEO_PARA_GANAR - 1 : COLUMNAS - 1;
    int yInicio = (y - CONTEO_PARA_GANAR >= 0) ? y - CONTEO_PARA_GANAR + 1 : 0;
    int contador = 0;
    while (x <= xFin && yInicio <= y)
    {
        if (tablero[y][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
        x++;
        y--;
    }
    return contador;
}

int contarHaciaAbajoDerecha(int x, int y, char jugador, char tablero[FILAS][COLUMNAS])
{
    int xFin = (x + CONTEO_PARA_GANAR < COLUMNAS) ? x + CONTEO_PARA_GANAR - 1 : COLUMNAS - 1;
    int yFin = (y + CONTEO_PARA_GANAR < FILAS) ? y + CONTEO_PARA_GANAR - 1 : FILAS - 1;
    int contador = 0;
    while (x <= xFin && y <= yFin)
    {
        if (tablero[y][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
        x++;
        y++;
    }
    return contador;
}

// Indica si el jugador gana
int comprobarSiGana(char jugador, char tablero[FILAS][COLUMNAS])
{
    int y;
    for (y = 0; y < FILAS; y++)
    {
        int x;
        for (x = 0; x < COLUMNAS; x++)
        {
            if (
                contarHaciaArriba(x, y, jugador, tablero) >= CONTEO_PARA_GANAR ||
                contarHaciaDerecha(x, y, jugador, tablero) >= CONTEO_PARA_GANAR ||
                contarHaciaArribaDerecha(x, y, jugador, tablero) >= CONTEO_PARA_GANAR ||
                contarHaciaAbajoDerecha(x, y, jugador, tablero) >= CONTEO_PARA_GANAR)
            {
                return 1;
            }
        }
    }
    // Terminamos de recorrer y no conectó
    return 0;
}

// Devuelve el jugador contrario al que se le pasa. Es decir, le das un O y te devuelve el X
char oponenteDe(char jugador)
{
    if (jugador == JUGADOR_O)
    {
        return JUGADOR_X;
    }
    else
    {
        return JUGADOR_O;
    }
}

// Imprime algo que el CPU "dice"
void hablar(char *mensaje, char jugador)
{
    printf("\nEl secuaz (%c) dice: %s\n\n", jugador, mensaje);
}

// Debería llamarse después de verificar si alguien gana
// Indica si hay un empate
int empate(char tableroOriginal[FILAS][COLUMNAS])
{
    int y;
    for (y = 0; y < FILAS; y++)
    {
        int x;
        for (x = 0; x < COLUMNAS; x++)
        {
            // Si hay al menos un espacio vacío se dice que no hay empate
            if (tableroOriginal[y][x] == ESPACIO_VACIO)
            {
                return 0;
            }
        }
    }
    return 1;
}

// Devuelve un número aleatorio en un rango, incluyendo los límites
int aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

// Coloca dos coordenadas aleatorias y válidas en xDestino y yDestino
void obtenerCoordenadasAleatorias(char jugador, char tableroOriginal[FILAS][COLUMNAS], int *yDestino, int *xDestino)
{
    int x, y;
    do
    {
        x = aleatorio_en_rango(0, COLUMNAS - 1);
        y = aleatorio_en_rango(0, FILAS - 1);
    } while (!coordenadasVacias(y, x, tableroOriginal));
    *yDestino = y;
    *xDestino = x;
}

// Coloca en yDestino y xDestino las coordenadas para que jugador gane en tableroOriginal.
// Si no puede ganar, colocará ambas coordenadas en -1
void coordenadasParaGanar(char jugador, char tableroOriginal[FILAS][COLUMNAS], int *yDestino, int *xDestino)
{
    char copiaTablero[FILAS][COLUMNAS];
    int y, x;
    for (y = 0; y < FILAS; y++)
    {
        for (x = 0; x < COLUMNAS; x++)
        {
            clonarMatriz(tableroOriginal, copiaTablero);
            if (coordenadasVacias(y, x, copiaTablero))
            {
                colocarPieza(y, x, jugador, copiaTablero);
                if (comprobarSiGana(jugador, copiaTablero))
                {
                    *yDestino = y;
                    *xDestino = x;
                    return;
                }
            }
        }
    }
    *yDestino = *xDestino = -1;
}

/*
Esta función cuenta y te dice el mayor puntaje, pero no te dice en cuál X ni cuál Y. Está pensada
para ser llamada desde otra función que lleva cuenta de X e Y
*/
int contarSinSaberCoordenadas(char jugador, char copiaTablero[FILAS][COLUMNAS])
{
    int conteoMayor = 0;
    int x, y;
    for (y = 0; y < FILAS; y++)
    {
        for (x = 0; x < COLUMNAS; x++)
        {
            // Colocamos y contamos el puntaje
            int conteoTemporal;
            conteoTemporal = contarHaciaArriba(x, y, jugador, copiaTablero);
            if (conteoTemporal > conteoMayor)
            {
                conteoMayor = conteoTemporal;
            }
            conteoTemporal = contarHaciaArribaDerecha(x, y, jugador, copiaTablero);
            if (conteoTemporal > conteoMayor)
            {
                conteoMayor = conteoTemporal;
            }

            conteoTemporal = contarHaciaDerecha(x, y, jugador, copiaTablero);
            if (conteoTemporal > conteoMayor)
            {
                conteoMayor = conteoTemporal;
            }

            conteoTemporal = contarHaciaAbajoDerecha(x, y, jugador, copiaTablero);
            if (conteoTemporal > conteoMayor)
            {
                conteoMayor = conteoTemporal;
            }
        }
    }
    return conteoMayor;
}

/*
Esta función complementa a contarSinSaberCoordenadas. Te dice en qué X e Y el jugador [jugador]
obtendrá el mayor puntaje si pone ahí su pieza
*/
void coordenadasParaMayorPuntaje(char jugador, char tableroOriginal[FILAS][COLUMNAS], int *yDestino, int *xDestino, int *conteo)
{

    char copiaTablero[FILAS][COLUMNAS];
    int y, x;
    int conteoMayor = 0,
        xConteoMayor = -1,
        yConteoMayor = -1;
    for (y = 0; y < FILAS; y++)
    {
        for (x = 0; x < COLUMNAS; x++)
        {
            clonarMatriz(tableroOriginal, copiaTablero);
            if (!coordenadasVacias(y, x, copiaTablero))
            {
                continue;
            }
            // Colocamos y contamos el puntaje
            colocarPieza(y, x, jugador, copiaTablero);
            int conteoTemporal = contarSinSaberCoordenadas(jugador, copiaTablero);
            if (conteoTemporal > conteoMayor)
            {
                conteoMayor = conteoTemporal;
                yConteoMayor = y;
                xConteoMayor = x;
            }
        }
    }
    *conteo = conteoMayor;
    *xDestino = xConteoMayor;
    *yDestino = yConteoMayor;
}

// Hace que el CPU elija unas coordenadas para ganar
void elegirCoordenadasCpu(char jugador, char tablero[FILAS][COLUMNAS], int *yDestino, int *xDestino)
{
    hablar("Estoy pensando...", jugador);
    /*
    El orden en el que el CPU infiere las coordenadas que toma es:
    1. Ganar si se puede
    2. Hacer perder al oponente si está a punto de ganar
    3. Tomar el mejor movimiento del oponente (en donde obtiene el mayor puntaje)
    4. Tomar mi mejor movimiento (en donde obtengo mayor puntaje)
    5. Elegir la de la esquina superior izquierda (0,0)
    6. Coordenadas aleatorias
    */
    int y, x, conteoJugador, conteoOponente;
    char oponente = oponenteDe(jugador);
    // 1
    coordenadasParaGanar(jugador, tablero, &y, &x);
    if (y != -1 && x != -1)
    {
        hablar("Voy a ganar jajajajaja.", jugador);
        *yDestino = y;
        *xDestino = x;
        return;
    }
    // 2
    coordenadasParaGanar(oponente, tablero, &y, &x);
    if (y != -1 && x != -1)
    {
        hablar("Tomar victoria de oponente", jugador);
        *yDestino = y;
        *xDestino = x;
        return;
    }
    // 3
    coordenadasParaMayorPuntaje(jugador, tablero, &y, &x, &conteoJugador);
    coordenadasParaMayorPuntaje(oponente, tablero, &y, &x, &conteoOponente);
    if (conteoOponente > conteoJugador)
    {
        hablar("Tomaré tu mayor puntaje.", jugador);
        *yDestino = y;
        *xDestino = x;
        return;
    }
    else
    {
        hablar("Tomaré mi mayor puntaje", jugador);
        *yDestino = y;
        *xDestino = x;
        return;
    }
    // 4
    if (coordenadasVacias(0, 0, tablero))
    {
        hablar("Tomar columna superior izquierda", jugador);
        *yDestino = 0;
        *xDestino = 0;
        return;
    }
    // 5
    hablar("Coordenadas aleatorias", jugador);
    obtenerCoordenadasAleatorias(jugador, tablero, yDestino, xDestino);
}

// Devuelve un jugador aleatorio
char jugadorAleatorio()
{
    if (aleatorio_en_rango(0, 1) == 0)
    {
        return JUGADOR_O;
    }
    else
    {
        return JUGADOR_X;
    }
}

// Loop principal del juego
int iniciarJuego(int modo)
{
    if (modo != JUGADOR_CPU)
    {
        printf("Modo de juego no permitido");
        return;
    }

    // Para que salgan cosas aleatorias
    srand(getpid());
    // Iniciar tablero de juego
    char tablero[FILAS][COLUMNAS];
    // Y limpiarlo
    limpiarTablero(tablero);
    // Elegir jugador que inicia al azar
    char jugadorActual = jugadorAleatorio();
    printf("El jugador que inicia es: %c\n", jugadorActual);
    int x, y;
    // Y allá vamos
    while (1)
    {
        imprimirTablero(tablero);
        if(modo == JUGADOR_CPU && jugadorActual == JUGADOR_X)
        {
            printf("Tú (%c). Ingresa coordenadas (x,y) para colocar la pieza separadas por una coma. Por ejemplo: 5,5\n", jugadorActual);
            scanf("%d,%d", &x, &y);
            // Al usuario se le solicitan números comenzando a contar en 1, pero en los arreglos comenzamos desde el 0
            // así que necesitamos restar uno en ambas variables
            x--;
            y--;
        }
        else if (modo == JUGADOR_CPU && jugadorActual == JUGADOR_CPU_O)
        {
            // Si es modo CPU contra CPU o es el turno del CPU, dejamos que las coordenadas las elija
            // el programa
            elegirCoordenadasCpu(jugadorActual, tablero, &y, &x);
        }
        // Sin importar cuál modo haya sido, colocamos la pieza según las coordenadas elegidas
        colocarPieza(y, x, jugadorActual, tablero);
        // Puede que después de colocar la pieza el jugador gane o haya un empate, así que comprobamos
        if (comprobarSiGana(jugadorActual, tablero))
        {
            imprimirTablero(tablero);
            printf("El jugador %c gana\n", jugadorActual);
            if(jugadorActual == 'X'){
                return 1;
            }
            return 0;
        }
        else if (empate(tablero))
        {
            imprimirTablero(tablero);
            printf("Empate");
            return 0;
        }
        // Si no, es turno del otro jugador
        jugadorActual = oponenteDe(jugadorActual);
    }
}

void tresenraya(int *i)
{

    sleep(1);
    int modo,s;
    printf("Juegas contra un secuaz de Bowser ( El secuaz juega como %c).\n ", JUGADOR_CPU_O);
        modo=2;
        *i = iniciarJuego(modo);
    }
