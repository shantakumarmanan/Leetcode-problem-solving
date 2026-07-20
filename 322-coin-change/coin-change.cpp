class Solution {
public:
    int f(vector<int>& c, int i, int a, vector<vector<int>>& dp) {
        if (i == 0) return (a % c[0] == 0) ? a / c[0] : 1e9;
        if (dp[i][a] != -1) return dp[i][a];
        int nt = f(c, i - 1, a, dp);
        int t = 1e9;
        if (c[i] <= a) t = 1 + f(c, i, a - c[i], dp);
        return dp[i][a] = min(t, nt);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(coins, n - 1, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};