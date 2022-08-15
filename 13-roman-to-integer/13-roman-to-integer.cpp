class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        map<char,int> mp;
        
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int n = s.size();
        
        for(int i=n-1;i>=0;i--){
            if(s[i] == 'I' && i+1<n && (s[i+1]=='V' or s[i+1]=='X')){
                res--;
            }
            else if(s[i] == 'X' && i+1<n && (s[i+1]=='L' || s[i+1]=='C')){
                res-=10;
            }
            else if(s[i] == 'C' && i+1<n && (s[i+1]=='D' || s[i+1]=='M') ){
                res-=100;
            }
            else{
                res+=mp[s[i]];
            }
        }
        return res;
    }
};