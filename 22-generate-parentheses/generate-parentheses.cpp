class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        helper(s,n,n);
        return ans;
    }
private:
    vector<string> ans;
    void helper(string& s,int left, int right){
        if(left==0 && right==0){
            ans.push_back(s);
            return;
        }
        
        if(left>0){
            s += "(";
            helper(s,left-1,right);
            s.pop_back();
        }

        if(right>left){
            s += ")";
            helper(s,left,right-1);
            s.pop_back();
        }
    }
};