class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> st;
        map<int,int> loss;
        for(auto x:matches){
            st[x[0]]=1;
            st[x[1]]=1;
            if(loss[x[1]] <= 1 )
                loss[x[1]]++;
        }
        vector<vector<int>>res;
        vector<int> f, s;
        for(auto y:st){
            auto x = y.first;
            if(loss[x]==1){
                s.push_back(x);
            }
            if(loss[x]==0){
                f.push_back(x);
            }
        }
        // sort(f.begin(),f.end());
        // sort(s.begin(),s.end());
        res.push_back(f);
        res.push_back(s);
        return res;
    }
};