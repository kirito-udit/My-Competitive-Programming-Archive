//implement a stack using a single queue
#include<bits/stdc++.h>
using namespace std;
class Stack{
	queue<int>q;
	public:
		void push(int x){
			int size=q.size();
			q.push(x);
			for(int i=1;i<=size;i++){
				int x=q.front();
				q.pop();
				q.push(x);
			}
		}
		int pop(){
			if(q.empty()){
				cout<<"Queue is empty\n";
				return INT_MIN;
			}
			else{
				int x=q.front();
				q.pop();
				return x;
			}
		}
};
int main(){
	Stack st;
	st.push(10);
	st.push(20);
	st.push(30);
	
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	
	cout<<st.pop()<<endl;
}
