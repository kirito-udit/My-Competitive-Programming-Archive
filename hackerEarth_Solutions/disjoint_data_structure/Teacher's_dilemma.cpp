#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
int root(int arr[],int i){
	while(arr[i]!=i){
		arr[i]=arr[arr[i]];
		i=arr[i];
	}
	return i;
}
void weighted_union(int arr[],int size[],int a,int b){
	int root_a=root(arr,a);
	int root_b=root(arr,b);
	if(root_a==root_b){
		return;
	}
	if(size[root_a]<size[root_b]){
		arr[root_a]=arr[root_b];
		size[root_b]+=size[root_a];
		size[root_a]=0;
	}
	else{
		arr[root_b]=arr[root_a];
		size[root_a]+=size[root_b];
		size[root_b]=0;
	}
	
}
int main(){
	int n,m;
	cin>>n>>m;
	int arr[n+1]={0},size[n+1]={0};
	for(int i=1;i<=n;i++){
		arr[i]=i;
		size[i]=1;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		weighted_union(arr,size,u,v);
	}
	ll ans=1;
	for(int i=1;i<=n;i++){
		if(size[i]>0){
			ans=(ans%MOD *size[i]%MOD)%MOD;
		}
	}
	cout<<ans<<'\n';
}
