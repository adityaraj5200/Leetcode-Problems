class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> hashmap;
        for(int i=0;i<strs.size();i++){
            string word = strs[i];
            sort(word.begin(),word.end());
            hashmap[word].push_back(i);
        }
        
        vector<vector<string>> ans;
        for(auto p: hashmap){
            vector<string> temp;
            for(int idx: p.second){
                temp.push_back(strs[idx]);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};