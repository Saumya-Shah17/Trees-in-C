#include<stdio.h>
#include<stdlib.h>

int stack[40];
int top = -1 ;
struct node{
int data;
struct node *left;
struct node *right;
}*root;

struct node *create(int x){
struct node *nw = (struct node*)malloc(sizeof(struct node));
nw->data = x;
nw->left = NULL;
nw->right = NULL;
return nw;
}

struct node * tree(struct node *r,int x){
if(r==NULL){
r = create(x);
}
else if(r->data>x){
r->left = tree(r->left,x);
}
else{
r->right = tree(r->right,x);
}
return r;
}

void printtree(struct node *ro,int l){
int i;
if(ro!=NULL){
printtree(ro->right,l+1);
for(i=0;i<l;i++){
printf("   ");
}
printf("%d\n",ro->data);
printtree(ro->left,l+1);
}
}

void preorder(struct node * root){
    node * t = root;
    while(t!=NULL){
        printf("%d",t->data);
        stack[++top] = t->data;
        t = t->left;
    }
    while (top!=-1){
        top--;
        t=t->right;
        while(t!=NULL){
            printf("%d",t->data);
            stack[++top] = t->data;
            t = t -> right;
        }
    }
}


int main(){
int a;
root =(struct node *)malloc(sizeof(struct node));
root = NULL;
while(1){
printf("Enter data\n");
scanf("%d",&a);
if(a==-1)
break;
root = tree(root,a);
}
    preorder(root);
}


