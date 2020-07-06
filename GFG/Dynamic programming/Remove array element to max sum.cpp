#include<bits/stdc++.h>
using namespace std;
int fun(int arr[],int n){
//	if(l>r){
//		return 0;
//	}
//	else if(l==r){
//		return arr[l]* (cnt+1);
//	}
//	else{
//		return max((cnt+1)*arr[l]+fun(arr,l+1,r,cnt+1),(cnt+1)*arr[r]+fun(arr,l,r-1,cnt+1));
//	}

	int dp[n][n];
	memset(dp,0,sizeof(dp));
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n;j++){
			int cnt=n-j+i;
			if(i>j){
				dp[i][j]=0;
			}
			else if(i==j){
				dp[i][j]=arr[i]*(cnt);
			}
			else{
				dp[i][j]=max(dp[i+1][j]+(cnt)*arr[i],dp[i][j-1]+(cnt)*arr[j]);
			}
		}
	}
	return dp[0][n-1];
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<fun(arr,n)<<endl;
}
