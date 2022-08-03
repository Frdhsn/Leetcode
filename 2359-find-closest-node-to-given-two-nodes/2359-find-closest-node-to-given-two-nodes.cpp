class Solution {
public:
    vector<int> g[100007];
    void dfs(int u,int p,vector<int>&dist,vector<bool>&vs){
        if(vs[u])return;
        vs[u]=1;
        if(p==-1){
            dist[u]=0;
        }
        else dist[u]=min(dist[u],dist[p]+1);
        if(g[u].size()){
            if(g[u][0]!=p)
            dfs(g[u][0],u,dist,vs);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1)
            g[i].push_back(edges[i]);
        }
        vector<int>dist1(n,1e9),dist2(n,1e9);
        vector<bool>vs1(n),vs2(n);
        dfs(node1,-1,dist1,vs1);
        dfs(node2,-1,dist2,vs2);
        // vector<int> cost1(n,-1);
        // int d=0;
        // for(auto x:path1){
        //     cost1[x] = d++;
        // }
        // d=0;
        int res_node=-1,res_d=1e9;
        for(int i=0;i<n;i++){
            if(dist1[i]!=1e9 && dist2[i]!=-1e9){
                if(res_d > max(dist1[i],dist2[i])){
                    res_d = max(dist1[i],dist2[i]);
                    res_node = i;
                }
            }
        }
        return res_node;
    }
};