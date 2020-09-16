#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int x): data{x},next{NULL}{
	}
};
Node *newNode(int x){
	return new Node(x);
}
void push(Node *&head,int x){
	Node *newnode = newNode(x);
	newnode->next = head;
	head = newnode;
}
void printList(Node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}
void reverseLinkedList(Node *&head){
	Node *prev=NULL,*curr=head,*next=NULL;
	
	while(curr!=NULL){
		next = curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	
	head = prev;
}
int main(){
	Node *head = NULL;
	push(head,5);
	push(head,4);
	push(head,3);
	push(head,2);
	push(head,1);
	//1-2-3-4-5-NULL
	
	printList(head);
	
	reverseLinkedList(head);
	
	printList(head);
	
}
