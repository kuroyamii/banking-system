#include "../transaction/trxDb.h"

int trxDeposit(long uid)
{
    int x=0, y=0, z=0;
    char tmp[101], sec[7];
    int choice, amount;
    Database userDb[max];
    user=fopen(db, "r");
    history=fopen(dbHistory, "r+");
    printf("\nDeposit Saldo\n");
    printf("\nLokasi Deposit:\n");
    printf("\n1. Minimarket\n2. Teller Denpasar");
    printf("\n3. Teller Kuta\n4. Teller Jimbaran");
    printf("\n\nMasukkan Pilihan: "); scanf("%d", &choice);
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
        fscanf(user,"%ld_%[^_]_%ld_%s\n", &userDb[x].userId, &userDb[x].userName, &userDb[x].userSaldo, &userDb[x].userPin);
        fflush(stdin);
        if (uid==userDb[x].userId){
            printf("\nMasukkan PIN: "); scanf("%s", &sec);
            if (strcmp(sec, userDb[x].userPin)==0){
                userDb[x].userSaldo=userDb[x].userSaldo+amount;
                fflush(stdin);
                while (fgets(tmp, 101, history)!=NULL){
                    fscanf(history,"%ld", &userDb[y].userHistory);
                    fflush(stdin);
                    if (userDb[y].userHistory==userDb[x].userId){
                        fprintf(history,"%d_Deposit\n", amount);
                        z=1;
                    }
                    y++;
                }
                if (z==0)
                fprintf(history,"*****\n%ld\n%d_Deposit\n", userDb[x].userId, amount);
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
        fprintf(user,"%ld_%s_%ld_%s\n", userDb[i].userId, userDb[i].userName, userDb[i].userSaldo, userDb[i].userPin);
    }
    fclose(user);
}