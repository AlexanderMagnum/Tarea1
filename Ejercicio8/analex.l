/*Zona de declaración de variables*/
%{
  int contAmor=0;
  int contOdio=0;
  int contPalabras=0;
  int contMayus=0;
  int charCount=0;
%}

mayus [A-Z]([0-9]|[a-zA-Z])*
AMOR AMOR|Amor
amor amor
ODIO ODIO|Odio
odio odio
word [^ \t\n]+
eol \n 

%%

{AMOR} {contAmor++; contPalabras++; contMayus++;}
{amor} {contAmor++; contPalabras++;}
{ODIO} {contOdio++; contPalabras++; contMayus++;}
{odio} {contOdio++; contPalabras++;}
{mayus} {contMayus++;contPalabras++;}
{word} {contPalabras++;}
. charCount++; 
{eol} {charCount++;}

%%

int main(int argc, char*argv[]){
    FILE *file = fopen("reporte.txt", "w+");
    if (file == NULL){
      printf("Generando reporte ... %s\n", "reporte.txt");
      exit(1);
    }
    yyout = file;
    yylex();
    printf("amor: %d\n",contAmor);
    printf("odio: %d\n",contOdio);
    printf("Palabras : %d\n", contPalabras);
    printf("Mayusculas : %d\n", contMayus);
    fprintf(yyout, "amor: %d\n",contAmor);
    fprintf(yyout, "odio: %d\n",contOdio);
    fprintf(yyout, "Palabras : %d\n", contPalabras);
    fprintf(yyout, "Mayusculas : %d\n", contMayus);
    fclose(file);
    return 0;
}