class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> ans;
        int i = 0;
        int n = a.size();
        while(i<n && a[i][1] < b[0]){
            ans.push_back(a[i]);
            i++;
        }
        while(i<n && a[i][0] <= b[1]){
            b[0] = min(b[0] , a[i][0]);
            b[1] = max(b[1], a[i][1]);
            i++; 
        }
        ans.push_back(b);
        while(i<n){
            ans.push_back(a[i]);
            i++;
        }
        return ans;
    }
};