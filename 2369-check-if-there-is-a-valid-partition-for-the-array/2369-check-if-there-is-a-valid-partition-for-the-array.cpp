
class Solution {
    public:
    int n;
    int dp[100100];
    bool ret[100100];
    vector<int>num;

    bool solve(int i){
        if(i>=n) return true;
        if(dp[i]!=-1) return ret[i];

        bool ans = false;

        if(i+1<n && num[i+1]==num[i]){
            if(solve(i+2)==true) ans = true;
        }
        if(i+2<n && num[i]==num[i+1] && num[i]==num[i+2]){
            if(solve(i+3)==true) ans = true;
        }
        if(i+2<n && num[i]+1==num[i+1] && num[i]+2==num[i+2]){
            if(solve(i+3)==true) ans = true;
        }
        dp[i] = 1;
        return ret[i] = ans;
    }

    bool validPartition(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        num = nums;

        return solve(0);
    }
};