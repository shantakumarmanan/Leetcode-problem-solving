class Solution {
public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }
    int solve(string &s, int start, int end, int k) {
        if (end - start < k)
            return 0;

        vector<int> freq(26, 0);
        for (int i = start; i < end; i++)
            freq[s[i] - 'a']++;
        for (int mid = start; mid < end; mid++) {
            if (freq[s[mid] - 'a'] >= k)
                continue;
            int nextMid = mid + 1;
            while (nextMid < end &&
                   freq[s[nextMid] - 'a'] < k)
                nextMid++;
            return max(solve(s, start, mid, k),
                       solve(s, nextMid, end, k));
        }
        return end - start;
    }
};