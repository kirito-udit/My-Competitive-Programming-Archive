#include<bits/stdc++.h>
using namespace std;
void reverseUtil(queue<int>&q,int k){
	if(q.empty() or k==0){
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
void printQueue(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

int main(){
	queue<int>q;
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		q.push(x);
	}
	cout<<"Enter the value of k\n";
	int k;
	cin>>k;
	cout<<"Before reverse\n"<<endl;
	printQueue(q);
	cout<<"After reverse\n"<<endl;
	reverse(q,k);
	printQueue(q);
	
}
