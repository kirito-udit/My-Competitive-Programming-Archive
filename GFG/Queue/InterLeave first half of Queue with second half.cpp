//interleave elements of queue
//1.reverse the first half of queue
//2.push them into the stack
//3.now push stack top element at the end of the queue and now push queue front element at the end of the queue
#include<bits/stdc++.h>
using namespace std;
void printQueue(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}
void reverseUtil(queue<int>&q,int k){
	if(q.empty()or k<=0){
		return;
	}
	else{
		int x=q.front();
		q.pop();
		reverseUtil(q,k-1);
		q.push(x);
	}
}
void reverse(queue<int>&q,int k){
	reverseUtil(q,k);
	for(int i=0;i<q.size()-k;i++){
		int x=q.front();
		q.pop();
		q.push(x);
	}

}

void interLeave(queue<int>&q){
	//reverse first half
	int n=q.size();
	reverse(q,n/2);
	//now since stack is allowed 
	//create a stack
	stack<int>st;
	//push first half elements into the stack
	for(int i=0;i<n/2;i++){
		st.push(q.front());
		q.pop();
	}
	//one by one pop fromt stack push to queue then pop from queue push to queue
	for(int i=0;i<n/2;i++){
		int x=st.top();
		st.pop();
		q.push(x);
		x=q.front();
		q.pop();
		q.push(x);
	
	}
}

int main(){
	cout<<"Enter number of elements\n";
	int n;
	cin>>n;
	queue<int>q;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		q.push(x);
	}
	cout<<"Queue before interleave\n";
	printQueue(q);
	cout<<"Queue after interleave\n";
	interLeave(q);
	printQueue(q);
}
