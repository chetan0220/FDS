#include <stdio.h>
#define size 4
int queue[size] , front = -1 , rear = -1;
void enqueue()
{
    int data; 
    printf("enter data : ");
    scanf("%d",&data);
    if( (rear == size - 1 && front == 0) || (front == (rear+1)%size) )
    {
        printf("overflow\n");
        return;
    }
    else if(rear==-1)
    {
        front = 0 ; 
        rear = 0 ;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    queue[rear] = data;
}
void dequeue()
{
    int e;
    if(front == -1)
    {
        printf("underflow\n");
        return;
    }
    else 
    {
        e = queue[front];
        if(front == rear)
        {
            front = rear = -1 ;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
    printf("deleted : %d\n",e);
}
void print()
{
    if(front == -1)
    {
        printf("empty queue\n");
    }
    else
    {
        if(front == rear)           //for one element
        {
            printf("%d ",queue[rear]);
        }
        else if(front < rear)           //when front is behid rear
        {
            for(int i = front; i <=rear ; i++ )
            {
                printf("%d ",queue[i]);
            }
        }
        else
        {
            for(int i = front  ; i != rear+1 ; i = (i + 1)%size )
            {
                printf("%d ",queue[i]);
            }
        }
    }
    printf("\n");
}
int main()
{
    int ch; 
    do
    {
        int ch;
        printf("\n1.insert\n2.delete\n3.print\n0.exit\nenetr your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
                    enqueue();
                    break;
            case 2 :
                    dequeue();
                    break;
            case 3 :
                    print();
                    break;
            case 0 :
                    return 0 ;
            default :
                    printf("enetr valid choice : ");
        }
    }while(ch!=0);
    return 0;
}
