class Solution {
public:
    bool solve(int i, int j, int index,
               vector<vector<char>>& board,
               string& word) {
        if(index == word.size())
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
           board[i][j] != word[index])
            return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found =
            solve(i + 1, j, index + 1, board, word) ||
            solve(i - 1, j, index + 1, board, word) ||
            solve(i, j + 1, index + 1, board, word) ||
            solve(i, j - 1, index + 1, board, word);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(solve(i, j, 0, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};