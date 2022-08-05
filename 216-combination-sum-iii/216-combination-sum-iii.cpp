class Solution {
public:
    
    void go(int idx,int mask,int sum, int k,int n, vector<vector<int>> &res){
        if(idx >=10){
            
            if(sum==0 &&  __builtin_popcount(mask) == k){
                vector<int>temp;
                int s=0;
                for(int i=0;i<10;i++){
                    if(mask&(1<<i)){
                        temp.push_back(i+1);
                        s+=(i+1);
                    }
                }
                if(s == n)
                res.push_back(temp);
            }
            return;
        }
        if(sum-idx>=0)
        go(idx+1,mask|(1<<(idx-1)),sum-idx,k,n,res);
        go(idx+1,mask         ,sum      ,k,n,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        go(1,0,n,k,n,res);
        return res;
    }
};