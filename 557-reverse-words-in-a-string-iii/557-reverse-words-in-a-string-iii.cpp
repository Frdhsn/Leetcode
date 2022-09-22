class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res="",temp;
        
        int n = s.size();
        
        while(ss>>temp){
            reverse(temp.begin(),temp.end());
            res+=temp;
            res+=" ";
        }
        res.pop_back();
        return res;
    }
};