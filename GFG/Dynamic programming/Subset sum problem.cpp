#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define testcase() int t;cin>>t; while(t--)
int fun(int arr[],int n,int sum){
	int dp[n+1][sum+1];
	
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	
	for(int i=1;i<=sum;i++){
		dp[0][i]=0;
	}
	//outer is loop is for size 1 to n
	for(int i=1;i<=n;i++){
		//inner loop is for sum 1 to sum
		for(int j=1;j<=sum;j++){
			//sum is less than arr[size-1] exclude it
			if(j<arr[i-1]){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
			}
		}
	}
	
	return dp[n][sum];
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
	int ok = fun(a,n,sum);
	if(ok){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}
int main(){
	FAST
	testcase(){
		solve();
	}
}
