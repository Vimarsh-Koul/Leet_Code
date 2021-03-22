class Solution {
public:
    
    int find(vector<vector<int>> &board, int i, int j){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]==0 || board[i][j]==-2)
            return 0;
        return 1;
    }
    
    void fill(vector<vector<int>> &board, int rows, int col){
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                int count =0;
                count+=find(board, i-1,j-1);
                count+=find(board, i-1, j);
                count+=find(board, i-1, j+1);
                count+=find(board, i, j-1);
                count+=find(board, i, j+1);
                count+=find(board, i+1, j-1);
                count+=find(board, i+1, j);
                count+=find(board, i+1, j+1);
                
                if(board[i][j]==1 || board[i][j]==-2){
                    if(count< 2)
                        board[i][j]=-1;
                    else if(count==2 || count==3)
                        board[i][j]=1;
                    else if(count>3)
                        board[i][j]=-1;
                }
                
                else{
                    if(count==3)
                        board[i][j]=-2;
                }
            }
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int col = board[0].size();
        
        fill(board, rows, col);
        
        for(int i=0;i<rows;i++)
            for(int j=0;j<col;j++){
                if(board[i][j]==-1)
                    board[i][j]=0;
                else if(board[i][j]==-2)
                    board[i][j]=1;
            }
  
    }
};