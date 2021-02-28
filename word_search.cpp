class Solution {
public:
    
    bool solve(vector<vector<char>> &board, string &word, int index, int i, int j){
        
        if(index==word.length())
            return true;
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[index])
            return false;

            char temp = board[i][j];
            board[i][j]= ' ';
        
            // cout<<s<<endl;
            bool c0 = solve(board, word, index+1, i+1,j);
            bool c1 = solve(board, word, index+1, i-1,j);
            bool c2 = solve(board, word, index+1, i,j+1);
            bool c3 = solve(board, word, index+1, i,j-1);
        bool sub = c0||c1||c2||c3;
        if(!sub){
            board[i][j]= temp;
            return false;
        }
        return true;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0] && (solve(board,word, 0, i, j)))
                    return true;
                   }
        }
        return false;
    }
};