#ifndef TRXDB_DOT_H
#define TRXDB_DOT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct{
    long userId, userSaldo, userHistory;
    char userName[max+1], userPin[7];
} Database;

FILE *user, *history;
char db[35]="../database/database_rekening.txt";
char dbHistory[25]="../database/history.txt";

#endif