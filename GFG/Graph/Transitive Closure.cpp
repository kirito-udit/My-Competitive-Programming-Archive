#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	vector<int> *adj;
	int **mat;
	public:
		Graph(int v){
			V=v;
			adj=new vector<int>[v];
			mat=new int* [v];
			for(int i=0;i<v;i++){
				mat[i]=new int[v];
			}
		}
		void addEdge(int u,int w){
			adj[u].push_back(w);
		}
		void dfsUtil(bool visited[],int u,int v,int **mat){
			visited[v]=true;
			mat[u][v]=1;
			for(auto it=adj[v].begin();it!=adj[v].end();it++){
				if(visited[*it]==false){
					dfsUtil(visited,u,*it,mat);
				}
			}
		}
		void transclose(){
			for(int i=0;i<V;i++){
				for(int j=0;j<V;j++){
					mat[i][j]=0;
				}
			}
			for(int i=0;i<V;i++){
				bool visited[V]={0};
				dfsUtil(visited,i,i,mat);
			}
			
			for(int i=0;i<V;i++){
				for(int j=0;j<V;j++){
					cout<<mat[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};
int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,3);
	g.addEdge(3,4);
	g.addEdge(4,1);
    g.transclose();
}
