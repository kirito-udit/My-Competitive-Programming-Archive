#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
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
		}
		void dfs(int v){
			//iterative dfs traversal
			bool visited[V]={0};
			stack<int>st;
			st.push(v);
			visited[v]=true;
			while(!st.empty()){
				int x=st.top();
				cout<<x<<" ";
				st.pop();
				for(auto it = adj[x].begin() ; it != adj[x].end(); it ++){
					if(!visited[*it]){
						visited[*it]=true;
						st.push(*it);
					}
				}
			}
		}
};
int main(){
	Graph g(5); // Total 5 vertices in graph 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4); 
  
    cout << "Following is Depth First Traversal\n"; 
    g.dfs(0); 
}
