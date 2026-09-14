class Solution {
public:
    int countDigits(int n) {
        int a = n;
        int count = 0;
        while(a>0){
            int d = a%10;
            if(n%d == 0){
                count++;
            }
            a = a/10;
        }
        return count;
    }
};