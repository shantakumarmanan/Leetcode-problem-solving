class Solution {
public:
    unordered_map<int, int> pos;
    vector<vector<int>> dp;
    bool solve(vector<int>& stones, int i, int k) {
        if (i == stones.size() - 1) return true;
        if (dp[i][k] != -1) return dp[i][k];
        for (int jump = k - 1; jump <= k + 1; jump++) {
            if (jump <= 0) continue;
            int next = stones[i] + jump;
            if (pos.count(next) && solve(stones, pos[next], jump))
                return dp[i][k] = true;
        }
        return dp[i][k] = false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; i++)
            pos[stones[i]] = i;
        dp.assign(n, vector<int>(n + 1, -1));
        return solve(stones, 0, 0);
    }
};