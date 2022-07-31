class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res=0;
        while(true){
            vector<int> tmp;
            int mn = 1e9;
            for(auto x:nums){
                if(x){
                    mn = min(mn,x);
                }
            }
            for(auto x:nums){
                if(x){
                    tmp.push_back(x-mn);
                }
            }
            nums = tmp;
            if(nums.empty())break;
            res++;
        }
        return res;
    }
};