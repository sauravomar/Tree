#include<stdio.h>
#include<stdlib.h>

struct tree{
	struct tree *right;
	struct tree *left;
	int data;

}*root;


void  insert(struct tree **root , int data){

	if(*root == NULL){
		struct tree *temp = malloc(sizeof(struct tree));
		temp->right = NULL;
		temp->left  = NULL;
		temp->data  = data;
		*root = temp;
		return ;	
	}else{
		if((*root)->data > data){
			 insert(&(*root)->left,data);
		}else if ((*root) ->data < data){
			 insert(&(*root)->right, data);
		}	

	     }
}

void childSum(struct tree *root){
	
	if(root ==  NULL){
		return ;
	}else{
		 childSum(root->left);
		 childSum(root->right);
		 if(root->left != NULL && root->right != NULL){
		 	root->data =  root->left->data + root->right->data;		
	         }else if(root ->left != NULL && root->right == NULL)	{
		   	root->data = root->left->data ;	
		 }else if(root -> right != NULL && root->left == NULL){
			root->data = root->right->data;
		 }
	     }	
}		

void  displayLVR(struct tree *root){
	if(root == NULL){
		return ;
	}else{
		displayLVR(root->left);
		printf("%d\t",root->data);
		displayLVR(root->right);
	}
}

int main(){
	root = NULL;
	insert(&root,5);
	insert(&root,6);
	insert(&root,1);
	insert(&root,4);
	insert(&root,9);
	insert(&root,10);
	insert(&root,14);
	insert(&root,8);
	displayLVR(root);
	childSum(root);
	printf("summed value\n");
	displayLVR(root);
	return 0;
}
