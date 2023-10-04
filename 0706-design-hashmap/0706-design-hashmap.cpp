class MyHashMap {
private:
    list<pair<int, int>> myMap;
    
public:
    MyHashMap() {}
    
    void put(int key, int value) {
        bool found = false;
        
        for(auto it = myMap.begin(); it != myMap.end(); it++)
        {
            if(it->first == key)
            {
                it->second = value;
                found = true;
                break;
            }
        }
        
        if(!found)
            myMap.push_back({key, value});
    }
    
    int get(int key) {
        for(auto it = myMap.begin(); it != myMap.end(); it++)
            if(it->first == key)
                return it->second;
        
        return -1;
    }
    
    void remove(int key) {
         auto rem = myMap.end();
        
        for(auto it = myMap.begin(); it != myMap.end(); it++)
        {
            if(it->first == key)
            {
                rem = it;
                break;
            }
        }
        
        if(rem != myMap.end())
            myMap.erase(rem);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */