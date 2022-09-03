class Solution {
public:
    int digit(int n){
        if(n<10)return 1;
        return 1 + digit(n/10);
    }
    void gen(int num,int k,int n,vector<int>&res){
        if( digit(num) == n){
            res.push_back(num);
            return;
        }
        int r = num%10;
        int nxt = 0;
        if(r+k<=9){
            nxt = r+k;
            gen(num*10+nxt,k,n,res);
        }
        if(r-k>=0&&k){
            nxt = r-k;
            gen(num*10+nxt,k,n,res);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        int curr = 1;
        vector<int>res;
        for(int i=1;i<=9;i++)
            gen(i,k,n,res);
        return res;
    }
};