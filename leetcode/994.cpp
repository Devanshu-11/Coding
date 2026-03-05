class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int column=grid[0].size();
        vector<vector<int>>rotten_oranges(grid.size(),vector<int>(column,INT_MAX));
        queue<pair<int,int>>q;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<column;j++){
                if(grid[i][j]==2){
                    rotten_oranges[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(q.size()!=0){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            // for top
            if(i-1>=0&&grid[i-1][j]==1){
                if(1+rotten_oranges[i][j]<rotten_oranges[i-1][j]){
                    q.push({i-1,j});
                }
                rotten_oranges[i-1][j]=min(1+rotten_oranges[i][j], rotten_oranges[i-1][j]);
            }
            
            // for bottom
            if(i+1<grid.size()&&grid[i+1][j]==1){
                if(1+rotten_oranges[i][j]<rotten_oranges[i+1][j]){
                    q.push({i+1,j});
                }
                rotten_oranges[i+1][j]=min(1+rotten_oranges[i][j], rotten_oranges[i+1][j]);
            }
            
            // for left
            if(j-1>=0&&grid[i][j-1]==1){
                if(1+rotten_oranges[i][j]<rotten_oranges[i][j-1]){
                    q.push({i,j-1});
                }
                rotten_oranges[i][j-1]=min(1+rotten_oranges[i][j], rotten_oranges[i][j-1]);
            }
            
            // for right
            if(j+1<grid[0].size()&&grid[i][j+1]==1){
                if(1+rotten_oranges[i][j]<rotten_oranges[i][j+1]){
                    q.push({i,j+1});
                }
                rotten_oranges[i][j+1]=min(1+rotten_oranges[i][j], rotten_oranges[i][j+1]);
            }
        }
        
        int findMaxAns=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<column;j++){
                if(rotten_oranges[i][j]!=INT_MAX){
                    findMaxAns=max(findMaxAns, rotten_oranges[i][j]);
                }
                
                if(rotten_oranges[i][j]==INT_MAX&& grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return findMaxAns;
    }
};

// Best solution