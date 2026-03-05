// Depth First Search- Recursion
// 1-2, 1-3, 2-5, 2-6, 1-9, 9-10, 3-7, 7-8, 3-4, 4-8
// DFS of the above graph if starting node is 1- 1,2,5,6,3,7,8,4,9,10
// DFS of the above graph if starting node is 3- 3,4,8,7,1,2,5,6,9,10 

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[], vector<int> &visited){
    // base case
    visited[node]=1;
    cout<<node<<" ";
    
    // Now traverse through all neighbours
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
    }
}

int main(){
    int n,m; // n-vertices, m-edges
    cin>>n>>m;
    vector<int>adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0;i<=n;i++){
        cout<<i<<"->";
        
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
    // DFS 
    vector<int>visited(n+1,0);
    int node=1;
    dfs(node,adj,visited);

}

// eg- 10,10
// 1-2,1-3,2-5,2-6,1-9,9-10,3-7,7-8,3-4,4-8
// DFS of graph is- 1,2,5,6,3,7,8,4,9,10