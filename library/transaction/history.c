#include "../transaction/trxDb.h"

int trxHistory(int uid)
{
    int choice;
    history=fopen(dbHistory, "a");
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
        return 1;
    default:
        pause();
        trxHistory(uid);
        break;
    }
    fclose(history);
}