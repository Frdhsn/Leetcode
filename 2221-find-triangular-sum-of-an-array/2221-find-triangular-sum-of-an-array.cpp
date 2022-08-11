class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        // generating pascals traingle
        vector<int> triangle(n+1,0);
        
        triangle[0] = 1;
        for(int i=1;i<n;i++){
            for(int j=i;j>=1;j--){
                triangle[j]+=triangle[j-1]%10;
                triangle[j]%=10;
            }
        }
        int ret=0;
        for(int i=0;i<n;i++){
            ret+=(triangle[i]*nums[i])%10;
            ret%=10;
        }
        cout<<endl;
        return ret;
    }
};