#include<stdio.h>
#include<stdlib.h>

struct tree{
	struct tree *right;
	struct tree *left;
	int data;

}*root,*root1;


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

int check(struct tree *root, struct tree *root1){
	int val1,val2;
	if(root1 == NULL && root == NULL){
		return 1 ;
	}
	else if (root1 == NULL || root == NULL){
		return 0;
	}
	if(root->data  == root1->data){
		val1 = check(root->left, root1->left);
		val2 = check(root->right, root1->right);
		printf("%d  %d \n",val1,val2);
		if(val1 == 1 && val2 == 1){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
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

        insert(&root1,5);
        insert(&root1,6);
        insert(&root1,1);
        insert(&root1,4);
        insert(&root1,9);
        insert(&root1,10);
        insert(&root1,14);
        insert(&root1,7);
        displayLVR(root1);
	int val = check(root, root1);
	if(val){
		printf("\nidentical \n");
	}else{
		printf("\nnot identical\n");
	}
	return 0;
}
