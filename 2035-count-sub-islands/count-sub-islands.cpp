class Solution {
public:
    int n, m;
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid2[i][j] == 0)
            return true;
        grid2[i][j] = 0;   
        bool ans = (grid1[i][j] == 1);
        ans &= dfs(grid1, grid2, i + 1, j);
        ans &= dfs(grid1, grid2, i - 1, j);
        ans &= dfs(grid1, grid2, i, j + 1);
        ans &= dfs(grid1, grid2, i, j - 1);
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && dfs(grid1, grid2, i, j))
                    count++;
            }
        }
        return count;
    }
};