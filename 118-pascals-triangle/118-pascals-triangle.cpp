class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int k=2;k<=numRows;k++){
            vector<int> temp;
            temp.push_back(1);
            for(int i=0;i<ans.back().size()-1;i++){
                temp.push_back(ans.back()[i] + ans.back()[i+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        
        return ans;
    }
};