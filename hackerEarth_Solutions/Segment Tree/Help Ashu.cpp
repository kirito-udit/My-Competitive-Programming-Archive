#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
const int maxN=1e5+6;
int arr[maxN];
PI st[4*maxN];
void build(int si,int ss,int se){
	if(ss==se){
		if(arr[ss]%2==1){
			st[si]={1,0};
		}
		else{
			st[si]={0,1};
		}
		return;
	}
	int mid = ss + (se-ss)/2;
	build(2*si,ss,mid);
	build(2*si+1,mid+1,se);
	st[si].first = st[2*si].first + st[2*si+1].first;
	st[si].second = st[2*si].second + st[2*si+1].second;
}
void update(int si,int ss,int se,int qi,int val){
	if(ss==se){
		if(arr[qi]%2==1){
			st[si]={0,1};
		}
		else{
			st[si]={1,0};
		}
		arr[qi]=val;
		return;
	}
	int mid = ss + (se-ss)/2;
	if(qi<=mid){
		update(2*si,ss,mid,qi,val);
	}
	else{
		update(2*si+1,mid+1,se,qi,val);
	}
	st[si].first = st[2*si].first + st[2*si+1].first;
	st[si].second = st[2*si].second + st[2*si+1].second;
}
int query(int si,int ss,int se,int qs,int qe,int f){
	if(qs>se || qe<ss){
		return 0;
	}
	if(qs<=ss && qe>=se){
		if(f==0)
		return st[si].second;
		else{
			return st[si].first;
		}
	}
	int mid = ss + (se-ss)/2;
	int l = query(2*si,ss,mid,qs,qe,f);
	int r = query(2*si+1,mid+1,se,qs,qe,f);
	return l+r;
}
// int queryeven(int si,int ss,int se,int qs,int qe){
// 	if(qs>se || qe<ss){
// 		return 0;
// 	}
// 	if(qs<=ss && qe>=se){
// 		return st[si].second;
// 	}
// 	int mid = ss + (se-ss)/2;
// 	int l = queryeven(2*si,ss,mid,qs,qe);
// 	int r = queryeven(2*si+1,mid+1,se,qs,qe);
// 	return l+r;
// }
// int queryodd(int si,int ss,int se,int qs,int qe){
// 	if(qs>se || qe<ss){
// 		return 0;
// 	}
// 	if(qs<=ss && qe>=se){
// 		return st[si].first;
// 	}
// 	int mid = ss + (se-ss)/2;
// 	int l = queryodd(2*si,ss,mid,qs,qe);
// 	int r = queryodd(2*si+1,mid+1,se,qs,qe);
// 	return l+r;
// }
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	build(1,1,n);
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		if(x==0){
			int i,val;
			cin>>i>>val;
			if(arr[i]%2==val%2){
				continue;
			}
			else{
				update(1,1,n,i,val);
			}
		}
		else if(x==1){
			int l,r;
			cin>>l>>r;
			cout<<query(1,1,n,l,r,0)<<endl;
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<query(1,1,n,l,r,1)<<endl;
		}
	}
}
