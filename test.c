#include <stdio.h>
#include "wordSort.h"

int main() {
   printf("Enter a string to sort:\n");
   char stringToSort[100];
   scanf("%[^\n]%*c", stringToSort);
   //char* sortedString = wordSort(stringToSort);
   wordSort(stringToSort);
   printf("The sorted string is:\n%s\n", stringToSort);

   return 0;
}
