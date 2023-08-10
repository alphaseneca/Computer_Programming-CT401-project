#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
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

} data;
void wlecomeScreen();
void insert();
void viewout();
char update();
int main()
{
    wlecomeScreen();
    int choice;

    while (1)
    {
        printf("Enter the choice\n");
        printf("1-Insert a new record into file\n2-print the records\n");
        printf("3-Update the record\n4-Exit\n");
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
    printf("\t\t\t\t\t***** First Semester Project ******\n");
    printf("\t\t\t\t\t*              by                 *\n");
    printf("\t\t\t\t\t*        Ram Krishna Sharma       *\n");
    printf("\t\t\t\t\t*              &                  *\n");
    printf("\t\t\t\t\t*         Ukesh Aryal             *\n");
    printf("\t\t\t\t\t*                                 *\n");
    printf("\t\t\t\t\t*                                 *\n");
    printf("\t\t\t\t\t***********************************\n");
    getch();
    system("cls");
}
void insert()
{

    system("cls");

    FILE *fp1;

    fp1 = fopen("records.txt", "a+");
    printf(" Enter records \n\n");

    printf(" Name : \n");
    scanf(" %[^\n]s", data.name);

    printf(" Date of birth \n");
    scanf(" %[^\n]s", data.dob);
    printf(" Father's name\n");
    scanf(" %[^\n]s", data.father);
    printf(" Mother's name\n");
    scanf(" %[^\n]s", data.mother);
    printf(" Marital status\n");
    scanf(" %[^\n]s", data.mar_status);
    printf(" Address\n");
    scanf(" %[^\n]s", data.address);
    printf(" Religion\n");
    scanf(" %[^\n]s", data.religion);
    printf(" Gender\n");
    scanf(" %[^\n]s", data.gender);
    toupper((unsigned char)*data.mar_status);
    if (strcmp(data.mar_status, "YES") == 1)
    {
        printf("Spouse name\n");
        scanf(" %[^\n]s", data.spouse);
    }
    fprintf(fp1, "record:%s\n", data.name);
    fprintf(fp1, "%s\n", data.name);
    fprintf(fp1, "%s\n", data.dob);
    fprintf(fp1, "%s\n", data.father);
    fprintf(fp1, "%s\n", data.mother);
    fprintf(fp1, "%s\n", data.mar_status);
    fprintf(fp1, "%s\n", data.address);
    fprintf(fp1, "%s\n", data.religion);
    fprintf(fp1, "%s\n", data.gender);
    toupper((unsigned char)*data.mar_status);
    if (strcmp(data.mar_status, "YES") == 1)
    {
        fprintf(fp1, "s", data.spouse);
    }
    fclose(fp1);
    printf("Enter any key to continue.....");
    getch();
    system("cls");
}

void viewout()
{
    system("cls");
    FILE *fp;
    char ch;
    int var = 1;
    char s[20], s1[20];
    fp = fopen("records.txt", "a+");
    if (fp == NULL)
        perror("ERROR: ");
    else
    {
        printf("********* Data of community people **************\n");
        char record[50];
        while (fgets(record, 50, fp) != NULL)

        {
            fgets(data.name, 50, fp);
            fgets(data.dob, 50, fp);
            fgets(data.father, 50, fp);
            fgets(data.mother, 50, fp);
            fgets(data.mar_status, 50, fp);
            fgets(data.address, 50, fp);
            fgets(data.religion, 50, fp);
            char religion[20];
            strcpy(religion, data.religion);

            fgets(data.gender, 50, fp);

            printf("*************** %d************************", var);

            printf("\n\n\n\n Name: %s\n", data.name);
            printf(" Date of birth: %s\n", data.dob);
            printf(" Father's name: %s\n", data.father);
            printf(" Mother's name: %s\n", data.mother);
            printf(" Marital status: %s\n", data.mar_status);
            printf(" Address : %s \n", data.address);
            printf(" Religion: %s \n", religion);
            printf(" Gender: %s\n", data.gender);
            toupper((unsigned char)*data.mar_status);
            if (strcmp(data.mar_status, "YES") == 1)
            {

                fgets(data.spouse, 50, fp);
                printf(" Spouse %s \n\n\n\n\n", data.spouse);
            }
            var++;
        }
    }
    fclose(fp);
    printf(" Enter any key to continue.....");
    getch();
    system("cls");
}

char update()
{

    system("cls");
    FILE *fp1;
    char ch, name[200];
    int id, c;

    fp1 = fopen("records.txt", "r+");
    if (fp1 == NULL)
        perror("ERROR: ");
    else
    {

        printf(" Enter the name to be updated\n");
        scanf(" %[^\n]s", name);

        char record_name[10] = "record:";
        strcat(record_name, name);
        printf("%s", record_name);

        printf("file scan started\n");

        char record[150];

        printf("\n");
        while (fscanf(fp1, "%[^\n]s", record) != EOF)
        {
            printf("Hello\n");
            printf("%s\n", record_name);

            if (strcmp(record, record_name) == 0)
            {
                printf("Enter records: \n\n");

                printf(" Name : \n");
                scanf(" %[^\n]s", data.name);

                printf(" Date of birth\n");
                scanf(" %[^\n]s", data.dob);
                printf(" Father's name\n");
                scanf(" %[^\n]s", data.father);
                printf(" Mother's name\n");
                scanf(" %[^\n]s", data.mother);
                printf(" Marital status\n");
                scanf(" %[^\n]s", data.mar_status);
                printf(" Address\n");
                scanf(" %[^\n]s", data.address);
                printf(" Religion\n");
                scanf(" %[^\n]s", data.religion);
                printf(" Gender\n");
                scanf(" %[^\n]s", data.gender);
                toupper((unsigned char)*data.mar_status);
                if (strcmp(data.mar_status, "YES") == 1)
                {
                    printf(" Spouse name\n");
                    scanf(" %[^\n]s", data.spouse);
                }

                printf("**************************");

                fseek(fp1, 0, SEEK_SET);
                fprintf(fp1, "record:%s\n", data.name);

                fprintf(fp1, "%s\n", data.name);

                fprintf(fp1, "%s\n", data.dob);
                fprintf(fp1, "%s\n", data.father);
                fprintf(fp1, "%s\n", data.mother);

                fprintf(fp1, "%s\n", data.mar_status);
                fprintf(fp1, "%s\n", data.address);
                fprintf(fp1, "%s\n", data.religion);
                fprintf(fp1, "%s\n", data.gender);
                toupper((unsigned char)*data.mar_status);
                if (strcmp(data.mar_status, "YES") == 1)
                {
                    fprintf(fp1, "s", data.spouse);
                }
                c = 1;
                break;
            }
            fread(data.name, 200, 1, fp1);
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
