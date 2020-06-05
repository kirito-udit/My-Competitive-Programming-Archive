//path with maximum average value https://www.geeksforgeeks.org/path-maximum-average-value/
//since we can only move right and bottom to reach last cell we have to cover at most 2*n-1 cells therefore denominator is fixed
//and we need to maximize only numerator i.e sum
//let dp[i[[j] representts max sum till ith row and jth col
//dp[i][j]=max(dp[i-1][j],dp[i][j-1])+costs[i][j]
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define testcase() int t; cin>>t; while(t--)
#define MAX 10
double fun(int mat[][MAX],int n){
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	dp[0][0]=mat[0][0];
	for(int i=1;i<n;i++){
		dp[i][0]=dp[i-1][0]+mat[i][0];
	}
	for(int j=1;j<n;j++){
		dp[0][j]=dp[0][j-1]+mat[0][j];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+mat[i][j];
		}
	}
	
	return (double)(dp[n-1][n-1])/(2*n-1);
}
void solve(){
	int n;
	cin>>n;
	int mat[n][MAX];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	cout<<fun(mat,n)<<endl;
}
int main(){
	testcase(){
		solve();
	}
}
