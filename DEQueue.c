/*
DEQueue using arrays 
        - enqueueFront
        - enqueueRear
        - dequeueFront
        - dequeueRear
        - display
*/

#include<stdio.h>
# define size 5
int queue[size];
int front = -1;
int rear = -1;
void display()
{
    if(front == -1)
    {
        printf("empty queue\n");
        return;
    }    
    for(int i = front ; i <= rear ; i++)
    {
        printf("%d ",queue[i]);
    }
}
void enqueueFront()
{
    if(front <= 0 )
    {
        printf("insertion not possible from front\n");
    }
    else
    {
        printf("enter data : ");
        scanf("%d",&queue[--front]);
    }
    display();
}
void enqueueRear()
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
void dequeueFront()
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
void dequeueRear()
{
    if(rear == -1)              // no elements
    {
        printf("empty queue\n");
        return;
    }
    else
    {
        if(front == rear)       // 1 element
        {
            front = rear = -1 ;
        }
        else                // >1 elements
        {
            rear--;
        }
    }
    display();
}

int main()
{
    int ch ;
    do{
        printf("\n1.insert front\n2.insert rear\n3.delete front\n4.delete rear\n5.display\n0.exit\nenter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : 
                    enqueueFront();
                    break;
            case 2 : 
                    enqueueRear();
                    break;
            case 3 : 
                    dequeueFront();
                    break;
            case 4 : 
                    dequeueRear();
                    break;
            case 5 : 
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
