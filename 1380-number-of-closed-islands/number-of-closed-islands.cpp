class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1)
            return;

        grid[i][j] = 1; // Mark visited

        for (auto &d : dir)
            dfs(grid, i + d[0], j + d[1]);
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Remove islands connected to boundaries
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) dfs(grid, i, 0);
            if (grid[i][m - 1] == 0) dfs(grid, i, m - 1);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0) dfs(grid, 0, j);
            if (grid[n - 1][j] == 0) dfs(grid, n - 1, j);
        }

        // Count remaining islands
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};