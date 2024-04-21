#include <stdlib.h>
#include <stdio.h>
#include "Dataframe.h"

int main() {

    COLUMN *mycolumn = create_column("mycolumn");


    insert_value(mycolumn, 10);
    insert_value(mycolumn, 15);
    insert_value(mycolumn, 20);
    insert_value(mycolumn, 25);
    insert_value(mycolumn, 30);
    print_column(mycolumn);

    return 0;
}
