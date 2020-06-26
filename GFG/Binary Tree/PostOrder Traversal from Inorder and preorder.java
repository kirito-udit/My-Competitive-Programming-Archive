import java.util.*;
class Try{
	static int preindex=0;
	public static void main(String args[]) {
		int inorder[]= {4,2,5,1,3,6};
		int preorder[]= {1,2,4,5,3,6};
		preindex=0;
		printPostOrder(inorder, preorder, 0, inorder.length-1);
	}
	static void printPostOrder(int inorder[],int preorder[],int s,int e) {
		if(s>e) {
			return;
		}
		int index=search(inorder,s,e,preorder[preindex++]);
		
		printPostOrder(inorder,preorder,s,index-1);
		printPostOrder(inorder,preorder,index+1,e);
		System.out.print(inorder[index]+" ");
	}
	static int search(int arr[],int start,int end,int key) {
		int in=0;
		for(int i=start;i<=end;i++) {
			if(arr[i]==key) {
				in=i;
				break;
			}
		}
		return in;
	}
}