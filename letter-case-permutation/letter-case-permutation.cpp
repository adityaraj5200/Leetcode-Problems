class Solution {
public:
    void helper(string &s,int i,vector<string> &vec){
        if(i == s.length()){
            vec.push_back(s);
            return;
        }
        if(isdigit(s[i]))
            helper(s,i+1,vec);
        else if(islower(s[i])){
            helper(s,i+1,vec);
            s[i] -= 32;
            helper(s,i+1,vec);
            s[i] += 32;
        }
        else{
            helper(s,i+1,vec);
            s[i] += 32;
            helper(s,i+1,vec);
            s[i] -= 32;
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> vec;
        helper(s,0,vec);
        return vec;
    }
};