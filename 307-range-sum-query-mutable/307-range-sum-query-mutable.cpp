class NumArray {
public:
    int BIT[30007],n,ar[30007];
    NumArray(vector<int>& nums) {
        n = nums.size();
        for(int i=1;i<=n;i++)
            BIT[i]=0;
        for(int i=1;i<=n;i++){
            ar[i]=nums[i-1];
            updateX(i,ar[i]);
        }
    }
    
    void updateX(int idx,int val)
    {
        for(;idx<=n;idx+=(idx&-idx))
            BIT[idx]+=val;
    }
    void update(int idx,int val)
    {
        idx++;
        updateX(idx,-ar[idx]);
        ar[idx]=val;
        updateX(idx,ar[idx]);
    }
    int query(int idx)
    {
        int ans=0;
        for(;idx>0;idx-=(idx&-idx))
            ans+=BIT[idx];
        return ans;
    }
    
    int sumRange(int left, int right) {
        return query(right+1)-query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */