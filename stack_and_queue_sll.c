// Stack and Queue using Singly Linked Lists

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node *link;
} *head = NULL, *temp, *front = NULL, *rear = NULL, *ptr;

int push(int item)
{
 temp = (struct node *)malloc(sizeof(struct node));
 temp -> info = item;
 temp -> link = head;
 head = temp;
 return 0;
}

int pop()
{
 if(head == NULL)
 {
  printf("Underflow");
  return 0;
 }
 int item = head -> info;
 temp = head;
 head = head -> link;
 free(temp);
 printf("Popped element: %d", item);
 return 0;
}

int Sdisplay()
{
 ptr = (struct node *)malloc(sizeof(struct node));
 ptr = head;
 if(ptr == NULL)
 {
  printf("No nodes.");
  return 0;
 }
 else
 {
  while(ptr != NULL)
  {
   printf("%d\t",ptr -> info);
   ptr = ptr -> link;
  }
 }
 return 0;
}

int enque(int item)
{
 temp = (struct node *)malloc(sizeof(struct node));
 temp -> info = item;
 temp -> link = NULL;
 if(front == NULL)
 {
  front = temp;
  rear = temp;
 }
 else
 {
  rear -> link = temp;
  rear = temp;
 }
 return 0;
}

int deque()
{
 if(front == NULL)
 {
  printf("Underflow");
  return 0;
 }
 int item = front -> info;
 temp = front;
 if(front == rear)
 {
  front = NULL;
  rear = NULL;
 }
 else
  front = front -> link;
 free(temp);
 printf("Deleted element: %d", item);
 return 0;
}

int  Qdisplay()
{
 ptr = (struct node *)malloc(sizeof(struct node));
 ptr = front;
 if(ptr == NULL)
 {
  printf("No nodes.");
  return 0;
 }
 else
 {
  while(ptr != NULL)
  {
   printf("%d\t",ptr -> info);
   ptr = ptr -> link;
  }
 }
 return 0;
}

int main()
{
 int opt, choice, item;
 int ch;
 do
 {
  printf("1) Stack\n");
  printf("2) Queue\n");
  printf("\nPick an option: ");
  scanf("%d", &opt);
   switch(opt)
  {
   case 1: do
           {
            printf("1) Push\n");
            printf("2) Pop\n");
            printf("3) Display\n");
            printf("\nPick an option: ");
            scanf("%d", &choice);
            switch(choice)
            {
             case 1: printf("Enter item to insert: ");
                     scanf("%d", &item);
                     push(item);
                     break;
             case 2: pop();
                     break;
             case 3: Sdisplay();
                     break;
             default: printf("Invalid Option");
            }
            printf("\nDo you want to repeat menu? (1/0)\n");
            scanf("%d", &ch);
           }while(ch==1);
           break;
   case 2: do
           { 
            printf("1) Enque\n");
            printf("2) Deque\n");
            printf("3) Display\n");
            printf("\nPick an option: ");
            scanf("%d", &choice);
            switch(choice)
            {
             case 1: printf("Enter item to insert: ");
                     scanf("%d", &item);
                     enque(item);
                     break;
             case 2: deque();
                     break;
             case 3: Qdisplay();
                     break;        
             default: printf("Invalid Option");
            }
            printf("\nDo you want to repeat menu? (1/0)\n");
            scanf("%d", &ch);
            
           }while(ch==1);
           break;
   default: printf("Invalid Option");
  }
  printf("\nDo you want to repeat stack or queue? (1/0)\n");
  scanf("%d", &ch);
 }while(ch==1);
 return 0;
}
