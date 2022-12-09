#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *left , *right;
};
struct node* createNode(struct node *root , int key)
{
    root = (struct node*) malloc (sizeof(struct node));
    root->data = key;
    root->left = NULL;
    root->right = NULL;
    return root;
}
struct node* insert(struct node *root , int key)
{
    if(root == NULL)                    // if tree is not created
    {
        createNode(root,key);
    }
    else if(key < root->data)             //if data is smaller insert on left side
    {
        insert(root->left , key);
    }
    else                                 //if data is greater insert on right side
    {
        insert(root->right , key);
    }
    return root;
}
void search(struct node *root ,int key)
{
    
}
int main()
{
    struct node *root;
    int key,ch;
    do
    {
        printf("1.insert\n2.search\n3.display inorder\n4.display preorder\n5.display postorder\n0.exit\nenter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter data : ");
                scanf("%d",&key);
                insert(root,key);
                break;
            
            case 2 :
                printf("enter data to be searched : ");
                scanf("%d",&key);
                search(root,key);
                break;
                
            case 0 :
                return 0;
                break;
            
            default : 
                printf("enter valid choice ");
        }
    }while(ch!=0);
    return 0;
}
