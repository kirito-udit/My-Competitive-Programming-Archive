#include<bits/stdc++.h>
using namespace std;
void solve(int n){
	int dp[n+1][10];
	memset(dp,0,sizeof(dp));
	for(int j=9;j>=1;j--){
		dp[1][j]=10-j;
	}
	for(int i=2;i<=n;i++){
		for(int j=8;j>=1;j--){
			dp[i][j]=dp[i][j+1]+dp[i-1][j+1];
		}
	}
	cout<<dp[n][1];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve(n);
	}
}
