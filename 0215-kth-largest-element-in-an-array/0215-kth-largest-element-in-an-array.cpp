class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:nums){
            if(pq.empty()){
                pq.push(x);
            }
            else{
                if(pq.size()<k){
                    pq.push(x);
                }
                else{
                    if(x>pq.top()){
                        pq.pop();
                        pq.push(x);
                    }
                }
            }
        }
        while(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};