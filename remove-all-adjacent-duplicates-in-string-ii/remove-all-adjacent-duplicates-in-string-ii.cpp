class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char,int>> q;
        for(char &ch: s){
            if(q.empty()) q.push_back({ch,1});
            else if (q.back().first != ch) q.push_back({ch,1});
            else q.back().second++;
            
            if(q.back().second == k)
                q.pop_back();
        }
        
        string result;
        while(!q.empty()){
            string toAdd(q.front().second , q.front().first);
            result += toAdd;
            q.pop_front();
        }
        return result;
        
    }
};