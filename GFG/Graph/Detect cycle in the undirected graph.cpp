#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	vector<int> *adj;
	public:
		Graph(int v){
			V=v;
			adj = new vector<int>[V];
		}
		void addEdge(int u,int w){
			adj[u].push_back(w);
			adj[w].push_back(u);
		}
		bool dfs(int v,bool visited[],int parent){
			visited[v] = true;
			for(auto it = adj[v].begin();it!=adj[v].end();it++){
				if(visited[*it]==false){
					if(dfs(*it,visited,v)){
						return true;
					}
				}
				else if(*it!=parent){
					return true;
				}
			}
			return false;
		}
		bool isCyclic(){
			bool visited[V];
			for(int i=0;i<V;i++){
				visited[i]=false;
			}
			
			for(int u=0;u<V;u++){
				if(visited[u]==false){
					if(dfs(u,visited,-1)){
						return true;
					}
				}
			}
			return false;
		}
};
int main(){
	Graph g1(5); 
	g1.addEdge(1, 0); 
	g1.addEdge(0, 2); 
	g1.addEdge(2, 1); 
	g1.addEdge(0, 3); 
	g1.addEdge(3, 4); 
	g1.isCyclic()? cout << "Graph contains cycle\n": 
				cout << "Graph doesn't contain cycle\n"; 

	Graph g2(3); 
	g2.addEdge(0, 1); 
	g2.addEdge(1, 2); 
	g2.isCyclic()? cout << "Graph contains cycle\n": 
				cout << "Graph doesn't contain cycle\n"; 

	return 0; 
}
