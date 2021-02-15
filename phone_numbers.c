//**********************************************************************
// Written by Steven Smail for COP3514
//
// phone_numbers.c (Project 7)
//
// This program reads the content of a file and translates seven-letter
// words into their corresponding phone numbers, then writes the phone
// numbers to a file with the same name but an added extension of .cvt.
//**********************************************************************

#include <stdio.h>
#include <string.h>
#define NAME_LEN 100
#define WORD_LEN 7

void translate(char *word, char *phone_number);

int main(void)
{
  char file1[NAME_LEN + 1];
  char file2[NAME_LEN + 5];
  char ext[] = ".cvt";
  char str1[WORD_LEN + 1];
  char str2[WORD_LEN + 1];

//Receiving the file name from user
  printf("Enter file name:\n");
  scanf("%s", file1);

//Opening the file to be read
  FILE *pFile;  pFile = fopen(file1, "r");  if (pFile == NULL)  {    printf("File cannot be found\n");    return 1;  }

//Naming the ".cvt" file
  strcpy(file2, file1);
  strcat(file2, ext);

//Opening the file to be written
  FILE *qFile;
  qFile = fopen(file2, "w");

  while (fgets(str1, WORD_LEN, pFile) != NULL)  {
    translate(str1, str2);    fputs(str2, qFile);  }

//Closing file to be written
  fclose(qFile);
//Closing file to be read
  fclose(pFile);

  printf("Output file name: %s\n", file2);

  return 0;
}

void translate(char *word, char *phone_number)
{
  char *p;
  for(p = word; *p != '\0'; p++)
    if(*p == 'A'||*p == 'B'||*p == 'C')
      *phone_number++ = '2';
    else if(*p == 'D'||*p == 'E'||*p == 'F')
      *phone_number++ = '3';
    else if(*p == 'G'||*p == 'H'||*p == 'I')
      *phone_number++ = '4';
    else if(*p == 'J'||*p == 'K'||*p == 'L')
      *phone_number++ = '5';
    else if(*p == 'M'||*p == 'N'||*p == 'O')
      *phone_number++ = '6';
    else if(*p == 'P'||*p == 'R'||*p == 'S')
      *phone_number++ = '7';
    else if(*p == 'T'||*p == 'U'||*p == 'V')
      *phone_number++ = '8';
    else if(*p == 'W'||*p == 'X'||*p == 'Y')
      *phone_number++ = '9';
    else
      *phone_number++ = *p;

  *phone_number = '\0';
}