#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int d;
    struct tree *left;
    struct tree *right;

};
struct tree *root;
void insert(int b){
     struct tree *ptr,*parptr,*nodeptr;
     ptr=(struct  tree *) malloc(sizeof(struct tree));
     if (ptr==NULL)
      printf("Can't insert\n");
     else{
         ptr->d=b;
         ptr->left=NULL;
         ptr->right=NULL;
     }
     if(root==NULL){
       root=ptr;
       root->left=NULL;
       root->right=NULL;
     }
     else{
         parptr=NULL;
         nodeptr=root;
         while(nodeptr!=NULL){
             parptr=nodeptr;
             if (b<nodeptr->d){
                 nodeptr=nodeptr->left;
             }
             else
             {
                 nodeptr=nodeptr->right;
             }
             
         }
         if (b<parptr->d)
           parptr->left=ptr;
         else
         {
             parptr->right=ptr;
         }
         
     }

}

void preorder(struct tree* root ){
    if(root==NULL)
    return;
    printf("%d->",root->d);
    preorder(root->left);
    preorder(root->right); 

}
void inorder(struct tree* root ){
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d->",root->d);
    inorder(root->right); 

}
void postorder(struct tree* root ){
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right); 
    printf("%d->",root->d);

}
  
int main(){
    int i,n,a;
    printf("DFS of a tree\n 1.Preorder <root><left><right>\n 2.Inorder <left><root><right>\n 3.Postorder <left><right><root>\n");
    printf("Enter your choice:");
    scanf("%d",&a);
    do{
      int b;
      printf("\nEnter the element:");
      scanf("%d",&b);
      insert(b);
      printf("\nPreorder:");
      preorder(root);
      printf("\nInorder:");
      inorder(root);
      printf("\nPostorder:");
      postorder(root);
      printf("\nEnter the choice:");
      scanf("%d",&a);
    }while(a==0);
    return 0;
}