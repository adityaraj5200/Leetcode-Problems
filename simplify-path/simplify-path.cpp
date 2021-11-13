class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        int i=0,n=path.length();
        while(i<n){
            string curr;
            while(i<n && path[i]=='/')
                i++;
            while(i<n && path[i] != '/')
                curr += path[i++];
            // cout<<"curr = "<<curr<<endl;
            
            if(curr == ".."){
                if(!stk.empty())
                    stk.pop();
                curr = "";
            }
            else if(curr == ".")
                curr = "";
            
            
            if(curr.length())
                stk.push(curr);
        }
        vector<string> vec;
        while(!stk.empty()){
            vec.push_back(stk.top());
            stk.pop();
        }
        reverse(vec.begin(),vec.end());
        string result;
        for(string &str: vec){
            result += "/" + str;
        }
        if(result.empty()) result = "/";
        return result;
    }
};