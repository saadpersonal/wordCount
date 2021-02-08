//By: Saad Khan
//Program to sort an input string
#include "wordSort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



void wordSort(char* str) {
        int wordCount = 0;
	int i, j, k = 0;
	for (i = 0; i < strlen(str)+1; i++) {
          //if((str[i] == ' ') || (str[i] == ',') || (str[i] == '.')) {
	  if( (isspace(str[i])) || (str[i] == ',') || (str[i] == '.') || (str[i] == '\0') || (str[i] == '\n')) {	  
		wordCount++;
	   }
	}
	
	for(i = 0; i < strlen(str); i++) {
	   if(isupper(str[i])) {
	      str[i] = tolower(str[i]);
	   }
	}
	
	//char sortString[100];
	for (i = 0, j = 0; i<strlen(str); i++, j++) {
	    if(ispunct(str[j])) {
		str[i] = str[j+1];
		j++;
	    }
	    else {
              str[i] = str[j];
	    }
	}
	//printf("The string w/o punct or upper:\n%s\n", str);
	//printf("%lu\n", strlen(str));
	//printf("%d\n", wordCount);
	
	
	char split[wordCount][100];
	for (i = 0, j = 0, k = 0; k < strlen(str)+1; k++ )  {
	   if( (str[k] == ' ') || (str[k] == '\0') || (str[k] == '\n')) {
		split[i][j] = '\0';
		i++;
		j = 0;
	   }
	   else {
	     split[i][j++] = str[k];
	   }
	}
	
	
	//printf("The array of array is:\n");
	//for (i = 0; i < wordCount; i++) {
	//   printf("%s ", split[i]);
	//}
	//printf("\n");

	//sort
	char temp[100];
	for(i = 0; i < wordCount; i++) {
	   for (j = i + 1; j < wordCount; j++) {
	      if((strcmp(split[i], split[j]) > 0)) {
		 strcpy(temp, split[i]);
		 strcpy(split[i], split[j]);
		 strcpy(split[j], temp);
	      }
	   }
	}

	//printf("The sorted array of array is:\n");
	//for (i = 0; i < wordCount; i++) {
	//   printf("%s ", split[i]);
	//}	
	//printf("\n");

	char output[100];
	for (i = 0; i < wordCount; i++) {
	   strcat(output, split[i]);
	   if (i != wordCount-1) {
	      strcat(output, " ");
	   }
	}
	//printf("The sorted string pre-copy is:\n%s\n", output);
	
	for(i = 0; i < strlen(str)+1; i++) {
	   str[i] = output[i];
	}
}
