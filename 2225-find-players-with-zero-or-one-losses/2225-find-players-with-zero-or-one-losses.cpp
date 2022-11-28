class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> st;
        map<int,int> loss;
        for(auto x:matches){
            st.insert(x[0]);
            st.insert(x[1]);
            loss[x[1]]++;
        }
        vector<vector<int>>res;
        vector<int> f, s;
        for(auto x:st){
            if(loss[x]==1){
                s.push_back(x);
            }
            if(loss[x]==0){
                f.push_back(x);
            }
        }
        res.push_back(f);
        res.push_back(s);
        return res;
    }
};