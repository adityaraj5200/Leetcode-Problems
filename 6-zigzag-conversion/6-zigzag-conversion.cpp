class Solution {
public:
    string convert(string s, int numRows) {
        const int n = s.length();
        if(numRows==1) return s;
        
        string ans;
        
        for(int curr_row = 0; curr_row<numRows ; curr_row++){
            int idx = curr_row;
            bool alternate = true;
            
            while(idx<n){
                ans += s[idx];
                if(alternate){
                    int rows_down = numRows-1-curr_row;
                    int skip_down = 2*rows_down;
                    if(skip_down==0) ans.pop_back();
                    idx += skip_down;
                }
                else{
                    int rows_up = curr_row;
                    int skip_up = 2*rows_up;
                    if(skip_up==0) ans.pop_back();
                    idx += skip_up;
                }
                
                alternate = !alternate;
            }
        }
        
        return ans;
    }
};