class Solution {
public:
    bool go(int rem,int turn){
        if(rem<=3)
            return turn;
        
        for(int i=1;i<=3;i++){
            if(go(rem-i,turn^1) == turn)
                return turn;
        }
        return turn^1;
    }
    bool canWinNim(int n) {
        return n%4;
    }
};