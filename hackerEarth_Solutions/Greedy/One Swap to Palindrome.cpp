//problem link:- https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/one-swap-to-palindrome-d96d4e21/description/?layout=old
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
bool evenlength(string s){
    int n=s.size();
    unordered_map<char,int>mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second%2==1){
            return false;
        }
    }
    int mismatch=0;
    int id1=0,id2=0;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i]){
            mismatch++;
            if(mismatch==1){
                id1=i;
            }
            else if(mismatch==2){
                id2=i;
            }
            else{
                return false;
            }
        }
    }
    if(mismatch==0){
        return true;
    }
    else if(mismatch==1){
        return false;
    }
    else{
        if(s[id1]==s[n-1-id2] and s[id2]==s[n-1-id1]) {
            return true;
        }
        else if(s[id1]==s[id2] and s[n-1-id1]==s[n-1-id2]){
            return true;
        }
        else{
            return false;
        }
    }
}
bool oddlength(string s){
    int n=s.size();
    unordered_map<char,int>mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    int odd=0,even=0;
    char ch;
    for(auto it = mp.begin();it != mp.end(); it++){
        if((it->second)%2==1){
            ch=it->first;
            odd++;
        }
        else{
            even++;
        }
    }
    if(odd!=1)
    {
        return false;
    }
    if(even==0){
        return true;
    }
    if(s[n/2]==ch){
        string temp=s;
        temp.erase(n/2,1);
        return evenlength(temp);
    }
    else{
        char diff=s[n/2];
        for(int i=0;i<n;i++){
            if(i==n/2){
                continue;
            }
            if(s[i]==diff and s[n-1-i]==ch){
                s[n-1-i]=diff;
                s[n/2]=ch;
                string temp=s;
                temp.erase(n/2,1);
                return evenlength(temp);
            }
        }
    }
    return false;
}
int main() {
    FAST
	// your code goes here
    testcase(){
        string s;
        cin>>s;
        if(s.length()%2==0){
            if(evenlength(s)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            if(oddlength(s)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    
}
