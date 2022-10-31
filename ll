#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node * next ;
};
struct node *head;
void create()
{
    struct node * neew , * temp ;
    int n;
    temp = head ;
    printf("no of nodes : ");
    scanf("%d",&n);
    for(int i = 1 ; i < n ; i++) 
    {
        neew = (struct node *) malloc (sizeof(struct node *));
        printf("enter data %d: ", i+1);
        scanf("%d", &neew -> data);
        temp -> next = neew ;
        temp = temp -> next ;
    }
}
void display()
{
    struct node * temp ;
    temp = head ;
    if(head == NULL)
    {
        printf("no linked list");
    }
    while(temp != NULL)
    {
        printf("%d  ",temp -> data);
        temp = temp -> next;
    }
}
void reverse()
{
    struct node *p , *q , *r ;
    p = head ;
    q = p -> next;
    r = q -> next;
    while(q != NULL)
    {
        q -> next = p ;
        p = q ;
        q = r ;
        r = r -> next ;
    }
    head -> next = NULL;
}
int main()
{
    head = (struct node *) malloc (sizeof(struct node));
    printf("enter data 1 : ");
    scanf("%d",&head->data);
    head -> next = NULL;
    create();
    display();
    //reverse();
    //display();
    return 0;
}
