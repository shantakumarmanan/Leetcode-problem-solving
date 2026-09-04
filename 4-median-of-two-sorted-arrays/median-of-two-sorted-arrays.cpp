class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> c;
        int i = 0, j=0;
        while(i<a.size() && j<b.size()){
            if(a[i] <= b[j]){
                c.push_back(a[i]);
                i++;
            }
            else{
                c.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size()){
            c.push_back(a[i]);
            i++;
        }
        while(j<b.size()){
            c.push_back(b[j]);
            j++;
        }
        int n = c.size();
        if(n % 2 == 1) {
            return c[n / 2];
        }
        else {
            return (c[n/2 - 1] + c[n/2]) / 2.0;
        }
    }
};