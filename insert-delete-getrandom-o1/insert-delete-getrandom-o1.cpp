class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int,int> m;
    
    template<typename T>
    T random(T l,T r){
        return rand() % (r-l+1) + l;
    }

    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()){
            m[val] = (int)vec.size();
            vec.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            int idx = m[val], lastval = vec.back();
            m[lastval] = idx;
            m.erase(val);
            vec[idx] = lastval;
            vec.pop_back(); 
            
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        // for(int &val: vec) cout<<val<<' '; cout<<endl;
        int idx = random(0,(int)vec.size()-1);
        return vec[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */