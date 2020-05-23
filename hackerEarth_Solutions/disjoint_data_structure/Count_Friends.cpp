//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/count-friends/submissions/
#include<bits/stdc++.h>
using namespace std;
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
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int n,m;
        cin>>n>>m;
        int arr[n+1]={0};
        int size[n+1]={0};
        //init
        for(int i=1;i<=n;i++){
            arr[i]=i;
            size[i]=1;
        }
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            weighted_union(arr,size,u,v);
        }
        for(int i=1;i<=n;i++){
            int root_x=root(arr,i);
            cout<<size[root_x]-1<<" ";//excluding himself
        }
        cout<<endl;
}
