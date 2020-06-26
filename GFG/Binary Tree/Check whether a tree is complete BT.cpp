//check whether a BT is complete or not
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
bool isCompleteBT(Node *root){
	if(root==NULL){
		return true;
	}
	
	queue<Node*>q;
	q.push(root);
	
	bool flag=false;
	
	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		
		
		if(temp->left){
			if(flag==true){
				return false;
			}
			q.push(temp->left);
		}
		else{
			flag=true;
		}
		
		if(temp->right){
			if(flag==true){
				return false;
			}
			q.push(temp->right);
		}
		else{
			flag=true;
		}
	}
	return true;
}

int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
//	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	
	if(isCompleteBT(root)){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}
