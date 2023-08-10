#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

#define DefaultUsername "admin"
#define DefaultPassword "admin"
#define MaxCharSize 40

void gotoxy(short x, short y)
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

using namespace std;
enum status
{
  error,
  warning,
  notice
};

struct community
{
  char name[20];
  char dob[20];
  char mar_status[20];
  char father[20];
  char mother[20];
  char gender[5];
  char religion[10];
  char address[20];
  char spouse[20];

} database;
int dataSize = sizeof(database);
void wlecomeScreen();
void insert();
void viewout();
char update();
void loginScreen();
bool isStringValid(HANDLE h, char *address);
void suggestion(char *name);
void printMessage(HANDLE h, enum status currentStatus, char *message)
{
  switch (currentStatus)
  {
  case error:
  {
    SetConsoleTextAttribute(h, 4);
    break;
  }
  case warning:
  {
    SetConsoleTextAttribute(h, 14);
    break;
  }
  case notice:
  {
    SetConsoleTextAttribute(h, 1);
    break;
  }
  default:
    SetConsoleTextAttribute(h, 11);
  }
  printf("%s", message);
  SetConsoleTextAttribute(h, 11);
}

int main()
{
  wlecomeScreen();
  loginScreen();
  int choice;
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  while (1)
  {
    printf("\n\n\n\n\n\n\n");
    SetConsoleTextAttribute(h, 4);

    printf("\t\t\t\t\t            Enter the choice    \n");
    SetConsoleTextAttribute(h, 15);
    printf("\t\t\t\t\t            *****************\n\n\n");
    SetConsoleTextAttribute(h, 11);
    printf("\t\t\t\t\t   1-Insert a new record into file  \n\n");
    printf("\t\t\t\t\t   2-print the records              \n\n");
    printf("\t\t\t\t\t   3-Update the records             \n\n");
    printf("\t\t\t\t\t   4-Exit                           \n\n");
    SetConsoleTextAttribute(h, 15);
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      insert();
      break;
    case 2:
      viewout();
      break;
    case 3:
    {
      update();
      break;
    }
    case 4:
      exit(1);
    default:
      printf("Enter the correct choice\n");
    }
  }
}

void wlecomeScreen()
{
  printf("\n\n\n\n\n\n");

  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(h, 11);
  printf("\t\t\t\t\t***********************************\n");
  SetConsoleTextAttribute(h, 12);
  printf("\t\t\t\t\t      1st semester project by           \n\n");
  SetConsoleTextAttribute(h, 9);
  printf("\t\t\t\t\t         Ram Krishna Sharma          \n");
  SetConsoleTextAttribute(h, 14);
  printf("\t\t\t\t\t                &                    \n");
  SetConsoleTextAttribute(h, 6);
  printf("\t\t\t\t\t           Ukesh Aryal              \n");
  printf("\t\t\t\t\t                                  \n");
  printf("\t\t\t\t\t                                  \n");
  SetConsoleTextAttribute(h, 11);
  printf("\t\t\t\t\t**********************************\n");
  SetConsoleTextAttribute(h, 15);
  getch();
  system("cls");
}
bool isCharactervalid(HANDLE h, char *address)
{
  bool valid = false;
  for (int i = 0; i < strlen(address); i++)
  {
    int s = (int)address[i];
    if ((48 <= s && 57 >= s) || s == 45 || s == 47)
    {
      valid = true;
    }
    else
    {
      valid = false;
      break;
    }
  }
  char errorMessage[90] = "ALERT:entered character should contain numerical character!!!!\n";
  if (!valid)
  {
    printf("\n\t\t\t\t\t\t");
    printMessage(h, error, errorMessage);
  }
  return valid;
}
bool isStringValid(HANDLE h, char *address)
{
  bool valid = false;
  for (int i = 0; i < strlen(address); i++)
  {
    int s = (int)address[i];
    if ((97 <= s && 122 >= s) || (65 <= s && 90 >= s) || s == 44 || s == 32)
    {
      valid = true;
    }
    else
    {
      valid = false;
      break;
    }
  }
  char errorMessage[80] = "ALERT:entered string should contain alphanumeric character only!!!!\n";
  if (!valid)
  {
    printf("\n\t\t\t\t\t\t");
    printMessage(h, error, errorMessage);
  }
  return valid;
}

