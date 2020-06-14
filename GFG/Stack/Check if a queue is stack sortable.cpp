//check if a queue is stack sortable
#include<bits/stdc++.h>
using namespace std;
bool check(queue<int>q,int n){
	if(q.empty() or q.size()==1){
		return true;
	}
	stack<int>st;
	int next=1;
	while(next<=n){
		if(q.empty()==false and next==q.front()){
			q.pop();
			next++;
		}
		else if(st.empty()==false and next==st.top()){
			st.pop();
			next++;
		}
		else if(q.empty()==false){
			
				if(st.empty()){
					st.push(q.front());
					q.pop();
				}
				else if(st.top()>q.front()){
					st.push(q.front());
					q.pop();
				}
				else{
					return false;
				}
			
		}
		else{
			return false;
		}
	}
	return true;
}
int main(){
	queue<int>q;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		q.push(x);
	}
	if(check(q,n)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}
