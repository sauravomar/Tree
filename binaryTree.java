

class binaryTree{
	private int data;
	private binaryTree left;
	private binaryTree right;

	public binaryTree insert(binaryTree root, int data){
	
		if(root == null){
			binaryTree temp = new binaryTree();
                	temp.left = null;
                	temp.right = null;
                	temp.data = data;
			root = temp;
		}else{
			if(root.data > data)
				root.left = insert(root.left, data);
			if(root.data < data)	
				root.right = insert(root.right, data);
		}
		return root;
	}
	public void display(binaryTree root){
		binaryTree temp = new binaryTree();
		temp = root;
		if(root == null) return ;

		if(root.left != null) display(root.left);

		System.out.println("data->" + root.data);

		if(root.right != null) display(root.right);
	}
	public void delete (binaryTree root, binaryTree par, int data){
		if(root.data == data) {
			if(root.left == null && root.right == null) {
				if(par.left == root ){
					par.left = null;
				}else if(par.right == root){
					par.right = null;
				}

			}else if(root.left == null && root.right != null || root.left != null && root.right == null){

				if(root.left == null){
					if(par.left == root){
                                		par.left = root.right;
						root = null;
                                	}else if(par.right == root){
                                		par.right = root.right;
						root = null;
                       		 }
				}else if(root.right == null){
                                	if(par.left == root){
                                		par.left = root.left;
						root = null;
                                	}else if(par.right == root){
                                		par.right = root.left;
						root = null;
                               		}

				}	
			}else if (root.left != null && root.right != null){
                        	binaryTree temp = new binaryTree();
                       	 	binaryTree temp1 = new binaryTree();
                        	temp = root.right;
                        	temp1 = root;
                        	int value = 0;

                        	while(temp.left != null){
                                	temp1 = temp;
                                	temp = temp.left;
                       		 }
                        	if(temp.right != null) {
					if( temp1.right == temp  ){
                                		value = temp.data;
                                		temp1.right = temp.right;
						temp  = null;
                               		}else{
						value = temp.data;
                                                temp1.left = temp.right;
                                                temp  = null;
					     }		
                       		}else if(temp.right == null){
                                	value = temp.data;
                               		temp1.right =  null;
                        	}
                        	root.data = value;
               }
	
		
		}else{
			if(root.data > data)
                                 delete(root.left, root, data);
                        if(root.data < data)
                                 delete(root.right, root, data);
		}
	}
	public static void main(String args[]){
		binaryTree root = new binaryTree();
		binaryTree obj = new binaryTree();
		binaryTree par = new binaryTree();
		root = null;
		par  = null; 	
		root = obj.insert(root, 5);
		root = obj.insert(root, 6);
		root = obj.insert(root, 1);
		root = obj.insert(root, 4);
		root = obj.insert(root, 8);
                root = obj.insert(root, 9);
		root = obj.insert(root, 10);
                root = obj.insert(root, 14);
		
		obj.display(root);
		obj.delete(root,par,5);
		System.out.println("after deletion");
		obj.display(root);
		
	}
} 
