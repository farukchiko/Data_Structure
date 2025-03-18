#include <stdio.h>
#include <string.h>

struct Mahasiswa{
        char nama[50];
        int umur;
        float ipk;
    };
int main(){
    struct Mahasiswa mhs[3]; //mhs itu bebbas, bisa diganti dengan nama lain

    strcpy(mhs[0].nama, "Budi"); 
    mhs[0].umur = 20;
    mhs[0].ipk = 3.5;

    strcpy(mhs[1].nama, "Andi");
    mhs[1].umur = 21;
    mhs[1].ipk = 3.6;

    strcpy(mhs[2].nama, "Caca");
    mhs[2].umur = 22;
    mhs[2].ipk = 3.7;

    printf("Data Mahasiswa\n");
    printf("==============\n");

    for (int i = 0; i < 3; i++){
        printf("Nama: %s, Umur: %d, IPK: %.2f\n", mhs[i].nama, mhs[i].umur, mhs[i].ipk);
    }
    
    return 0;
}