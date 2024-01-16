#include<stdio.h>
#include<stdlib.h>
struct node 
{
int a;
struct node *l,*r;
}*ro;
struct node *inp(int x)
{
struct node *nw;
nw=(struct node*)malloc(sizeof(struct node));
nw->a=x;
nw->r=nw->l=NULL;
return nw;
}
struct node *tree(struct node *root,int x)
{
if(root == NULL)
root=inp(x);
else if(x>root->a)
root->r=tree(root->r,x);
else
root->l=tree(root->l,x);
return root;
}
void ptree(struct node *root,int l)
{
if(root!=NULL)
{
int i;
ptree(root->r,l+1);
for(i=0;i<l;i++)
printf("   ");
printf("%d\n",root->a);
ptree(root->l,l+1);
}
}
struct node * mir(struct node *root)
{
if(root == NULL)
return NULL;
struct node *t=(struct node*)malloc(sizeof(struct node));
t=root->l;
root->l=root->r;
root->r=t;

mir(root->l);
mir(root->r);

return root;
}
int main()
{
int a;
ro=(struct node*)malloc(sizeof(struct node));
ro=NULL;
while(1)
{
printf("Enter data(-1 to stop):");
scanf("%d",&a);
if(a==-1)
break;
ro=tree(ro,a);
}
ptree(ro,0);
ro=mir(ro);
ptree(ro,0);
return 0;
}