void insert()
{

  system("cls");
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  FILE *fp1;
  SetConsoleTextAttribute(h, 2);
  fp1 = fopen("records.txt", "a+");
  if (fp1 == NULL)
  {
    printf("file opening error");
  }
  else
  {

    printf("\t\t\t\t\t\t\t      Enter records \n");
    SetConsoleTextAttribute(h, 15);
    printf("\t\t\t\t\t\t\t       ************* \n\n");

    fflush(stdin);
    do
    {
      SetConsoleTextAttribute(h, 14);
      printf("\t\t\t\t\t\t             Name : ");
      SetConsoleTextAttribute(h, 11);
      scanf("%[^\n]%*c", database.name);
    } while (!isStringValid(h, database.name));
    do
    {
      SetConsoleTextAttribute(h, 14);
      printf("\t\t\t\t\t\t     Date of birth: ");
      SetConsoleTextAttribute(h, 11);
      scanf("%[^\n]%*c", database.dob);
    } while (!isCharactervalid(h, database.dob));
    do
    {
      SetConsoleTextAttribute(h, 14);
      printf("\t\t\t\t\t\t     Father's name: ");
      SetConsoleTextAttribute(h, 11);
      scanf("%[^\n]%*c", database.father);
    } while (!isStringValid(h, database.father));
    do
    {
      SetConsoleTextAttribute(h, 14);
      printf("\t\t\t\t\t\t     Mother's name: ");
      SetConsoleTextAttribute(h, 11);
      scanf("%[^\n]%*c", database.mother);
    } while (!isStringValid(h, database.mother));
    do
    {
      SetConsoleTextAttribute(h, 14);
      printf("\t\t\t\t\t\t    Marital status: ");
      SetConsoleTextAttribute(h, 11);
      scanf("%[^\n]%*c", database.mar_status);
    } while (!isStringValid(h, database.mar_status));
    do
    {
      SetConsoleTextAttribute(h, 14);
      printf("\t\t\t\t\t\t           Address: ");
      SetConsoleTextAttribute(h, 11);
      scanf("%[^\n]%*c", database.address);
    } while (!isStringValid(h, database.address));
    do
    {
      SetConsoleTextAttribute(h, 14);
      printf("\t\t\t\t\t\t          Religion: ");
      SetConsoleTextAttribute(h, 11);
      scanf("%[^\n]%*c", database.religion);
    } while (!isStringValid(h, database.religion));
    do
    {
      SetConsoleTextAttribute(h, 14);
      printf("\t\t\t\t\t\t           Gender: ");
      SetConsoleTextAttribute(h, 11);
      scanf("%[^\n]%*c", database.gender);
    } while (!isStringValid(h, database.gender));
    SetConsoleTextAttribute(h, 15);
    fwrite(&database, dataSize, 1, fp1);

    fclose(fp1);
    printf("Enter any key to continue.....");
    getch();

    system("cls");
  }
}

void viewout()
{
  system("cls");
  FILE *fp;
  char ch;
  int
      var = 1;
  char s[20], s1[20];
  fp = fopen("records.txt", "a+");
  if (fp == NULL)
    perror("ERROR: ");
  else
  {
    printf("********* Data of community people **************\n");
    while (fread(&database, dataSize, 1, fp) == 1)
    {
      HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(h, 11);
      printf("*************** %d************************",
             var);
      SetConsoleTextAttribute(h, 14);
      printf("\n\n\n\n Name: %s\n", database.name);
      printf(" Date of birth: %s\n", database.dob);
      printf(" Father's name: %s\n", database.father);
      printf(" Mother's name: %s\n", database.mother);
      printf(" Marital status: %s\n", database.mar_status);
      printf(" Address : %s \n", database.address);
      printf(" Religion: %s \n", database.religion);
      printf(" Gender: %s\n", database.gender);
      var++;
      SetConsoleTextAttribute(h, 14);
    }
  }
  fclose(fp);
  printf(" Enter any key to continue.....");
  getch();
  system("cls");
}

