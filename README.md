# T�tulo del trabajo
#**Escapa como puedas**

# Descripci�n del proyecto
En este juego el jugador tendr� que investigar e ir descubriendo secretos con el fin de escapar antes de que se agote el tiempo pues de lo contrario tendr� un mal final.

## Integrantes del equipo

* �ngel Canosa. 
* Juan Ignacio Vi�uales. 
* Fernando Zurera.
* Javier Dur�n. 

## Objetivos del trabajo

- Mediante la programaci�n realizar un juego con buena jugabilidad que permita al jugador _**interactuar**_ con el programa.

- Crear un juego que implemente la mec�nica de generacion aleatoria de m�s o menos objetos que facilitar�n la experiencia de juego dependienco de la _**dificultad**_ seleccionada.

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
    printf("ESCAPA COMO PUEDAS\n Bienvenido al juego, �Qu� deseas hacer?\n");
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