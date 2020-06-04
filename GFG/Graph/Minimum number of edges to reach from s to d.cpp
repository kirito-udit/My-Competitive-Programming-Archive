#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	vector<int> *adj;
	public:
		Graph(int v){
			V=v;
			adj= new vector<int>[V];//since 1 based indexing
		}
		void addEdge(int u,int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		void BFS(int s,int d){
			int distance[V]={0};
			bool visited[V]={0};
			queue<int>q;
			q.push(s);
			visited[s]=true;
			while(!q.empty()){
				int x=q.front();
				q.pop();
				
			
				for(auto it = adj[x].begin() ; it != adj[x].end() ; it++){
					if(visited[*it]==false){
						visited[*it]=true;
						distance[*it]=distance[x]+1;
						q.push(*it);
					}
				}
			}
			
			cout<<distance[d]<<endl;
		}
};
int main(){
	Graph g(9);
	g.addEdge(0,1);
	g.addEdge(0,7);
	g.addEdge(1,7);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,5);
	g.addEdge(2,8);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(6,7);
	g.addEdge(7,8);
	int s=0;
	int d=5;
	g.BFS(s,d);
}
