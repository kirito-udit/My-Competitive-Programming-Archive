//implementation of deque using circular array
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
class Deque{
	int arr[MAX];
	int front;
	int rear;
	int size;
	public:
		Deque(int s){
			front = -1;
			rear = 0;
			size = s;
		}
		void insertfront(int key);
		void insertrear(int key);
		void deletefront();
		void deleterear();
		bool isFull();
		bool isEmpty();
		int getFront();
		int getRear();
};
void Deque::insertrear(int key){
	//if deque is full or not
	if(isFull()){
		cout<<"Deque is full\n";
		return;
	}
	if(front==-1){
		//queue is empty
		front = 0;
		rear = 0;
	}
	else if(rear==size-1){
		rear=0;
	}
	else{
		rear = rear+1;
	}
	arr[rear]=key;
}
void Deque::insertfront(int key){
	if(isFull()){
		cout<<"Deque is Full\n";
		return;
	}
	
	if(front==-1){
		front = 0;
		rear = 0;
	}
	else if(front==0){
		front = size-1;
	}
	else{
		front = front - 1;
	}
	
	arr[front]=key;
}
void Deque::deletefront(){
	if(isEmpty()){
		cout<<"Deque is empty\n";
		return;
	}
	if(front==rear){
		front=rear=-1;
	}
	else if(front==size-1){
		front=0;
	}
	else{
		front = front+1;
	}
}
void Deque::deleterear(){
	if(isEmpty()){
		cout<<"Deque is empty\n";
		return;
	}
	if(front==rear){
		front=rear=-1;
	}
	else if(rear==0){
		rear = size-1;
	}
	else{
		rear = rear-1;
	}
}
int Deque::getFront(){
	if(isEmpty()){
		cout<<"Deque is empty\n";
		return INT_MAX;
	}
	return arr[front];
}
int Deque::getRear(){
	if(isEmpty()){
		cout<<"Deque is empty\n";
		return INT_MAX;
	}
	return arr[rear];
}
bool Deque::isEmpty(){
	return front==-1;
}
bool Deque::isFull(){
	return (front==0 && rear==size-1) || (front==rear+1);
}
int main(){
	Deque dq(5);
	cout<<dq.isEmpty()<<endl;//1
	cout<<dq.isFull()<<endl;//0;
	
	dq.insertfront(10);
	dq.insertrear(20);
	
	cout<<dq.getFront()<<endl;//10
	cout<<dq.getRear()<<endl;//20
	
	dq.insertfront(30);
	dq.insertrear(40);
	
	cout<<dq.getFront()<<endl;//30
	cout<<dq.getRear()<<endl; //40
	
	dq.insertfront(50);
	
	dq.insertfront(60);//full
	
	cout<<dq.isFull()<<endl;//1
	
	cout<<dq.getFront()<<endl;//50
	cout<<dq.getRear()<<endl;//40
	
	dq.deletefront();
	dq.deletefront();
	
	cout<<dq.getFront()<<endl;//10
	
	dq.deleterear();
	dq.deleterear();
	
	cout<<dq.getRear()<<endl;//10
	
	dq.deletefront();
	
	cout<<dq.getFront()<<endl;//empty
	
	cout<<dq.isEmpty()<<endl;//true
	
}
