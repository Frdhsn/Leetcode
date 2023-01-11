class Solution {
public:
    static const int MAX = 1e5 + 7;
    vector<int>g[MAX];
    bool has[MAX];
    int sub[MAX];
    int dfs(int u,int p,int n,vector<bool>& hasApple){
        int ret=0;
        for(int v:g[u]){
            if(v==p)continue;
            ret|=dfs(v,u,n,hasApple);
            
        }
        if(hasApple[u])ret=1;
        return has[u] = ret;
    }
    int dfs2(int u,int p,int n,vector<bool>& hasApple){
        int ret=0;
        for(int v:g[u]){
            if(v==p)continue;
            ret+=dfs2(v,u,n,hasApple);
            
        }
        if(has[u])ret+=1;
        return sub[u] = ret;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //memset(has,0,sizeof has);
        //for(int i=0;i<=n;i++)g[i].clear();
        for(vector<int>e:edges){
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,0,n,hasApple);
        dfs2(0,0,n,hasApple);
        int ret=0;
        for(int v:g[0]){
            if(has[v]){ret+=sub[v]*2;}
        }
        return ret;
    }
};