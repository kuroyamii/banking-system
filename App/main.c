#include <stdio.h>
#include <stdlib.h>
#include "../library/utils/utils.h"
#include "../library/auth/auth.h"
#include "../library/transaction/trx.h"

long users,u_id;
int choice;
int id;
void header();
void menu();

void userCount(){
    FILE *fptr;
    char *ptr;
    char temp[20];
    fptr = fopen("../database/userCount.txt","r");
    fgets(temp,20,fptr);
    sscanf(temp,"%[^\n]\n",&temp);
    fflush(stdin);
    users = strtol(temp,&ptr,20);
    //users = atol(temp);
    fclose(fptr);
}

void userCountWrite(){
    FILE *fptr;
    char temp[20];
    fptr = fopen("../database/userCount.txt","w");
    fprintf(fptr,"%ld\n",users);
    fclose(fptr);
}


//Main Driver To Run The Program
int main()
{  
    userCount();

main:
    do
    {
        clear();
        printf("(NAMABANK) Banking System\n\n");
        printf("Apakah Anda Sudah Memiliki Rekening? ");
        printf("\n1. Sudah\n2. Belum\n\nMasukkan Pilihan: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Menu:\n1. Sign in\n2. Sign up\n3. Keluar\nPilih: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                {
                    if(signin(&u_id) == true){
                        printf("%ld",u_id);
                        printf("berhasil masuk!\n");
                        menu();
                    }else{
                        printf("Gagal");   
                    }
                    break;
                }
                case 2:
                    signup();
                    break;
                case 3:
                    goto end;
                    break;
            }
            break;
        }
        case 2:
            clear();
            printf("(NAMABANK) Banking System\n\n");
            printf("Apakah Anda Ingin Membuat Rekening?");
            printf("\n1. Ya\n2. Tidak\n3. Keluar\n\nMasukkan Pilihan: ");
            scanf("%d", &choice);
            if (choice==1){
                users = users + addRekening(users);
            }
            else if (choice==2){
                goto main;
            }
            else if (choice==3){
                goto end;
            }
            break;
        default:
            break;
        }
    } while (choice < 1 || choice > 2);
end:
    userCountWrite();
    return 0;
}

/*
Procedure to print out the title of the app
*/
void header()
{
    //clear();
    printf("-----------------------------------------\n");
    printf("|       (NAMABANK) Banking System       |\n");
    printf("|              ID %-8d              |\n", id);
    printf("|            version xxx                |\n");
    printf("-----------------------------------------\n");
}

void menu()
{
    header();
    printf("\n1. Tarik Tunai\n2. Setor Tunai\n3. Riwayat Transaksi\n4. Logout");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        header();
        trxWithdraw(id);
        if (trxWithdraw)
        menu();
        break;
    case 2:
        header();
        trxDeposit(id);
        if (trxDeposit)
        menu();
        break;
    case 3:
        header();
        trxHistory(id);
        if (trxHistory)
        menu();
        break;
    case 4:
        header();
        printf("\nTekan ENTER untuk Logout.");
        fflush(stdin);
        getchar();
        //TBA
        break;
    default:
        header();
        pauseErr();
        menu();
        break;
    }
}