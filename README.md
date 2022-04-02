# Título del trabajo
#**Escapa como puedas**

# Descripción del proyecto
En este juego el jugador tendrá que investigar e ir descubriendo secretos con el fin de escapar antes de que se agote el tiempo pues de lo contrario tendrá un mal final.

## Integrantes del equipo

* Ángel Canosa. 
* Juan Ignacio Viñuales. 
* Fernando Zurera.
* Javier Durán. 

## Objetivos del trabajo

- Mediante la programación realizar un juego con buena jugabilidad que permita al jugador _**interactuar**_ con el programa.

- Crear un juego que implemente la mecánica de generacion aleatoria de más o menos objetos que facilitarán la experiencia de juego dependienco de la _**dificultad**_ seleccionada.

- Realizar un programa que suponga un _**reto**_ al jugador y que nos permita implementar todos los conocimientos adquiridos en clase.

##Codigo

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale (LC_CTYPE,"spanish");
    int x = 0;
    jump: while(x == 1){
        system("cls");
        x = 0;
    }
    int menu;
    int opciones;
    printf("ESCAPA COMO PUEDAS\n Bienvenido al juego, ¿Qué deseas hacer?\n");
    printf(" [1]JUGAR\n [2]OPCIONES\n [3]SALIR\n");
    scanf("%i", &menu);

    switch(menu){
    case 1:
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