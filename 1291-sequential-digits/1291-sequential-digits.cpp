class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        queue<int> q;
        for(int i=1;i<=9;i++)
            q.push(i);
        
        while(!q.empty()){
            int num = q.front();
            q.pop();
            
            if(num>=low && num<=high)
                ans.push_back(num);
            if(num > high)
                break;
            
            if(num%10 < 9)
                q.push((num*10) + (num%10)+1);
        }
        return ans;
    }
};