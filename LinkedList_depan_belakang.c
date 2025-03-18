#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi gagal");
        exit(1);
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi gagal");
        exit(1);
    }

    newNode->data = data;

    if (head == NULL) { 
        return newNode;
    }

    
    newNode->next = NULL;

    struct Node *current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
   
    return head;
}

struct Node* deleteNodeBeginning(struct Node *head) {
    if (head == NULL) {
        printf("List kosong");
        return NULL;
    }    

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;

}

struct Node* deleteNodeAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List kosong");
        return NULL;
    }

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *current = head;
    while(current->next->next != NULL) {
        current = current->next;
    } 
    free(current->next);
    current->next = NULL;
    return head;   

    
}

int main() {
    struct Node *head = NULL;
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 40);
    head = insertAtEnd(head, 50);
    head = deleteNodeBeginning(head);
    head = deleteNodeAtEnd(head);
 
    printf("isi dari linked list: ");

    struct Node *current = head;
    
    while(current != NULL) {
        printf(" %d ->", current->data);
        current = current->next;
    }
    printf(" NULL");
}