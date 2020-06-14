//sort a stack using another temporary stack
#include<bits/stdc++.h>
using namespace std;
stack<int> sort(stack<int>&st){
	stack<int>temp;
	while(!st.empty()){
		int x=st.top();
		st.pop();
		while(!temp.empty() and temp.top()<x){
			st.push(temp.top());
			temp.pop();
		} 
		temp.push(x);
	}
	return temp;
}
void printStack(stack<int>st){
	while(st.empty()==0){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}
int main(){
	stack<int>st;
	st.push(8);
	st.push(2);
	st.push(4);
	st.push(1);
	st.push(5);
	st.push(3);	
	printStack(st);
	st=sort(st);
	printStack(st);
}
