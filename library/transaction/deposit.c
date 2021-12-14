#include "../transaction/trxDb.h"

int trxDeposit(int uid)
{
    int x=0;
    int choice, amount, sec;
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