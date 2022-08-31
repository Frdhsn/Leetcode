class Solution {
public:
    int dx[5]={-1,1,0,0};
    int dy[5]={0,0,-1,1};
    int a,p;
    bool isPacificOcean(int i,int j,int n,int m){
        return (i<n && j==-1)or(i==-1&&j>=0);
    }
    bool isAtlanticOcean(int i,int j,int n,int m){
        return (i==n)or(i>=0&&j==m);
    }
    bool isValid(int i,int j,int n,int m){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    bool vs[205][205];
    void dfs(int i,int j,int n,int m,vector<vector<int>>& heights){
        //cout<<"("<<i<<","<<j<<")\n";
        if(isPacificOcean(i,j,n,m)){
            p++;
            return;
        }
        if(isAtlanticOcean(i,j,n,m)){
            a++;
            return;
        }
        if(isValid(i,j,n,m)==0 or vs[i][j])return;
        vs[i][j]=1;
        for(int k=0;k<4;k++){
            int x = dx[k]+i;
            int y = dy[k]+j;
            
            if(isValid(x,y,n,m)){
                if(heights[x][y]<=heights[i][j]){
                    dfs(x,y,n,m,heights);
                }
            }
            else{
                dfs(x,y,n,m,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a=0,p=0;
                //cout<<"start: ";
                dfs(i,j,n,m,heights);
                //cout<<"end\n";
                if(a&&p){
                    vector<int>t;
                    t.push_back(i);
                    t.push_back(j);
                    res.push_back(t);
                }
                memset(vs,0,sizeof vs);
            }
        }
        return res;
    }
};