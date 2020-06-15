//implement queue using one stack
#include<bits/stdc++.h>
using namespace std;
class Queue{
	stack<int>st;
	public:
		void enQueue(int x){
			st.push(x);
		}
		int deQueue(){
			if(st.empty()){
				cout<<"Queue is empty\n";
				return INT_MIN;
			}
			if(st.size()==1){
				int y=st.top();
				st.pop();
				return y; 
			}
			else{
				int x=st.top();
				st.pop();
				int item=deQueue();
				st.push(x);
				return item;
			}
		}
};
int main(){
 	 Queue q;
 	 q.enQueue(10);
 	 q.enQueue(20);
 	 q.enQueue(30);
 	 
 	 cout<<q.deQueue()<<endl;
 	cout<<q.deQueue()<<endl;
 	   cout<<q.deQueue()<<endl;
 	   
 	    cout<<q.deQueue()<<endl;
 	 
}
