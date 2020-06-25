#include<bits/stdc++.h>
using namespace std;
void solve(vector<pair<int,int>>&v,int n){
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++){
		pair<int,int>p=v[i];
		auto it = mp.find(p.second);
		if(it!=mp.end() and mp[p.second]==p.first){
			cout<<p.second<<" "<<p.first<<endl;
			
		}
		else{
			mp[p.first]=p.second;
		}
	}
}
int main(){
	int n;
	cin>>n;
	vector<pair<int,int>>v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back({x,y});
	}	
	solve(v,n);
}
