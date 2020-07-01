//convert a BT to ciruclar doubly linked list
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
//concatenate two circular DLL
Node *concetenate(Node *leftlist,Node *rightlist){
	if(leftlist==NULL){
		return rightlist;
	}
	if(rightlist==NULL){
		return leftlist;
	}
	
	Node *leftLast=leftlist->left;//prev
	
	Node *rightLast=rightlist->left;//prev
	
	leftLast->right=rightlist;
	rightlist->left=leftLast;
	
	rightLast->right=leftlist;
	leftlist->left=rightLast;
	
	
	return leftlist;
}

Node *convertBTtoCDLL(Node *root){
	if(root==NULL){
		return NULL;
	}
	
	Node *left=convertBTtoCDLL(root->left);
	Node *right=convertBTtoCDLL(root->right);
	
	root->left=root->right=root;
	
	return concetenate(concetenate(left,root),right);
}
void displayCList(Node *head) 
{ 
    cout << "Circular Linked List is :\n"; 
    Node *itr = head; 
    do
    { 
        cout << itr->data <<" "; 
        itr = itr->right; 
    } while (head!=itr); 
    cout << "\n"; 
} 
  
  
// Create a new Node and return its address 
Node *newNode(int data) 
{ 
   return new Node(data);
} 
  
// Driver Program to test above function 
int main() 
{ 
    Node *root = newNode(10); 
    root->left = newNode(12); 
    root->right = newNode(15); 
    root->left->left = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 
  
    Node *head = convertBTtoCDLL(root); 
    displayCList(head); 
  
    return 0; 
} 
