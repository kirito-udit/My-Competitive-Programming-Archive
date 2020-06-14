//create stack to support getmin in O(1) space and O(1) time
#include<bits/stdc++.h>
using namespace std;
class Stack{
	stack<int>st;
	int minEle;
	public:
		void getMin(){
			if(st.empty()){
				cout<<"Stack is empty\n";
				return;
			}
			cout<<"Minimum element of stack is "<<minEle<<endl;
		}
		void push(int x){
			if(st.empty()){
				st.push(x);
				minEle=x;
				return;
			}
			if(x>=minEle){
				st.push(x);
			}
			else{
				st.push(2*x-minEle);
				minEle=x;
			}
		}
		int top(){
			if(st.empty()){
				cout<<"Stack is empty\n";
				return INT_MAX;
			}
			int x=st.top();
			if(x>=minEle){
				return x;
			}
			else{
				return minEle;
			}
		}
		void pop(){
			if(st.empty()){
				cout<<"Stack is empty\n";
				return;
			}
			int x=st.top();
			if(x>=minEle){
				st.pop();
			}
			else{
				minEle=2*minEle-x;
				st.pop();
			}
		}
};
int main(){
	Stack st;
	st.push(10);
	st.getMin();
	cout<<endl;
	
	st.push(20);
	st.getMin();
	cout<<endl;
	
	st.push(5);
	st.getMin();
	cout<<st.top()<<endl;
	cout<<endl;
	
	st.push(4);
	st.getMin();
	cout<<st.top()<<endl;
	cout<<endl;
	
	
	st.pop();
	st.getMin();
	cout<<st.top()<<endl;
	cout<<endl;
}
