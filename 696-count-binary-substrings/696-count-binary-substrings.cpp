class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> vec;
        char last = '.';
        int cnt = 0;
        for(char &ch: s){
            if(ch == last) cnt++;
            else{
                vec.push_back(cnt);
                cnt = 1;
                last = ch;
            }
        }
        vec.push_back(cnt);
        
        int ans = 0;
        for(int i=0;i<vec.size()-1;i++){
            ans += min(vec[i],vec[i+1]);
        }
        
        return ans;
    }
};