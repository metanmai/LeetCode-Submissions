class RandomizedSet {
private:
    set<int> nums;
    
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(nums.find(val) != nums.end())
            return false;
        
        nums.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(nums.find(val) == nums.end())
            return false;
        
        nums.erase(val);
        return true;
    }
    
    int getRandom() {
        int random = rand() % nums.size();
        auto it = nums.begin();
        
        return *(next(it, random));
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */