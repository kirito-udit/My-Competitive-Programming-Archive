//problem link:-https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/subxor-e114a622/description/
#include <bits/stdc++.h>
using namespace std;
/*
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
*/
typedef long long ll;
typedef unsigned long long ull;
#define testcase() int t; cin>>t; while(t--)
#define setbits(x) __builtin_popcount(x);
#define gcd(a,b) __gcd(a,b);
#define ALL(X) (X).begin(), (X).end()
#define rep(I, A, B) for (int  I = (A); I <= (B); ++I)
#define per(I, A, B) for (int I = (A); I >= (B); --I)
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define pb push_back
#define mp make_pair
const int MOD=1e9+7;

ll power(ll a ,ll b){
    ll ans=1;
    
    while(b){
       if(b&1){
           ans=ans*a;
       }
       b=b>>1;
       a=a*a;
    }
    return ans;
}

ll fastexpo(ll a,ll b, ll m){
    ll ans=1;
    
    a=a%m;
    
    if(a==0) return 0;
    
    while(b){
        if(b&1){
            ans=((ans%m)*(b%m))%m;
        }
        b=b>>1;
        a=((a%m)*(a%m))%m;
    }
    return ans;
}
int main() {
    FAST
	// your code goes here
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ans^=x;
    }
    if(ans==0){
        cout<<"-1"<<endl;
    }
    else{
        cout<<"1"<<endl;
    }
   
    
}

