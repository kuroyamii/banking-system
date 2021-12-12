#include <stdio.h>

void history(){
    FILE *filePointer;
    filePointer = fopen("transaction.txt", "r");
    char tmp[51], jenisTrans[51];
    int nominal;

    while(fgets(tmp, 51, filePointer) != NULL){
        if(strcmp(tmp, "*****\n") == 0){
            fgets(tmp, 51, filePointer);
            sscanf(tmp, "%60[^\n]\n", &jenisTrans);
            printf("Jenis Transaksi: %s\n", jenisTrans);
            fscanf(filePointer, "%d", &nominal);
            printf("Nominal: %d\n", nominal);
        }
    }
    fclose(filePointer);
}