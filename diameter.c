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

int diameter(struct tree *root){
	if(root == NULL) return ;
return (diameterofchild(root->left) + diameterofchild(root->right) );
}
int diameterofchild(struct tree *root){
	int val1,val2;
	if(root ==  NULL){
		return 0 ;
	}else{
		val1 = diameterofchild(root->left);
		val2 = diameterofchild(root->right);
		printf("%d,%d\n",val1,val2);
		if(val1 > val2){
		return (val1 +  1);
		}else{
			return (val2 +1);
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
	printf("\ndiameter of tree %d\n" ,diameter(root));
	return 0;
}
