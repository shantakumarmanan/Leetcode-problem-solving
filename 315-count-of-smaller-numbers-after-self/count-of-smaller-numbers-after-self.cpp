class Solution {
public:
    vector<int> ans, id;
    void ms(vector<int>& a, int l, int r){
        if(r-l<2) return;
        int m=(l+r)/2,i=l,j=m,c=0;
        ms(a,l,m); ms(a,m,r);
        vector<int> t;
        while(i<m&&j<r)
            if(a[id[j]]<a[id[i]]) t.push_back(id[j++]),c++;
            else ans[id[i]]+=c,t.push_back(id[i++]);
        while(i<m) ans[id[i]]+=c,t.push_back(id[i++]);
        while(j<r) t.push_back(id[j++]);
        copy(t.begin(),t.end(),id.begin()+l);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        ans.assign(n,0);
        id.resize(n);
        iota(id.begin(),id.end(),0);
        ms(nums,0,n);
        return ans;
    }
};