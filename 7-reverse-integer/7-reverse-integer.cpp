class Solution {
public:
    int reverse(int x) {
        int y = abs(x);
        long long int n=0;
        while(y){
            n = n*10 + y%10;
            y/=10;
        }
        if(n > INT_MAX or n< INT_MIN)return 0;
        if(x<0)
        return -n;
        return n;
    }
};