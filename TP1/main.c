#include "scan.h"

int main(void) {
   char bufferDeCadena[256];
   int token = get_token(bufferDeCadena);

   while(token != FDT) {
      if (token == CAD) printf("Cadena: %s\n", bufferDeCadena);
      else if (token == SEP) printf("Separador: ,\n");
      token = get_token(bufferDeCadena);
   }
   printf("--- Fin de Texto ---\n");
   return 0;
}