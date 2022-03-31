/*Zona de declaración de variables*/
alfabeto [a-z]

%{
    char caracter;
%}

%%
{alfabeto} {
            caracter = yytext[0];
            printf("%c", caracter+'A'-'a');
            fprintf(yyout,"%c", caracter+'A'-'a');
            }
%%

/* El puntero se situa en el caracter leído, 
   lo lleva a la sección de mayusculas en 
   el código ascii y resta la parte de las 
   minúsuculas para lograr la conversión */

int main(){
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

