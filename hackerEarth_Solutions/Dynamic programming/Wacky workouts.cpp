//problem link:-https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/angry-neighbours/description/?layout=old
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define testcase() int t;cin>>t;while(t--)
#define MOD 1000000007
typedef long long int ll;
//matrix exponential
//defining matrix class
struct Matrix{
    static const int MAXN=2;
    int x[MAXN][MAXN];
    Matrix(){
        memset(x,0,sizeof(x));
    }
   
    int* operator [] (int r) {
        return x[r];
    }
    static Matrix unit() {
        Matrix res;
        for (int i = 0; i < MAXN; i++) res[i][i] = 1;
        return res;
    }
    friend Matrix operator + (Matrix A, Matrix B) {
        Matrix res;
        for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
            res[i][j] = A[i][j] + B[i][j];
            if (res[i][j] >= MOD) res[i][j] -= MOD;
        }
        return res;
    }
    friend Matrix operator * (Matrix A,Matrix B){
        Matrix res;
        for(int i=0;i<MAXN;i++){
            for(int k=0;k<MAXN;k++){
                for(int j=0;j<MAXN;j++){
                    res[i][j]=(res[i][j]+(ll)A[i][k]*B[k][j])%MOD;
                }
            }
        }
        return res;
    }
    
    friend Matrix operator ^ (Matrix A,ll k){
        if(k==0)
        return unit();
        Matrix res,tmp;
        for(int i=0;i<MAXN;i++){
            for(int j=0;j<MAXN;j++){
                res[i][j]=tmp[i][j]=A[i][j];
            }
        }
        k--;
        while(k){
            if(k&1) res= res*tmp;
            tmp=tmp*tmp;
            k>>=1;
        }
        return res;
    }
};
void solve(){
    ll n;
    cin>>n;
    Matrix mat;
    mat[0][0]=mat[0][1]=mat[1][0]=1;
    mat[1][1]=0;
    mat=mat^(n-1);
    int ans=(((mat[0][0]%MOD*2%MOD)%MOD)+((mat[0][1]%MOD)))%MOD;
    cout<<ans<<endl;
}
int main(){
    FAST
    testcase(){
        solve();
    }
}
