//implementation of dequeue using circular array
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
class Deque{
	int arr[MAX];
	int f;
	int r;
	int size;
	public:
		Deque(int s){
			f=-1;
			r=-1;
			size=s;
		}
		void insertFront(int x);
		void insertRear(int x);
		void deleteFront();
		void deleteRear();
		int getFront();
		int getRear();
		bool isEmpty();
		bool isFull();
};
bool Deque::isEmpty(){
	if(f==-1){
		return true;
	}
	else{
		return false;
	}
}
bool Deque::isFull(){
	if(f==0 and r==size-1 ){
		return true;
	}
	else if((r+1)==f){
		return true;
	}
	else{
		return false;
	}
}
int Deque::getFront(){
	if(isEmpty()){
		cout<<"Queue is empty\n";
		return INT_MAX;
	}
	else{
		return arr[f];
	}
}
int Deque::getRear(){
	if(isEmpty()){
		cout<<"Queue is empty\n";
		return INT_MAX;
	}
	else{
		return arr[r];
	}
}
void Deque::insertRear(int x){
	if(isFull()){
		cout<<"Can't insert Queue is full\n";
		return;
	}
	if(isEmpty()){
		f=0;
		r=0;
	}
	else if(r==size-1){
		r=0;
	}
	else{
		r=r+1;
	}
	arr[r]=x;
}
void Deque::deleteFront(){
	if(isEmpty()){
		cout<<"Can't delete Queue is empty\n";
		return;
	}
	if(f==r){
		f=-1;
		r=-1;
	}
	else if(f==size-1){
		f=0;
	}
	else{
		f=f+1;
	}
}
void Deque::deleteRear(){
	if(isEmpty()){
		cout<<"Can't delete Queue is empty\n";
		return;
	}
	if(f==r){
		f=-1;
		r=-1;
	}
	else if(r==0){
		r=size-1;
	}
	else{
		r=r-1;
	}
}
void Deque::insertFront(int x){
	if(isFull()){
		cout<<"Can't insert Queue is Full"<<endl;
		return;
	}
	if(f==-1 and r==-1){
		f=0;
		r=0;
	}
	else if(f==0){
		f=size-1;
	}
	else{
		f=f-1;
	}
	arr[f]=x;
}
int main(){
	Deque q(5);
	cout<<q.isEmpty()<<endl;
	
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.insertFront(2);
	q.insertRear(10);
	
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.insertFront(-1);
	q.insertRear(20);
	
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.insertFront(5);
	
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	cout<<q.isFull()<<endl;
	//these will cause overflow
	q.insertFront(3);
	q.insertRear(7);
	
	q.deleteFront();
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	//now it is ok
	q.insertFront(3);
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.deleteRear();
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.deleteRear();
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.deleteFront();
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.deleteFront();
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	q.deleteRear();
	
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	
	cout<<q.isEmpty()<<endl;
}
