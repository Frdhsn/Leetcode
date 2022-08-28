class Solution {
public:
    bool isPalindrome(string s) {
        string tmp="";
        for(auto x:s){
            if(isalnum(x)){
                if(isupper(x)) x = tolower(x);
                tmp.push_back(x);
            }
        }
        string rtmp=tmp;
        reverse(tmp.begin(),tmp.end());
        return tmp==rtmp;
    }
};