class Solution {
public:
    using ll = long long int;
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
       ll curr = startFuel,res=0;
        priority_queue< ll > pq;
        
        for(int i=0;curr<target;res++){
            while(i<stations.size()&&stations[i][0]<=curr)
            {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())return -1;
            curr+=pq.top();
            pq.pop();
        }
        return res;
    }
};