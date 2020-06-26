//prufer code to tree creation
#include<bits/stdc++.h>
using namespace std;
void printEdgeFromPrufer(int prufer[],int n){
	//if a labeled tree has n vertices then prufer seq will have size n-2
	int vertices=n+2;
	int vertex_set[vertices]={0};
	
	//storing freq of every element of prufer to vertex-set
	for(int i=0;i<n;i++){
		vertex_set[prufer[i]-1]+=1;//-1 bcz we are using 0 bases indexing and labels are 1 based
	}
	//finding the smallest node in set which is not in prufer seq and not visited
	int j=0;
	for(int i=0;i<n;i++){
		for(j=0;j<vertices;j++){
			//if not in prufer seq then freq will be zero
			if(vertex_set[j]==0){
				//this means that there is an edge betwenn j+1 and prufer [i]
				cout<<" ("<<j+1<<","<<prufer[i]<<") ,";
				//mark as visited
				vertex_set[j]=-1;
				
				//decrease the freq of used vertex of prufer seq
				vertex_set[prufer[i]-1]-=1;
				break;
			}
		}
	}
	
	//for last element
	j=0;
	for(int i=0;i<vertices;i++){
		if(vertex_set[i]==0 && j==0){
			cout<<" ("<<(i+1)<<",";
			j++;
		}
		else if(vertex_set[i]==0 && j==1){
			cout<<(i+1)<<" )\n";
		}
	}
}
int main(){
	 int prufer[] = { 4, 1, 3, 4 }; 
    int n = sizeof(prufer) / sizeof(prufer[0]); 
    printEdgeFromPrufer(prufer, n); 
    return 0; 
}
