class Solution {
public:
    bool valid(int i,int j,int n,int m){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    void dfs(int x,int y,vector<vector<char>>& image,int n,int m,vector<vector<int>>&vs){
        if(valid(x,y,n,m)==0 or vs[x][y] or image[x][y]=='0')
            return;
        vs[x][y]=1;
        dfs(x+1,y,image,n,m,vs);
        dfs(x,y+1,image,n,m,vs);
        dfs(x-1,y,image,n,m,vs);
        dfs(x,y-1,image,n,m,vs);
    }
    int numIslands(vector<vector<char>>& image) {
        int n = image.size();
        if(!n)return 0;
        int m = image[0].size();
        if(!m)return 0;
        vector<vector<int>>vs(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vs[i][j]==0&&image[i][j]=='1'){
                    cnt++;
                    dfs(i,j,image,n,m,vs);
                }
            }
        }
        return cnt;
    }
};