#include<bits/stdc++.h>
using namespace std;
class DLLNode{
	public:
		int data;
		DLLNode *prev,*next;
		DLLNode(int x){
			data=x;
			prev=next=NULL;
		}
};
class TreeNode{
	public:
		int data;
		TreeNode *left,*right;
		TreeNode(int x){
			data=x;
			left=right=NULL;
		}
};
void verticalSum(TreeNode* root,DLLNode *head){
	head->data=head->data+root->data;
	
	if(root->left){
		if(head->prev==NULL){
			head->prev=new DLLNode(0);
			head->prev->next=head;
		}
		verticalSum(root->left,head->prev);
	}
	if(root->right){
		if(head->next==NULL){
			head->next=new DLLNode(0);
			head->next->prev=head;
		}
		verticalSum(root->right,head->next);
	}
}
void verticalSummain(TreeNode *root){
	DLLNode *head=new DLLNode(0);
	
	verticalSum(root,head);
	
	while(head->prev){
		head=head->prev;
	}
	
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
}
int main(){
	/* 
                 1 
                / \ 
               /   \ 
              2     3 
             / \   / \ 
            /   \ /   \ 
           4    5 6    7 
    */
    TreeNode *root = new TreeNode(1); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5); 
    root->right->left = new TreeNode(6); 
    root->right->right = new TreeNode(7); 
  
    cout << "Vertical Sums are\n"; 
    verticalSummain(root); 
    return 0; 
}
