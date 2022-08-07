class Solution {
public:
    vector<int> g[100005];
    int res;
    void dfs(int u,int p,vector<int>& bad){
        if(bad[u])return;
        res++;
        for(auto v:g[u]){
            if(v!=p)
                dfs(v,u,bad);
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        for(auto x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<int> bad(n+7, 0);
        for(auto x:restricted)
            bad[x]=1;
        res=0;
        dfs(0,0,bad);
        return res;
    }
};