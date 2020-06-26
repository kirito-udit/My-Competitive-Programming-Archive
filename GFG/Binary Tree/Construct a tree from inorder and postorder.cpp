//constrcut a tree from given inorder and postorder
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *left,*right;
		Node(int x){
			data=x;
			left=right=NULL;
		}
};
int search(int arr[],int s,int e,int key){
	for(int i=s;i<=e;i++){
		if(arr[i]==key){
			return i;
		}
	}
	return -1;
}
Node *buildTree(int in[],int post[],int s,int e,int &postIndex){
	if(s>e || postIndex<0){
		return NULL;
	}
	Node *root=new Node(post[postIndex--]);
	if(s==e){
		return root;
	}
	int index=search(in,s,e,root->data);
	root->right=buildTree(in,post,index+1,e,postIndex);
	root->left=buildTree(in,post,s,index-1,postIndex);
	return root;
}
void preOrder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
int main(){
	int in[]={4, 8, 2, 5, 1, 6, 3, 7};
	int post[]={8, 4, 5, 2, 6, 7, 3, 1};
	int n=sizeof(in)/sizeof(in[0]);
	int postIndex=n-1;
	Node *root=buildTree(in,post,0,n-1,postIndex);
	preOrder(root);
}
