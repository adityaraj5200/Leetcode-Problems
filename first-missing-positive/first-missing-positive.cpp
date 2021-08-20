#define print(u)              for(auto it=u.begin();it!=u.end();it++)\
                        cout<<*it<<' '; cout<<endl
#define printii(u)            for(auto it=u.begin();it!=u.end();it++)\
                        cout<<it->first<<' '<<it->second<<endl
#define deb(u)                cout<<'>'<<#u<<" = "<<u<<endl
#define deb2(u, v)            cout<<'>'<<#u<<" = "<<u<<" , "<<#v<<" = "<<v<<endl
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
                nums[i] = 0;
        }
                
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i]);
            // if(index==0) nums[i] = 1;
            if(index>0 && index<=nums.size()){
                if(nums[index-1]==0) nums[index-1] = -1*(index);
                else nums[index-1] = -1 * abs(nums[index-1]);
            }
        }
        
        // print(nums);
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0)
                return i+1;
        }
        return nums.size()+1;
    }
};