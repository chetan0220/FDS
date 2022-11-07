#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[10];
    int prn ;
    struct node * next,*prev ;
};
void insertSecretary(struct node * head)
{
    struct node *new ;
    new = (struct node *) malloc (sizeof(struct node));
    printf("enter secretary name : ");
    scanf(" %s", new->name);
    printf("enter secretary prn : ");
    scanf("%d", &new->prn);    
    new->next = NULL;
    new->prev = NULL;
    head->next = new;
    new->prev = head;
   
}
void insertMember(struct node *head)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("enter member name:\n");
    scanf(" %s",new->name);
    printf("enter member's prn\n");
    scanf("%d",&new->prn);
   
    new->next=NULL;
    new->prev=NULL;
    new->next=head->next;
    head->next=head;
    new->next->prev=new;
}
void display(struct node * head)
{
    printf("members : \n");
    struct node * temp ;
    temp = head ;
    while(temp!=NULL)
    {
        printf("%s\t",temp->name);
        printf(" %d\n",temp->prn);
        temp=temp->next;
    }
}
void deleteMember(struct node * head)
{
    
    
    
    
    
}
int main()
{
    struct node * head ;
    head = (struct node *) malloc (sizeof(struct node));
    printf("enter president name : ");
    scanf(" %s", head->name);
    printf("enter president prn : ");
    scanf("%d", &head->prn);
    head->next = NULL;
    head->prev = NULL;
    insertSecretary(head);
    int ch , y ;
    do
    {
        printf("1.insert member\n2.delete member\n3.delete president\n4.delete secretary\n5.count\n6.reverse\n7.display\n");
        printf("enter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
            insertMember(head);
            break;
            
            case 2 : 
            display(head);
            break;
            
            case 3 : 
            deleteMember(head);
            default :
            printf("enter valid choice ");
        }
       
    }while(ch<=2 && ch >=1);
    return 0;
}
