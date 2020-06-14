//implement queue suing stack 
//push O(n) and pop O(1)
#include<bits/stdc++.h>
using namespace std;
class Queue{
	stack <int> st1,st2;
	public:
		void enQueue(int x);
		int deQueue();
};
//push an item in the queue we want first element pushed at the top of the stack
void Queue::enQueue(int x){
	//empty stack 1 into stack 2
	while(st1.empty()==false){
		st2.push(st1.top());
		st1.pop();
	}
	st1.push(x);
	//again empty stack 2 into stack 1
	while(!st2.empty()){
		st1.push(st2.top());
		st2.pop();
	}
}
int Queue::deQueue(){
	if(st1.empty()){
		cout<<"Queue is empty\n";
		return INT_MAX;
	}
	int x= st1.top();
	st1.pop();
	return x;
}
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
