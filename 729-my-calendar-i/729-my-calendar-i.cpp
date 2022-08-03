class MyCalendar {
public:
    vector<pair<int,int>> ranges;
    MyCalendar() {
        ranges = {};
    }
    
    bool book(int start, int end) {
        for(pair<int,int> range: ranges){
            int curr_st = range.first, curr_end = range.second;
            bool intersect = !(curr_end<=start || end<=curr_st);
            if(intersect){
                return false;
            }
        }
        
        ranges.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */