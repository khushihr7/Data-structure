#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void deleteFromFirst(struct Node** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}
void deleteFromEnd(struct Node** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}
void deleteAtPosition(struct Node** head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 0)
    {
        deleteFromFirst(head);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
void insertEnd(struct Node** head, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}
void display(struct Node* head)
{
    struct Node* temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
int main()
{
    struct Node* head = NULL;
    int n, value, choice, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    while (1)
    {
        printf("\n1. Delete from Front");
        printf("\n2. Delete from End");
        printf("\n3. Delete at Specified Position");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                deleteFromFirst(&head);
                break;

            case 2:
                deleteFromEnd(&head);
                break;

            case 3:
                printf("Enter position to delete (starting from 0): ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 4:
                display(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
