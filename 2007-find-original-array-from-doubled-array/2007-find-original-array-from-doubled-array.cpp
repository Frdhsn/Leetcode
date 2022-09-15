class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.rbegin(),changed.rend());
        vector<int>res;
        map<int,int> boro;
        for(auto x:changed){
            if(boro[x*2]>0){
                res.push_back(x);
                boro[x*2]--;
            }
            else{
                boro[x]++;
            }
        }
        for(auto x:boro){
            if(x.second) return {};
        }
        //cout<<endl;
        //if(boro.size())return {};
        return res;
    }
};