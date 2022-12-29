/*
simple queue using arrays
                        -enqueue
                        -dequeue
                        -display
*/
#include <stdio.h>
# define size 5
int queue[size];
int front = -1;
int rear = -1;
void display()
{
    for(int i = front ; i <= rear ; i++)
    {
        printf("%d ",queue[i]);
    }
}
void insert()
{
    if(front == -1)             //if queue is empty
    {
        printf("enter data : ");
        scanf("%d",&queue[++rear]);
        front++;
    }
    else
    {
        printf("enter data : ");
        scanf("%d",&queue[++rear]);
    }
    display();
}
void delete()
{
    if(front == -1)         //no elements in array
    {
        printf("queue is empty\n");
        return ;
    }
    else 
    {
        if(front == rear)       // 1 element in array
        {
            front = rear = -1;
        }
        else                // >1 elements in array 
        {
            front++;
        }
    }
    display();
}
int main()
{
    int ch ;
    do{
        printf("\n1.insert\n2.delete\n3.display queue\n0.exit\nenter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : 
                    insert();
                    break;
            case 2 : 
                    delete();
                    break;
            case 3 : 
                    display();
                    break;
            case 0 : 
                    return 0;
                    break;
            default :
                    printf("enter valid choice");
        }

    }while(ch!=0);



    return 0;
}
