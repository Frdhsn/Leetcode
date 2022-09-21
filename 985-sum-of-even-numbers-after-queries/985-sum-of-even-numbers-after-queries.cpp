class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        int even=0;
        for(auto x:nums){
            if(x%2==0)even+=x;
        }
        for(auto x:queries){
            int v = x[0], index = x[1];
            
            if(nums[index]%2){
                if(v%2){ // sum is even
                    nums[index]+=v;
                    even+=nums[index];
                }
                else{
                    nums[index]+=v;
                }
            }
            else{
                if(v%2){ // sum is odd
                    even-=nums[index];
                    nums[index]+=v;
                }
                else{
                    nums[index]+=v;
                    even+=v;
                }
                
            }
            res.push_back(even);
        }
        return res;
    }
};