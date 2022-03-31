#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//estados del AFD
typedef enum {
    S_0=0,
    S_1=1,
    S_2=2,
}Estado;

int esEstadoAceptado(Estado estado){
    if (estado == S_1) return 1;
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
        printf("%c", entrada);
        if (entrada == EOF){
            break;
        }
        if (entrada == '\n'){
            if (esEstadoAceptado(estado)) printf ("\n Es un numero aceptado\n");
            if (!esEstadoAceptado(estado)) printf("\n No es un numero aceptado\n");
            estado = S_0;
            entrada = getchar();
            
            //printf("ESTADO S_%d\n",estado);
        }
        switch(estado) {
            case S_0:
                if (entrada >= 48 && entrada <= 57){
                    estado = S_1;   
                }else{
                    estado = S_2;
                }
                //printf("S_0: siguente Estado S_%d \n",estado);
                break;
            case S_1:
                if (entrada >= 48 && entrada <= 57){
                    estado = S_1;
                } else{
                    estado = S_2;
                }
                //printf("S_1: siguente  Estado S_%d \n",estado);
                break;

            case S_2:
                entrada = S_2;
                //printf("S__2: siguente Estado S_%d \n",estado);
                break;

            default:
                if (entrada == '\n') estado = S_0;
                else estado = S_0;
                //printf("D: siguente Estado S_%d \n",estado);
                break;

        }
         
    }
    
}