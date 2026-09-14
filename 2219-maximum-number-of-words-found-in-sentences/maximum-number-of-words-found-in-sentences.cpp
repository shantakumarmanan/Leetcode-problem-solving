class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(string s : sentences){
            int count = 1;
            for(char c : s){
                if(c == ' '){
                    count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};