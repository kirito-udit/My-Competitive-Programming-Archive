//basic strategy here is to build a max heap from starting k elements of array.(O(k))
//after that compare next n-k elements one by one from root(max of heap) array
//if the root is smallet then its ok otherwise swap them and heapify them (O(n-k)log(n))
//overall time complexity is (O(k)+(O(n-k)logn)

#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcase() int t; cin>>t; while(t--)
class Heap{
	int *arr;
	int heap_size;
	int capacity;
	public:
		//default constructor
		Heap(int c){
			capacity=c;
			arr=new int[c];
			heap_size=0;
		}
		//left right and parent
		int left(int i){
			return 2*i+1;
		}
		int right(int i){
			return 2*i+2;
		}
		int parent(int i){
			return (i-1)/2;
		}
		void heapify(int i){
			int large=i;
			int l=left(i);
			int r=right(i);
			if(l<heap_size and arr[l]>arr[large]){
				large=l;
			}
			if(r<heap_size and arr[r]>arr[large]){
				large=r;
			}
			if(large!=i){
				swap(arr[i],arr[large]);
				heapify(large);
			}
		}
		void buildHeap(int a[],int n){
			arr=a;
			heap_size=n;
			for(int i=(n-1)/2;i>=0;i--){
				heapify(i);
			}
		}
		int kthSmallest(int a[],int n,int k){
			buildHeap(a,k);
			for(int i=k;i<n;i++){
				if(arr[0]>a[i]){
					swap(arr[0],a[i]);
					heapify(0);
				}
			}
			return arr[0];
		}
};
int main(){
	FAST
	testcase(){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int k;
		cin>>k;
		Heap myheap(n);
		cout<<myheap.kthSmallest(a,n,k)<<endl;
	}
}
