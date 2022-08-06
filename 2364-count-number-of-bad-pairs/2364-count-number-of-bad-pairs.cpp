class Solution {
public:
    using ll = long long int;
    long long countBadPairs(vector<int>& nums) {
        map<ll,ll> cnt;
        ll n = nums.size();
        ll res=0;
        for(int i=0;i<nums.size();i++){
            res+=cnt[nums[i]-i]++;
            cnt[nums[i]-i]++;
        }
        res/=2;
        ll tot = n*(n-1)/2;
        res = tot - res;
        return res;
    }
};