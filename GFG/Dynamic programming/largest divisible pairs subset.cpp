//largest divisible pair subset
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//int fun(int a[],int n,int index,int large){
//	if(index>=n){
//		return 0;
//	}
//	if(a[index]%large==0){
//		return max(fun(a,n,index+1,a[index])+1,fun(a,n,index+1,large));
//	}
//	return fun(a,n,index+1,large);
//}
int fun(int a[],int n){
	int dp[n]={0};//store length of req subset at every index
	
	dp[n-1]=1;
	for(int i=n-2;i>=0;i--){
		int maxx=0;
		
		for(int j=i+1;j<n;j++){
			if(a[j]%a[i]==0){
				maxx=max(maxx,dp[j]);
			}
		}
		
		dp[i]=1+maxx;
	}
	
	return *max_element(dp,dp+n);
}
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cout<<fun(arr,n)<<endl;
	
}
int main(){
	FAST
	solve();
}
