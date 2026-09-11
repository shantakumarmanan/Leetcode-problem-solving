class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i<=right; i++){
            int n = 0;
            n=i;
            bool x = true;
            while(n>0){
                int d = n%10;
                if(d==0||i%d!=0){
                    x = false;
                    break;
                }
                n=n/10;
            }
            if(x==true)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};