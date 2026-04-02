class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size(),false));
        vector<vector<int>>result=image;
        q.push({sr,sc});
        vector<vector<int>>directions{{0,-1},{0,1},{-1,0},{1,0}};
        
        while(q.size()!=0){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            result[i][j]=color;
            visited[i][j]=true;
            
            for(vector<int> &dir: directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];
                
                if(new_i>=0&&new_j>=0&&new_i<image.size()&&new_j<image[0].size()&&image[new_i][new_j]==image[i][j]&&visited[new_i][new_j]==false){
                    q.push({new_i,new_j});
                }
            }
        }
        
        return result;
    }
};