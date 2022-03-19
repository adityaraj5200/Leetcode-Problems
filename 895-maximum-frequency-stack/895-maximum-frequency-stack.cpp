class FreqStack {
public:
    map<int,int> freq;
    map<int,vector<int>> freqfreq;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        freqfreq[freq[val]].push_back(val);
    }
    
    int pop() {
        int maxfreq = (freqfreq.rbegin())->first;
        int val = (freqfreq.rbegin())->second.back();
        freq[val]--;
        if(freq[val]==0)
            freq.erase(val);
        freqfreq[maxfreq].pop_back();
        if(freqfreq[maxfreq].size() == 0)
            freqfreq.erase(maxfreq);
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */