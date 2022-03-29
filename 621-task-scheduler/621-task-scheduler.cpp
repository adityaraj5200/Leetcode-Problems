class Solution {
public:
    int leastInterval(vector<char>& tasks, int n){
        vector<int> freq(26,0);
        for(char &ch: tasks)
            freq[ch-'A']++;
        
        sort(freq.begin(),freq.end());
        
        int maxFreq = freq.back();
        int emptySlots = (maxFreq-1)*n;
        
        for(int i=24;i>=0;i--){
            emptySlots -= min(freq[i],maxFreq-1);
        }
        
        return tasks.size() + max(0,emptySlots);
    }
};