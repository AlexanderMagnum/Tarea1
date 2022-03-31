#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//estados del AFD
typedef enum {
    S_0=0,
    S_1=1,
    S_2=2,
    S_3=3,
    S_4=4,
    S_5=5,
    S_6=6,
}Estado;

int esOtro(int entrada){
    //printf("esOtro: %c: %d\n",entrada,(entrada != '/' && entrada != '*' && entrada != '\n'));
    return entrada != '/' && entrada != '*' && entrada != '\n';
}

int esAsterisco(int entrada){
    //printf("esAsterisco: %d\n",entrada == '*');
   return entrada == '*';
}

int esDiagonal(int entrada){
    //printf("esDiagonal: %d\n",entrada == '/');
    return entrada == '/';
}

int esSaltoLinea(int entrada){
    //printf("esSaltoLinea: %d\n",entrada == '\n');
    return entrada == '\n';
}

int esEstadoLimbo(Estado estado){
    if (estado == S_6) return 1;
    else return 0;
}

int esEstadoAceptado(Estado estado){
    if (estado == S_5 || estado == S_4) return 1;
    else return 0;
}


int main(int argc, char *argv[]){
    int entrada;
    Estado estado = S_0;
    printf("Ingresa tu cadena, para iniciar analisis pulsa ENTER \n");
    printf("Para salir del sistema pulsa Ctrl+D \n");
    printf("--> ");
    entrada = getchar();
    int i = 0;
    while(1) {
        if (entrada == EOF){
            break;
        }
        if (entrada == '\n' && estado != S_2){
            if (esEstadoAceptado(estado)) printf ("\nSI ES UN COMENTARIO DE C\n");
            if (!esEstadoAceptado(estado)) printf("\nNO ES UN COMENTARIO DE C\n");
            estado = S_0;
            entrada = getchar();
        }
        //printf("%c",entrada);
        switch(estado) {
            case S_0:
                if (esOtro(entrada)) estado = S_6;
                if (esSaltoLinea(entrada)) estado = S_0;
                if (esAsterisco(entrada)) estado = S_6;
                if (esDiagonal(entrada)) estado = S_1;
                //printf("S_0: siguente Estado S_%d \n",estado);
                break;
            
            case S_1:
                if (esOtro(entrada)) estado = S_1;
                if (esSaltoLinea(entrada)) estado = S_6;
                if (esAsterisco(entrada)) estado = S_2;
                if (esDiagonal(entrada)) estado = S_5;
                //printf("S_1: siguente  Estado S_%d \n",estado);
                break;

            case S_2:
                if (esOtro(entrada)) estado = S_2;
                if (esSaltoLinea(entrada)) estado = S_2;
                if (esAsterisco(entrada)) estado = S_3;
                if (esDiagonal(entrada)) estado = S_2;
               //printf("S__2: siguente Estado S_%d \n",estado);
                break;

            case S_3:
                if (esOtro(entrada)) estado = S_2;
                if (esSaltoLinea(entrada)) estado = S_2;
                if (esAsterisco(entrada)) estado = S_3;
                if (esDiagonal(entrada)) estado = S_4;
                //printf("S_3: siguente Estado S_%d \n",estado);
                break;

            case S_4:
                if (esOtro(entrada)) estado = S_4;
                if (isalnum(entrada)) estado = S_6;
                if (esSaltoLinea(entrada)) estado = S_4;
                if (esAsterisco(entrada)) estado = S_6;
                if (esDiagonal(entrada)) estado = S_6;
                //printf("S_4: siguente Estado S_%d \n",estado);
                break;

            case S_5:
                if (esOtro(entrada)) estado = S_5;
                if (esSaltoLinea(entrada)) estado = S_6;
                if (esAsterisco(entrada)) estado = S_5;
                if (esDiagonal(entrada)) estado = S_5;
                //printf("S_5: siguente Estado S_%d \n",estado);
                break;

            case S_6:
                if (esOtro(entrada)) estado = S_6;
                if (esSaltoLinea(entrada)) estado = S_6;
                if (esAsterisco(entrada)) estado = S_6;
                if (esDiagonal(entrada)) estado = S_6;
                //printf("S_6: siguente Estado S_%d \n",estado);
                break;
        }
        entrada = getchar();   
    }
    
}