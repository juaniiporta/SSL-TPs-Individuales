#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

enum tokens
{
    FDT,
    SEP,
    CAD,
    IGN
};

int get_token(char vector[]);