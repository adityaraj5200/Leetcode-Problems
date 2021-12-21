class OrderedStream {
public:
    vector<string> vec;
    int i;
    OrderedStream(int n) {
        i = 0;
        vec = vector<string>(n,"");
    }
    
    vector<string> insert(int idKey, string value) {
        idKey--;
        vec[idKey] = value;
        vector<string> ans;
        while(i<vec.size() && vec[i]!="")
            ans.push_back(vec[i++]);
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */