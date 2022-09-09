class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
     {
          if (a[0] == b[0])
          {
               return a[1] > b[1];
          }
          return a[0] < b[0];
     }
    int numberOfWeakCharacters(vector<vector<int>>& pr) {
        sort(pr.begin(),pr.end(),cmp);
        int n = pr.size(), res=0,mn=-1e9;
       // for(auto x:pr)
       //     cout<<x[0]<<","<<x[1]<<endl;
        for(int i=n-1;i>=0;i--){
            
            if(pr[i][1] < mn)
                res++;
            mn = max(mn,pr[i][1]);
        }
        return res;
    }
};