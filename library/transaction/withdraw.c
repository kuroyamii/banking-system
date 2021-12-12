#include <stdio.h>

void withdrw(){
    FILE *filePointer;
    int nomWthDrw;
    filePointer = fopen("../database/transaction.txt", "a+");
    printf("Nominal pengambilan: ");
    scanf("%d", &nomWthDrw);
    fflush(stdin);
    fprintf(filePointer, "*****\nWITHDRAW\n%d\n", nomWthDrw);
    fclose(filePointer);
}