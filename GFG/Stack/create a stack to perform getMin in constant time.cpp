//design a stack which supports find middle in constant time
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *prev;
		Node *next;
		Node(int d){
			data=d;
			prev=next=NULL;
		}
};
class Stack{
	int size;
	Node *head;
	Node *mid;
	public:
		Stack(){
			size=0;
			head=mid=NULL;
		}
		void push(int x){
			Node *newnode = new Node(x);
			//insert at first 
			newnode->next=head;
			if(head!=NULL){
				head->prev=newnode;
			}
			head=newnode;
			size++;
			if(size==1){
				mid=head;
				return;
			}
			else{
				if(size&1){
					mid=mid->prev;
				}
			}
		}
		int pop(){
			if(head==NULL){
				cout<<"Stack is empty\n";
				return INT_MAX;
			}
			Node *temp=head;
			head=head->next;
			head->prev=NULL;
			temp->next=NULL;
			free(temp);
			size--;
			if(size==0){
				mid=NULL;
			}
			else{
				if(size%2==0){
					mid=mid->next;
				}
			}
		}
		int getMid(){
			if(mid==NULL){
				cout<<"Stack is empty\n";
				return INT_MAX;
			}
			return mid->data;
		}
		void deleteMid(){
			if(size==0){
				cout<<"Stack is empty\n";
				return;
			}
			if(size==1){
				Node *temp=mid;
				mid=NULL;
				head=NULL;
				free(temp);
			}
			else{
				Node *temp=mid;
				size--;
				if(size%2==0){
					mid=mid->next;
				}
				else{
					mid=mid->prev;
				}
				if(temp->prev){
					temp->prev->next=temp->next;
				}
				if(temp->next){
					temp->next->prev=temp->prev;
				}
				free(temp);
			}
		}
		void printStack(){
			Node *temp=head;
			if(head==NULL){
				cout<<"Stack is empty\n";
			}
			while(temp){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		
		}
};
int main(){
	Stack st;
	
	st.push(10);
	cout<<st.getMid()<<endl; // 10
	st.printStack();
	cout<<endl;
	
	st.push(20);
	cout<<st.getMid()<<endl;
	st.printStack();
	cout<<endl;
	
	st.push(30);
	cout<<st.getMid()<<endl;
	st.printStack();
	cout<<endl;
	
	st.push(40);
	cout<<st.getMid()<<endl;
	st.printStack();
	cout<<endl;
	
	st.push(50);
	cout<<st.getMid()<<endl;
	st.printStack();
	cout<<endl;
	
	
	st.deleteMid();
	cout<<st.getMid()<<endl;
	st.printStack();
	cout<<endl;
	
	st.deleteMid();
	cout<<st.getMid()<<endl;
	st.printStack();
	cout<<endl;
	
	
	st.deleteMid();
	cout<<st.getMid()<<endl;
	st.printStack();
	cout<<endl;
	
	st.deleteMid();
	cout<<st.getMid()<<endl;
	st.printStack();
	cout<<endl;
	
	st.deleteMid();
	cout<<st.getMid()<<endl;
	st.printStack();
	cout<<endl;
}
