//implement deque using circlar linkes list
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int d){
			data=d;
			next=NULL;
		}
};
class DeQueue{
	Node *tail=NULL;
	public:
		DeQueue(){
			tail=NULL;
		}
		void insertFront(int d){
			Node *newnode = new Node(d);
			//list is empty
			if(tail==NULL){
				tail=newnode;
				newnode->next=tail;
			}
			else{
				newnode->next=tail->next;
				tail->next=newnode;
			}
		}
		void insertRear(int d){
			Node *newnode = new Node(d);
			//list is empty
			if(tail==NULL){
				tail=newnode;
				newnode->next=tail;
			}
			else{
				Node *head=tail->next;
				tail->next=newnode;
				newnode->next=head;
				tail=newnode;
			}
		}
		
		void deleteFront(){
			if(tail==NULL){
				cout<<"list is empty\n";
				return;
			}
			else if(tail->next==tail){
				Node *temp=tail;
				tail->next=NULL;
				tail=NULL;
				delete(temp);
			}
			else{
				Node *temp=tail->next;//get front element
				tail->next=temp->next;
				temp->next=NULL;
				delete(temp);
			}
		}
		
		void deleteRear(){
			if(tail==NULL){
				cout<<"List is empty\n";
				return;
			}
			else if(tail->next==tail){
				Node *temp=tail;
				tail->next=NULL;
				tail=NULL;
				delete(temp);
			}
			else{
				Node *head=tail->next;
				while(head->next!=tail){//move to second last node
					head=head->next;
				}
				Node *temp=tail;
				head->next=tail->next;
				tail->next=NULL;
				tail=head;
				delete(temp);
			}
		}
		
		bool isEmpty(){
			if(tail==NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		int getFront(){
			if(tail==NULL){
				cout<<"No front, list is empty\n";
				return INT_MIN;
			}
			else{
				return tail->next->data;
			}
		}
		
		int getRear(){
			if(tail==NULL){
				cout<<"No rear, list is empty\n";
				return INT_MIN;
			}
			else{
				return tail->data;
			}
		}
};
int main(){
	DeQueue dq;
	if(dq.isEmpty()){
		cout<<"List is empty\n";
	}
	else{
		cout<<"list is not empty\n";
	}
	dq.insertFront(10);
	cout<<dq.getFront()<<endl; //10
	cout<<dq.getRear()<<endl; //10
	
	dq.insertRear(20);
	
	cout<<dq.getFront()<<endl;//10
	cout<<dq.getRear()<<endl;//20
	
	dq.insertFront(30);
	dq.insertRear(40);
	cout<<dq.getFront()<<endl;//30
	cout<<dq.getRear()<<endl; //40
	
	dq.deleteFront();
	cout<<dq.getFront()<<endl;//10
	dq.deleteRear();
	cout<<dq.getRear()<<endl;//20
	
	dq.deleteRear();
	cout<<dq.getFront()<<endl;//10
	cout<<dq.getRear()<<endl;//10
	
	dq.deleteFront();
	cout<<dq.getFront()<<endl;//no front list is empty
	
}


