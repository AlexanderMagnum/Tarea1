Para ejecutar el programa será ncesario ejecutar las siguentes líneas de comando:

lex CifradoCesar.l
gcc lex.yy.c -ll
./a.out  < texto.txt

NOTA: Es importante mencionar que si se mueve de fichero el archivo CifradoCesar.l, deberá crear un nuevo archivo txt