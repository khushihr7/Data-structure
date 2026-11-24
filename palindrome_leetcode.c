#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

bool isPalindrome(struct node* head) {

    struct node *mid = head, *last = head;
    struct node *prev = NULL, *next, *temp;
    while(last != NULL && last->next != NULL){
        mid = mid->next;
        last = last->next->next;
    }

    temp = mid;
    while(temp != NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    struct node *p1 = head, *p2 = prev;
    while(p2 != NULL){
        if(p1->data != p2->data)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}
