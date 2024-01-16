#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* left;
 struct node* right;
};

struct node* createNode(int data){
 struct node *r = (struct node*)malloc(sizeof(struct node));
 r->data = data;
 r->left = r->right = NULL;

 return r;
}
struct node* createBinarySTree(struct node* root, int data){
     if(root == NULL){
      root = createNode(data);
      return root;
     }
     else if(data>= root->data){
     root->right = createBinarySTree(root->right, data);
     }
     else{
     root->left = createBinarySTree(root->left, data);
     }

     return root;
}

void inOrderTraversal(struct node* root){
 if(root == NULL){
  return;
} else{
inOrderTraversal(root->left);
printf("%d ",root->data);
inOrderTraversal(root->right);
 }
}
void ptree(struct node *root,int l)
{
    int i;
    if(root!=NULL)
    {
        ptree(root->right,l+1);
        for(i=0;i<l;i++)
            printf("   ");
        printf("%d\n",root->data);
        ptree(root->left,l+1);
    }
}
int main() {
    int a;
    struct node* tree1 = NULL;
    while(1)
    {
        printf("Enter data:(-1 to stop):");
        scanf("%d",&a);
        if(a==-1)
            break;
        tree1=createBinarySTree(tree1,a);
    }
    printf("\nInOrder raversal:\n");
    inOrderTraversal(tree1);
    printf("\n\n");
    ptree(tree1,0);
 return 0;
}
