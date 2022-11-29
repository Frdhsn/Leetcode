class RandomizedSet {
public:
        set<int>S;
        map<int,bool>M;
    /** Initialize your data structure here. */
    RandomizedSet() {
        S.clear();
        M.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(M[val]==0){
            M[val]=1;
            S.insert(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
        if(M[val]==0)return false;
        
        M[val]=0;
        S.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int sz = S.size();
        int cnt = rand()%sz;
        int i=0;
        for(auto it:S){
            if(cnt==i)return it;
            i++;
            
        }
        return *S.begin();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */