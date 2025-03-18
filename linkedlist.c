#include <stdio.h>
#include <stdlib.h>

// Definisi struktur untuk Node dalam linked list
struct Node {
    int data;           // Menyimpan data integer
    struct Node* next;  // Menyimpan pointer ke node berikutnya
};

// Fungsi untuk menyisipkan elemen pada awal linked list
struct Node* InsertAtBeginning(struct Node *head, int data) {
    // Alokasi memori untuk node baru
    struct Node* newMode = (struct Node*)malloc(sizeof(struct Node));

    // Mengecek apakah alokasi memori berhasil
    if(newMode == NULL) {
        printf("Memory Error");  // Jika gagal, tampilkan pesan error
        return head;
    }

    // Menetapkan data untuk node baru
    newMode->data = data;

    // Menghubungkan node baru dengan node pertama
    newMode->next = head;

    // Menetapkan node baru sebagai head yang baru
    head = newMode; 
    return head;
}

// Fungsi untuk menyisipkan elemen pada akhir linked list
struct Node* InsertAtEnd(struct Node *head, int data) {
    // Alokasi memori untuk node baru
    struct Node *newMode = (struct Node*)malloc(sizeof(struct Node));

    // Mengecek apakah alokasi memori berhasil
    if(newMode == NULL) {
        printf("Memory Error");  // Jika gagal, tampilkan pesan error
        return NULL;
    }

    // Menetapkan data untuk node baru
    newMode->data = data;

    // Node baru harus menjadi node terakhir, jadi next-nya NULL
    newMode->next = NULL;

    // Mencari node terakhir dalam linked list
    struct Node *ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    // Menyambungkan node terakhir dengan node baru
    ptr->next = newMode;

    return head;
}

// Fungsi untuk menghapus node pertama (head) dari linked list
struct Node *DeleteAtBeginning(struct Node *head) {
    // Mengecek apakah linked list kosong
    if(head == NULL) {
        printf("List is empty");  // Jika kosong, tampilkan pesan error
        return NULL;
    }

    // Menyimpan pointer ke node pertama yang akan dihapus
    struct Node *ptr = head;

    // Memindahkan head ke node berikutnya
    head = head->next;

    // Menghapus node pertama
    free(ptr);

    return head;
}

int main() {
    // Inisialisasi linked list kosong
    struct Node* head = NULL;

    // Menyisipkan elemen 10 pada awal linked list
    head = InsertAtBeginning(head, 10);

    // Menyisipkan elemen 5 pada awal linked list
    head = InsertAtBeginning(head, 5);

    // Menyisipkan elemen 15 pada akhir linked list
    head = InsertAtEnd(head, 15);

    // Menghapus elemen pertama (head) dari linked list
    head = DeleteAtBeginning(head);

    // Menampilkan isi dari linked list
    printf("Hasil dari linked list adalah: ");

    struct Node* mainPtr = head;
    // Menampilkan semua elemen dalam linked list
    while(mainPtr != NULL) {
        printf("%d -> ", mainPtr->data);
        mainPtr = mainPtr->next;
    }

    // Menampilkan NULL setelah elemen terakhir
    printf("NULL\n");

    return 0;
}
