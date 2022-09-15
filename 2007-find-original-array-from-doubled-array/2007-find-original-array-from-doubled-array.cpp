class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.rbegin(),changed.rend());
        vector<int>res,boro(200007);
        for(auto x:changed){
            if(boro[x*2]>0){
                res.push_back(x);
                boro[x*2]--;
            }
            else{
                boro[x]++;
            }
        }
        for(int i=0;i<=100000;i++){
            if(boro[i]) return {};
        }
        //cout<<endl;
        //if(boro.size())return {};
        return res;
    }
};