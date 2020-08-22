//https://www.spoj.com/problems/RMQSQ/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
int arr[100002];
int st[4*(100002)];
int n,q;
const int INF=(int)1e12;
void buildTree(int si,int ss,int se){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	int mid = ss+(se-ss)/2;
	buildTree(2*si,ss,mid);
	buildTree(2*si+1,mid+1,se);
	st[si] = min(st[2*si],st[2*si+1]);
}
int query(int si,int ss,int se,int qs,int qe){
	//compeletely outside
	if(qs>se || qe<ss){
		return INF;
	}
	//completely inside
	if(ss>=qs && se<=qe){
		return st[si];
	}
	int mid = ss + (se-ss)/2;
	int l = query(2*si,ss,mid,qs,qe);
	int r = query(2*si+1,mid+1,se,qs,qe);
	return min(l,r);
}
int32_t main(){
	FAST
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	buildTree(1,1,n);
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		++l,++r;
		cout<<query(1,1,n,l,r)<<endl;
	}
}
