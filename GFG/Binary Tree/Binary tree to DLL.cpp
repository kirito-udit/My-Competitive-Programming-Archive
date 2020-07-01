#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *left,*right;
		Node (int x){
			data=x;
			left=right=NULL;
		}
};
Node *newNode(int x){
	return new Node(x);
}
Node *BTtoDLL(Node *root){
	if(root==NULL){
		return NULL; 
	}
	if(root->left){
		Node *left=BTtoDLL(root->left);
		
		while(left->right!=NULL){
			left=left->right;
		}
		
		left->right=root;
		root->left=left;
	}
	if(root->right){
		Node *right=BTtoDLL(root->right);
		
		while(right->left!=NULL){
			right=right->left;
		}
		
		right->left=root;
		root->right=right;
	}
	return root;
}
Node *BTtoDLLmain(Node *root){
	if(root==NULL){
		return NULL;
	}
	root=BTtoDLL(root);
	
	while(root->left){
		root=root->left;
	}
	return root;
}
void printList(Node *head){
	while(head){
		cout<<head->data<<" ";
		head=head->right;
	}
	cout<<endl;
}
int main()  
{  
    // Let us create the tree shown in above diagram  
    Node *root = newNode(10);  
    root->left = newNode(12);  
    root->right = newNode(15);  
    root->left->left = newNode(25);  
    root->left->right = newNode(30);  
    root->right->left = newNode(36);  
  
    // Convert to DLL  
    Node *head = BTtoDLLmain(root);  
  
    // Print the converted list  
    printList(head);  
  
    return 0;  
}  
