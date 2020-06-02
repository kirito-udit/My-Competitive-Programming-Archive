//cut segments
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define testcase() int t; cin>>t; while(t--)
int fun(int n,int x,int y,int z){
	int dp[n+1]={0};
	int arr[3];
	arr[0]=x;
	arr[1]=y;
	arr[2]=z;
	sort(arr,arr+3);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int maxx=INT_MIN;
		for(int j=0;j<3;j++){
			if(arr[j]<=i){
				maxx=max(maxx,1+dp[i-arr[j]]);
			}
		}
		dp[i]=maxx;
	}
	cout<<dp[n]<<endl;
}
void solve(){
	int n;
	cin>>n;
	int x,y,z;
	cin>>x>>y>>z;
	fun(n,x,y,z);
}
int main(){
	testcase(){
		solve();
	}
}
