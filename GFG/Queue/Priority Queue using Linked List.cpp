//implement priority queue using linked list
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		int priority;
		Node *next;
		Node(int d,int p){
			data=d;
			priority = p;
			next=NULL;
		}
};
class PQ{
	Node *head;
	public:
		PQ(){
			head = NULL;
		}
		int top(){
			if(head==NULL){
				cout<<"Priority Queue is empty\n";
				return -1;
			}
			return head->data;
		}
		void pop(){
			if(head==NULL){
				cout<<"Priority Queue is empty\n";
				return;
			}
			Node *temp = head;
			head = head->next;
			temp->next=NULL;
			free(temp);
			return;
		}
		
		void push(int d,int p){
			//higher priority top
			Node *newnode = new Node(d,p);
			if(head==NULL){
				head = newnode;
				return;
			}
			else{
				if(head->priority<p){
					newnode->next=head;
					head = newnode;
					return;
				}
				else{
					Node *temp = head;
					Node *prev = temp;
					while(temp && temp->priority>p){
						prev = temp;
						temp = temp->next;
					}
					if(temp==NULL){
						//current node has lowest priority
						//insert at last
						prev->next=newnode;
					}
					else{
						prev->next=newnode;
						newnode->next=temp;
						return;
					}
				}
			}
		}
		
		void display(){
			Node *temp = head;
			while(temp){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};
int main(){
	PQ pq;
	pq.push(10,2);
	cout<<pq.top()<<endl;//10
	
	pq.push(20,1);
	cout<<pq.top()<<endl;//10
	
	pq.push(5,5);
	cout<<pq.top()<<endl;//5
	
	
	pq.push(1,10);
	
	pq.display();
	
	pq.pop();
	
	pq.pop();
	
	pq.display();
	
	pq.pop();
	pq.pop();
	
	cout<<pq.top()<<endl;
	pq.display();
	
}
