#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("\n[ERROR] Stack Overflow! Cannot push %d. The stack is full.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("\nSuccess: %d pushed onto the stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("\n[ERROR] Stack Underflow! Cannot pop. The stack is empty.\n");
    } else {
        printf("\nSuccess: Popped element is %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("\nThe stack is currently empty.\n");
    } else {
        printf("\nCurrent Stack Elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nSTACK OPERATIONS");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
