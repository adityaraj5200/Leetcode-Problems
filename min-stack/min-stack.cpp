class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    multiset<int> pq;
    MinStack() {
        stack.resize(30001);
    }
    
    void push(int val) {
        stack.push_back(val);
        pq.insert(val);
    }
    
    void pop() {
        int val = stack.back();
        pq.erase(pq.find(val));
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return *(pq.begin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */