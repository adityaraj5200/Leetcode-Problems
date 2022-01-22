class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hashmap;
        for(auto s: strs){
            string word = s;
            sort(s.begin(),s.end());
            hashmap[s].push_back(word);
        }
        vector<vector<string>> result;
        for(auto &p: hashmap){
            result.push_back(p.second);
        }
        return result;
    }
};