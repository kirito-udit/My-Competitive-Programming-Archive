//implement queue using stacks
//making push O(1) and pop O(n)
#include<bits/stdc++.h>
using namespace std;
class Queue{
	stack<int>st1,st2;
	public:
		void enQueue(int x);
		int deQueue();
};
void Queue::enQueue(int x){
	st1.push(x);
}
int Queue::deQueue(){
	if(st1.empty() and st2.empty()){
		cout<<"queue is empty\n";
		return INT_MAX;
	}
	if(st2.empty()){
		while(st1.empty()==0){
			st2.push(st1.top());
			st1.pop();
		}
	}
	int x=st2.top(); st2.pop();
	return x;
}
int main(){
	Queue q;
	q.enQueue(10);
	q.enQueue(5);
	q.enQueue(15);
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
}
