class MyHashSet {
    vector<int> hash;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!contains(key))
        hash.push_back(key);
    }
    
    void remove(int key) {
        if(contains(key)){
        hash.erase(std::remove(hash.begin(), hash.end(), key), hash.end());
        }
    }
    
    bool contains(int key) {
        auto it = find(hash.begin(), hash.end(), key);
        if(it == hash.end()) {
            return false;
        }
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */