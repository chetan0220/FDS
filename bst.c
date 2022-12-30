#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *left , *right;
};
struct node *createNode(int key)
{
    struct node *temp ;
    temp = (struct node*) malloc (sizeof(struct node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node *insert(struct node *root , int key)
{
    if(root == NULL)                    // if tree is not created
    {
        return createNode(key);
    }
    if(key < root->data)             //if data is smaller insert on left side
    {
        root->left = insert(root->left , key);
    }
    else                                 //if data is greater insert on right side
    {
        root->right = insert(root->right , key);
    }
    return root;
}
int search(struct node *root ,int key)
{
    if(root == NULL)
    {
        return 0;
    }
    if(key < root->data)
    {
        search(root->left , key);
    }
    else
    {
        search(root->right , key);
    }
    return 1;
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
int inorderSuccessor(struct node *root)
{
    while(root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
struct node *delete (struct node *root,int key)
{
	//searching the node
    if(root == NULL)
    {
        return root;
    }
    if(key<root->data)
    {
        root->left = delete (root->left , key);
    }
    else if(key > root->data)
    {
        root->right = delete(root->right , key);
    }
	//deleting logic
    else 
    {
        if(root->left == NULL)
        {
            struct node *temp;
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp;
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node * temp;
            temp = root->right;
            root->data = inorderSuccessor(temp);
            root->right = delete(root->right , root->data);
        }
    }
    return root;
}
int main()
{
    struct node *root = NULL;
    int key,ch;
    do
    {
        printf("\n1.insert\n2.search\n3.display inorder\n4.display preorder\n5.display postorder\n6.delete\n0.exit\nenter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter data : ");
                scanf("%d",&key);
                root = insert(root,key);
                break;
            
            case 2 :
                printf("enter data to be searched : ");
                scanf("%d",&key);
                (search(root,key) == 1) ? printf("found\n") : printf("not found");
                break;
            
            case 3:
                inorder(root);
                break;
                
            case 4:
                preorder(root);
                break;
                
            case 5:
                postorder(root);
                break;
                
            case 6:
                printf("enter data to be deleted : ");
                scanf("%d",&key);
                delete(root,key);
                inorder(root);
                break;

            case 0 :
                return 0;
                break;
            
            default : 
                printf("enter valid choice\n");
        }
    }while(ch!=0);
    return 0;
}
