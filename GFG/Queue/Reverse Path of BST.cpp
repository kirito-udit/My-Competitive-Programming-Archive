#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *left,*right;
		Node(int d){
			data=d;
			left=right=NULL;
		}
};
void insert(Node *&root,int key){
	if(root==NULL){
		root=new Node(key);
		return;
	}
	else if(root->data>key){
		insert(root->left,key);
	}
	else if(root->data<key){
		insert(root->right,key);
	}
}
void reversePath(Node *&root,queue<int>&q,int &key){
	if(root==NULL){
		return;
	}
	if(root->data==key){
		q.push(root->data);
		root->data=q.front();
		q.pop();
	}
	else if(root->data>key){
		q.push(root->data);
		reversePath(root->left,q,key);
		root->data=q.front();
		q.pop();
	}
	else if(root->data<key){
		q.push(root->data);
		reversePath(root->right,q,key);
		root->data=q.front();
		q.pop();
	}
	return;
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
	Node *root=NULL;
	queue<int>q;
	root=new Node(50);
	int k=80;
	insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    cout<<"Before revers\n";
    inorder(root);
    cout<<endl;
    cout<<"After reverse\n";
    reversePath(root,q,k);
    inorder(root);
}
