class Solution {
public:
    struct Trie{
        Trie* child[2];
        Trie(){
            child[0] = child[1] = NULL;
        }
    };
    Trie *root = new Trie();
    
    void insert(int num){
        Trie* currnode = root;
        for(int i=31;i>=0;i--){
            int bit = ((num>>i) & 1) ? 1 : 0;
            if(currnode->child[bit] == NULL)
                currnode->child[bit] = new Trie();
            currnode = currnode->child[bit];
        }
    }
    
    int getMaxXOR(int num){
        if (root->child[0] == NULL && root->child[1] == NULL)
            return -1;
        
        Trie* currnode = root;
        int ans = 0;
        
        for(int i=31;i>=0;i--){
            int bit = ((num>>i) & 1) ? 1 : 0;
            
            if(bit==1){
                if(currnode->child[0]){
                    ans += (1<<i);
                    currnode = currnode->child[0];
                }
                else currnode = currnode->child[1];
            }
            else{
                if(currnode->child[1]){
                    ans += (1<<i);
                    currnode = currnode->child[1];
                }
                else currnode = currnode->child[0];
            }
        }
        
        return ans;
    }
    
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> offlineQueries;
        for(int i=0;i<queries.size();i++){
            offlineQueries.push_back({queries[i][1],queries[i][0],i});
        }
        
        sort(offlineQueries.begin(),offlineQueries.end());
        sort(nums.begin(),nums.end());
        
        int j = 0;
        vector<int> answer(queries.size());
        
        for(vector<int> &q: offlineQueries){
            int &limit = q[0], &x = q[1], &idx = q[2];
            
            while(j<nums.size() && nums[j]<=limit)
                insert(nums[j++]);
            
            answer[idx] = getMaxXOR(x);
        }
            
        return answer;
    }
};