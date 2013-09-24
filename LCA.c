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
		}else if((*root) ->data == data ){
			return ;
		}

	     }
}

void  lca(struct tree *root, int val1, int val2){
	if(root ==  NULL){
		return  ;
	}
	if (root->data > val1 && root->data > val2){
        	lca(root->left, val1, val2);
 	}
        else if (root->data < val1 && root->data < val2){
        	 lca(root->right, val1, val2);
	}
   	else {
		printf("lca is found %d\n", root->data); 
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
	insert(&root,13);
	insert(&root,12);
	insert(&root,15);
	insert(&root,16);
	displayLVR(root);
	lca(root,12,16);
	return 0;
}
