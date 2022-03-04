class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int &val: stones){
            pq.push(val);
        }
        
        while(pq.size()>=2){
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            if(y-x > 0)
                pq.push(y-x);
        }
        
        return pq.size() == 1 ? pq.top() : 0;
    }
};