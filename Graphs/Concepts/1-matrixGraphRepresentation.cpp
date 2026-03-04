// Directed Graph is that type of graph where all edges are directed
// undirected graph is that type of graph where all edges are undirected
// The number of edges attached to a vertex is called the degree of that vertex
// Total Degree in undirected and directed graph- 2*Edges
// In directed graph, there is a concept of indegree and outdegree

#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1,vector<int>(n+1,0));
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u][v]=1;
        adj[v][u]=1;
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

// TC- O(n^2)
// SC- O(n^2);

// undirected graph
// 1-2 
// 1-3
// 3-4
// 2-4
// 2-5 
// 4-5
// No of nodes-5 and no of edges-6