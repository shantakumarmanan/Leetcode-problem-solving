class NumArray {
    vector<int> t; int n;
    void build(int i, int l, int r, vector<int>& a){
        if(l==r) return t[i]=a[l],void();
        int m=(l+r)/2;
        build(2*i+1,l,m,a); build(2*i+2,m+1,r,a);
        t[i]=t[2*i+1]+t[2*i+2];
    }
    void upd(int i,int l,int r,int p,int v){
        if(l==r) return t[i]=v,void();
        int m=(l+r)/2;
        p<=m?upd(2*i+1,l,m,p,v):upd(2*i+2,m+1,r,p,v);
        t[i]=t[2*i+1]+t[2*i+2];
    }
    int qry(int i,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr) return t[i];
        if(r<ql||l>qr) return 0;
        int m=(l+r)/2;
        return qry(2*i+1,l,m,ql,qr)+qry(2*i+2,m+1,r,ql,qr);
    }
public:
    NumArray(vector<int>& nums){
        n=nums.size();
        t.resize(4*n);
        build(0,0,n-1,nums);
    }
    void update(int index,int val){ upd(0,0,n-1,index,val); }
    int sumRange(int left,int right){ return qry(0,0,n-1,left,right); }
};