class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentmax = nums[0];
        int maximum = nums[0];
        for(int i=1; i<nums.size(); i++){
            currentmax = max(nums[i] , currentmax + nums[i]);
            maximum = max(currentmax , maximum);
        }
        return maximum;
    }
};