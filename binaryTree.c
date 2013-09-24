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

void delete( struct tree *root, struct tree *root1, int data){
	if(root->data == data ){
		if(root->left == NULL && root->right == NULL){
			if(root1->left == root){
				root1->left = NULL;
				free(root);
			}else if(root1->right == root){
				root1->right = NULL;
				free(root);
			}	
		}else if((root->left != NULL && root->right == NULL) || ( root->right != NULL && root->left == NULL)){
	
			if(root->left == NULL){
		        	if(root1->left == root){
                                root1->left = root->right;
                                free(root);
                        	}else if(root1->right == root){
                                root1->right = root->right;
                                free(root);
                        }else if(root->right == NULL){
                                if(root1->left == root){
                                root1->left = root->left;
                                free(root);
                                }else if(root1->right == root){
                                root1->right = root->left;
                                free(root);
                        	}

		
		        }
		     }		
	       }else if (root->left != NULL && root->right != NULL){
			struct tree *temp = malloc(sizeof(struct tree));
			struct tree *temp1 = malloc(sizeof(struct tree));	
			temp = root->right;
			temp1 = root;
			int value;

			while(temp->left != NULL){
				temp1 = temp;	
				temp = temp->left;
			}
			if(temp->right != NULL){
				value = temp->data; 
				temp1->left = temp->right;
				free(temp);	
			}else if(temp->right == NULL){
				value = temp->data;
				free(temp);
				temp1->right =  NULL;
			}	
			root->data = value;	
	       }
	}else{
		if( root->data > data){
			delete(root->left, root, data);
		}else if (root->data < data){
			delete(root->right, root, data);
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
	delete(root,NULL,6);
	displayLVR(root);
	return 0;
}
