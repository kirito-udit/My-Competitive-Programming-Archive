//print all subsets with given sum
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define testcase() int t;cin>>t; while(t--)
#define MOD 1000000007
//int fun(int arr[],int n,int sum){
//	if(sum==0 and n!=0){
//		return 1;
//	}
//	if(n==0 or sum<0){
//		return 0;
//	}
//	else{
//		return (fun(arr,n-1,sum)%MOD+fun(arr,n-1,sum-arr[n-1])%MOD)%MOD;
//	}
//}
int fun(int arr[],int n,int sum){
	int dp[n+1][sum+1];
	
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=sum;i++){
		dp[0][i]=0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i-1]>j){
				dp[i][j]=dp[i-1][j]%MOD;
			}
			else{
				dp[i][j]=(dp[i-1][j]%MOD + dp[i-1][j-arr[i-1]]%MOD)%MOD;
			}
		}
	}
	return dp[n][sum]%MOD;
}
void solve(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum;
	cin>>sum;
	cout<<fun(a,n,sum)%MOD<<endl;
}
int main(){
	FAST
	testcase(){
		solve();
	}
}
