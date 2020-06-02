//subset sum problem using O(sum) space
#include<bits/stdc++.h>
using namespace std;
#define testcase() int t;cin>>t;while(t--)
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int fun(int arr[],int n,int sum){
	int dp[2][sum+1];
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(j==0){
				dp[i%2][j]=1;
			}
			else if(i==0){
				dp[i%2][j]=0;
			}
			
			else if(arr[i-1]>j){
				dp[i%2][j]=dp[(i+1)%2][j];
			}
			else{
				dp[i%2][j]=dp[(i+1)%2][j] or dp[(i+1)%2][(j-arr[i-1])];
			}
		}
	}
	
	return dp[n%2][sum];
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
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}
int main(){
	FAST
	testcase(){
		solve();
	}
}
