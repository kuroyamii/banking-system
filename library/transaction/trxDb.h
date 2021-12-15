#ifndef TRXDB_DOT_H
#define TRXDB_DOT_H
#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct{
    int userPin;
    long userId, userSaldo, userHistory;
    char userName[max+1];
} Database;

FILE *user, *history;
char db[35]="../database/database_rekening.txt";
char dbHistory[25]="../database/history.txt";

#endif