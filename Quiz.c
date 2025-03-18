#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void printList(Node *head) {
    printf("SLL: ");
    while(head != NULL) {
        printf("[%d] -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insertAtHead(Node **headRef, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
    printf("Inserted %d at head.\n", data);
    printList(*headRef);
}

void deleteAtHead(Node **headRef) {
    if(*headRef == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    Node *temp = *headRef;
    int removedData = temp->data;
    *headRef = temp->next;
    free(temp);
    printf("Deleted node with value %d from head.\n", removedData);
    printList(*headRef);
}

int main(void) {
    Node *head = NULL;

    insertAtHead(&head, 40);
    insertAtHead(&head, 50);
    insertAtHead(&head, 60);

    deleteAtHead(&head);
    deleteAtHead(&head);

    while(head != NULL) {
        deleteAtHead(&head);
    }

    return 0;
}
