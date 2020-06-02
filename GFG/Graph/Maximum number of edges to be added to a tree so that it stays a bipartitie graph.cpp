//maximun edges you can add to a tree so that it stays bipartitie
#include<bits/stdc++.h>
using namespace std;
class Graph{
	private:
		int V;
		vector<int> *adj;
	public:
		Graph(int v){
			V=v;
			adj= new vector<int>[V+1];
		}
		void addEdge(int u,int w){
			adj[u].push_back(w);//fromt parent to child
		}
		int BFS(int s){
			int colors[2]={0};
			int color=0;
			queue<int>q;
			bool visited[V+1]={0};//1 based indexing
			q.push(s);
			visited[s]=true;
			colors[0]++;
			while(!q.empty()){
				int x=q.front();
				q.pop();
				
//				colors[color]++;
				
				for(auto it=adj[x].begin();it!=adj[x].end();it++){
					if(visited[*it]==false){
						visited[*it]=true;
						q.push(*it);
						colors[color]++;
					}
				}
				color=(color+1)%2;
			}
			return colors[0]*colors[1];	
		}	
		int countNodes(int v){
			return abs(v+1-BFS(1));
		}
};
int main(){
	Graph g(5);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(3,5);
	cout<<g.countNodes(5)<<endl;
}
