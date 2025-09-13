class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1,curr=1;i<=n;i++){
            ans.push_back(curr);
            if(curr*10<=n){
                curr *= 10;
            }
            else{
                curr++;
                while(curr%10==0){
                    curr /= 10;
                }
                if(curr>n){
                    curr = curr/10 + 1;
                }
                while(curr%10==0){
                    curr /= 10;
                }
            }
        }

        return ans;
    }
};