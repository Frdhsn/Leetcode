class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n  = nums.size(),i=0,j=0;
        vector<int>temp(n);
        while(j<nums.size()-1){
            for(int i=0;i<nums.size()-1;i++)
                temp[i]= (nums[i]+nums[i+1])%10;
            nums = temp;
            j++;
        }
        return nums[0];
    }
};