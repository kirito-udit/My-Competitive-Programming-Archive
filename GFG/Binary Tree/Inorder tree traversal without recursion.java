import java.util.*;
class Try {
	public static void main(String[] args) {
		Node root=new Node(1);
		root.left=new Node(2);
		root.right=new Node(3);
		root.left.left=new Node(4);
		root.left.right=new Node(5);
		inorder(root);
	}
	static void inorder(Node root) {
		Stack<Node> st=new Stack<Node>();
		if(root==null) {
			return;
		}
//		st.push(root);
		Node temp=root;
		while(st.empty()==false || temp!=null) {
			while(temp!=null) {
				st.push(temp);
				temp=temp.left;
			}
			
			temp=st.pop();
			System.out.print(temp.data+" ");
			temp=temp.right;
		}
	}
}
class Node{
	int data;
	Node left;
	Node right;
	Node(int x){
		data=x;
		left=right=null;
	}
}
