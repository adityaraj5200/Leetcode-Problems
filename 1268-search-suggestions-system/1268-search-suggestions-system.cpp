class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        auto it = A.begin();
        sort(it, A.end());
        vector<vector<string>> res;
        string typed;
        for (char c : searchWord) {
            typed += c;
            
            vector<string> suggested;
            it = lower_bound(it, A.end(), typed);
            for (int i = 0; i < 3 && it + i != A.end(); i++){
                string& s = *(it + i);
                
                bool flag = false;
                if(typed.size() > s.size()) break;
                for(int i=0;i<typed.size();i++){
                    if(typed[i] != s[i]){
                        flag = true;
                        break;
                    }
                }
                
                if(flag) break;
            
                suggested.push_back(s);
            }
            
            res.push_back(suggested);
        }
        return res;
    }
};