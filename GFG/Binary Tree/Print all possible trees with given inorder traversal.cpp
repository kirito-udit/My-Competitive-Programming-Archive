//print all possible trees with given inorder traversal
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
void preOrder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
vector<Node*> getTrees(int inorder[],int start,int end){
	
	vector<Node*>trees;
	if(start>end){
		trees.push_back(NULL);
		return trees;
	}
	
	for(int i=start;i<=end;i++){
		vector<Node*>ltrees=getTrees(inorder,start,i-1);
		vector<Node*>rtrees=getTrees(inorder,i+1,end);
		
		for(int j=0;j<ltrees.size();j++){
			for(int k=0;k<rtrees.size();k++){
				Node *root=new Node(inorder[i]);
				root->left=ltrees[j];
				root->right=rtrees[k];
				trees.push_back(root);
			}
		}
	}
	
	return trees;
}
int main(){
	int inorder[]={4,5,7};
	int n=3;
	vector<Node*>trees=getTrees(inorder,0,n-1);
	
	
	cout<<"All preordeers are\n";
	for(int i=0;i<trees.size();i++){
		preOrder(trees[i]);
		cout<<endl;
	}
	return 0;
}
