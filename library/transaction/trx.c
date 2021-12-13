#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#define max 100

typedef struct{
    int userId, userPin;
    long userSaldo;
    char userName[max];
} Database;

FILE *user, *history;
char db[35]="../database/database_rekening.txt";
char dbHistory[25]="../database/history.txt";
int choice, amount, sec;

void trxDeposit(int uid)
{
    int x=0;
    Database userDb[max];
    user=fopen(db, "r");
    history=fopen(dbHistory, "a");
    printf("\nDeposit Saldo");
    printf("\nLokasi Deposit:");
    printf("\n1. Minimarket\n2. Teller Denpasar");
    printf("\n3. Teller Kuta\n4. Teller Jimbaran");
    printf("\nMasukkan Pilihan: "); scanf("%d", &choice);
    if (choice==1){
        printf("\nMasukkan Jumlah Deposit: "); scanf("%d", &amount);
        printf("\nHarap Periksa Kembali Jumlah Dana\nKemudian Setor Jumlah Dana Yang Sesuai Pada Kasir.");
        pause();

    }
    else if ((choice>1) && (choice<5)){
        printf("\nMasukkan Jumlah Deposit: "); scanf("%d", &amount);
        printf("\nHarap Periksa Kembali Jumlah Dana\nKemudian Setor Jumlah Dana Yang Sesuai Pada Petugas.");
        pause();
    }
    else {
        pauseErr();
    }

    while (!feof(user)){
        fscanf(user,"%d_%[^_]_%ld_%d\n", &userDb[x].userId, &userDb[x].userName, &userDb[x].userSaldo, &userDb[x].userPin);
        fflush(stdin);
        if (uid==userDb[x].userId){
            printf("\nMasukkan PIN: "); scanf("%d", &sec);
            if (sec==userDb[x].userPin){
                userDb[x].userSaldo=userDb[x].userSaldo+amount;
                fflush(stdin);
                fprintf(history,"Deposit_%d_%d\n", userDb[x].userId, amount);
            }
            else {
                printf("\nPIN Salah.");
                pause();
                return menu();
            }
        }
        x++;
    }
    fclose(user);
    fclose(history);
    user=fopen(db, "w");
    fclose(user);
    user=fopen(db, "a");
    for (int i=0; i<x; i++){
        fprintf(user,"%d_%s_%ld_%d\n", userDb[i].userId, userDb[i].userName, userDb[i].userSaldo, userDb[i].userPin);
    }
    fclose(user);
}

void trxWithdraw(int uid)
{
    int x=0;
    Database userDb[max];
    user=fopen(db, "r");
    printf("\nPenarikan Saldo");
    printf("\nLokasi Penarikan:");
    printf("\n1. ATM\n2. Cabang Denpasar");
    printf("\n3. Cabang Kuta\n4. Cabang Jimbaran");
    printf("\nMasukkan Pilihan: "); scanf("%d", &choice);
    if (choice==1){
        printf("\nMasukkan ID Pengguna Pada Mesin."); pause();
        printf("\nMasukkan Jumlah Penarikan: "); scanf("%d", &amount);
        printf("\nHarap Periksa Kembali Jumlah Dana.");
        pause();
    }
    else if ((choice>1) && (choice<5)){
        printf("\nMasukkan Jumlah Penarikan: "); scanf("%d", &amount);
        printf("\nInformasikan ID Pengguna dan Jumlah Penarikan\nPada Petugas, dan Periksa Kembali Jumlah Dana.");
        pause();
    }
    else {
        pauseErr();
    }

    while (!feof(user)){
        fscanf(user,"%d_%[^_]_%ld_%d\n", &userDb[x].userId, &userDb[x].userName, &userDb[x].userSaldo, &userDb[x].userPin);
        fflush(stdin);
        if (uid==userDb[x].userId){
            printf("\nMasukkan PIN: "); scanf("%d", &sec);
            if (sec==userDb[x].userPin){
                userDb[x].userSaldo=userDb[x].userSaldo-amount;
                fflush(stdin);
                fprintf(history, "Penarikan_%d_%d\n", userDb[x].userId, amount);
            }
            else {
                printf("\nPIN Salah.");
                pause();
                return menu();
            }
        }
        x++;
    }
    fclose(user);
    user=fopen(db, "w");
    fclose(user);
    user=fopen(db, "a");
    for (int i=0; i<x; i++){
        fprintf(user,"%d_%s_%ld_%d\n", userDb[i].userId, userDb[i].userName, userDb[i].userSaldo, userDb[i].userPin);
    }
    fclose(user);
}

void trxHistory(int uid)
{
    printf("\n1. Nominal Terkecil Ke Terbesar");
    printf("\n2. Nominal Terbesar Ke Terkecil");
    printf("\n3. Default\n4. Kembali");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        //TBA
        break;
    case 2:
        //TBA
        break;
    case 3:
        //TBA
        break;
    case 4:
        menu();
    default:
        pause();
        trxHistory(uid);
        break;
    }
}