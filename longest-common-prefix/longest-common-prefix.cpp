class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int minsize = INT_MAX;
        
        for(string str: strs)
            if(minsize > str.size()){
                minsize = str.size();
            }
        
        if(minsize==0)
            return result;
        
        for(int i=0;i<minsize;i++){
            bool add = true;
            char ch = strs[0][i];
            for(string& str: strs){
                if(str[i] != ch){
                    add = false;
                    break;
                }
            }
            if(add) result += ch;
            else break;
        }
        return result;
    }
};