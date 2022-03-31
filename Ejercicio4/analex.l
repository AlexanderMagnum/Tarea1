/*Zona de declaración de variables*/
%{
#include <stdlib.h>
unsigned long charCount = 0; /*Contador de caracteres*/
unsigned long wordCount = 0; /*Contador de palabras*/
unsigned long lineCount = 1; /*Contador de lineas de texto*/
%}

word [^ \t\n]+    
eol \n 
/*Toma como palabra aquello que no inicie con un espacio con Spacekey, espacio con Tab ó un salto de línea*/
/* eol identifica el salto de línea como fin de la misma.*/
%%

{word} { wordCount++; charCount += yyleng; } /* Cada que encuentra una palabra aumenta el wordCount en 1
                                                y suma el número de caracteres en charCount*/
{eol} { charCount++; lineCount++; }          /* Cada que encuentra salto de línea aumenta en 1 lineCount */
. charCount++;                               /* Cualquier caracter encontrado aumenta en 1 a charCount*/
%%

int main ( int argc, char **argv) {
  FILE *file = fopen("reporte.txt", "w+");
  if (file == NULL){
    printf("Generando reporte ... %s\n", "reporte.txt");
    exit(1);
  }
  yyout = file;
  yylex ();                                         
  printf ("El archivo contiene:\n-> Líneas    : %lu \n-> Palabras  : %lu \n-> Caracteres: %lu\n", lineCount, wordCount,charCount);
  fprintf (yyout,"El archivo contiene:\n-> Líneas    : %lu \n-> Palabras  : %lu \n-> Caracteres: %lu\n", lineCount, wordCount,charCount);
  fclose(file);
  return 0;
}
