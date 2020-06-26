#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
int mat[MAX][MAX];
class Node{
	public:
		int data;
		Node *left,*right;
		Node(int x){
			data=x;
			left=right=NULL;
		}
};
int ancestorRec(Node *root,vector<int>&anc){
	//return size of tree is 0
	if(root==NULL){
		return 0;
	}
	
	//process root left right
	int data=root->data;
	//process all the ancestor of current node
	for(int i=0;i<anc.size();i++){
		mat[anc[i]][data]=1;//that means anc[i] is ancestor of current node
	}
	
	//push this node in ancestor array
	anc.push_back(data);
	
	int l=ancestorRec(root->left,anc);
	int r=ancestorRec(root->right,anc);
	//remove the data since all the descendents of it are processed now
	anc.pop_back();
	return l+r+1; //return the size of ancestor array
}
void ancestorMatrix(Node *root){
	vector<int>anc;
	
	int n=ancestorRec(root,anc);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	Node *root=new Node(5);
	root->left=new Node(1);
	root->right=new Node(2);
	root->left->left=new Node(0);
	root->left->right=new Node(4);
	root->right->left=new Node(3);
	
	ancestorMatrix(root);
}
