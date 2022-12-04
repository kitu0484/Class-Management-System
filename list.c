#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int serial;
    char name[25];
    char last[25];
    int roll;
    char contact[20];
} Node;

FILE *b = NULL;

int main()
{
    char name_[25];

    printf("*************** CLASS MANAGEMENT SYSTEM ****************");

    printf("\n\n");

    int a;

    printf("1. Enter a new student.");
    printf("\n");
    printf("2. Display All Students.");
    printf("\n");
    printf("3. Search any student.");
    printf("\n");
    printf("4. Exit.");

    printf("\n\n");

    printf("Please choose an option: ");
    scanf("%d", &a);

    printf("\n\n");

    printf("You choose option %d. ", a);

    system("clear");

    printf("\n");

    switch (a)
    {
    case 1:

        b = fopen("class.txt", "a");

        system("clear");

        Node *a = (Node *)malloc(sizeof(Node));

        printf("\n****************************\n");

        printf("\n");

        printf("Enter the name of student: ");
        scanf("%s", a->name);
        printf("\n");
        printf("Enter the last name of student here: ");
        scanf("%s", a->last);
        printf("\n");
        printf("Enter the Roll Number: ");
        scanf("%d", &a->roll);
        printf("\n");
        printf("Enter Contact details here: ");
        scanf("%s", a->contact);
        printf("\n");
        printf("Enter the serial number here: ");
        scanf("%d", &a->serial);

        fwrite(a, sizeof(Node), 1, b);

        fclose(b);

        system("clear");

        printf("\nData has been saved succesfully.\n");
        break;

    case 2:
    
        system("clear");

        printf("\nDisplaying all the information.\n");

        FILE *c = NULL;
        c = fopen("class.txt", "r");

        Node *n = (Node *)malloc(sizeof(Node));

        while (fread(n, sizeof(Node), 1, c))
        {
            printf("\n****************************\n");

            printf("Serial Number\t=\t%d", n->serial);
            printf("\n");
            printf("Name\t\t=\t%s", n->name);
            printf("\n");
            printf("Last Name\t=\t%s", n->last);
            printf("\n");
            printf("Roll Number\t=\t%d", n->roll);
            printf("\n");
            printf("Contact Details\t=\t%s", n->contact);

            printf("\n****************************\n");
        }

        fclose(c);
        break;

    case 3:
        system("clear");
        b = fopen("class.txt", "r");

        int flag = 0;

        Node *z = (Node *)malloc(sizeof(Node));

        printf("\n");

        printf("Enter the name of student here you want to search: ");
        scanf("%s", name_);

        while (fread(z, sizeof(Node), 1, b))
        {
            if (strcmp(z->name, name_) == 0)
            {
                flag = 1;
                printf("\n******************************\n");

                printf("Serial Number\t=\t%d", z->serial);
                printf("\n");
                printf("Name\t\t=\t%s", z->name);
                printf("\n");
                printf("Last name\t=\t%s", z->last);
                printf("\n");
                printf("Roll Number\t=\t%d", z->roll);
                printf("\n");
                printf("Contact Details\t=\t%s", z->contact);

                printf("\n*****************************\n");
            }
        }

        if(flag == 0)
        {
            printf("\nStudent not found.\n");
        }

        break;

    case 4:
        system("clear");

        printf("Thank you.");
        system("exit");

        break;

    default:
        printf("Invalid option: Please choose valid option !! \n");
        break;
    }

    return 0;
}