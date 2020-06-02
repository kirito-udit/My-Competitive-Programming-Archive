#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcase() int t;cin>>t;while(t--)
typedef long long int ll;
#define MOD 1000000007
#define MAX 100
ll dp[MAX]={0};
void init(){
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=MAX;i++){
		dp[i]=(dp[i-1]%MOD + ((i-1)%MOD*(dp[i-2]%MOD))%MOD)%MOD;
	}
}
ll friends(ll n){
	return dp[n];
}
void solve(){
	int n;
	cin>>n;
	cout<<friends(n)<<endl;
}

int main(){
	FAST
	init();
	testcase(){
		solve();
	}
}
