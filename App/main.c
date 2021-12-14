#include <stdio.h>
#include <stdlib.h>
#include "../library/utils/utils.h"
#include "../library/auth/auth.h"
#include "../library/transaction/trx.h"

int choice;
int id;
void header();
void menu();

//Main Driver To Run The Program
int main()
{   
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
            //signin();
            break;
        case 2:
            clear();
            printf("(NAMABANK) Banking System\n\n");
            printf("Apakah Anda Ingin Membuat Rekening?");
            printf("\n1. Ya\n2. Tidak\n3. Keluar\n\nMasukkan Pilihan: ");
            scanf("%d", &choice);
            if (choice==1){
                //signup();
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
    // printf("\n\nSelect Action: ");
    // scanf("%d", &choice);
    // switch (choice)
    // {
    // case 1:
    //     //login();
    //     break;
    // case 2:
    //     //signup();
    //     break;
    // case 3:
    //     goto end;
    //     break;
    // default:
    //     pauseErr();
    //     goto main;
    //     break;
    // }

end:
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