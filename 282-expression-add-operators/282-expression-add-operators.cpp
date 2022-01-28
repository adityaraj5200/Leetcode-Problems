class Solution{
public:
    vector<string> addOperators(string s, int target){
        this->s = s;
        this->target = target;
        traverse(0,"",0,0);
        return result;
    }
    
private:
    vector<string> result;
    string s;
    int target;
    
    void traverse(int idx,string path,long resSoFar,long prevNum){
        if(idx == s.length()){
            if(resSoFar == target)
                result.push_back(path);
            return;
        }
        
        string numStr;
        long currNum = 0;
        
        for(int j=idx;j<s.length();j++){
            if(j>idx && s[idx]=='0') break;
            
            numStr += s[j];
            currNum = currNum*10 + (s[j]-'0');
            if(idx==0)
                traverse(j+1,path+numStr,resSoFar+currNum,currNum);
            else{
                traverse(j+1,path+"+"+numStr,resSoFar+currNum,currNum);
                traverse(j+1,path+"-"+numStr,resSoFar-currNum,-currNum);
                traverse(j+1,path+"*"+numStr,resSoFar-prevNum+prevNum*currNum, prevNum*currNum);
            }
        }
    }
};
