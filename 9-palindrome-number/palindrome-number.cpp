class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int d;
        long rev = 0;
        int og = x;
        while(x>0){
            d= x % 10;
            rev = rev * 10 + d;
            x = x/10;
        }
        if(og == rev){
            return true;
        } else{
            return false;
        }
    }
};