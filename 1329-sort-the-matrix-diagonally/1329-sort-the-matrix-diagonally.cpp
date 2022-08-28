class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int,multiset<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].insert(mat[i][j]);
            }
        }
        //for(int i=n-1;i>-m;i--)
            //sort(mp[i].begin(),mp[i].end());
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]= *mp[i-j].begin();
                mp[i-j].erase(mp[i-j].begin());
            }
        }
        return mat;
    }
};