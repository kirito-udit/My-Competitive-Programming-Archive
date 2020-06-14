#include<bits/stdc++.h>
using namespace std;
class kStacks{
	int *arr;
	int *top;
	int *next;
	int free=-1;
	int n,k;
	public:
		kStacks(int k1,int n1){
			k=k1,n=n1;
			arr=new int[n1];
			top=new int[k1];
			next=new int[n1];
			free=0;
			for(int i=0;i<k;i++){
				top[i]=-1;
			}
			for(int i=0;i<n-1;i++){
				next[i]=i+1;
			}
			next[n-1]=-1;
		}
		bool isFull(){
			return free==-1;
		}
		bool isEmpty(int sn){
			return top[sn]==-1;
		}
		void push(int sn,int item);
		int pop(int sn);
};
void kStacks::push(int item,int sn){
	if(isFull()){
		cout<<"Overflow\n";
		return;
	}
	int i=free;
	free=next[i];
	
	next[i]=top[sn];
	top[sn]=i;
	
	arr[i]=item;
}
int kStacks::pop(int sn){
	if(isEmpty(sn)){
		cout<<"Stack is empty\n";
		return INT_MAX;
	}
	
	int return_index=top[sn];
	
	top[sn]=next[return_index];
	
	next[return_index]=free;
	free=return_index;
	
	return arr[return_index];
}
int main(){
	// Let us create 3 stacks in an array of size 10 
    int k = 3, n = 10; 
    kStacks ks(k, n); 
  
    // Let us put some items in stack number 2 
    ks.push(15, 2); 
    ks.push(45, 2); 
  
    // Let us put some items in stack number 1 
    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1); 
  
    // Let us put some items in stack number 0 
    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0); 
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
  
    return 0; 
}
