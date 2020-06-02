//counting number of paths between two vertices
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
		void addEdge(int s,int d){
			adj[s].push_back(d);
		}
		void countPaths(int s,int d,int &count){
			if(s==d){
				count++;
			}
			for(auto it=adj[s].begin();it!=adj[s].end();it++){
				countPaths(*it,d,count);
			}
		}
		void fun(int s,int d){
			int count=0;
			countPaths(s,d,count);
			cout<<"Number of paths between "<<s<<" and "<<d<<" are "<<count<<endl;
		}
};
int main(){
	 Graph g(5); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(1, 3); 
    g.addEdge(2, 3); 
    g.addEdge(1, 4); 
    g.addEdge(2, 4); 
  
    int s = 0, d = 3; 
    g.fun(s, d); 
}
