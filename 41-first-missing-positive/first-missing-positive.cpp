class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for(int x : nums){
            if(x>0)
            s.insert(x);
        }
        int ans = 0;
        for(int i = 1; i<=s.size(); i++){
            if(s.find(i) == s.end()){
                return i;
            }
        }
        return s.size()+1;
    }
};