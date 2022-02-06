class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> hash;
        for(int &val: nums){
            hash[val]++;
        }
        
        int idx = 0;
        int k = 0;
        for(auto &p: hash){
            if(p.second==1){
                nums[idx++] = p.first;
                k++;
            }
            else{
                nums[idx++] = p.first;
                nums[idx++] = p.first;
                k += 2;
            }
        }
        
        return k;
    }
};