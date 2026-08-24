class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> answer(2);
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(m.find(diff) != m.end() && i != m[diff]){
                answer[0] = i;
                answer[1] = m[diff];
                return answer;
            }
            m[nums[i]] = i;
        }
        return answer;
        
    }
};