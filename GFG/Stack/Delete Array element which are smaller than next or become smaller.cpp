//delete array element which are smaller than next or become smaller
#include<bits/stdc++.h>
using namespace std;
void domyjob(stack<int>&st,int k){
	if(st.empty()){
		return;
	}
	stack<int>temp;
	temp.push(st.top());
	st.pop();
	while(k and !st.empty()){
		while(k and !temp.empty() and temp.top()<st.top()){
			temp.pop();
			k--;
		}
		if(k<=0){
			break;
		}
		else{
			temp.push(st.top());
			st.pop();
		}
	}
}
void printStack(stack<int>st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	stack<int>st;
	for(int i=n-1;i>=0;i--){
		st.push(arr[i]);
	}
	printStack(st);
	domyjob(st,k);
	printStack(st);
}
