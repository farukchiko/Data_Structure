#include <stdio.h>

int main() {
    // Deklarasikan array bilangan bulat
    int numbers[5];
    
    // Inisialisasikan elemen-elemen array
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    // Akses dan cetak elemen-elemen array
    printf("Elemen-elemen array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}