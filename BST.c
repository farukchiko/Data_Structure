#include <stdio.h>
#include <stdlib.h>

// Struktur Node untuk BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Fungsi untuk membuat Node baru
void newNode(struct Node** ptr, int data) {
    *ptr = (struct Node*)malloc(sizeof(struct Node));
    if (*ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    (*ptr)->data = data;
    (*ptr)->left = NULL;
    (*ptr)->right = NULL;
}

// Fungsi untuk menyisipkan elemen ke dalam BST
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        newNode(root, data);
    } else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    } else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        printf("Data %d sudah ada dalam tree\n", data);
    }
}

void delete(struct Node** root, int data) {
    if (*root == NULL) {
        printf("Data %d tidak ditemukan di dalam tree.\n", data);
        return;
    } else if (data > (*root)->data) {
        delete(&((*root)->right), data);
    } else if (data < (*root)->data) {
        delete(&((*root)->left), data);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            struct Node* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            struct Node* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            struct Node* temp = (*root)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->data = temp->data;
            delete(&((*root)->right), temp->data);
        }
    }
}

struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return findMin(root->left);
    }
}

// Fungsi inorder traversal (menampilkan data secara terurut)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d | ", root->data);
        inorder(root->right);
    }
}

// Fungsi untuk membebaskan memori tree (agar tidak terjadi memory leak)
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int input, data;

    do {
        system("clear"); // Mengganti "cls" dengan "clear" agar kompatibel dengan Mac/Linux
        printf("Menu BST (INSERT)\n");
        printf("1. View inorder\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Input >> ");
        scanf("%d", &input);
        getchar(); // Menangani newline setelah input

        switch (input) {
            case 1:
                system("clear");
                printf("Data view In-Order Traversal: \n");
                inorder(root);
                printf("\n");
                printf("Tekan Enter untuk melanjutkan...\n");
                getchar();
                break;

            case 2:
                printf("Input data: ");
                scanf("%d", &data);
                getchar(); // Menangani newline setelah input
                insert(&root, data);
                printf("Data berhasil dimasukkan!\n");
                printf("Tekan Enter untuk melanjutkan...\n");
                getchar();
                break;

            case 3:
                printf("Input data yang ingin dihapus: ");
                scanf("%d", &data);
                getchar(); // Menangani newline setelah input
                delete(&root, data);
                printf("Data berhasil dihapus!\n");
                printf("Tekan Enter untuk melanjutkan...\n");
                getchar();
                break;

            case 4:
                printf("Keluar...\n");
                break;

            default:
                printf("Pilihan tidak valid! Tekan Enter untuk kembali...\n");
                getchar();
                break;
        }
    } while (input != 3);

    // Bebaskan memori sebelum keluar
    freeTree(root);

    return 0;
}
