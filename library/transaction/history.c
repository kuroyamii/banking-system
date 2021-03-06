#include "../transaction/trxDb.h"

struct tnode{
    struct tnode *prev;
    char tipeTrx[11];
    //char lokasi[16];
    int nominal;
    struct tnode *next;
};

struct tnode *head = NULL;
struct tnode *tail = NULL;

int isEmpty(){
    if(tail == NULL) return 1;
    else return 0;
}

void linkedList(char tipe[], int value){
    struct tnode *nodeBaru, *bantu, *temp;
    nodeBaru = (struct tnode*)malloc(sizeof(struct tnode));
    strcpy(nodeBaru->tipeTrx, tipe);
    nodeBaru->nominal = value;
    if(isEmpty()){
        head = nodeBaru;
        tail = head;
        head->next = head;
        head->prev = head;
        tail->next = tail;
        tail->prev = tail;
    }else{
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
        tail->next = head;
        head->prev = tail;
    }
}

void defaultDisplay(int uid){
    struct tnode *bantu;
    bantu = head;
        printf("+---------------------------------------+\n");
        printf("|       (NAMABANK) Banking System       |\n");
        printf("|              ID %08d              |\n", uid);
        printf("|              version xxx              |\n");
        printf("+---------------------------------------+\n");
        do{
            printf("Tipe transaksi: %s\n", bantu->tipeTrx);
            printf("Nominal: %ld\n", bantu->nominal);
            bantu = bantu->next;
        }while(bantu != tail);
}

void ascending(int count, int uid){
    struct tnode asc[count];
    struct tnode *bantu;
    struct tnode temp;
    bantu = head;
    for(int i = 0; i < count; i++){
        strcpy(asc[i].tipeTrx, bantu->tipeTrx);
        asc[i].nominal = bantu->nominal;
        bantu = bantu->next;
    }
    for(int k = 0; k < count - 1; k++){
        bool cek = false;
        for(int l = 0; l < count - k - 1; l++){
            if(asc[l].nominal > asc[l + 1].nominal){
                temp = asc[l];
                asc[l] = asc[l + 1];
                asc[l + 1] = temp;
                cek = true;
            }
        }
        if(cek == false) break;
    }
    printf("+---------------------------------------+\n");
    printf("|       (NAMABANK) Banking System       |\n");
    printf("|              ID %08d              |\n", uid);
    printf("|              version xxx              |\n");
    printf("+---------------------------------------+\n");
    for(int j = 0; j < count; j++){
        printf("Tipe transaksi: %s\n", asc[j].tipeTrx);
        printf("Nominal: %d\n", asc[j].nominal);
    }
}

void descending(int count, int uid){
    struct tnode asc[count];
    struct tnode *bantu;
    struct tnode temp;
    bantu = head;
    for(int i = 0; i < count; i++){
        strcpy(asc[i].tipeTrx, bantu->tipeTrx);
        asc[i].nominal = bantu->nominal;
        bantu = bantu->next;
    }
    for(int k = 0; k < count - 1; k++){
        bool cek = false;
        for(int l = 0; l < count - k - 1; l++){
            if(asc[l].nominal < asc[l + 1].nominal){
                temp = asc[l];
                asc[l] = asc[l + 1];
                asc[l + 1] = temp;
                cek = true;
            }
        }
        if(cek == false) break;
    }
    printf("+---------------------------------------+\n");
    printf("|       (NAMABANK) Banking System       |\n");
    printf("|              ID %08d              |\n", uid);
    printf("|              version xxx              |\n");
    printf("+---------------------------------------+\n");
    for(int j = 0; j < count; j++){
        printf("Tipe transaksi: %s\n", asc[j].tipeTrx);
        printf("Nominal: %d\n", asc[j].nominal);
    }
}

int trxHistory(int uid)
{
    int choice;
    int tempId;
    char tempT[11];
    char tmp[11];
    long int tempV;
    int count = 0;
    history=fopen(dbHistory, "r");
    while(fgets(tmp, 11, history) != NULL){
        if(strcmp(tmp, "*****\n") == 0){
            fscanf(history, "%ld", &tempId);
            if(tempId == uid){
                while(strcmp(fgets(tmp, 11, history), "*****\n") != 0){
                    fscanf(history, "%ld_%[^\n]", &tempV, &tempT);
                    linkedList(tempT, tempV);
                    count++;
                    if(feof(history)){
                        //count--;
                        break;
                    }
                }
                count--;
                break;
            }
        }
    }
    printf("\n1. Nominal Terkecil Ke Terbesar");
    printf("\n2. Nominal Terbesar Ke Terkecil");
    printf("\n3. Default\n4. Kembali");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        if(isEmpty()) printf("Maaf! Belum ada data transaksi\n");
        else ascending(count, uid);
        pause();
        break;
    case 2:
        system("cls");
        if(isEmpty()) printf("Maaf! Belum ada data transaksi\n");
        else descending(count, uid);
        pause();
        break;
    case 3:
        system("cls");
        if(isEmpty()) printf("Maaf! Belum ada data transaksi\n");
        else defaultDisplay(uid);
        pause();
        break;
    case 4:
        return 1;
    default:
        pause();
        trxHistory(uid);
        break;
    }
    fclose(history);
    head = NULL;
    tail = NULL;
}