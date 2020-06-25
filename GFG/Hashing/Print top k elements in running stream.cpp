#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n,int k){
	vector<int>top(k+1);
	
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
		
		top[k]=arr[i];
		
		auto it = find(top.begin(),top.end()-1,arr[i]);
		
		for(int i=distance(top.begin(),it)-1;i>=0;i--){
			if(mp[top[i]]<mp[top[i+1]]){
				swap(top[i],top[i+1]);
			}
			else if(mp[top[i]]==mp[top[i+1]] and top[i]>top[i+1]){
				swap(top[i],top[i+1]);
			}
			else{
				break;
			}
		}
		
		for(int i=0;i<k and top[i]!=0;i++){
			cout<<top[i]<<" ";
		}
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	solve(arr,n,k);
}
