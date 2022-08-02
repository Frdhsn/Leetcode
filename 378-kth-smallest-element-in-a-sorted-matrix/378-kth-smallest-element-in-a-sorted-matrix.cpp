class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int cnt=1;
        vector<int>v;
        priority_queue<int> pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(pq.size()<k){
                    pq.push(matrix[i][j]);
                }
                else{ // pq.size() == k
                    if(pq.top()>matrix[i][j]){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};
