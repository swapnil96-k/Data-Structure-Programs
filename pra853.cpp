#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int prn;
    struct Node* next;
};

struct Node* head = NULL;  // Start of the linked list

// Function to add PRN at the end
void addPRN() {
    int prn;
    printf("Enter PRN of new admitted student: ");
    scanf("%d", &prn);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->prn = prn;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("PRN %d added successfully.\n", prn);
}

// Function to delete PRN
void deletePRN() {
    if(head == NULL) {
        printf("List is empty. No PRN to delete.\n");
        return;
    }

    int prn;
    printf("Enter PRN of admission cancelled student: ");
    scanf("%d", &prn);

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If the head node needs to be deleted
    if(temp != NULL && temp->prn == prn) {
        head = temp->next;
        free(temp);
        printf("PRN %d deleted successfully.\n", prn);
        return;
    }

    // Search for the PRN to be deleted
    while(temp != NULL && temp->prn != prn) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("PRN %d not found in the list.\n", prn);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("PRN %d deleted successfully.\n", prn);
}

// Function to display the linked list
void displayList() {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("PRNs of students in the list:\n");
    while(temp != NULL) {
        printf("%d -> ", temp->prn);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n*** Student PRN Linked List ***\n");
        printf("1. Add PRN of new student\n");
        printf("2. Delete PRN of cancelled admission\n");
        printf("3. Display PRN list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addPRN(); break;
            case 2: deletePRN(); break;
            case 3: displayList(); break;
            case 4: 
                printf("Exiting program.\n");
                system("pause");
                exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
