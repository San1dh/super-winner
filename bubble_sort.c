#include <stdio.h>

int main(void) {
  int a[10];
  printf("input 5 numbers\n");
  for(int i=0; i<5; i++)
    scanf("%d", &a[i]);
  int temp;
  for(int i=0; i<4; i++)
   for(int j=0; j<4-i; j++)
     if(a[j] > a[j+1])
     {
       temp = a[j];
       a[j] = a[j+1];
       a[j+1] = temp;
     }
  for(int i=0; i<5; i++)
    printf("%d\t", a[i]);
  printf("\n");
  return 0;
}
