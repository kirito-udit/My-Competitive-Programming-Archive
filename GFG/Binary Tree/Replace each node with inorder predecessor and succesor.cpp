//replace each node with inorder predecessor and succesor
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
void inorderTraversal(Node *root){
	if(root==NULL){
		return;
	}
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}
void inorder(vector<int>&v,Node *root){
	if(root==NULL){
		return ;
	}
	inorder(v,root->left);
	v.push_back(root->data);
	inorder(v,root->right);
}
void replace(Node *root,vector<int>&v,int &index){
	if(root==NULL){
		return;
	}
	replace(root->left,v,index);
	root->data=v[index-1]+v[index+1];
	index++;
	replace(root->right,v,index);
}
void fun(Node *root){
	vector<int>v;
	if(root==NULL){
		return;
	}
	v.push_back(0);
	inorder(v,root);
	v.push_back(0);
	int index=1;
	replace(root,v,index);
}
int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	cout<<"Before replace\n";
	inorderTraversal(root);
	cout<<endl;
	fun(root);
	cout<<"After\n";
	inorderTraversal(root);
	cout<<endl;
}
