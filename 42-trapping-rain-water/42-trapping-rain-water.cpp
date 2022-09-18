class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans = 0;
        int n = height.size();
        if(!n)return 0;
        
        
        vector<int> prefix(n), suffix(n);
        prefix[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(height[i], prefix[i - 1]);
        }
        suffix[n- 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(height[i], suffix[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            ans += min(prefix[i], suffix[i]) - height[i];
        }
        return ans;
    }
};