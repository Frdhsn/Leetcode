class Solution {
public:
    using ll = long long int;
    pair<ll,ll> dectobin(int st,int x){
        //cout<<"base "<<st<<", ";
        //cout<<x<<": ";
        ll ret=0,b=st,mod=1e9+7;
        while(x){
            if(x&1){
                ret=ret%mod+b%mod;
            }
            ret%=mod;
            b=b*2;
            b%=mod;
            x/=2;
            if(x){
                
                st=st*2;
                st%=mod;
            }
        }
        //cout<<" dec "<<ret<<endl;
        return {ret,st};
    }
    int concatenatedBinary(int n) {
        ll res=0,mod= 1e9+7,st=1;
        
        for(int i=n;i>=1;i--){
            pair<ll,ll> ret = dectobin(st,i);
            res+=ret.first;
            res%=mod;
            st=ret.second*2;
            st%=mod;
        }
        return res;
    }
};