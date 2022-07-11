class Solution {
public:
    struct Trie{
        unordered_map<int,Trie*> child;
        int val;
    };
    
    int countDistinct(vector<int>& nums, int k, int p) {
        Trie* root = new Trie();
        
        int n = nums.size(), ans = 0;
        
        for(int i=0;i<n;i++){
            int cnt = 0;
            Trie *currnode = root;
            for(int j=i;j<n;j++){
                if(nums[j]%p == 0){
                    cnt++;
                    if(cnt > k)
                        break;
                }
                
                if(currnode->child[nums[j]] == NULL){
                    ans++;
                    currnode->child[nums[j]] = new Trie();
                }
                
                currnode = currnode->child[nums[j]];
            }
        }
        
        return ans;
    }
};