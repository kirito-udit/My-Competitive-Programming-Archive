#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,k;
int main(){
	cin>>n>>k;
	priority_queue<ll>pq;
	double sum=0;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		sum+=x;
		pq.push(x);
	}
	printf("%lf\n",sum/n);
	int count=k;
	sum=0;
	while(count--){
		ll x=pq.top();
		pq.pop();
		x=ceil(x/3.0);
		pq.push(x);
	}
	while(pq.empty()==false){
		sum=sum+pq.top();
		pq.pop();
	}
	printf("%lf",sum/n);
}

