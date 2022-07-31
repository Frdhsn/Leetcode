class Solution {
    public:
        const static int N = 1e5 + 9;
    bool vis[N];
    vector < int > g[N], r[N], vec; //G is the condensed graph
    void dfs1(int u) {
        vis[u] = 1;
        for (auto v: g[u])
            if (!vis[v]) dfs1(v);
        vec.push_back(u);
    }

    vector < int > comp;
    void dfs2(int u) {
        comp.push_back(u);
        vis[u] = 1;
        for (auto v: r[u])
            if (!vis[v]) dfs2(v);
    }
    int longestCycle(vector < int > & edges) {
        int n = edges.size();
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] != -1) {

                g[i].push_back(edges[i]);
                r[edges[i]].push_back(i);
            }
        }
        for (int i = 0; i < n; i++)
            if (!vis[i]) dfs1(i);
        reverse(vec.begin(), vec.end());
        memset(vis, 0, sizeof vis);
        int scc = 0, res = 0;
        for (auto u: vec) {
            if (!vis[u]) {
                comp.clear();
                dfs2(u);
                scc++;
                res = max(res, (int) comp.size());
            }
        }
        //cout<<"scc "<<scc<<endl;
        for (int i = 0; i < n; i++)
            vis[i] = 0, g[i].clear();
        vec.clear();
        if (res == 1) res = -1;
        return res;
    }
};