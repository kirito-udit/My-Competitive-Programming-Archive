#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int x){
		data=x;
		next = NULL;
	}
};
Node *newNode(int x){
	return new Node(x);
}
void printList(Node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<'\n';
}
void push(Node *&head,int x){
	Node *newnode = newNode(x);
	newnode->next = head;
	head = newnode;
}
void swapNodes(Node *&head,int x,int y){
	Node *prevX=NULL ,*nodeX=head,*prevY = NULL,*nodeY=head;
	while(nodeX && nodeX->data!=x){
		prevX = nodeX;
		nodeX = nodeX->next;
	}
	while(nodeY && nodeY->data!=y){
		prevY = nodeY;
		nodeY = nodeY->next;
	}
	/*nodes not found*/
	if(nodeX==NULL or nodeY==NULL){
		cout<<"Nodes not found\n";
		return;
	}
	
	if(prevX!=NULL){
		prevX->next = nodeY;	
	}
	else{
		head = nodeY;
	}
	if(prevY!=NULL){
		prevY ->next = nodeX;
	}
	else{
		head = nodeX;
	}
	
	Node *temp = nodeY->next;
	nodeY->next=nodeX->next;
	nodeX->next=temp;
}
int main(){
	Node *head = NULL;
	push(head,14);
	push(head,12);
	push(head,13);
	push(head,20);
	push(head,15);
	push(head,10);
	//10->15->20->13->12->14
	
	printList(head);
	
	int x = 20, y = 13;
	swapNodes(head,x,y);
	
	printList(head);
}

