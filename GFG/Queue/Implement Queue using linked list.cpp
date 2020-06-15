//implement a queue using linked list
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int x){
			data=x;
			next=NULL;
		}
};
class Queue{
	Node *front,*rear;
	public:
		Queue(){
			front=rear=NULL;
		}
		void enQueue(int x){
			Node *newnode = new Node(x);
			if(rear==NULL){
				rear=newnode;
				front=rear;
			}
			else{
				rear->next=newnode;
				rear=newnode;
			}
		}
		int deQueue(){
			if(front==NULL){
				cout<<"Queue is empty\n";
				return INT_MIN;
			}
			int y=front->data;
			Node *temp=front;
			front=front->next;
			if(front==NULL){
				rear=NULL;
			}
			free(temp);
			return y;
		}
};
int main(){
	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.enQueue(30);
	
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	
	cout<<q.deQueue()<<endl;
}
