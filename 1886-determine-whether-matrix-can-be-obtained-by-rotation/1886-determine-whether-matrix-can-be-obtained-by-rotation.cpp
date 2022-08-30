class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void print(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        transpose(matrix);
        //print(matrix);
        
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target)
            return true;
        rotate(mat);
        if(mat == target)
            return true;
        rotate(mat);
        if(mat == target)
            return true;
        rotate(mat);
        if(mat == target)
            return true;
        return false;
    }
};