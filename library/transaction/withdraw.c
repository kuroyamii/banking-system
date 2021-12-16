#include "../transaction/trxDb.h"

int trxWithdraw(long uid)
{
    int x=0, y=0, z=0;
    char tmp[101], sec[7];
    int choice, amount;
    long int tempId;
    Database userDb[max];
    user=fopen(db, "r");
    history=fopen(dbHistory, "r+");
    printf("\nPenarikan Saldo\n");
    printf("\nLokasi Penarikan:\n");
    printf("\n1. ATM\n2. Cabang Denpasar");
    printf("\n3. Cabang Kuta\n4. Cabang Jimbaran");
    printf("\n\nMasukkan Pilihan: "); scanf("%d", &choice);
    if (choice==1){
        printf("\nMasukkan ID Pengguna Pada Mesin."); pause();
    }
    else if ((choice>1) && (choice<5)){
        printf("\nInformasikan ID Pengguna dan\nJumlah Penarikan Pada Petugas");
        pause();
    }
    else {
        pauseErr();
    }

    while (!feof(user)){
        fscanf(user,"%ld_%[^_]_%ld_%s\n", &userDb[x].userId, &userDb[x].userName, &userDb[x].userSaldo, &userDb[x].userPin);
        fflush(stdin);
        FILE *fpCopy;
        if (uid==userDb[x].userId){
            printf("\nMasukkan Jumlah Penarikan: "); scanf("%d", &amount);
            if (amount<=userDb[x].userSaldo){
                printf("\nHarap Periksa Kembali Jumlah Dana.");
                pause();
                printf("\nMasukkan PIN: "); scanf("%s", &sec);
                    if (strcmp(sec, userDb[x].userPin)==0){
                    userDb[x].userSaldo=userDb[x].userSaldo-amount;
                    fflush(stdin);
                    while (fgets(tmp, 101, history)!=NULL){
                        fscanf(history,"%ld", &userDb[y].userHistory);
                        fflush(stdin);
                        if (userDb[y].userHistory==userDb[x].userId){
                            fprintf(history,"%ld_Penarikan\n", amount);
                            z=1;
                            fpCopy = fopen("../database/copycat.txt", "a");
                            fseek(history, 0, SEEK_SET);
                            int c = 0;
                            while(fgets(tmp, 101, history) != NULL){
                                fputs(tmp, fpCopy);
                                if(strcmp(tmp, "*****\n") == 0){
                                    fscanf(history, "%ld", &tempId);
                                    if(tempId == userDb[y].userHistory){
                                        fprintf(fpCopy, "%ld\n%ld_Penarikan", tempId, amount);
                                    }
                                    else{
                                        fprintf(fpCopy, "%ld", tempId);
                                    }
                                }
                            }
                        }
                        y++;
                    }
                    if(z == 1){
                        fclose(fpCopy);
                        fclose(history);
                        history = fopen(dbHistory, "w+");
                        fpCopy = fopen("../database/copycat.txt", "r");
                        fseek(fpCopy, 0, SEEK_SET);
                        while(fgets(tmp, 101, fpCopy) != NULL){
                            fputs(tmp, history);
                        }
                        fclose(fopen("../database/copycat.txt", "w"));
                    }
                    if (z==0){
                        fprintf(history,"*****\n%ld\n%d_Penarikan\n", userDb[x].userId, amount);
                    }
                }
                else {
                    printf("\nPIN Salah.");
                    pause();
                    return 1;
                    }
            }
            else {
                printf("\nSaldo Tidak Mencukupi.");
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
