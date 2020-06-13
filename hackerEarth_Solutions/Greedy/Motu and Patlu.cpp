//problem link:-https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/motu-and-patlu-1-ab612ad8/?layout=old
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
    testcase(){
        int n;
        cin>>n;
        ll a[n+2]={0};
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll b[n+2]={0};
        for(int i=1;i<=n;i++){
            b[i]=2*a[i];
        }
        for(int i=n-1;i>=1;i--){
            b[i]+=b[i+1];
        }
        for(int i=1;i<=n;i++){
            a[i]+=a[i-1];
        }
        int l=1,r=n;
        while(l<r){
            if(a[l]<b[r]){
                l++;
            }
            else{
                r--;
            }
        }
        if(a[l-1]<=b[r+1]){
            l++;
        }
        else{
            r--;
        }
        int motu=l-1;
        int patlu=n-r;
        cout<<motu<<" "<<patlu<<endl;
        if(motu>patlu){
            cout<<"Motu"<<endl;
        }
        else if(motu==patlu){
            cout<<"Tie"<<endl;
        }
        else{
            cout<<"Patlu"<<endl;
        }
    }
}

