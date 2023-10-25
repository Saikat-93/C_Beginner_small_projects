//THIS PROJECT IS TO COLECT STUDENT INFO,AND SEARCH INFO RECORDS,SEE THE RECORDS AND DELETE THE RECORDS WITH THE HELP OF C PROGRAMING AND FILE HANDELING
#include "stdio.h"
#include "conio.h"
#include <stdlib.h>
void addstudent();
void studentrecord();
void searchstudent();
void delete();

struct student
{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
    char vill[20];
    float per;
};

void main()
{

    int choice;
    while (choice != 5)
    {

        printf("\t\t\t=====STUDENT INFO MANAGEMENT SYSTEM=====");
        printf("\n\n\n\t\t\t\t     1. Add Student\n");
        printf("\t\t\t\t     2. Students Records\n");
        printf("\t\t\t\t     3. Search Student\n");
        printf("\t\t\t\t     4. Delete Student\n");
        printf("\t\t\t\t     5. Exit\n");
        printf("\t\t\t\t    _____________________\n");
        printf("\t\t\t\t     ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            addstudent();
           system("cls");
            break;
        case 2:
           system("cls");

            studentrecord();
            printf("\t\t\t\t  press any key to exit this panel..... \n");
            getch();
           system("cls");

            break;

        case 3:
           system("cls");
            searchstudent();
            printf("\n\t\t\t\t  Press any key to exit this panel.......\n");

            getch();
         system("cls");

            break;

        case 4:
            system("cls");
            delete ();
            printf("\n\t\t\t\tPress any key to exit this panel.......\n");
            getch();
            system("cls");
            break;
        case 5:
            system("cls");
            printf("\n\t\t\t\tTHANK YOU,AND MOST WELCOME .\n\n");
            exit(0);
            break;

        default:
           system("cls");
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue your work.......");
            getch();
           system("cls");
            break;
        }
    }

    getch();
}

void addstudent()
{

    char another;
    FILE *fp;
    int n, i;
    struct student info;
    do
    {
      system("cls");
        printf("\t\t\t\t=======Add Students Info=======\n\n\n");
        fp = fopen("information.txt", "a");

        printf("\n\t\t\tEnter First Name of the candidate    : ");
        scanf("%s", &info.first_name);
        printf("\n\t\t\tEnter Last Name of the candidate    : ");
        scanf("%s", &info.last_name);
        printf("\n\t\t\tEnter Roll-No       : ");
        scanf("%d", &info.roll_no);
        printf("\n\t\t\tEnter Class(course) : ");
        scanf("%s", &info.Class);
        printf("\n\t\t\tEnter Address       : ");
        scanf("%s", &info.vill);
        printf("\n\t\t\tEnter Percentage    : ");
        scanf("%f", &info.per);
        printf("\n\t\t\t______________________________\n");

        if (fp == NULL)
        {
            fprintf(stderr, "can't open file");
        }
        else
        {
            printf("\t\t\tRecord stored successfuly\n");
        }

        fwrite(&info, sizeof(struct student), 1, fp);
        fclose(fp);

        printf("\t\t\tYou want to add another record?(y/n) : ");

        scanf("%s", &another);

    } while (another == 'y' || another == 'Y');
}

void studentrecord()
{

    FILE *fp;

    struct student info;
    fp = fopen("information.txt", "r");

    printf("\t\t\t\t=======STUDENTS RECORD=======\n\n\n");

    if (fp == NULL)
    {

        fprintf(stderr, "can't open file\n");
        exit(0);
    }
    else
    {
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }

    while (fread(&info, sizeof(struct student), 1, fp))
    {
        printf("\n\t\t\t\t Student Name  : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\t Roll NO       : %d", info.roll_no);
        printf("\n\t\t\t\t Class         : %s", info.Class);
        printf("\n\t\t\t\t Village/City  : %s", info.vill);
        printf("\n\t\t\t\t Percentage    : %f", info.per);
        printf("\n\t\t\t\t ________________________________\n");
    }
    fclose(fp);
    getch();
}

void searchstudent()
{
    struct student info;
    FILE *fp;
    int roll_no, found = 0;

    fp = fopen("information.txt", "r");
    printf("\t\t\t\t=======SEARCH STUDENTS RECORD=======\n\n\n");
    printf("\t\t\tEnter the roll no : ");

    scanf("%d", &roll_no);

    while (fread(&info, sizeof(struct student), 1, fp) > 0)
    {

        if (info.roll_no == roll_no)
        {

            found = 1;
            printf("\n\n\t\t\tStudent Name : %s %s", info.first_name, info.last_name);
            printf("\n\t\t\tRoll NO        : %d", info.roll_no);
            printf("\n\t\t\tClass          : %s", info.Class);
            printf("\n\t\t\tAddress        : %s", info.vill);
            printf("\n\t\t\tPercentage     : %f%", info.per);
            printf("\n\t\t\t______________________________________\n");
        }
    }

    if (!found)
    {
        printf("\n\t\t\tRecord not found\n");
    }

    fclose(fp);
    getch();
}

void delete()
{
    struct student info;
    FILE *fp, *fp1;

    int roll_no, found = 0;

    printf("\t\t\t\t=======DELETE STUDENTS RECORD=======\n\n\n");
    fp = fopen("information.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("\t\t\t\tEnter the roll no : ");
    scanf("%d", &roll_no);
    if (fp == NULL)
    {
        fprintf(stderr, "can't open file\n");
        exit(0);
    }

    while (fread(&info, sizeof(struct student), 1, fp))
    {
        if (info.roll_no == roll_no)
        {

            found = 1;
        }
        else
        {
            fwrite(&info, sizeof(struct student), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if (!found)
    {
        printf("\n\t\t\t\tRecord not found\n");
    }
    if (found)
    {
        remove("information.txt");
        rename("temp.txt", "information.txt");

        printf("\n\t\t\t\tRecord deleted succesfully\n");
    }

    getch();
}
