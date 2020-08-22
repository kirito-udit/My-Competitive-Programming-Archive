#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[100006];
int ste[4*100006]={0};
int sto[4*100006]={0};
void build(int si,int ss,int se){
	if(ss==se){
		if(arr[ss]%2==0){
			ste[si]=1;
		}
		else{
			sto[si]=1;
		}
		return;
	}
	int mid = ss+ (se-ss)/2;
	build(2*si,ss,mid);
	build(2*si+1,mid+1,se);
	ste[si]=ste[2*si]+ste[2*si+1];
	sto[si]=sto[2*si]+sto[2*si+1];
	return;
}
int queryeven(int si,int ss,int se,int qs,int qe){
	if(qs>se||qe<ss){
		return 0;
	}
	if(qs<=ss && qe>=se){
		return ste[si];
	}
	int mid = ss + (se-ss)/2;
	int l = queryeven(2*si,ss,mid,qs,qe);
	int r = queryeven(2*si+1,mid+1,se,qs,qe);
	return l+r;
}
int queryodd(int si,int ss,int se,int qs,int qe){
	if(qs>se||qe<ss){
		return 0;
	}
	if(qs<=ss && qe>=se){
		return sto[si];
	}
	int mid = ss + (se-ss)/2;
	int l = queryodd(2*si,ss,mid,qs,qe);
	int r = queryodd(2*si+1,mid+1,se,qs,qe);
	return l+r;
}
void update(int si,int ss,int se,int qi,int f){
	if(ss==se){
		if(f==1){
			sto[si]=1;
			ste[si]=0;	
		}
		else{
			sto[si]=0;
			ste[si]=1;	
		}
		return;
	}
	
	int mid = ss + (se-ss)/2;
	if(qi<=mid){
		update(2*si,ss,mid,qi,f);	
	}
	else{
		update(2*si+1,mid+1,se,qi,f);
	}
	sto[si]=sto[2*si]+sto[2*si+1];
	ste[si]=ste[2*si]+ste[2*si+1];
}
int32_t main(){
	memset(arr,0,sizeof(arr));
	memset(ste,0,sizeof(ste));
	memset(sto,0,sizeof(sto));
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
		if(x==1){
			int l,r;
			cin>>l>>r;
			cout<<queryeven(1,1,n,l,r)<<endl;
		}
		else if(x==2){
			int l,r;
			cin>>l>>r;
			cout<<queryodd(1,1,n,l,r)<<endl;
		}
		else{
			int qi,val;
			cin>>qi>>val;
			update(1,1,n,qi,val%2);
		}
	}
}
