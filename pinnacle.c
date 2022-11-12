#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[10];
    int prn ;
    struct node * next,*prev ;
} *head;
void display()
{
    struct node * temp ;
    temp = head ;
    while(temp!=NULL)
    {
        printf("%s : %d\n",temp->name ,temp->prn);
        temp=temp->next;
    }
}
void insertSecretary()
{
    struct node *new ;
    new = (struct node *) malloc (sizeof(struct node));
    printf("enter secretary name : ");
    scanf(" %s", new->name);
    printf("enter secretary prn : ");
    scanf("%d", &new->prn);    
    new->next = NULL;
    new->prev = NULL;
    new->prev = head;
    head->next = new;
}
void insertMember()
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("enter member name: ");
    scanf("%s",new->name);
    printf("enter member's prn : ");
    scanf("%d",&new->prn);
    new->next=NULL;
    new->prev=NULL;
    new->next=head->next;
    head->next=new;
    new->next->prev=new;
    new->prev = head;
}
void deleteMember()
{
    int n;
    printf("enter prn of member to be deleted : ");
    scanf("%d",&n);
    struct node *temp ;
    temp = head ;
    while(temp->prn != n)
    {
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
    display();
}
void deletePresident()
{
    struct node * temp ;
    temp = head;
    free(head);
    head = temp->next;
    display();
}
void deleteSecretary()
{
    struct node * temp ;
    temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    display();
}
void count()
{
    struct node * temp ;
    temp = head;
    int counter = 0 ;
    while(temp!=NULL)
    {
        counter++;
        temp = temp->next;
    }
    printf("total members are : %d",counter);
}

void reverse()
{
    struct node * ptr1 , *ptr2;
    ptr1 = head;
    ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while (ptr2!=NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    display(head);
}
int main()
{
    //inserting president
    head = (struct node *) malloc (sizeof(struct node));
    printf("enter president name : ");
    scanf("%s", head->name);
    printf("enter president prn : ");
    scanf("%d", &head->prn);
    head->next = NULL;
    head->prev = NULL;
    
    //inserting secretary
    insertSecretary();
    int ch , y ;
    do
    {
        printf("\n1.insert member\n2.delete member\n3.delete president\n4.delete secretary\n5.count\n6.reverse\n7.display\n0.exit\n");
        printf("\nenter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
            insertMember();
            break;

            case 2 : 
            deleteMember();
            break;

            case 3:
            deletePresident();
            break;

            case 4:
            deleteSecretary();
            break;

            case 5:
            count();
            break;

            case 6:
            printf("reversed list : \n");
            reverse();
            break;

            case 7:
            printf("members : \n");
            display();
            break;
            
            case 0:
            return 0;

            default :
            printf("\nEnter valid choice ");
        }
    }while(ch!=0);
    return 0;
}
