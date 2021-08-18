#include <stdio.h>
#include <ctype.h>
#include "scan.h"

enum tokens { FDT, SEP, CAD, SPA };

int get_token() {
    char caracter;
    const char* tokenString[3] = {"Fin de Texto: ", "Separador: ", "Cadena: "};

    puts("Escriba un texto de entrada:");

    while(1) {
        caracter=getchar();
        int tokenType;
        int lastTokenType;

        if(!isspace(caracter)){
            ungetc( caracter, stdin );
            caracter = getchar();

            switch (caracter) {
                case EOF:
                    tokenType = FDT;
                    break;
                case ',':
                    tokenType = SEP;
                    break;
                default:
                    tokenType = CAD;
                break;
            }
            
            if (tokenType != CAD && lastTokenType == CAD) printf("\n");
            if (tokenType == CAD) {
                if (lastTokenType == CAD) {
                    printf( "%c", caracter);
                } else {
                    printf( "%s%c", tokenString[tokenType], caracter);
                }
            } else if(tokenType == SEP) {
                printf( "%s%c\n", tokenString[tokenType], caracter);
            } else if (tokenType == FDT) {
                printf( "%s%c\n", tokenString[tokenType], caracter);
                return 0;
            }
            lastTokenType = tokenType;
        } else {
            if (lastTokenType == CAD){
                printf("\n");
            }
            lastTokenType = SPA;
        }
        
    }

    return 0;
}
