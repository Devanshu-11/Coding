#include <iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    
    // in this,instead of store in 2D array, we stored in list and stores the adjacent neighbours
    vector<int>adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0;i<=n;i++){
        cout<<i<<"-> ";
        
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
}

// TC- O(n+2E)
// SC- O(n+2*E);

// undirected graph
// 1-2 
// 1-3
// 3-4
// 2-4
// 2-5 
// 4-5
// No of nodes-5 and no of edges-6