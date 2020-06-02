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
		bool isnotvisited(int x,vector<int>&path){
			for(int i=0;i<path.size();i++){
				if(path[i]==x){
					return false;
				}
			}
			return true;
		}
		
		vector<vector<int>> BFSmodified(int s,int d){
			vector<vector<int>>ans;
			queue<vector<int>>q;
			vector<int>path;
			path.push_back(s);
			q.push(path);
			
			while(q.empty()==false){
				path=q.front();
				q.pop();
				
				int iamat=path[path.size()-1];
				
				if(iamat==d){
//					
					ans.push_back(path);
				}
				
				for(auto it = adj[iamat].begin();it!=adj[iamat].end();it++){
					if(isnotvisited(*it,path)){
						vector<int>newpath(path);
						newpath.push_back(*it);
						q.push(newpath);
					}
				}
			}
			return ans;
		}
		
		void countPaths(int s,int d){
		
			vector<vector<int>>ans=BFSmodified(s,d);
			
			cout<<"Number of paths from "<<s<<" to "<<d<<" are "<<ans.size()<<endl;
			for(int i=0;i<ans.size();i++){
				for(int j=0;j<ans[i].size();j++){
					cout<<ans[i][j]<<" ";
				}
				cout<<endl;
			}
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
    g.countPaths(s,d);
}
