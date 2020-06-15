//implement deque using doubly linked list
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *prev,*next;
		Node(int d){
			data=d;
			prev=next=NULL;
		}
};
class Deque{
	Node *front,*rear;
	int size;
	public:
		Deque(){
			front=rear=NULL;
			size=0;
		}
		bool isEmpty(){
			return front==NULL;
		}
		//no concept of is full;
		int getFront(){
			if(isEmpty()){
				cout<<"List is empty\n";
				return INT_MIN;
			}
			return front->data;
		}
		int getRear(){
			if(isEmpty()){
				cout<<"List is empty\n";
				return INT_MIN;
			}
			return rear->data;
		}
		void insertFront(int d){
			Node *newnode = new Node(d);
			if(front==NULL){
				newnode->next=front;
				front=rear=newnode;
			}
			else{
				front->prev=newnode;
				newnode->next=front;
				front=newnode;
			}
			size++;
		}
		void deleteFront(){
			if(isEmpty()){
				cout<<"List is empty\n";
				return;
			}
			size--;
			Node *temp=front;
			front=front->next;
			if(front==NULL){
				rear=NULL;
			}
			else{
				front->prev=NULL;
			}
			free(temp);
		}
		void insertRear(int d){
			Node *newnode = new Node(d);
			if(isEmpty()){
				front=rear=newnode;
			}
			else{
				rear->next=newnode;
				newnode->prev=rear;
				rear=newnode;
			}
			size++;
		}
		void deleteRear(){
			if(isEmpty()){
				cout<<"Queue is empty\n";
			}
			else{
				size--;
				Node *temp=rear;
				rear=rear->prev;
				if(rear==NULL){
					front=NULL;
				}
				else{
					rear->next=NULL;
				}
				temp->prev=temp->next=NULL;
				free(temp);
			}
		}
		int sizeQueue(){
			return size;
		}
		void erase(){
			Node *temp=front;
			Node *pre=NULL;
			while(temp){
				pre=temp;
				temp=temp->next;
				pre->prev=NULL;
				pre->next=NULL;
				free(pre);
			}
			front=NULL;
			rear=NULL;
		}
};
int main(){
	Deque q;
	cout<<q.isEmpty()<<endl;
	
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.insertFront(2);
	q.insertRear(3);
	
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.insertFront(-1);
	q.insertRear(4);
	
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.deleteFront();
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
}

