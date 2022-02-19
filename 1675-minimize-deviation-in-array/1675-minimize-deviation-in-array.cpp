class Solution{
public:
    int minimumDeviation(vector<int>& nums){
        int minval = INT_MAX;
        int ans = INT_MAX;
        priority_queue<int> pq;
        
        for(int val: nums){
            if(val&1) val <<= 1;
            pq.push(val);
            minval = min(minval, val);
        }
        
        while(pq.top()%2==0){
            int top = pq.top();
            pq.pop();
            ans = min(ans,top-minval);
            minval = min(minval,top/2);
            pq.push(top/2);
        }
        
        return min(ans,pq.top()-minval);
    }
};