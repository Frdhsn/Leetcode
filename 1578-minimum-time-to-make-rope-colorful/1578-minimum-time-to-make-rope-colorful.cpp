class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int res=0;
        for(int l=0;l<n;l++){
            int mx = 0, sum=0,r=l;
            
            while(r<n&&colors[l]==colors[r]){
                sum+=neededTime[r];
                mx = max(mx,neededTime[r]);
                r++;
            }
            res+= sum-mx;
            if(r>=n)break;
            l=r-1;
        }
        return res;
    }
};