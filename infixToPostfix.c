#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
struct node 
{
    char data;
    struct node *next;
}*top=NULL;

int s[20] , top1 = -1;
void push(char a)
{
    struct node * newnode ;
    newnode = ( struct node *) malloc (sizeof(struct node));
    newnode->data = a;
    newnode->next = NULL;
    if(top == NULL)
    {
        top = newnode ;
    }
    else
    {
        newnode->next = top ;
        top = newnode;
    }
}
char pop()
{
    char op;
    struct node * temp;
    if(top==NULL)
    {
        printf("stack empty\n");
    }
    else
    {
        temp = top ;
        op = top->data;
        top = top->next;
        free(temp);
    }
    return op;
}
int precedence(char a)
{
    switch(a)
    {
        case '^' :
            return 3;
        break;
        
        case '*' :
            return 2;
        break;
        
        case '/' :
            return 2;
        break;
        
        case '+' :
            return 1;
        break;
        
        case '-' :
            return 1;
        break;
    }
}

void push1(int num)
{
    top1++;
    s[top1] = num;
}
int pop1()
{
    int num;
    num = s[top1];
    top1--;
    return num;
}
void evaluate(char postfix[])
{
    int i = 0 ,num ,n1,n2,n3;
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
        {
            num = postfix[i] - 48;
            push1(num);
        }
        else
        {
            n1 = pop1();
            n2 = pop1();
            switch(postfix[i])
            {
                case '^' :
                    n3 = pow(n2,n1);
                    push1(n3);
                    break;
            
                case '*' :
                    n3 = n2*n1;
                    push1(n3);
                    break;
            
                case '/' :
                    n3 = n2/n1;
                    push1(n3);
                    break;
            
                case '+' :
                    n3 = n2+n1;
                    push1(n3);
                    break;
            
                case '-' :
                    n3 = n2-n1;
                    push1(n3);
                    break;
            }
            
        }
        
        i++;
        
        
    }
    
    printf("evaluation : %d",pop1());
    
    
    
    
}
int main()
{
    char infix[20],postfix[20];
    int i = 0 , j = 0 ;
    printf("enter expression : ");
    scanf(" %s",infix);
    
    while(infix[i] != '\0')
    {
        if(isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else
        {
            if(top==NULL)
            {
                push(infix[i]);
            }
            else
            {
                while(precedence(infix[i]) <= precedence(top->data) && top != NULL)
                {
                    postfix[j++] = pop();
                }
                push(infix[i]);
            }
        }
        i++;
    }
    
    while(top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("%s\n",postfix);
    
    evaluate(postfix);
    
    
    
    return 0;
}


