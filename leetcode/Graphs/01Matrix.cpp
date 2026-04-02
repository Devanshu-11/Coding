class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>grid(row,vector<int>(col,-1));
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>directions{{0,-1},{0,1},{-1,0},{1,0}};
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    grid[i][j]=0;
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        
        while(q.size()!=0){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int value=q.front().second;
            q.pop();
            
            for(vector<int>direction:directions){
                int new_i=i+direction[0];
                int new_j=j+direction[1];
                
                if(new_i>=0&&new_j>=0&&new_i<row&&new_j<col&&visited[new_i][new_j]==false){
                    visited[new_i][new_j]=true;
                    grid[new_i][new_j]=value+1;
                    q.push({{new_i,new_j},value+1});
                }
            }
        }
        
        return grid;
    }
};