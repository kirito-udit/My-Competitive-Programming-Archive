#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n){
	unordered_map<int,int>mp;
	vector<int>index;
	for(int i=0;i<n;i++){
		if(mp[arr[i]]==0){
			index.push_back(arr[i]);
		}
		mp[arr[i]]++;
	}
	
	int k=0;
	for(int x:index){
		int times=mp[x];
		while(times--){
			arr[k]=x;
			k++;
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	solve(arr,n);
}
