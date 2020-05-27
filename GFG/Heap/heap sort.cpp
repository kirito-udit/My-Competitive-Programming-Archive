#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n and a[left]>a[largest]){
		largest=left;
	}
	if(right<n and a[right]>a[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(a[largest],a[i]);
		heapify(a,n,largest);
	}
}
void heapsort(int arr[],int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	//one by one extract element and heapify remaining tree
	for(int i=n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int arr[]={10,9,8,7,6,5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	heapsort(arr,n);
	printArray(arr,n);
}
