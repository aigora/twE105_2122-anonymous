#include <stdio.h>
#include <locale.h>

int main(){
setlocale (LC_CTYPE,"spanish");
int x = 0;
jump: while(x == 1){ system("cls"); x = 0; }
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
return 0; }
