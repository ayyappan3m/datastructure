#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node* newNode(int data)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node)*1);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};
void add(Node** node,int data)
{
    if((*node) == NULL)
        *node = newNode(data);
    else if((*node)->data > data)
        add(&(*node)->left,data);
    else if((*node)->data < data)
        add(&(*node)->right,data);
}
void printInorder(Node** node)
{
    if(*node == NULL)
        return;
    printf("%d\t",(*node)->data);

    printInorder(&(*node)->left);
    printInorder(&(*node)->right);
}

void printPreorder(Node** node)
{
    if(*node == NULL)
        return;
    
    printPreorder(&(*node)->left);
    printf("%d\t",(*node)->data);
    printPreorder(&(*node)->right);
}
void printPostorder(Node** node)
{
    if(*node == NULL)
        return;
    
    printPostorder(&(*node)->left);
    printPostorder(&(*node)->right);
    printf("%d\t",(*node)->data);
}
void delete(Node** node,int data)
{
    
}
int main()
{
    Node *root;
    int choice;
    int data;
    /*add(&root,20);
    add(&root,17);
    add(&root,13);
    add(&root,19);
    add(&root,29);
    add(&root,25);
    add(&root,30);
    printf("%d->",root->data);
0    printf("%d->",root->left->data);
    printf("%d->",root->right->data);
    printf("%d->",root->left->left->data);
    printf("%d->",root->left->right->data);
    printf("%d->",root->right->left->data);
    printf("%d->",root->right->right->data);
*/
    //printf("Hello world!\n %d",root->data);
    do
    {
      printf("\t\tBinary Tree\n\n");
      printf("1.Insert\n");
      printf("2.Delete\n");
      printf("3.Inorder\n");
      printf("4.Preorder\n");
      printf("5.postorder\n");
      printf("6.Exit\n");
      
      printf("Choice:");
      scanf("%d",&choice);
      if(choice<6)
      {
          switch(choice)
          {
            case 1: printf("Enter value to insert:");
                    scanf("%d",&data);
                    add(&root,data);
                    break;
            case 2: printf("Enter element to delete:");
                    scanf("%d",&data);
                    delete(data);
                    break;
            case 3: printf("Inorder:");
                    printInorder(&root);
                    break;
            case 4: printf("Preorder:");
                    printPreorder(&root);
                    break;
            case 5: printf("Postorder:");
                    printPostorder(&root);
                    break;
                    

          }
      }
      else if(choice == 6)
        break;
      else
      {
          printf("Enter correct choice:");
          getchar();
      }
      printf("\n");
      getchar();
    }while(choice!=6);
    return 0;
}
