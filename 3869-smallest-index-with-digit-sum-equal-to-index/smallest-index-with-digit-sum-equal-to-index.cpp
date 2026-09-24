class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int m = 0;
            int a = nums[i];

            while (a > 0) {
                m += a % 10;
                a /= 10;
            }

            if (i == m) {
                return i;
            }
        }

        return -1;
    }
};