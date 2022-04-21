class MyHashSet {
public:
    set<int> myset;
    MyHashSet() {
        myset.clear();
    }
    
    void add(int key) {
        myset.insert(key);
    }
    
    void remove(int key) {
        if(myset.find(key) != myset.end())
            myset.erase(key);
    }
    
    bool contains(int key) {
        return myset.find(key) != myset.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */