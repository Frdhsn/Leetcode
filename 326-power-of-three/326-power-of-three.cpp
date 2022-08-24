class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        
        double x = log10(n*1.0)/(log10(3.0)*1.0);
        int y = x;
        
        return x == y;
    }
};