#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* removeDuplicates(struct node *head)
{
    struct node *temp = head, *prev = NULL, *next;

    while(temp != NULL) {
        if(temp->next != NULL && temp->data == temp->next->data){
            int value = temp->data;

            while(temp != NULL && temp->data == value) {
                next = temp->next;
                free(temp);
                temp = next;
            }

            if(prev == NULL)
                head = temp;
            else
                prev->next = temp;
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
