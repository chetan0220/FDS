#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char city[20];  
    int value;
    struct node *next;
};
void display(struct node *head)
{
    struct node *temp ;
    temp = head;
    while(temp != NULL)
    {
        printf("%s : %d\n", temp->city , temp->value);
        temp = temp->next;
    }
}
void create(struct node *head , int n)
{
    struct node *new , *temp; 
    temp = head;
    for(int i = 2 ; i <= n ; i++)
    {
        new = (struct node *)malloc (sizeof(struct node));
        printf("Enter name of city %d : ",i);
        scanf(" %s",new->city);
        printf("Enter number of covid 19 patients in %s : ",new->city);
        scanf("%d",&new->value);
        new->next = NULL;
        temp->next = new;
        temp = temp->next;
    }
}
void sort(struct node *head)
{
    //Bubble sort
    int swapTemp , swapped;
    char swapCityTemp[20];
    struct node *i ,*j;
    i = head;
    while(i->next != NULL)
    {
        swapped = 0 ;
        j = i->next;
        while(j != NULL)
        {
            if(i->value > j->value)
            {
                //swapping integers
                swapTemp = i->value;
                i->value = j->value ; 
                j->value = swapTemp;
                //swapping the city name
                strcpy(swapCityTemp , i->city) ;
                strcpy(i->city , j->city) ;
                strcpy(j->city , swapCityTemp) ;
                swapped = 1 ; 
            }
            j = j->next;
        }
        i = i->next;
    }
}
int main()
{
    int n  , swapped;
    struct node *head = (struct node *)malloc (sizeof(struct node)) ;
    // head node input 
    printf("Enter number of cities : ");
    scanf("%d",&n);
    printf("\nEnter name of city 1 : ");
    scanf(" %s",head->city);
    printf("Enter number of covid 19 patients in %s : ",head->city);
    scanf("%d",&head->value);
    head->next = NULL;
    //creating remaining nodes
    create(head,n);                 
    printf("-----------------------------");

    printf("\nEntered Data : \n");
    display(head);

    sort(head);
    printf("-----------------------------");

    printf("\nSorted list of patients and respective cities : \n");
    display(head);
    printf("-----------------------------");
    return 0; 
} 

/*
    Time complexity = O(n^2)     bubble sort
*/