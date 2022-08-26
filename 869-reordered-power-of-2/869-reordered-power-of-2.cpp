class Solution {
public:
    vector<int> digits(int n){
        vector<int>ret;
        while(n){
            ret.push_back(n%10);
            n/=10;
        }
        sort(ret.begin(),ret.end());
        return ret;
    }
    // bool isLeadingZero(vector<int>&t){
    //     return t[0]==0;
    // }
    // bool isPowerOfTwo(vector<int>&t){
    //     int num=0;
    //     for(int i=0;i<t.size();i++){
    //         num = num*10 + t[i];
    //     }
    //     return __builtin_popcount(num)==1;
    // }
    // void print(vector<int>&a){
    //     for(auto x:a){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    // bool reorderedPowerOf2(int n) {
    //     vector<int> nums = digits(n);
    //     sort(nums.begin(),nums.end());
    //     int sz = nums.size();
    //     vector<int>p;
    //     for(int i=1;i<=nums.size();i++){
    //         p.push_back(i);
    //     }
    //     do{
    //         //print(p);
    //         vector<int>t(sz);
    //         int i=0;
    //         for(auto idx:p)
    //             t[i++]=nums[idx-1];
    //         if(isLeadingZero(t)==0){
    //             if(isPowerOfTwo(t))
    //                 return true;
    //         }
    //     }while(next_permutation(p.begin(),p.end()));
    //     return false;
    // }
    bool reorderedPowerOf2(int n) {
        vector<int> nums = digits(n);
        //sort(nums.begin(),nums.end());
        for(long long i=1;i<=1000000000;i=i*2){
            if(nums == digits(i)) 
                return true;
        }
        return false;
    }
};