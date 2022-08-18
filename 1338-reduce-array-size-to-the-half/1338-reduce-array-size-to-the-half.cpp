class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> hashmap;
        for(int &val: arr){
            hashmap[val]++;
        }
        
        vector<int> freq;
        for(auto p: hashmap){
            freq.push_back(p.second);
        }
        
        sort(freq.begin(),freq.end(),greater<int>());
        
        int integersPicked = 0, setsPicked = 0;
        
        for(int i=0;i<freq.size();i++){
            integersPicked += freq[i];
            setsPicked++;
            if(integersPicked*2 >= arr.size())
                break;
        }        
        
        return setsPicked;
    }
};