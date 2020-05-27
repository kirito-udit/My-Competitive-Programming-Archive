#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	vector<int> *adj;
	public:
		Graph(int v){
			V=v;
			adj= new vector<int>[V];
		}
		void addEdge(int u,int w){
			adj[u].push_back(w);
		}
		void dfsUtil(bool visited[],int u){
			visited[u]=true;
			for(auto it = adj[u].begin();it!=adj[u].end();it++){
				if(visited[*it]==false){
					dfsUtil(visited,*it);
				}
			}
		}
		void dfs(int u,int &ans){
			bool visited[V]={0};
//			visited[u]=true;
			for(int i=0;i<V;i++){
				if(visited[i]==false){
					dfsUtil(visited,i);
					ans=i;
				}
			}
		}
		void Mother(){
			int ans=0;
			dfs(0,ans);
			cout<<ans<<'\n';
		}
};
int main(){
	Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
    
    g.Mother();
}
