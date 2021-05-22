vector<vector<string>> ans;

bool is_valid(vector<string> &board, int row, int col){
    
    for(int i=row;i>=0;i--)
        if(board[i][col]=='Q')
            return false;
    
    for(int i=row,j=col; i>=0 and j>=0;i--,j--)
        if(board[i][j]=='Q')
            return false;
    
    for(int i=row,j=col; i>=0 and j<board.size(); i--,j++)
        if(board[i][j]=='Q')
            return false;
    
    return true;
}

void solve(vector<string> &board, int row){
    
    if(row == board.size()){
        ans.push_back(board);
       return; 
    }
        
    
    for(int i=0; i<board.size();i++){
        
        if(is_valid(board, row, i)){
            board[row][i] = 'Q';
            solve(board, row+1);
            board[row][i] = '.'; 
        }
        
    }
}


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<string> board(n,string(n,'.'));
        solve(board, 0);
        return ans;
    }
};