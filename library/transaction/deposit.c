#include <stdio.h>

void deposit(){
    FILE *filePointer;
    filePointer = fopen("transaction.txt", "a");
    int withdrawValue;
    printf("Nominal masuk: ");
    scanf("%d", &withdrawValue);
    fflush(stdin);
    fprintf(filePointer, "*****\nDEPOSIT\n%d\n", withdrawValue);
    fclose(filePointer);
}