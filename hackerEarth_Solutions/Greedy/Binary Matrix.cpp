//problem link-:https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/binary-matrix-1-d77d7d00/description/
#include<bits/stdc++.h>
using namespace std;
#define testcase() int t;cin>>t;while(t--)
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
    FAST
    int n,m;
    cin>>n>>m;
    string arr[n];
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        string res;
        for(int i=0;i<str.size();i++){
            if(str[i]=='1'){
                res+='z';
            }
            else{
                res+='a';
            }
        }
        arr[i]=res;
    }
    int index=0;
    string t=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>t){
            t=arr[i];
            index=i;
        }
    }
    cout<<index+1<<endl;
}
