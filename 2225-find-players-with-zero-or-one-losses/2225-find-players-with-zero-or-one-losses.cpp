class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> st;
        map<int,int> loss;
        for(auto x:matches){
            st.insert(x[0]);
            st.insert(x[1]);
            if(loss[x[1]] <=1 )
                loss[x[1]]++;
        }
        vector<vector<int>>res;
        vector<int> f, s;
        for(auto x:st){
            //auto x = y.first;
            if(loss[x]==1){
                s.push_back(x);
            }
            if(loss[x]==0){
                f.push_back(x);
            }
        }
        sort(f.begin(),f.end());
        sort(s.begin(),s.end());
        res.push_back(f);
        res.push_back(s);
        return res;
    }
};