class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(char &ch: s)
            m[ch]++;
        
        vector<pair<int,char>> vec;
        for(auto &p: m)
            vec.push_back({p.second,p.first});
        
        sort(vec.begin(),vec.end());
        
        string res;
        for(auto &p: vec){
            int t = p.first;
            while(t--)
                res += p.second;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};