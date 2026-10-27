
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;

void insert()
{
  int val;
  if ((front==rear+1)||(front==0 && rear==MAX-1))
  {
   printf("queue is full");
   return;
  }
  printf("enter element to be added:");
  scanf("%d",&val);
  if(front==-1 && rear==-1)
   {
     front=0;
   }
  if(rear==MAX-1 && front!=0)
   {
     rear=0;
   }
  else
   {
     rear++;
   }
  queue[rear]=val;
  printf("%d added to queue",val);
}

void delete()
{
   if(front==-1)
    {
     printf("queue is empty");
     return;
    }
   printf("%d deleted from queue",queue[front]);
   if(front==rear)
    {
     front=rear=-1;
    }
  else
   {
     if(front==MAX-1)
       {
         front=0;
       }
     else
       {
         front++;
       }
   }
}

void display()
{
   int i;

   if(front == -1)
     {
       printf("Queue is empty\n");
       return;
     }

   printf("Queue elements are: ");

   for(i = front; ; i = (i + 1) % MAX)
     {
       printf("%d ", queue[i]);

       if(i == rear)
          {
            break;
          }
     }

   printf("\n");
}

int main()
{
int choice;

while (1)
    {
  printf("\nQUEUE OPERATIONS \n");
  printf("1. Insert\n");
  printf("2. Delete\n");
  printf("3. Display\n");
  printf("4. Exit\n");

  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice)
    {
      case 1:
      insert();
      break;
      case 2:
      delete();
      break;
      case 3:
      display();
      break;
      case 4:
      return 0;
      default:
      printf("invalid choice\n");
   }
 }
}
