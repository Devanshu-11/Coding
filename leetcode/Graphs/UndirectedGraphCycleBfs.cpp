class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            int first_ele=edges[i][0];
            int second_ele=edges[i][1];
            adj[first_ele].push_back(second_ele);
            adj[second_ele].push_back(first_ele);
        }
        
        // visited array
        vector<int>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                queue<pair<int,int>>q;
                q.push({i,-1});
                visited[i]=true;
                
                while(q.size()!=0){
                    int node=q.front().first;
                    int parent=q.front().second;
                    q.pop();
                    
                    for(auto it:adj[node]){
                        if(!visited[it]){
                            visited[it]=true;
                            q.push({it,node});
                        }else if(it!=parent){
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};