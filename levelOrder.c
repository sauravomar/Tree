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

void levelorder(struct tree *root, struct tree *level){                                                                                                        
	 int i=-1,j=1;
	                                                                                                                                               if(root ==  NULL){
		return ;
	}else{
		while(level[i] == level[j]){
			if(level[i+1] = = 1000){
				level[j++] = 1000;
				root = level[i++];
			
			}else{
				root = level[i++];
			}
			if(root->left != NULL){
				level[j++] = root->left;
			}
			if(root->right != NULL){	
                        	level[j++] = root->right;
			}	
			
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
	struct tree *level;
	level[0] = root;
	level[1] = "flag";
	levelorder(root,level);
	printf("\nlevelorder of tree\n");
	displayLVR(root);
	return 0;
}
