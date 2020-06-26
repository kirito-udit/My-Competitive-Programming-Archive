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
int search(int arr[],int start,int end,int key){
	for(int i=start;i<=end;i++){
		if(arr[i]==key){
			return i;
		}
	}
	return -1;
}
Node *buildTree(int pre[],int post[],int start,int end,int &preIndex){
	if(start>end){
		return NULL;
	}
	Node *root=new Node(pre[preIndex++]);
	if(start==end){
		return root;//leaf node
	}
	int index=search(post,start,end,pre[preIndex]);
	root->left=buildTree(pre,post,start,index,preIndex);
	root->right=buildTree(pre,post,index+1,end-1,preIndex);
	return root;
}
void inorder(Node *root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){
	int pre[]={1,2,4,5,3};
	int post[]={4,5,2,3,1};
	int n=sizeof(pre)/sizeof(pre[0]);
	int i=0;
	Node *root=buildTree(pre,post,0,n-1,i);
	inorder(root);
}
