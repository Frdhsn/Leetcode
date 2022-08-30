// rotate groups of four cells
// top left: matrix[i][j]

// top right: matrix[j][n-i-1]
// bottom left: matrix[n-1-j][i]
// bottom right: matrix[n-1-i][n-j-1]
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<(n+1)/2;i++){
            for(int j=0;j<n/2;j++){
                
                // bottom left
                int tmp = matrix[n-1-j][i];
                
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-j-1]=matrix[j][n-1-i];
                
                matrix[j][n-1-i]=matrix[i][j];
                matrix[i][j]=tmp;
            }
        }
    }
};