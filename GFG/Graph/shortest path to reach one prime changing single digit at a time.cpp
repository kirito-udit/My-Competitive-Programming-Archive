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
		int bfs(int in1,int in2){
			int visited[V]={0};
			queue<int>q;
			visited[in1]=1;
			q.push(in1);
			while(!q.empty()){
				int x=q.front();
				q.pop();
				for(auto it = adj[x].begin();it!=adj[x].end();it++){
					if(visited[*it]==false){
						visited[*it]=visited[x]+1;
						q.push(*it);
					}
					if(*it==in2){
						return visited[*it]-1;
					}
				}
			}
		}
};
//store all 4 digit primes
void sieve(vector<int>&v){
	int n = 9999;
	bool prime[n+1]={0};
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int p=2;p*p<=n;p++){
		if(prime[p]){
			for(int j=p*p;j<=n;j+=p){
				prime[j]=false;
			}
		}
	}
	for(int i=1000;i<=n;i++){
		if(prime[i]){
			v.push_back(i);
		}
	}
}
//function to comapre diff digits of a 4 digit number (at max diff should be 1)
bool compare(int num1,int num2){
	string s1=to_string(num1);
	string s2=to_string(num2);
	
	int c=0;
	for(int i=0;i<4;i++){
		if(s1[i]!=s2[i]){
			c++;
		}
	}
	return c==1;
}
int shortestPath(int num1,int num2){
	vector<int>pset;
	sieve(pset);
	
	//create a graph where node are indexes of pset and there is an edge between two nodes
	//if and only if they differ by one digit only
	Graph g(pset.size());
	for(int i=0;i<pset.size();i++){
		for(int j=i+1;j<pset.size();j++){
			if(compare(pset[i],pset[j])){
				g.addEdge(i,j);
			}
		}
	}
	//finding index of the number num1 and num2
	int in1,in2;
	for(int i=0;i<pset.size();i++){
		if(pset[i]==num1){
			in1=i;
			break;
		}
	}
	for(int i=0;i<pset.size();i++){
		if(pset[i]==num2){
			in2=i;
			break;
		}
	}
	
	return g.bfs(in1,in2);
}
int main(){
	int num1 = 1033, num2 = 8179; 
    cout << shortestPath(num1, num2); 
    return 0; 
}
