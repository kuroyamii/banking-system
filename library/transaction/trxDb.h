#ifndef TRXDB_DOT_H
#define TRXDB_DOT_H
#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct{
    int userId, userPin;
    long userSaldo;
    char userName[max];
} Database;

FILE *user, *history;
char db[35]="../database/database_rekening.txt";
char dbHistory[25]="../database/history.txt";

#endif