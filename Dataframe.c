#include "Dataframe.h"
#include <stdio.h>


CDATAFRAME nouveauCDataframe(MAILLON* premier_col){
    premier_col->successeur=NULL;
    premier_col->column=NULL;
    return premier_col;
}

