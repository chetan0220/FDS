/*
phone number data type is taken int for simplicity
    CONTACT BOOK

    DONE ==> 
    insertion
    searching (by name and contact number)
    display

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int number;
    char name[20];
    struct node *next;
} *head = NULL;
void display()
{
    printf("\nConatct List ==> \n");
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%s : %d\n", temp->name, temp->number);
        temp = temp->next;
    }
}
void insert()
{
    struct node *newNode, *temp;
    temp = head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter name : ");
    scanf("%s", newNode->name);
    printf("Enter %s's phone number : ",newNode->name);
    scanf("%d", &newNode->number);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    display();
}
void searchContact()
{
    int ch;
    do
    {
        printf("SEARCH\n  1.Search by Name\n  2.Search by Contact Number\n  0.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        char nameToBeSearched[20];
        int numberToBeSearched;
        switch(ch)
        {
            case 1 :
                printf("Enter name to be searched : ");
                scanf("%s",nameToBeSearched);
                struct node *temp;
                temp = head;
                while( strcmp(temp->name , nameToBeSearched) )
                {
                    temp = temp->next;
                }
                printf("%s : %d\n",temp->name,temp->number);
                break;

            case 2 :
                printf("Enter phone number to be searched : ");
                scanf("%d",&numberToBeSearched);
                struct node *temp2;
                temp2 = head;
                while( temp2->number != numberToBeSearched )
                {
                    temp2 = temp2->next;
                }
                printf("%s : %d\n",temp2->name,temp2->number);
                break;

            case 0 :
                return;
                break;

            default :
                    printf("Enter valid choice\n");
        }
    }while(ch!=0);
}
int main()
{
    int ch;
    printf("CONTACT BOOK\n");
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter your name : ");
    scanf("%s", head->name);
    printf("Enter your phone number : ");
    scanf("%ld", &head->number);
    head->next = NULL;
    do
    {
        printf("\n1.Insert record\n2.Delete record\n3.Display\n4.Search Contact number\n0.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 3:
            display();
            break;
        case 4 :
            searchContact();
            break;
        case 0 :
            return 0;
            break;
        default:
            printf("Enter valid choice");
        }
    }while (ch != 0);
    return 0;
}