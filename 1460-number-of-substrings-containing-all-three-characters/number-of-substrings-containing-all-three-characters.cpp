class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> indices[3];
        int n = s.length(), ans = 0;
        for(int i=0;i<n;i++){
            indices[s[i]-'a'].push_back(i);
        }

        for(int k=0;k<3;k++){
            indices[k].push_back(n);
        }

        int aPtr=0, bPtr=0, cPtr=0;

        int aIdx = indices[0][aPtr];
        int bIdx = indices[1][bPtr];
        int cIdx = indices[2][cPtr];

        while(max({aIdx,bIdx,cIdx})<n){
            int st = min({aIdx,bIdx,cIdx});
            int end = max({aIdx,bIdx,cIdx});
            ans += n-end;

            if(st==aIdx){
                aPtr++;
                aIdx = indices[0][aPtr];
            }
            else if(st==bIdx){
                bPtr++;
                bIdx = indices[1][bPtr];
            }
            else if(st==cIdx){
                cPtr++;
                cIdx = indices[2][cPtr];
            }
        }


        return ans;
    }
};