class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        int cnt=0,n = nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[j]-nums[i] == nums[k]-nums[j] && nums[k]-nums[j]==diff)cnt++;
                }
            }
        }
        return cnt;
    }
};