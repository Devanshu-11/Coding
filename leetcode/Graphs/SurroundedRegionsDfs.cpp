class Solution {
    void checkSurroundedRegion(int i,int j,vector<vector<char>>& board, vector<vector<bool>>& visited){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||visited[i][j]==true||board[i][j]=='X'){
            return;
        }
        
        // mark it visited
        visited[i][j]=true;
        
        // left
        checkSurroundedRegion(i,j-1,board,visited);
        
        // right
        checkSurroundedRegion(i,j+1,board,visited);
        
        // top
        checkSurroundedRegion(i-1,j,board,visited);
        
        // bottom
        checkSurroundedRegion(i+1,j,board,visited);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        
        // for rows
        for(int j=0;j<col;j++){
            if(board[0][j]=='O'&&!visited[0][j]){
                checkSurroundedRegion(0,j,board,visited);
            }
            
            if(board[row-1][j]=='O'&&!visited[row-1][j]){
                checkSurroundedRegion(row-1,j,board,visited);
            }
        }
        
        // for columns
        for(int i=0;i<row;i++){
            if(board[i][0]=='O'&&!visited[i][0]){
                checkSurroundedRegion(i,0,board,visited);
            }
            
            if(board[i][col-1]=='O'&&!visited[i][col-1]){
                checkSurroundedRegion(i,col-1,board,visited);
            }
        }
        
        // we already surrounded Region as 'O' and mark rest of 'O' as 'X'
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'&&visited[i][j]==false){
                    board[i][j]='X';
                }
            }
        }
    }
};