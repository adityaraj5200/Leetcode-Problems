class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX, n = tops.size();
        for(int num=1;num<=6;num++){
            int movefortop = 0, moveforbottom = 0;
            bool consider = true;
            for(int i=0;i<n;i++){
                if(tops[i]!=num && bottoms[i]!=num){
                    consider = false;
                    break;
                }
                
                if(tops[i]!=num && bottoms[i]==num)
                    movefortop++;
                if(tops[i]==num && bottoms[i]!=num)
                    moveforbottom++;
            }
            if(consider)
                ans = min(ans,min(movefortop, moveforbottom));
        }
        return ans==INT_MAX ? -1 : ans;
    }
};