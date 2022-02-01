class Solution {
public:
    int numberOfWays(string corridor) {
        long long mod = 1e9+7, sofa=0, len=0, ans = 1;
        
        for(char &ch: corridor){
            if(ch == 'S')
                sofa++;
            
            if(sofa == 2){
                len++;
            }
            else if(sofa==3){
                sofa = 1;
                ans = (ans*len)%mod;
                len = 0;
            }
        }
        
        if((sofa & 1) || sofa==0) return 0;
        
        return (int)ans;
    }
};