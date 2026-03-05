// Breadth First Search
// 1-2, 2-3, 2-4, 1-6, 6-7, 6-8, 4-5, 7-5
// BFS of the above graph if starting node is 1- 1,2,6,3,4,7,8,5 
// BFS of the above graph if starting node is 6- 6,1,7,8,2,5,3,4 
// Just find the adjacent of it and then print them and push them into the queue and then start again by find adjacent untill queue is not empty

#include<bits/stdc++.h>
using namespace std;
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
    
    // BFS 
    vector<int>visited(n+1,0);
    visited[1]=1;
    queue<int>q;
    q.push(1);
    
    while(q.size()!=0){
        // Taken out the node from the queue
        int node=q.front();
        q.pop();
        
        // print that node 
        cout<<node<<" ";
        
        // find the adjacent nodes and push them into queue
        for(auto it:adj[node]){
            
            // if it is not visited
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
}

// eg- 9,9
// 1-2,1-6,2-3,2-4,6-7,6-9,4-5,7-8,5-8
// BFS of graph is- 1,2,6,3,4,7,9,5,8