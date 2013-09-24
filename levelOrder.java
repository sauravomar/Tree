import java.util.Queue;

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
	public void levelOrder(binaryTree root){
		Queue<binaryTree> queue = new LinkedList<binaryTree>();
		queue.add(root);
		queue.add(null);
		while(queue.)
		 
	}
	public void display(binaryTree root){
		binaryTree temp = new binaryTree();
		temp = root;
		if(root == null) return ;

		if(root.left != null) display(root.left);

		System.out.println("data->" + root.data);

		if(root.right != null) display(root.right);
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

		
	}
} 