char update()
{
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  system("cls");
  FILE *fp1;
  char ch, name[20] = "";
  int id, c;

  fp1 = fopen("records.txt", "r+");
  if (fp1 == NULL)
    perror("ERROR: ");
  else
  {

    SetConsoleTextAttribute(h, 11);
    printf("\t\t\t\t Enter the name to be updated\n");
    SetConsoleTextAttribute(h, 14);
    char s[20] = "";
    gotoxy(1, 2);

    // character to string
    while (1)
    {

      char character = getch();

      int xpos = strlen(s) + 1;
      gotoxy(xpos, 2);
      printf("%c", character);

      system("cls");
      SetConsoleTextAttribute(h, 11);
      printf("\t\t\t\t Enter the name to be updated\n");
      SetConsoleTextAttribute(h, 14);

      if (character == 8)
      {
        int pos = strlen(name);
        name[pos - 1] = 0;
        strcpy(s, name);
        gotoxy(2, 25);
        printf("suggestions:");
        suggestion(s);
        gotoxy(1, 2);
        printf("%s", s);
      }

      if (character != 13 && character != 8)
      {

        int pos = strlen(name);
        name[pos] = character;

        strcpy(s, name);
        gotoxy(2, 25);
        printf("suggestions:");
        suggestion(s);
        gotoxy(1, 2);
        printf("%s", s);
      }
      else if (character == 13)
      {
        break;
      }
    }

    rewind(fp1);
    while (fread(&database, dataSize, 1, fp1) == 1)
    {
      //      printf("%s: %s\t",s,data.name);

      if (strcmp(database.name, s) == 0)
      {

        printf("Enter records: \n\n");
        do
        {

          printf(" Name : \n");
          scanf(" %[^\n]s", database.name);
        } while (!isStringValid(h, database.name));
        do
        {

          printf(" Date of birth\n");
          scanf(" %[^\n]s", database.dob);
        } while (!isCharactervalid(h, database.dob));
        do
        {

          printf(" Father's name\n");
          scanf(" %[^\n]s", database.father);
        } while (!isStringValid(h, database.father));
        do
        {

          printf(" Mother's name\n");
          scanf(" %[^\n]s", database.mother);
        } while (!isStringValid(h, database.mother));
        do
        {

          printf(" Marital status\n");
          scanf(" %[^\n]s", database.mar_status);
        } while (!isStringValid(h, database.mar_status));
        do
        {

          printf(" Address\n");
          scanf(" %[^\n]s", database.address);
        } while (!isStringValid(h, database.address));
        do
        {

          printf(" Religion\n");
          scanf(" %[^\n]s", database.religion);
        } while (!isStringValid(h, database.religion));
        do
        {

          printf(" Gender\n");
          scanf(" %[^\n]s", database.gender);
        } while (!isStringValid(h, database.gender));
        printf("**************************");
        fseek(fp1, -dataSize, SEEK_CUR);
        fwrite(&database, dataSize, 1, fp1);
        c = 1;
        break;
      }
    }
  }
  if (c == 1)
    printf(" Update of the record succesfully\n");
  else
    printf(" Update unsuccesful enter correct name\n");
  fclose(fp1);
  printf(" Enter any key to continue.....");
  getch();
  system("cls");
}

void loginScreen()
{
  printf("\n\n\n\n\n\n");

  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(h, 11);
  printf("\t\t\t\t\t***********************************\n");
  SetConsoleTextAttribute(h, 12);
  printf("\t\t\t\t\t    1st semester project by           \n\n");
  SetConsoleTextAttribute(h, 9);
  printf("\t\t\t\t\t      Ram Krishna Sharma          \n");
  SetConsoleTextAttribute(h, 14);
  printf("\t\t\t\t\t             &                    \n");
  SetConsoleTextAttribute(h, 6);
  printf("\t\t\t\t\t         Ukesh Aryal              \n");
  printf("\t\t\t\t\t                                  \n");
  printf("\t\t\t\t\t                                  \n");
  SetConsoleTextAttribute(h, 11);
  printf("\t\t\t\t\t**********************************\n");
  SetConsoleTextAttribute(h, 15);
  getch();
  system("cls");
}

void suggestion(char *name)
{
  FILE *fp;
  fp = fopen("records.txt", "r");
  if (fp == NULL)
  {
    printf("file opening error");
  }
  else
  {

    while (fread(&database, dataSize, 1, fp) == 1)
    {
      int noc = strlen(name);
      if (strncmp(database.name, name, noc) == 0)
        printf("%s      ", database.name);
    }
  }
  fclose(fp);
}
