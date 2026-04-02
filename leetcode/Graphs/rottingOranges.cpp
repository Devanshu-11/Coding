class Solution {
public:
    // this is question of multisource bfs
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>visited=grid;
        vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
        
        int m=visited.size();
        int n=visited[0].size();
        queue<pair<int,int>>q;
        int freshCount=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==2){
                    q.push({i,j});
                }
                
                if(visited[i][j]==1){
                    freshCount++;
                }
            }
        }
        
        // all oranges are rotten
        if(freshCount==0){
            return 0;
        }
        
        int minutes=0;
        while(q.size()!=0){
            int size=q.size();
            
            while(size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                for(vector<int>&dir: directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    
                    if(new_i>=0&&new_i<m&&new_j>=0&&new_j<n&&visited[new_i][new_j]==1){
                        q.push({new_i,new_j});
                        visited[new_i][new_j]=2;
                        freshCount--;
                    }
                }
            }
            
            minutes++;
        }
        
        if(freshCount==0){
            return minutes-1;
        }
        
        return -1;
    }
};