//delete middle of a stack without using any additional data structure.
#include<bits/stdc++.h>
using namespace std;
void deleteMiddle(stack<int>&st,int n){
	static int count=0;
	if(count==n/2){
		st.pop();
		return;
	}
	else{
		int x=st.top();
		st.pop();
		count++;
		deleteMiddle(st,n);
		st.push(x);
	}
}
void printStack(stack<int> st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}
int main(){
	stack<int>st;
	st.push(6);
	st.push(5);
	st.push(4);
	st.push(3);
	st.push(2);
	st.push(1);
	printStack(st);
	deleteMiddle(st,st.size()-1);
	printStack(st);
}
