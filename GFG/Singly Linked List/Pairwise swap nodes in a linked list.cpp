//pairwise swap elements of given linked list
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
void swapNodes(Node *&head,Node *X,Node *Y){
	Node *prevX=NULL ,*nodeX=head,*prevY = NULL,*nodeY=head;
	while(nodeX && nodeX!=X){
		prevX = nodeX;
		nodeX = nodeX->next;
	}
	while(nodeY && nodeY!=Y){
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
void pairWiseSwapNodes(Node *&head){
	Node *temp = head;
	while(temp && temp->next){
		swapNodes(head,temp,temp->next);
		temp=temp->next;
	}
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
	
	pairWiseSwapNodes(head);
	
	printList(head);
}

