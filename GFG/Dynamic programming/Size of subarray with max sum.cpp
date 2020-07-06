#include<bits/stdc++.h>
using namespace std;
int fun(int arr[],int n){
	int max_so_far=INT_MIN,max_ending_here=0;
	int start=0,end=0,s=0;
	for(int i=0;i<n;i++){
		max_ending_here+=arr[i];
		if(max_so_far<max_ending_here){
			max_so_far=max_ending_here;
			start=s;
			end=i;
		}
		if(max_ending_here<0){
			max_ending_here=0;
			s=i+1;
		}
	}
	return end-start+1;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<fun(arr,n)<<endl;
}
