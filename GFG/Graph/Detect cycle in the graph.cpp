#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	vector<int> *adj;
	vector<int>parent;
	vector<int>color;
	int cycle_start,cycle_end;
	public:
		Graph(int v){
			V=v;
			adj = new vector<int>[V];
			parent.resize(V);
			color.resize(V);
		}
		void addEdge(int u,int w){
			adj[u].push_back(w);
		}
		bool dfs(int v){
			color[v]=1;
			for(int u:adj[v]){
				if(color[u]==0){
					parent[u]=v;
					if(dfs(u)){
						return true;
					}
				}
				else if(color[u]==1){
					cycle_start=u;
					cycle_end = v;
					return true;
				}
			}
			
			color[v] = 2;
			return false;
		}
		void detectCycle(){
			parent.assign(V,-1);
			color.assign(V,0);
			cycle_start=-1;
			
			for(int i=0;i<V;i++){
				if(color[i]==0 && dfs(i)){
					break;
				}
			}
			
			if(cycle_start==-1){
				cout<<"No cycle found\n";
			}
			else{
				vector<int>cycle;
				cycle.push_back(cycle_start);
				for(int  v= cycle_end;v!=cycle_start;v=parent[v]){
					cycle.push_back(v);
				}
				cycle.push_back(cycle_start);
				
				reverse(cycle.begin(),cycle.end());
				for(int v:cycle){
					cout<<v<<" ";
				}
				cout<<endl;
			}
		}
};
int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,1);
	g.addEdge(4,1);
	g.addEdge(4,3);
	
	g.detectCycle();
}
