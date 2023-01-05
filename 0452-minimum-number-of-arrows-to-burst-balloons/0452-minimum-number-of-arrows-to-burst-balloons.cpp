class Solution {
public:
    static bool fun(vector<int>&a,vector<int>&b){
        if(a[0]<b[0]) return true;
        if(a[0]>b[0]) return false;
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),fun);
        int n = points.size();
        if(n==1)return 1;
        
        vector<int> curr=points[0];
        int res=1;
        for(int i=1;i<n;i++){
            //cout<<points[i][0]<<" "<<points[i][1]<<endl;
            if(points[i][0] <= curr[1] && points[i][0]>=curr[0]){
                curr[0] = max(curr[0],points[i][0]);
                curr[1] = min(curr[1],points[i][1]);
            }
            else{
                res++;
                curr = points[i];
            }
        }
        return res;
    }
};