#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//estados del AFD
typedef enum {
    S_0=0,
    S_1=1,
    S_2=2,
    S_3=3,
    S_4=4
}Estado;

int esEstadoAceptado(Estado estado){
    if (estado == S_2 || estado == S_3) return 1;
    else return 0;
}

int main(int argc, char *argv[]){
    int entrada;
    Estado estado = S_0;
    printf("Ingresa tu cadena, para iniciar analisis pulsa ENTER \n");
    printf("Para salir del sistema pulsa Ctrl+D \n");
    printf("--> ");
    int i = 0;
    while(1) {
        entrada = getchar();
        if (entrada == EOF){
            if (esEstadoAceptado(estado)) printf ("\n SI es cadena aceptada\n");
            if (!esEstadoAceptado(estado)) printf("\n No es cadena NO aceptada\n");
            break;
        }
        if (entrada == '\n'){
            if (esEstadoAceptado(estado)) printf ("\n Si es cadena aceptada\n");
            if (!esEstadoAceptado(estado)) printf("\n No es cadena NO aceptada\n");
            estado = S_0;
            entrada = getchar();
            //printf("ESTADO S_%d\n",estado);
        }
        printf("%c", entrada);
        switch(estado) {
            case S_0:

                if (entrada >= '0' && entrada <= '9'){
                    estado = S_4;
                }else if (islower(entrada)){
                    estado = S_3; 
                }else if (entrada == '_'){
                    estado = S_1;
                }
                printf(" ESTADO :: %d\n", estado);
                //printf("S_0: siguente Estado S_%d \n",estado);
                break;
            
            case S_1:
                if (isalnum(entrada)){
                    estado = S_3;
                }else if (entrada == '_'){
                    estado = S_4;  
                } 
                printf(" ESTADO :: %d\n", estado);
                //printf("S_1: siguente  Estado S_%d \n",estado);
                break;

            case S_2:
                if (isalnum(entrada)) estado = S_3;
                printf(" ESTADO :: %d\n", estado);
                //printf("S__2: siguente Estado S_%d \n",estado);
                break;
            case S_3:
                if (isalnum(entrada)){
                    estado = S_3;
                }else if (entrada == '_'){
                    estado = S_2;
                }
                printf(" ESTADO :: %d\n", estado);
            case S_4:
                if (entrada == '\n') estado = S_0;
                printf(" ESTADO :: %d\n", estado);
                //printf("D: siguente Estado S_%d \n",estado);
                break;
        }
    }
}