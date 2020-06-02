#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	vector<int> *adj;
	public:
		Graph(int v){
			V=v;
			adj=new vector<int>[V];
		}
		void addEdge(int u,int w){
			adj[u].push_back(w);
			adj[w].push_back(u);
		}
		void dfsUtil(bool visited[],int v){
			visited[v]=true;
			for(auto it = adj[v].begin();it!=adj[v].end();it++){
				if(!visited[*it]){
					dfsUtil(visited,*it);
				}
			}
		}
		void countTrees(){
			int count=0;
			bool visited[V]={0};
			for(int i=0;i<V;i++){
				if(!visited[i]){
					dfsUtil(visited,i);
					count++;
				}
			}
			cout<<count<<"\n";
		}
};
int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(3,4);
	g.countTrees();
}
