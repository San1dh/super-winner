// Singly Linked List operations like Insertion at a postion, Deletion of an element & Display of all elements

#include<stdio.h>
#include<stdlib.h>

struct node
{
 int info;
 struct node *link;
} *head = NULL, *temp, *ptr, *prev;


int ins_pos(item, pos)
{
 temp = (struct node *)malloc(sizeof(struct node));
 temp -> info = item;
 temp -> link = NULL;
 if(pos < 0 )
 {
  printf("Invalid postion. Enter position again: ");
  scanf("%d", &pos);
 }
 if(pos == 1)
 {
  temp -> link = head;
  head = temp;
  return 1;
 }
 else
 {
  int c = 2;
  ptr = head -> link;
  prev = head;
  while(c < pos)
  {
   if(ptr == NULL)
   {
    return 0;
   }
   c++;
   prev = ptr;
   ptr = ptr -> link;
  }
  temp -> link = ptr;
  prev -> link = temp;
  return 1;
 }
}

int delete(item)
{
 if(head == NULL)
 {
  printf("No elements present to delete.");
  return 2;
 }
 if(head -> link == NULL)
 {
  if(item == head -> info)
  {
   temp = head;
   head = head -> link;
   return 1;
  }
  else
  {
   return 0;
  }
 }
  
 if(item == head -> info)
 {
  temp = head;
  head = head -> link;
  return 1;
 }
 else
 {
  ptr = head -> link;
  prev = head;
  while(item != ptr -> info)
  {
   prev = ptr;
   ptr = ptr -> link;
   if(ptr == NULL)
   {
    return 0;
   }
  }
  temp = ptr;
  prev -> link = ptr -> link;
  return 1;
 }
}

int display()
{
 ptr = head;
 if(ptr == NULL)
 { 
  printf("No elements present.");
  return 0;
 }
 while(ptr != NULL)
 {
  printf("%d\t", ptr -> info);
  ptr = ptr -> link;
 }
 return 0;
}

int main()
{
 int ch, option, item, pos, flag;
 do
 {
  printf("\n1) Insert at certain postion\n");
  printf("2) Delete a certain element\n");
  printf("3) Display elements\n");
  printf("\nEnter your option: ");
   scanf("%d", &option);
  switch(option)
  {
   case 1: printf("Enter element & postion to be inserted: ");
            scanf("%d", &item);
            scanf("%d", &pos);
           flag = ins_pos(item, pos);
           if(flag == 0)
            printf("Position not present.");
           else
            printf("Element successfully inserted.");
           break;
   case 2: printf("Enter element to be deleted: ");
            scanf("%d", &item);
           flag = delete(item);
           if(flag == 0)
            printf("\nElement not present.");
           if(flag == 1)
            free(temp);
            printf("Element successfully deleted.");
           break;
   case 3: display();
           break;
   default: printf("Invalid option.");
  }
  printf("\nDo you want to repeat menu? (1/0)\n");
   scanf("%d", &ch);
 }while(ch == 1);
 return 0;
}
