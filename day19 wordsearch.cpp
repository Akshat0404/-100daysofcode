class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && backtrack(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
    
private:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == word.size())
            return true;
        
        int m = board.size();
        int n = board[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#';  
        
        bool found = backtrack(board, word, i - 1, j, k + 1) ||
                     backtrack(board, word, i + 1, j, k + 1) ||
                     backtrack(board, word, i, j - 1, k + 1) ||
                     backtrack(board, word, i, j + 1, k + 1);
        
        board[i][j] = temp; 
        
        return found;
    }
};
