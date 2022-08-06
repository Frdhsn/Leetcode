class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets==1)return 0; // it's the poisonous bucket
        
        int pigs=1;
        
        int base = minutesToTest/minutesToDie + 1;
        
        int used=base;
        
        while(used < buckets){
            
            used=used*base;
            pigs++;
        }
        return pigs;
    }
};