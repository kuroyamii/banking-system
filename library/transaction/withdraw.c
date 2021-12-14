#include "../transaction/trxDb.h"

int trxWithdraw(int uid)
{
    int x=0;
    int choice, amount, sec;
    Database userDb[max];
    user=fopen(db, "r");
    history=fopen(dbHistory, "a");
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
                return 1;
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
