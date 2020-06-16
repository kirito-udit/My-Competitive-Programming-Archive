//sort a queue without using extra space
#include<bits/stdc++.h>
using namespace std;
int minIndex(queue<int>&q , int sortedIndex){
	int min_val=INT_MAX;
	int min_index=-1;
	int n=q.size();
	for(int i=0;i<n;i++){
		int curr=q.front();
		q.pop();
		//elements after sortedIndex are already sorted so we find rightmost minindex
		if(curr<=min_val and i<=sortedIndex){
			min_index=i;
			min_val=curr;
		}
		q.push(curr);
	}
	return min_index;
}
//moves given minimum element to the rear of the queue
void insertMinToRear(queue<int>&q , int min_index){
	int min_val;
	int n=q.size();
	for(int i=0;i<n;i++){
		int curr=q.front();
		q.pop();
		if(i!=min_index){
			q.push(curr);
		}
		else{
			min_val=curr;
		}
	}
	q.push(min_val);
} 
void sortQueue(queue<int>&q){
	for(int i=1;i<=q.size();i++){
		int min_index=minIndex(q,q.size()-i);
		insertMinToRear(q,min_index);
	}
}
int main() 
{ 
  queue<int> q; 
  q.push(30); 
  q.push(11); 
  q.push(15); 
  q.push(4); 
    
  // Sort queue 
  sortQueue(q); 
    
  // Print sorted queue 
  while (q.empty() == false) 
  { 
     cout << q.front() << " "; 
     q.pop(); 
  } 
  cout << endl; 
  return 0; 
} 
