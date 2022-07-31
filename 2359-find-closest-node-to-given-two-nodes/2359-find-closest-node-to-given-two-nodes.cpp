class Solution {
public:
    vector<int> g[100007];
    void dfs(int u,int p,vector<int>&path,vector<bool>&vs){
        if(vs[u])return;
        vs[u]=1;
        path.push_back(u);
        if(g[u].size())
        dfs(g[u][0],u,path,vs);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1)
            g[i].push_back(edges[i]);
        }
        vector<int>path1,path2;
        vector<bool>vs1(n),vs2(n);
        dfs(node1,0,path1,vs1);
        dfs(node2,0,path2,vs2);
        vector<int> cost1(n,-1);
        int d=0;
        for(auto x:path1){
            cost1[x] = d++;
        }
        d=0;
        int res_node=-1,res_d=1e9;
        for(auto x:path2){
            if(cost1[x]!=-1){
                if(res_d > max(cost1[x],d)){
                    res_d = max(cost1[x],d);
                    res_node = x;
                }
                d++;
            }
        }
        return res_node;
    }
};