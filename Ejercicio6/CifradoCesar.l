/*Zona de declaracion de variables*/
%{
char swap; /* Variable que guarda el puntero del caracter*/
unsigned int N = 7; /* Valor de N para el cifrado */
%}
minusculas [a-z]
mayusculas [A-Z]

/* minusculas es el alfabeto en minusculas*/
/* mayusculas es el alfabeto en mayusculas*/
%%
{minusculas} {

        swap = yytext[0];
        swap = swap + N;
        if (swap >= 'z'){
            swap = swap - ('z' + 1 - 'a');
        }
        printf("%c", swap);
        fprintf(yyout,"%c", swap);
       }
       /*Swap guarda el puntero al caracter leido*/
       /*Se realiza el movimiento de + N lugares*/
       /*Si swap se sale del rango toma un nuevo valor*/
       /*Swap se le resta el resultado de la suma del límite
         final + 1 menos el límite inicial para calcular la
         nueva posición*/
{mayusculas} {
        swap = yytext[0];
        swap = swap + N;
        if (swap > 'Z'){
            swap = swap - ('Z' + 1 - 'A');
        }
        printf("%c", swap);
        fprintf(yyout,"%c", swap);
}
       /*Swap guarda el puntero al caracter leido*/
       /*Se realiza el movimiento de + N lugares*/
       /*Si swap se sale del rango toma un nuevo valor*/
       /*Swap se le resta el resultado de la suma del límite
         final + 1 menos el límite inicial para calcular la
         nueva posición*/

%%

int main(int argc, char *argv[]) {
    FILE *file = fopen("reporte.txt", "w+");
    if (file == NULL){
        printf("Generando reporte ... %s\n", "reporte.txt");
        exit(1);
    }
    yyout = file;
    yylex();
    fclose(file);
    return 0;
}