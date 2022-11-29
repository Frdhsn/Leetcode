class RandomizedSet {
public:
    vector<int> list;
    unordered_map<int,int> index;
    
    RandomizedSet() {
        list.clear();
        index.clear();
    }
    
    bool insert(int val) {
        // check if already present
        if(index.find(val) == index.end()){
            index[val] = list.size();
            list.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        // check if already present
        if(index.find(val) != index.end()){
            int sz = list.size();
            index[list[sz-1]] = index[val];
            swap(list[index[val]],list[sz-1]);
            index.erase(val);
            list.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int sz = list.size();
        return list[rand()%sz];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */