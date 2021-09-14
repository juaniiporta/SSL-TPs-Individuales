#include "scan.h"

int get_token(char vector[])
{
    int i = 0;
    char caracter = getchar();

    if(isspace(caracter)) return IGN;
    else if (caracter == EOF) return FDT;
    else if (caracter == ',') return SEP;
    else {
        while(caracter != EOF && caracter != ','){
            if (!isspace(caracter)) {
                    vector[i] = caracter;
                    i++;
            }
            caracter = getchar();
        }
        ungetc(caracter, stdin);
        vector[i] = '\0';
    }
    return CAD;
}