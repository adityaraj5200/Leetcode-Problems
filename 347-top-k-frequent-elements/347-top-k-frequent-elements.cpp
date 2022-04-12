class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int &val: nums){
            freq[val]++;
        }
        
        vector<pair<int,int>> vec;
        for(auto p: freq){
            vec.push_back({p.second,p.first});
        }
        
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        
        return ans;
    }
};