#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int data;
    struct listNode* nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode* ListNodePtr;

ListNodePtr createNode(int data) {
    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->nextPtr = NULL;
    return newNode;
}

void insertAtBeginning(ListNodePtr* head, int data) {
    ListNodePtr newNode = createNode(data);
    newNode->nextPtr = *head;
    *head = newNode;
}

void insertAtEnd(ListNodePtr* head, int data) {
    ListNodePtr newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    ListNodePtr lastNode = *head;
    while (lastNode->nextPtr != NULL) {
        lastNode = lastNode->nextPtr;
    }
    lastNode->nextPtr = newNode;
}

void insertAtPosition(ListNodePtr* head, int data, int position) {
    if (position <= 0) {
        insertAtBeginning(head, data);
        return;
    }
    ListNodePtr newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    ListNodePtr currentNode = *head;
    int i = 1;
    while (currentNode != NULL && i < position) {
        currentNode = currentNode->nextPtr;
        i++;
    }
    if (currentNode == NULL) {
        insertAtEnd(head, data);
        return;
    }
    newNode->nextPtr = currentNode->nextPtr;
    currentNode->nextPtr = newNode;
}

void deleteNode(ListNodePtr* head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        ListNodePtr temp = *head;
        *head = (*head)->nextPtr;
        free(temp);
        return;
    }
    ListNodePtr currentNode = *head;
    while (currentNode->nextPtr != NULL && currentNode->nextPtr->data != data) {
        currentNode = currentNode->nextPtr;
    }
    if (currentNode->nextPtr == NULL) {
        return;
    }
    ListNodePtr temp = currentNode->nextPtr;
    currentNode->nextPtr = temp->nextPtr;
    free(temp);
}

void reverseList(ListNodePtr* head) {
    if (*head == NULL || (*head)->nextPtr == NULL) {
        return;
    }
    ListNodePtr prevNode = NULL;
    ListNodePtr currentNode = *head;
    ListNodePtr nextNode;
    while (currentNode != NULL) {
        nextNode = currentNode->nextPtr;
        currentNode->nextPtr = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    *head = prevNode;
}

void printList(ListNodePtr head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->nextPtr;
    }
    printf("\n");
}

int main() {
    //  Create a new empty linked list.
    ListNodePtr head = NULL;

    // Insert the integers 2, 3, 5, 7 and 11 in this order, starting from the beginning of the linked list. Print.
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 11);
    printf("Linked List after step 2: ");
    printList(head);

    // Insert the integer 13 at the end of the linked list. Print.
    insertAtEnd(&head, 13);
    printf("Linked List after step 3: ");
    printList(head);

    // Insert the integer 17 at the 3rd position (from the beginning) in the linked list. Print.
    insertAtPosition(&head, 17, 3);
    printf("Linked List after step 4: ");
    printList(head);

    // Insert the integer 19 at the beginning of the linked list. Print.
    insertAtBeginning(&head, 19);
    printf("Linked List after step 5: ");
    printList(head);

    // Delete the integer 3 from the linked list. Print.
    deleteNode(&head, 3);
    printf("Linked List after step 6: ");
    printList(head);

    // Reverse the order of the nodes in the linked list. Print.
    reverseList(&head);
    printf("Linked List after step 7: ");
    printList(head);

    // Print out the contents of the final linked list. Print.
    printf("Linked List at final    : ");
    printList(head);

    return 0;
}

