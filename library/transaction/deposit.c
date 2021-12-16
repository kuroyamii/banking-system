#include "../transaction/trxDb.h"

int trxDeposit(long uid)
{
    int x=0, y=0, z=0;
    char tmp[101], sec[7];
    char tmp2[101];
    long int tempId;
    int choice;
    long int amount;
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
        fscanf(user,"%ld_%50[^_]_%ld_%50[^\n]s\n", &userDb[x].userId, &userDb[x].userName, &userDb[x].userSaldo, &userDb[x].userPin);
        fflush(stdin);
        FILE *fpCopy;
        if (uid==userDb[x].userId){
            printf("\nMasukkan PIN: ");
            scanf("%[^\n]s", &sec);
            fflush(stdin);
            if (strcmp(sec, userDb[x].userPin) == 0){
                userDb[x].userSaldo = userDb[x].userSaldo+amount;
                fflush(stdin);
                while (fgets(tmp, 101, history)!=NULL){
                    fscanf(history,"%ld\n", &userDb[y].userHistory);
                    fflush(stdin);
                    if (userDb[y].userHistory==userDb[x].userId){
                        fprintf(history,"%ld_Deposit\n", amount);
                        z=1;
                        fpCopy = fopen("../database/copycat.txt", "a");
                        fseek(history, 0, SEEK_SET);
                        int c = 0;
                        while(fgets(tmp, 101, history) != NULL){
                            fputs(tmp, fpCopy);
                            if(strcmp(tmp, "*****\n") == 0){
                                fscanf(history, "%ld", &tempId);
                                if(tempId == userDb[y].userHistory){
                                    fprintf(fpCopy, "%ld\n%ld_Deposit", tempId, amount);
                                }
                                else{
                                    fprintf(fpCopy, "%ld", tempId);
                                }
                            }
                        }
                    }
                    y++;
                }
                fclose(fpCopy);
                fclose(history);
                history = fopen(dbHistory, "w+");
                fpCopy = fopen("../database/copycat.txt", "r");
                fseek(fpCopy, 0, SEEK_SET);
                while(fgets(tmp, 101, fpCopy) != NULL){
                    fputs(tmp, history);
                }
                fclose(fopen("../database/copycat.txt", "w"));
                if (z==0){
                    fprintf(history,"*****\n%ld\n%d_Deposit\n", userDb[x].userId, amount);
                }
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
    return 0;
}