class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &visited, string &word, int ind) {
        int m = board.size();
        int n = board[0].size();
        if(ind == word.size())
            return true;
        
        if(i >= m || j >= n || i < 0 || j < 0 || visited[i][j] || word[ind] != board[i][j]) 
            return false;
        
        visited[i][j] = 1;
        bool ans = dfs(i - 1, j, board, visited, word, ind + 1) || 
        dfs(i, j + 1, board, visited, word, ind + 1) || 
        dfs(i + 1, j, board, visited, word, ind + 1) || 
        dfs(i, j - 1, board, visited, word, ind + 1);
        
        visited[i][j] = 0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, board, visited, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
