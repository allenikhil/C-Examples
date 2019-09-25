/*program to implement binary search tree and its operations*/
#include<stdio.h>
#include<stdlib.h>
struct bst
{
 int val;
 struct bst *lc,*rc;
};
typedef struct bst node;
node *tree=NULL,*new,*parent;
node* insert(node* tree,int data);
void preorder(node* tree);
void postorder(node* tree);
void inorder(node* tree);
int totnodes(node* tree);
int totextnodes(node* tree);
int totintnodes(node* tree);
node* delete_tree(node* tree);
node* delete_node(node* tree,int del);
int max(node* tree);
int min(node* tree);
int tree_height(node* tree);
main()
{
 int ch,n,tn,ten,tin,d,h,l,s;
 do
 {
 printf("\nMENU...\n");
 printf("\nBinary Search Tree\n1.Insertion\n2.Inorder Traversal\n3.Preorder Traversal\n4.postorder Traversal\n5.Total nodes\6.Total   External nodes\n");
 printf("7.Total Internal Nodes\n8.Delete tree\n9.Delete a node\n10.Maximum element\n11.Minimum Element\n12.height of the tree\n0.exit\nenter your choice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
         printf("Enter the value:");
         scanf("%d",&n);
	 tree=insert(tree,n);
	 break;
  case 2:
         printf("\nInorder traversal:");
         inorder(tree);
	 break;
  case 3:
         printf("\nPreorder traversal:");
         preorder(tree);
	 break;
  case 4:
         printf("\nPostrder traversal:");
         postorder(tree);
	 break;
  case 5:
         tn=totnodes(tree);
	 printf("\nTotal number of nodes:%d\n",tn);
	 break;
  case 6:
         ten=totextnodes(tree);
	 printf("\nTotal number of External nodes:%d\n",ten);
	 break;
  case 7:
         tin=totintnodes(tree);
	 printf("\nTotal number of Internal nodes:%d\n",tin);
	 break;
  case 8:
         tree=delete_tree(tree);
	 if(tree==NULL)
            printf("\nEntire tree is deleted\n");
   	 break;
  case 9:
	 printf("\nEnter value to delete:");
 	 scanf("%d",&d);
         tree=delete_node(tree,d);
          if(tree==NULL)
             printf("tree is empty\n");
         else
            printf("\n%d is deletde from the tree\n",d);
  	 break;
  case 10:
 	  l=max(tree);
          printf("\n%d is largest in BST\n",l);
 	  break;
  case 11:
          s=min(tree);
          printf("\n%d is smallest in BST\n",s);
          break;
  case 12:
	  h=tree_height(tree);
	  printf("\nHeight of given BST:%d\n",h);
	  break;

  case 0:
         exit(0);
         break;
  default:
          printf("\nInvalid Choice\n");
  }
 }while(ch!=0);
}


node* insert(node* tree,int data)
{
 node *temp;
 new=(node*)malloc(sizeof(node));
 new->val=data;
 new->lc=NULL;
 new->rc=NULL;

 if(tree==NULL)
 {
  tree=new;
 }
 else
 {
  temp=tree;
  parent=NULL; 
   while(temp!=NULL)
  {
   parent=temp;
   if(data<temp->val)
   {
    temp=temp->lc;
   }
   else
   {
    temp=temp->rc;
   }
  }//end of while loop
 
  if(data<parent->val)
  {
   parent->lc=new;
  }
  else
  {
   parent->rc=new;
  }
 } //end of else
 return (tree);
}

void preorder(node* tree)
{
 if(tree!=NULL)
 {
  printf("%d\t",tree->val);
  preorder(tree->lc);
  preorder(tree->rc);
 }
 
}

void inorder(node* tree)
{
 if(tree!=NULL)
 {
  inorder(tree->lc);
  printf("%d\t",tree->val);
  inorder(tree->rc);
 }
 
 
}


void postorder(node* tree)
{
 if(tree!=NULL)
 {
  postorder(tree->lc);
  postorder(tree->rc);
  printf("%d\t",tree->val);
 }
}

int totnodes(node* tree)
{
 if(tree==NULL)
   return 0;
 else
   return (totnodes(tree->lc)+totnodes(tree->rc)+1);
}

int totextnodes(node* tree)
{
 if(tree==NULL)
  return 0;
 else if((tree->lc==NULL)||(tree->rc==NULL))
   return 1;
  else
    return (totextnodes(tree->lc)+totextnodes(tree->rc));
}

int totintnodes(node* tree)
{
 if((tree==NULL)||(tree->lc==NULL&&tree->rc==NULL))
   return 0;
  else
    return (totintnodes(tree->lc)+totintnodes(tree->rc)+1);
}

node* delete_tree(node* tree)
{
 node *lt,*rt;
 if(tree!=NULL)
 {
  lt=delete_tree(tree->lc);
  rt=delete_tree(tree->rc);
  free (tree);
 }
 return tree;
}
node* delete_node(node* tree,int del)
{
 node *t1,*t2;
 int t3;

 if(tree==NULL)
   return tree;
 else if(del<tree->val){
   tree->lc=delete_node(tree->lc,del);}
 else if(del>tree->val){
   tree->rc=delete_node(tree->rc,del);}
 else
  {
    if(tree->lc==NULL&&tree->rc==NULL){
             free(tree);
             tree=NULL;}
    else if(tree->lc==NULL){
           t1=tree;
           tree=tree->rc;
           free(t1);}
    else if(tree->rc==NULL){
           t2=tree;
           tree=tree->lc;
           free(t2);}
    else 
    {
      t3=min(tree->rc);
      tree->val=t3;
      tree->rc=delete_node(tree->rc,t3);
    }
  }
 return tree;
 }

int min(node *tree)
{ 
  if(tree==NULL)
     return (-1);
  while(tree->lc!=NULL)
  {
   tree=tree->lc;
  }
 
 return (tree->val);
}

int max(node* tree)
{
 
 if(tree==NULL)
    return (-1);
 while(tree->rc!=NULL)
 {
  tree=tree->rc;
 }

 return (tree->val);
}

int tree_height(node* tree)
{
 int lh,rh;
 if(tree==NULL)
   return (-1);
 else
   lh=tree_height(tree->lc);
   rh=tree_height(tree->rc);
   return ((lh>rh?lh:rh)+1);
}

    
         


 

 
