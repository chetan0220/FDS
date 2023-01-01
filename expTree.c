#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct node
{
    char data;
    struct node *left, *right;
};

int top = -1;
struct node *stack[20];
struct node *root;
void push(struct node *root) 
{
    top = top + 1;
    stack[top] = root;
} 
struct node *pop () 
{
    return stack[top--];
}
void inorder(struct node *root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root != NULL)
	    {
            inorder (root->left);
            printf ("%c", root->data);
            inorder (root->right);
        }
    }
}

void operand (char b) 
{
    struct node *root;
    root = (struct node *) malloc (sizeof (struct node));
    root->data = b;
    root->left = NULL;
    root->right = NULL;
    push (root);
} 
void operators (char a)
{
    struct node *root;
    root = (struct node *) malloc (sizeof (struct node));
    root->data = a;
    root->right = pop ();   
    root->left = pop ();
    push (root);
} 
int main ()
{
    int i = 0;
    char postfix[20];
    printf ("\nenter postfix expression : ");
    scanf ("%s", postfix);
    while (postfix[i] != '\0')
    {
        if(isalnum(postfix[i]))
    	{
            //printf ("\nOperand==>%c", postfix[i]);
            operand (postfix[i]);
        }
        else
	    {
            operators (postfix[i]);
        }
        i++;
    }
    printf ("\ninfix expression : ");
    inorder (stack[top]);
    return 0;
}
