//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/mandee-and-his-girlfriend-9a96aabd/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
};
Node *newNode(int key){
    Node *temp=new Node();
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
void insert(Node *&root,int val){
    if(root==NULL){
        root=newNode(val);
        return;
    }
    else if(root->data>val){
        insert(root->left,val);
    }
    else if(root->data<val){
        insert(root->right,val);
    }
    return;
}
int lower_bound(Node *root,int val){
    if(root==NULL){
        return -1;
    }
    if(root->data==val){
        return root->data;
    }
    if(root->data<val){
        return lower_bound(root->right,val);
    }

    int x=lower_bound(root->left,val);
    if(x>=val){
        return x;
    }
    else{
        return root->data;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    Node *root=NULL;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x==1){
            insert(root,y);
        }
        else{
            cout<<lower_bound(root,y)<<endl;
        }
    }
}
