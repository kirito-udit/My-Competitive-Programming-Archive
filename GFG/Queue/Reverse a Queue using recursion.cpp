//reverse a queue using recursion
#include<bits/stdc++.h>
using namespace std;
void reverse(queue<int>&q){
	if(q.empty()){
		return;
	}
	else{
		int x=q.front();
		q.pop();
		
		reverse(q);
		
		q.push(x);
	}
}
void printQueue(queue<int>q){
	while(q.empty()==0){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}
int main(){
	queue<int>q;
	q.push(10);
	q.push(20);
	q.push(30);			
	q.push(40);	
	q.push(50);
	cout<<"Before reverse\n";
	printQueue(q);
	cout<<"After reverse\n";
	reverse(q);
	printQueue(q);
}
