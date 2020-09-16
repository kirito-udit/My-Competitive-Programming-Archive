#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int x) : data{x},next{NULL}{
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
	cout<<'\n';
}
Node *sortedIntersect(Node *a,Node *b){
	if(a==NULL || b==NULL){
		return NULL;
	}
	
	if(a->data<b->data){
		return sortedIntersect(a->next,b);
	}
	if(a->data>b->data){
		return sortedIntersect(a,b->next);
	}
	
	Node *temp = newNode(a->data);
	temp->next = sortedIntersect(a->next,b->next);
	
	return temp;
}
int main(){
	Node *head1=NULL;
	push(head1,6);
	push(head1,5);
	push(head1,4);
	push(head1,3);
	push(head1,2);
	push(head1,1);
	
	//1->2->3->4->5->6;
	printList(head1);
	
	Node *head2=NULL;
	push(head2,8);
	push(head2,6);
	push(head2,4);
	push(head2,2);
	
	//2->4->6->8;
	
	printList(head2);
	
	Node *intersect = sortedIntersect(head1,head2);
	
	printList(intersect);
	
}
