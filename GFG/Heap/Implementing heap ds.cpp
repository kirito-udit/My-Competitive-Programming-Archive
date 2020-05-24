//implementiing heap data strucure 
//since heap is a complete binary tree it can be implementes using array efficiently
#include<bits/stdc++.h>
using namespace std;

class MinHeap{
	private:
	int *harr; // pointer to array
	int capacity; //max size of heap
	int heap_size; //current number of elements in heap
	
	public:
		//constructor 
		MinHeap(int capacity);
		
		void MinHeapify(int index);
		
		int parent(int i){
			return (i-1)/2;
		}
		
		int left(int i){
			return 2*i+1;
		}
		
		int right(int i){
			return 2*i+2;
		}
		
		int extractMin(); // to extractt the root which is the minimun element
		
		void decreaseKey(int i,int new_val); //decreases key value of key at index i to new_val
		
		int getMin(){
			return harr[0];
		}
		//insert a key wiht value k
		void insertKey(int k);
		//delete key stored at index i
		void deleteKey(int i);
};
MinHeap::MinHeap(int cap){
	capacity=cap;
	heap_size=0;
	harr=new int[capacity];
}
void MinHeap::insertKey(int k){
	if(heap_size==capacity){
		cout<<"heap overflow\n";
		return;
	}
	//first insert the new key at the end
	heap_size++; // increamenting size by 1
	int ind=heap_size-1; // last index
	harr[ind]=k;
	
	//fix the min heap property
	while(ind!=0 and harr[parent(ind)]>harr[ind]){
		swap(harr[ind],harr[parent(ind)]);
		ind=parent(ind);
	}
}
void MinHeap::decreaseKey(int i,int new_val){
	harr[i]=new_val;
	while(i!=0 and harr[parent(i)]>harr[i]){
		swap(harr[i],harr[parent(i)]);
		i=parent(i);
	}
}
int MinHeap::extractMin(){
	if(heap_size<=0){
		return INT_MAX;
	}
	if(heap_size==1){
		heap_size--;
		return harr[0];
	}
	int root=harr[0];
	harr[0]=harr[heap_size-1];
	heap_size--;
	MinHeapify(0);
	
	return root;
}
void MinHeap::deleteKey(int i){
	//change given index key to INT_MIN
	decreaseKey(i,INT_MIN);
	extractMin();
}
void MinHeap::MinHeapify(int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l<heap_size and harr[l]<harr[i]){
		smallest=l;
	}
	if(l<heap_size and harr[r]<harr[smallest]){
		smallest=r;
	}
	if(smallest!=i){
		swap(harr[i],harr[smallest]);
		MinHeapify(smallest);
	}
}
int main() 
{ 
    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 
} 
