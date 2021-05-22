void solve(vector<vector<char>> &board, int i, int j){
    
    if(i<0 or i>=board.size() or j<0 or j>=board[i].size() or board[i][j]!='X')
        return;
    
    board[i][j] = '.';
    solve(board, i-1, j);
    solve(board, i+1, j);
    solve(board, i, j-1);
    solve(board, i, j+1);
    
    return;
    
}


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int ships =0;
        
        for(int i=0;i<board.size();i++){
            for(int j =0;j<board[i].size(); j++){
                if(board[i][j]=='X'){
                    ships++;
                    solve(board, i, j);
                }
            }
        }
        
        return ships;
    }
};



class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int ships =0;
        
        for(int i=0;i<board.size();i++){
            for(int j =0;j<board[i].size(); j++){
                if(board[i][j]=='X'){
                    if(i>0 and board[i-1][j] == 'X')
                        continue;
                    
                    if(j>0 and board[i][j-1] == 'X')
                        continue;
                    
                    if(board[i][j] == '.')
                        continue;
                    
                    ships++;
                }
            }
        }
        
        return ships;
    }
};