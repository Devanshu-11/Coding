class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
        int rows=isWater.size();
        int column=isWater[0].size();
        vector<vector<int>>grid(rows,vector<int>(column,-1));
        queue<pair<int,int>>q;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<column;j++){
                if(isWater[i][j]==1){
                    grid[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(q.size()!=0){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(vector<int>&dir: directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];
                
                if(new_i>=0&&new_i<rows&&new_j>=0&&new_j<column&&grid[new_i][new_j]==-1){
                    q.push({new_i,new_j});
                    grid[new_i][new_j]=1+grid[i][j];
                }
            }
        }
        
        return grid;
    }
};