class Solution {
public:
    bool isPrime(int n){
        if(n<2)return false;
        
        int r = sqrt(n);
        
        for(int i=2;i<=r;i++){
            if(n%i==0)return false;
        }
        return true;
    }
    
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
    
    bool isPalindrome(int x){
        return x == reverse(x);
    }
    int primePalindrome(int n) {
        if(n>=1e7&&n<=1e8) return 100030001;
        if(isPrime(n)&&isPalindrome(n))
            return n;
        return primePalindrome(n+1);
    }
};