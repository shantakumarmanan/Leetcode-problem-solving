class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        if (fresh == 0) return 0;
        vector<int> d = {0, 1, 0, -1, 0};
        int time = 0;
        while (!q.empty()) {
            int sz = q.size();
            bool rotten = false;
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int ni = x + d[k];
                    int nj = y + d[k + 1];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                        grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        fresh--;
                        rotten = true;
                        q.push({ni, nj});
                    }
                }
            }
            if (rotten)
                time++;
        }
        return (fresh == 0) ? time : -1;
    }
};