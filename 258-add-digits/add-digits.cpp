class Solution {
public:
    int addDigits(int a) {
        int s = a;
        int n = a;
        while (n > 9){
            s=0;
            a=n;
            while (a > 0) {
                int d = a % 10;
                s = s + d;
                a = a / 10;
                // cout<<s<<" ";
            }
            n=s;

            if(s<=9){
                return s;
            }
            cout<<n<<" ";
        }
        return s;
    }
};