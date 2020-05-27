//time complexity O(n+klogn) O(n) for building heap and extractMin is calles k times (each take logn ) therefore (O(n+klogn)
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
class Heap{
	int *arr;
	int heap_size;
	int capacity;
	public:
	Heap(int c){
		capacity=c;
		arr=new int[c];
		heap_size=0;
	}
	int left(int index){
		return 2*index+1;
	}
	int right(int index){
		return 2*index+2;
	}
	int parent(int index){
		return (index-1)/2;
	}
	int getMin(){
		return arr[0];
	}
	int extractMin(){
		if(heap_size==0){
			return INT_MAX;
		}
		if(heap_size==1){
			int root=arr[0];
			heap_size--;
			return root;
		}
		int root=arr[0];
		swap(arr[0],arr[heap_size-1]);
		heap_size--;
		heapify(0);
		return root;
	}
	void heapify(int i){
		int smallest=i;
		int l=left(i);
		int r=right(i);
		if(l<heap_size and arr[l]<arr[smallest])
		smallest=l;
		if(r<heap_size and arr[r]<arr[smallest])
		smallest=r;
		if(smallest!=i){
			swap(arr[i],arr[smallest]);
			heapify(smallest);
		}
	}
	void buildHeap(int a[],int size){
		heap_size=size;
		arr=a;
		for(int i=(size-2)/2;i>=0;i--){
			heapify(i);
		}
	}
	int kthSmallest(int a[],int n,int k){
		buildHeap(a,n);
		for(int i=0;i<k-1;i++){
			extractMin();
		}
		return getMin();
	}
};
int main(){
	FAST
	 int arr[] = { 12, 3, 5, 7, 19 }; 
    int n = sizeof(arr) / sizeof(arr[0]), k = 2; 
    Heap myheap(n);
    cout << "K'th smallest element is " << myheap.kthSmallest(arr, n, k); 
    return 0; 
}
