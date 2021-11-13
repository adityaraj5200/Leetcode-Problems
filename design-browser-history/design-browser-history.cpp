class BrowserHistory {
public:
    
    vector<string> vec;
    int i;
    BrowserHistory(string homepage) {
        vec.push_back(homepage);
        i = 0;
    }
    
    void visit(string url) {
        while(vec.size() > i+1)
            vec.pop_back();
        vec.push_back(url);
        i++;
    }
    
    string back(int steps) {
        i = max(0,i-steps);
        return vec[i];
        
    }
    
    string forward(int steps) {
        i += steps;
        if(i>=vec.size())
            i = vec.size()-1;
        return vec[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */