//max length chain of pairs https://practice.geeksforgeeks.org/problems/max-length-chain/1
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define testcase() int t;cin>>t;while(t--)
bool compare(const pair<int,int>&p1,const pair<int,int>&p2){
	return p1.first<p2.first;
}
vector<pair<int,int>> fun(vector<pair<int,int>>v,int n){
	int dp[n];
	sort(v.begin(),v.end(),compare);
	vector<vector<pair<int,int>>>ans(n);
	for(int i=0;i<n;i++){
		dp[i]=1;
		ans[i].push_back(v[i]);
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(v[j].second<v[i].first){
				if(dp[i]<dp[j]+1){
					dp[i]=dp[j]+1;
					vector<pair<int,int>>path(ans[j].begin(),ans[j].end());
					path.push_back(v[i]);
					ans[i]=path;
				}
			}
		}
	}
	
	int maxindex=0;
	for(int i=1;i<n;i++){
		if(dp[i]>dp[maxindex]){
			maxindex=i;
		}
	}
	
	return ans[maxindex];
}
void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}
	vector<pair<int,int>>p=fun(v,n);
	for(pair<int,int>p1:p){
		cout<<"("<<p1.first<<","<<p1.second<<") ";
	}
}
int main(){
	testcase(){
		solve();
	}
}
