//k cores of a graph : k-cores of a graph are the connected components of the graph which are left after the 
// vertices having degree less than k been removed from the graph 
// Note:-1. degree of every vertex is size of its adj vector
//2. reducing a degree in an undirected graph means removing an edge b/w u and v therefore it will decrease deg of u and v both.
//3. we will modify dfs and take care of the above points.
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(nullptr);
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
			adj[w].push_back(u);
		}
		bool dfs(int v,vector<bool>&visited,vector<int>&degree,int k){
			visited[v]=true;
			for(auto it =adj[v].begin(); it!=adj[v].end(); it++){
				if(degree[v]<k){
					degree[*it]--;
				}
				if(!visited[*it]){
					if(dfs(*it,visited,degree,k)){
						degree[v]--;
					}
				}
			}
			return degree[v]<k;
		}
		void printKCores(int k){
			vector<bool>visited={0};
			
			int mindig=INT_MAX;
			int startvertex;
			
			//find all degrees
			vector<int>degree(V);
			for(int i=0;i<V;i++){
				degree[i]=adj[i].size();
				if(degree[i]<mindig){
					mindig=degree[i];
					startvertex=i;
				}
			}
			
			dfs(startvertex,visited,degree,k);
			
			for(int i=0;i<V;i++){
				if(!visited[i]){
					dfs(i,visited,degree,k);
				}
			}
			
			
			
			cout << "K-Cores : \n"; 
		    for (int v=0; v<V; v++) 
		    { 
		       
		        if (degree[v] >= k) 
		        { 
		            cout << "\n[" << v << "]"; 
		  
		            // Traverse adjacency list of v and print only 
		            // those adjacent which have vDegree >= k after 
		            // BFS. 
		            vector<int>::iterator itr; 
		            for (itr = adj[v].begin(); itr != adj[v].end(); ++itr) 
		                if (degree[*itr] >= k) 
		                    cout << " -> " << *itr; 
		        } 
		    } 
		}
};
int main(){
	int k = 3; 
    Graph g1(9); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 5); 
    g1.addEdge(2, 3); 
    g1.addEdge(2, 4); 
    g1.addEdge(2, 5); 
    g1.addEdge(2, 6); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 6); 
    g1.addEdge(3, 7); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(5, 8); 
    g1.addEdge(6, 7); 
    g1.addEdge(6, 8); 
    g1.printKCores(k); 
  
    cout << endl << endl; 
  
    Graph g2(13); 
    g2.addEdge(0, 1); 
    g2.addEdge(0, 2); 
    g2.addEdge(0, 3); 
    g2.addEdge(1, 4); 
    g2.addEdge(1, 5); 
    g2.addEdge(1, 6); 
    g2.addEdge(2, 7); 
    g2.addEdge(2, 8); 
    g2.addEdge(2, 9); 
    g2.addEdge(3, 10); 
    g2.addEdge(3, 11); 
    g2.addEdge(3, 12); 
    g2.printKCores(k); 
  
    return 0; 
} 
