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
Node *newNode(int x){
	return new Node(x);
}
void convertBTtoDLL(Node *root,Node *&head){
	if(root==NULL){
		return;
	}
	
	static Node *prev=NULL;
	
	convertBTtoDLL(root->left,head);
	
	if(prev==NULL){
		head=root;
	}
	else{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	
	convertBTtoDLL(root->right,head);
}
void printList(Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->right;
	}
}
int main(){
	 // Let us create the tree shown in above diagram 
    Node *root        = newNode(10); 
    root->left        = newNode(12); 
    root->right       = newNode(15); 
    root->left->left  = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 
  
    // Convert to DLL 
    Node *head = NULL; 
    convertBTtoDLL(root,head); 
  
    // Print the converted list 
    printList(head); 
  
    return 0; 
}
